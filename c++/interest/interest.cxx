#include <iostream>
using namespace std;

int main() {

int amount;
float interest;

cout << "Enter amount: "; cin >> amount;
cout << "Enter interest: "; cin >> interest;
cout << "Final amount: " << amount * (1+(interest / 100)) << endl;

// this one uses more assemler instructions than previous one
// cout << "Final amount: " << amount + (amount * interest / 100) << endl;

return 0;
}


