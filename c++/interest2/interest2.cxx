#include <iostream>
using namespace std;

float balance (int balance, float interest) {
	return balance * (1+ interest / 100);
}

float reversedBalance (int balance, float interest) {
	return balance / (1 + interest / 100);
}

int main() {

int bal = 1000;
float interest = 1.25;
//cout << "Enter balance : "; cin >> balance;
//cout << "Enter interest: "; cin >> interest;

float amount1 = balance(bal, interest);
float amount2 = reversedBalance(amount1, interest);

cout << "Final balance   : " << amount1 << endl;
cout << "Reversed balance: " << amount2 << endl;


return 0;
}


