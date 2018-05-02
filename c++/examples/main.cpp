#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(9);
    v.push_back(2);

    for (auto i=v.begin(); i!= v.end(); i++){ //i is type iterator(?)
        cout << "i: " << *i << endl;
    }
    cout << "--------\n";

    for (auto i=v.rbegin(); i!= v.rend(); i++){ //i is type iterator(?)
        cout << "i: " << *i << endl;
    }


    return 0;
}