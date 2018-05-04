/*
Objective:
==========
Write a C++ program that prints out a calendar for a given month.

April 2018
Mon Tue Wed Thu Fri Sat Sun
                         1
 2   3   4   5   6   7   8
 9  10  11  12  13  14  15
16  17  18  19  20  21  22
23  24  25  26  27  28  29
30

Command-line arguments:
=======================
-No program argument: Print calendar for current month
-Month Name: Print calendar for given month in current year
-Month and year: Print calendar for given month in given year

Write this program yourself, do not use an external library. However,
you might perhaps want to google around a little bit if you get stuck.

Extra:
======
If you have some spare time, you can add options to
-Start week on Sunday (or any other week-day if you like)
-Print more than one month, if given an interval as input
-Set language, such as Swedish week-day and month names.

 */

#include <iostream>
#include <ctime>
#include <map>
#include <stdexcept>
#include <vector>

using namespace std;

void printCalendar (int year, int month, int ws);

void showHelp(){
    cout << "Syntax:" << endl
         << "./Calendar [-l] [-h] [-m month] [-y year] [-nm num_monts] [-ws week_start] [-sv]" << endl
         << "\t-l            \tEnable logging (debug purposes)" << endl
         << "\t-h            \tShows this help" << endl
         << "\t-m month      \tMonth for the Calendar in numeric value, e.g.: -m 5. Must be 0 < value <= 12." << endl
         << "\t-y year       \tYear for the Calendar in numeric value, e.g.: -y 2018. Must be -1 < value." << endl
         << "\t-nm num_months\tNumber of months to print out in numeric value, e.g.: -nm 3. Must be 0 < value <= 24." << endl
         << "\t-ws week_start\tWeek starting day in numeric value, default is 0. Allowed values: [0:Sun|1:Mon|2:Tue|3:Wed|4:Thu|5:Fri|6:Sat]." << endl
         << "\t-sv           \tSkriv ut Calendar i svenska. Default is english." << endl
         << endl;
    return;
}

//Initialize stuff
bool log=false; //debugging logs
map<int,string> weekDays;  // Days of the week
map<int,pair<string, int>> months;  // Months and days per month

int main(int argc, char* argv[]) {

// Fetch current month and year, in case no arguments are entered
// IMPORTANT: tm_mon is 0-based, but this program will use 1-based month to avoid calculations later and improve readability
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    int year = now->tm_year + 1900;  //tm_year is 1900-based
    int month = now->tm_mon + 1;  //tm_mon is 0-based, adjust by adding 1
    int numMonths = 1; // default is to print out only one month
    int ws = 0; // default is to start on Sunday (0)
    bool sv = false; // flag for language: English (false) or Swedish (true)

// Treat arguments
    try {
        for (auto k = 1; k < argc; ++k) {

            string arg = argv[k];

            if (arg != "-l" && arg != "-h" && arg != "-m" && arg != "-y" && arg != "-nm" && arg != "-ws" && arg != "-sv") {
                throw invalid_argument(arg);

            } else if (arg == "-h") {
                showHelp();
                return 0;

            } else if (arg == "-m") {
                month = static_cast<int>(stoi(argv[++k]));
                if ((month < 1) || (month > 12)) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-y") {
                year = static_cast<int>(stoi(argv[++k]));
                if (year < 0) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-nm") {
                numMonths = static_cast<int>(stoi(argv[++k]));
                if ((numMonths < 1) || (numMonths > 24)) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-ws") {
                ws = static_cast<int>(stoi(argv[++k]));
                if ((ws < 0) || (ws > 6)) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-sv") {
                sv = true;

            } else if (arg == "-l") {
                log = true;
            }
        }
    } catch (exception& e) {
        cerr << endl << "\033[0;31m" << "Invalid argument: " << e.what() << "\033[0m" << endl << endl;
        showHelp();
        return -1;
    }

// Print out current date/time, debugging purposes only
    if (log) clog << "DoW: 0:Sun, 1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat" << endl;
    if (log) clog << "Now:  "  << (now->tm_year + 1900) << '-'
                  << (now->tm_mon + 1) << "-"
                  <<  now->tm_mday << " @ "
                  <<  now->tm_hour << ":"
                  <<  now->tm_min << ":"
                  <<  now->tm_sec << " DoW: "
                  <<  now->tm_wday << "."
                  << "\n";

// Fix the language: English or Swedish
    string jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec;
    jan= sv? "Januari"   : "January"   ;
    feb= sv? "Februari"  : "February"  ;
    mar= sv? "Mars"      : "March"     ;
    apr= sv? "April"     : "April"     ;
    may= sv? "Maj"       : "May"       ;
    jun= sv? "Juni"      : "June"      ;
    jul= sv? "Juli"      : "July"      ;
    aug= sv? "Augusti"   : "August"    ;
    sep= sv? "September" : "September" ;
    oct= sv? "Oktober"   : "October"   ;
    nov= sv? "November"  : "November"  ;
    dec= sv? "December"  : "December"  ;

//Fill in month names and days per month
    months = {
            {1,make_pair(jan, 31)},
            {2,make_pair(feb, 28)},  // days in February will be adjusted later, in case of leap years
            {3,make_pair(mar, 31)},
            {4,make_pair(apr, 30)},
            {5,make_pair(may, 31)},
            {6,make_pair(jun, 30)},
            {7,make_pair(jul, 31)},
            {8,make_pair(aug, 31)},
            {9,make_pair(sep, 30)},
            {10,make_pair(oct, 31)},
            {11,make_pair(nov, 30)},
            {12,make_pair(dec, 31)}
    };

    vector<string> week;
    if (sv)
        week = {"Sön", "Mån", "Tis", "Ons", "Tor", "Fre", "Lör"};
    else
        week = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

//Fix the offset for week starting day
    string day0=week[ws];
    string day1=week[ws<6?ws+1:ws-6];
    string day2=week[ws<5?ws+2:ws-5];
    string day3=week[ws<4?ws+3:ws-4];
    string day4=week[ws<3?ws+4:ws-3];
    string day5=week[ws<2?ws+5:ws-2];
    string day6=week[ws<1?ws+6:ws-1];
    weekDays = {{0,day0},{1,day1},{2,day2},{3,day3},{4,day4},{5,day5},{6,day6}};

    if (log) clog <<  "Week: " << day0 << "," << day1 << "," << day2 << "," << day3 << "," << day4 << "," << day5 << "," << day6 << endl;


//Print out calendar(s)
    for (int m=1; m<=numMonths; m++){  // Loop in case more than one month is to be printed out

        if(month>12) {  // If December is passed, increment the year and reset the month to January
            year++;
            month=1;
        }

        //Fix the number of days in february for leap years
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            months.find(2)->second.second = 29;
        else
            months.find(2)->second.second = 28;

        if (log) clog << "Days in February in " << year << ": " << months.find(2)->second.second << endl;
        if (log) clog << "Calling printCalendar( " << year << ", " << month << ", " << ws << " )" << endl;
        printCalendar(year, month++, ws);
    }

    return 0;
}


