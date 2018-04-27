#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <utility>
#include <numeric>
#include <random>

using namespace std;
using Frequencies = map<string, unsigned>;
using WordFreq = pair<string, unsigned>;

Frequencies load(istream& in, unsigned minSize);
vector<string> extractWords(string line, unsigned minSize);
vector<WordFreq> mostFrequent(Frequencies freqs, unsigned int N);
vector<string> toTags(vector<WordFreq> words);
string join(vector<string> strings, string delim);

const string htmlPrefix = "<html><body>\n";
const string htmlSuffix = "</body></html>\n";

int main(int argc, char** args) {
    unsigned maxWords = 25;
    unsigned minSize = 4;

    for(auto k=1;k<argc;++k){
        string arg = args[k];
        if (arg == "-w")
            maxWords = static_cast<unsigned>(stoi(args[++k]));
        else if (arg == "-s")
            minSize = static_cast<unsigned>(stoi(args[++k]));
    }

    auto freqs = load (cin, minSize);
    auto words = mostFrequent(freqs, maxWords);

    auto tags = toTags(words);

    random_shuffle(tags.begin(),tags.end());
    string htmlTags = join(tags, "\n" );
    cout << htmlPrefix << htmlTags << htmlSuffix << endl;

    //for (auto& t: tags) cout << t << endl;

    return 0;
}

string join(vector<string> strings, string delim) {
    return accumulate(strings.begin(),strings.end(),""s, [=](auto acc, auto str){
        return acc + delim + str;
    });
}

vector<string> toTags(vector<WordFreq> words) {
    auto maxFontSize = 120.0;
    auto minFontSize = 30.0;
    auto maxFreq = words.front().second;
    auto minFreq = words.back().second;
    double scale = (maxFontSize-minFontSize) / (maxFreq - minFreq);

    vector<string> tags;
    for(auto[word,freq]:words){
        unsigned fontSize = freq * scale;
        string color = "ff0000";

        ostringstream buf;
        buf << "<span style='font-size:"<< fontSize <<"px; color:#" << color << ";'>" << word << "</span>";
        tags.push_back(buf.str());
    }
    return tags;
}

vector<WordFreq> mostFrequent(Frequencies freqs, unsigned int N) {
    vector<WordFreq> sortable{freqs.begin(),freqs.end()};
    sort(sortable.begin(), sortable.end(), [](auto left, auto right){
        return left.second > right.second;
    });
    vector<WordFreq> mostFrequent;
    copy_n(sortable.begin(), N, back_inserter(mostFrequent));
    return mostFrequent;
}

Frequencies load(istream& in, unsigned minSize) {

    Frequencies freqs;
    for (string line; getline(in, line);) {
        //cout << "line: " << line << endl;
        vector<string> words = extractWords(line, minSize);
        for (auto& w:words){
            freqs[w]++;
        }
    }

    return freqs;}

vector<string> extractWords(string line, unsigned minSize) {
    transform(line.begin(), line.end(), line.begin(), [](auto ch){
        return isalpha(ch) ? tolower(ch): ' ';
    });
    vector<string> result;
    istringstream buf{line};
    for (string word; buf >> word;){
        if(word.size() >= minSize) {
            result.push_back(word);
        }
    }
    return result;
};


