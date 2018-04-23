#include <iostream>
using namespace std;

float balance (int balance, float interest) {
	return balance * (1+(interest / 100));
}

float reversedBalance (int balance, float interest) {
// 	not possible, why??
//	float bal = balance(balance, interest);
	float bal = balance * (1+(interest / 100));
	return bal * (1 / bal);
}

int main() {

//cout << "Enter amount: "; cin >> amount;
//cout << "Enter interest: "; cin >> interest;
//cout << "Final amount: " << amount * (1+(interest / 100)) << endl;

cout << "Final balance   : " << balance(100, 1.25) << endl;
cout << "Reversed balance: " << reversedBalance(100, 1.25) << endl;


return 0;
}


