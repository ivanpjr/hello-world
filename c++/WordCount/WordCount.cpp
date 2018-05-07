#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void count(string filename, istream& input);

int main(int argc, char* argv[]) {

    cout << "argc: " << argc << endl;
    cout << "arg1: " << argv[1] << endl;
    string filename;
    filename = argv[1];

    cout << "filename: " << filename << endl;
    ifstream file{filename};

    if (!file) throw invalid_argument ("cannot open "+filename);

    count(filename, file);

    return 0;
}

void count(string filename, istream& input) {
    int numChars = 0;
    int numLines = 0;
    int numWords = 0;
    for (string line; getline (input, line) ; ++ numLines) {
        numChars+=line.size();
        istringstream a_line{line};
        for(string word; a_line >> word; ++numWords){
        }
    }
    cout << "file: " << filename << ", lines: "<< numLines << ", words: " << numWords <<", chars: "<< numChars << endl ;
}
