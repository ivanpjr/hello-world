#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int n, char* args[]) {
   string name = (n==1) ? "Nisse" : args[1];
   cout << "Hi " << name << " welcome to C++" << endl;

   vector<string>  words = {"C++", "is", "cool"};
   for (auto& s : words) cout << s << ' '; cout << endl;

   return 0;
}

