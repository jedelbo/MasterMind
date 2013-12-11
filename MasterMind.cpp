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
  cout << "Sequence of " << ROW_SIZE << " random values has been generated" << endl;
  cout << "   ? ? ? ?" << endl;
  cout << "-> ";
  while (getline(cin, line)) {
    try {
      Row guess(line);
      guesses.push_back(guess);
      int i = 1;
      cout << "==================" << endl;
      for (Row r : guesses) {
        cout << i++  << ": " << r.rep() << "- " << secret.compare(r).rep() << endl;
      }
      if (guess == secret) {
        cout << "Code broken !!!" << endl;
        break;
      }
      if (i == 10) {
        cout << "No more guesses !!!" << endl;
        cout << "Code was: " << secret.rep() << endl;
        break;
      }
    }
    catch (const InvalidInput& e) {
      cout << e.what() << endl;
    }
    cout << "-> ";
  }
  return 0;
}
