#include <iostream>
using namespace std;

enum class AccountType {savings, check, transfer};

struct Account{
    AccountType type;
    int balance;
    float rate;
};

string toString(AccountType t) {
    switch (t){
        case AccountType::savings: return "savings";
        case AccountType::check: return "check";
        case AccountType::transfer: return "transfer";
    }
    return "***";
}

int main() {

   cout << "Hello, World!" << endl;

   Account a1 = {AccountType::savings, 100, 1.25};
   cout << "a1: " << toString(a1.type) << ", " << a1.balance << ", " << a1.rate << endl;

   Account a2 = {AccountType::transfer, 200, 2.35};
   cout << "a2: " << toString(a2.type) << ", " << a2.balance << ", " << a2.rate << endl;

   return 0;
}