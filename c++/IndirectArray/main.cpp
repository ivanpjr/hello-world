#include <iostream>
using namespace std;

int main() {
    int i[] = {10, 20, 30, 40, 50};
    const unsigned N = sizeof(i) / sizeof(i[0]);

    for(int n=0;n<N;n++)
       cout << "i[" << n << "]=" << i[n] << endl;

   int* i_ptr=i;
   cout << "*i_ptr=" << *i_ptr << endl;

    for(int* n=i_ptr;n<i_ptr+N;n++)
        cout << "i_ptr[" << n << "]=" << *n << endl;

    for(int* n=i_ptr;n<i_ptr+N;n++) {
        *n *= 10;
        cout << "i_ptr[" << n << "] x 10=" << *n << endl;
    }

    for(int n=0;n<N;n++)
        cout << "i[" << n << "]=" << i[n] << endl;


    return 0;
}
