#include <iostream>
using namespace std;

struct Account{
    int balance;
    float rate;
};

int main() {
    Account acc_array[] = {{100, 1.0},{200, 2.0},{300, 3.0},{400, 4.0},{500, 5.0}};
    const unsigned N = sizeof(acc_array) / sizeof(acc_array[0]);

    Account* a_ptr = acc_array;

    for(Account* n=a_ptr; n<a_ptr+N; n++)
        cout << "acc: " << n << " {" << n->balance << ", " << n->rate << "}" << endl;

    for(Account* n=a_ptr; n<a_ptr+N; n++) {
        n->balance = n->balance * (1+n->rate/100);
        cout << "Updated acc: " << n << " {" << n->balance << ", " << n->.rate << "}" << endl;
    }

    return 0;
}