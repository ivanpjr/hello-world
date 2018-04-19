//============================================================================
// Name        : hello-world.cpp
// Author      : Ivan Pinheiro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "How many? ";
	cin >> n;
	for (int i; i<n; i++)
	{
		cout << "~=+";
	}

	return 0;
}

