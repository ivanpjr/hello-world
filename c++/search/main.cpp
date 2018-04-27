#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* args[]) {

//    edbipjr@edbipjr-VirtualBox:~/myLab/c++/search/cmake-build-debug$ ./search iostream < ../main.cpp
//    argc: 2
//    args: 0x7ffdc904c308

    if (argc != 2) {
        cerr << "Syntax: search {string} < file";
        return -1;
    }
// iostream

    string phrase = args[1];
    int numChars = 0;
    int lineNo = 1;
    int found = 0;
    for(string line; getline(cin, line);lineNo++){
//        cout << "line " << lineNo << ": " << line << endl;
        if (line.find(phrase) != string::npos)
            cout << "found " << (++found) << " at line " << lineNo << " : " << line << endl;
    }

// iostream

    return 0;
}
// iostream
