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
using namespace std;

void printCalendar (int year, int month);
void showHelp();

//Initialize stuff
bool log=false; //debugging logs

map<int,string> weekDays{  //Days of the Week
        {0,"Sun"},
        {1,"Mon"},
        {2,"Tue"},
        {3,"Wed"},
        {4,"Thu"},
        {5,"Fri"},
        {6,"Sat"}
};

map<int,pair<string, int>> months{  // Months and days per month
        {1,make_pair("January", 31)},
        {2,make_pair("February", 28)},
        {3,make_pair("March", 31)},
        {4,make_pair("April", 30)},
        {5,make_pair("May", 31)},
        {6,make_pair("June", 30)},
        {7,make_pair("July", 31)},
        {8,make_pair("August", 31)},
        {9,make_pair("September", 30)},
        {10,make_pair("October", 31)},
        {11,make_pair("November", 30)},
        {12,make_pair("December", 31)}
};

int main(int argc, char* argv[]) {

// Fetch current month and year, in case no arguments are entered
// IMPORTANT: tm_mon is 0-based, but this program will use 1-based month to avoid calculations later and improve readability
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    int year = now->tm_year + 1900;  //tm_year is 1900-based
    int month = now->tm_mon + 1;  //tm_mon is 0-based, adjust by adding 1

// Treat arguments
    try {
        for (auto k = 1; k < argc; ++k) {

            string arg = argv[k];

            if (arg != "-h" && arg != "-m" && arg != "-y" && arg != "-nm" && arg != "-l") {
                throw invalid_argument(arg);

            } else if (arg == "-h")
                showHelp();

            else if (arg == "-m") {
                month = static_cast<int>(stoi(argv[++k]));
                if ((month < 1) || (month > 12)) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-y") {
                year = static_cast<int>(stoi(argv[++k]));
                if (year < 0) {
                    throw invalid_argument(arg);
                }

            } else if (arg == "-l")
                log = true;
        }
    } catch (exception& e) {
        cerr << endl << "\033[0;31m" << "Invalid argument: " << e.what() << "\033[0m" << endl << endl;
        showHelp();
        return -1;
    }

    if (log) clog << "DoW: 0:Sun, 1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat" << endl;
    if (log) clog << "Now:  "  << (now->tm_year + 1900) << '-'
                  << (now->tm_mon + 1) << "-"
                  <<  now->tm_mday << " @ "
                  <<  now->tm_hour << ":"
                  <<  now->tm_min << ":"
                  <<  now->tm_sec << " DoW: "
                  <<  now->tm_wday << "."
                  << "\n";

//Fix the number of days in february for leap years
    int daysFeb;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysFeb = 29;
    else
        daysFeb = 28;
    months.find(2)->second.second = daysFeb;

//Print out calendar
    printCalendar(year, month);

//Print out calendar
    month++;
    printCalendar(year, month);

    return 0;
}

void showHelp(){
    cout << "Syntax:" << endl
         << "./Calendar [-l] [-h] [-m month] [-y year]" << endl
         << "\t-l      \tEnable logging" << endl
         << "\t-h      \tShows this help" << endl
         << "\t-m month\tMonth for the Calendar in numeric value, e.g.: -m 5" << endl
         << "\t-y year \tYear for the Calendar in numeric value, e.g.: -y 2018" << endl
         << endl;
    return;
}

void printCalendar (int year, int month){

//Calculate day of the week based on input values for month and year, or current values if no input
    tm inputDate = { 0, 0, 0, 1, month - 1, year - 1900 }; // second, minute, hour, 1-based day, 0-based month, year since 1900
    time_t tmpDate = mktime(&inputDate);
    const tm * then = localtime(&tmpDate);
    int dow = then->tm_wday; // 0-based Day of the Week (dow)

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

//Print out days, in 7 columns
    int col;
    for (col=1; col<=dow; col++){
        cout << "\t";
    }
    for(int d=1; d<=it->second.second; d++) {
        cout << d << "\t";
        if (col%7 == 0) cout << endl;
        col++;
    }

//Skip a couple of lines
    cout << endl << endl;

    return;
}

