#include "fibonacci.hxx"
#include <iostream>

long fibonacci(int n) {
   if (n < 0) return -1;
   if (n == 0) return 0;
   return n <=2 ? 1 : fibonacci(n-2) + fibonacci(n-1);
}


