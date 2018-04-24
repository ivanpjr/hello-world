#include <iostream>
using namespace std;

int main() {

    int i = 40;
    cout << "i=" << i << endl;

    int* i_ptr = &i;
    cout << "i_prt=" << i_ptr << endl;

    *i_ptr=100;
    cout << "new i=" << i << endl;
    cout << "new *i_ptr=" << *i_ptr << endl;

    return 0;
}