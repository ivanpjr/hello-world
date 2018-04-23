#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void size(const string& name, unsigned bytes) {
   cout << setw(12) << name << ": " << right << setw(2) << bytes << " bytes\n";
}

int main() {
   size("char", sizeof(char));
   size("short", sizeof(short));
   size("int", sizeof(int));
   size("long", sizeof(long));
   size("long long", sizeof(long long));
   size("float", sizeof(float));
   size("double", sizeof(double));
   size("long double", sizeof(long double));
   size("void*", sizeof(void*));
   size("char*", sizeof(char*));
   size("long*", sizeof(long*));
   return 0;
}

