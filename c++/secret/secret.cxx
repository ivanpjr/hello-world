#include <iostream>
#include <cstdlib>
using namespace std;

unsigned genSecret() { 
	srand(static_cast<unsigned int>(time(NULL)));
	return 1 + (rand() % 10); 
}

int main() {
	int secret = genSecret();

	for (int i=4; i>=0; i--) {
		cout << "Guess the number: "; 
		int guess;
		cin >> guess;

		if (guess == secret) {
		   cout << "Congrats!! " << guess << " is the right number!" << endl;
		   return 0;
		}

		if (i == 0) {
		   cout << "You failed! Correct value is: " << secret << endl;
		   return 1;
		}

		if (guess < secret) {
		   cout << guess << " is too low, you have " << i << " chances, try again!" << endl;
		} else {
		   cout << guess << " is too high, you have " << i << " chances, try again!" << endl;
		}
	}
}


