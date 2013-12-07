//============================================================================
// Name        : MasterMind.cpp
// Author      : Jørgen Edelbo
// Version     :
// Copyright   : Copyright 2013 Jørgen Edelbo
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "row.h"

int main() {
	Row secret;
	string line;
	vector<Row> guesses;
	cout << " -> ";
	while (getline(cin, line)) {
		Row guess(line);
		if (guess.valid()) {
			guesses.push_back(guess);
			for (Row r : guesses) {
				cout << r.rep() << " - " << secret.compare(r).rep() << endl;
			}
			if (guess == secret) {
				cout << "Code broken !!!" << endl;
				break;
			}
			if (guesses.size() == 10) {
				cout << "No more guesses !!!" << endl;
				cout << "Code was: " << secret.rep() << endl;
				break;

			}
		}
		else {
			cout << "Illegal input" << endl;
		}
		cout << " -> ";
	}
	return 0;
}
