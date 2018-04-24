#include <iostream>
using namespace std;

struct Account{
    int balance;
    float rate;
};

int main() {
    Account a1 = {100, 0.5};
    cout << "a1: {" << a1.balance << ", " << a1.rate << "}" << endl;

    Account* a_ptr = &a1;
    cout << "a_ptr->: {" << a_ptr->balance << ", " << a_ptr->rate << "}" << endl;

    a_ptr->balance = a_ptr->balance * 10;
    cout << "a_ptr*10->: {" << a_ptr->balance << ", " << a_ptr->rate << "}" << endl;

    return 0;
}