#include <iostream>
#include <string>
#include <map>
using namespace std;

//TODO: funct strip from string utils should be here

int main(int argc, char* args[]) {

//    ./wordFrequency iostream < ../main.cpp
//    argc: 2
//    args: 0x7ffdc904c308

    if (argc != 2) {
        cerr << "Syntax: wordFrequency {string} < file";
        return -1;
    }

    map <string, unsigned> freqs;
    for (string word; cin >> word; ) {
       freqs[word]++;
    }

    for (auto [word, freq] : freqs) {
        cout << word << " : " << freq << endl;
    }

    return 0;
}