void printCalendar (int year, int month, int ws){
    if (log) clog << "Inside printCalendar( " << year << ", " << month << ", " << ws << " )" << endl;

//Calculate day of the week based on input values for month and year, or current values if no input
    tm inputDate = { 0, 0, 0, 1, month - 1, year - 1900 }; // second, minute, hour, 1-based day, 0-based month, year since 1900
    time_t tmpDate = mktime(&inputDate);
    const tm * then = localtime(&tmpDate);
    int dow = then->tm_wday; // 0-based Day of the Week (dow)
    if (log) cout << "Day of the week for first day of month: " << dow << endl;

//Skip one line
    cout << endl;

//Print out first line: Month Year
    map<int,pair<string, int>>::iterator it;
    it = months.find(month);
    cout << it->second.first << " " << year << endl;

//Print out second line: Days of the Week
    for (auto d: weekDays)
        cout << d.second << "\t";
    cout << endl;

//Adjust offset (tabs to be printed) before the first day of the month, depending on the week starting day
    switch (dow) {
        case 0: ws <= 0? dow=dow-ws: dow=dow+(7-ws); break;
        case 1: ws <= 1? dow=dow-ws: dow=dow+(7-ws); break;
        case 2: ws <= 2? dow=dow-ws: dow=dow+(7-ws); break;
        case 3: ws <= 3? dow=dow-ws: dow=dow+(7-ws); break;
        case 4: ws <= 4? dow=dow-ws: dow=dow+(7-ws); break;
        case 5: ws <= 5? dow=dow-ws: dow=dow+(7-ws); break;
        case 6: ws <= 6? dow=dow-ws: dow=dow+0; break;
    }
    if (log) cout << "Day of the week for first day of month (adjusted): " << dow << endl;

    //Print out days, in 7 columns
    int col;
    for (col=1; col<=dow; col++){ // Print empty tabs before first day of the month
        cout << "\t";
    }

    for(int d=1; d<=it->second.second; d++) {  // Print days in columns separated by tab
        cout << d << "\t";
        if (col%7 == 0) cout << endl; // Break line after every 7th column (when col is multiple of 7)
        col++;
    }

//Skip a couple of lines
    cout << endl << endl;

    return;
}

