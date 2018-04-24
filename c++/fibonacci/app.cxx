#include <string>
#include <iostream>
#include "fibonacci.hxx"
using namespace std;

int main(int argc, char** argv) {
   int n = stoi(argv[1]);
   cout << endl << "   Fibonacci of " << n << " is: " << fibonacci(n) << endl << endl;
   return 0;
}

