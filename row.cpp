/*
 * row.cpp
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */



#include "row.h"
#include <sstream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
minstd_rand0 generator(seed);
uniform_int_distribution<int> distribution(1, NB_VAL);

/*****************************************************************************/

void Row::CodePeg::randomize()
{
	mVal = distribution(generator);
}

void Row::CodePeg::read(std::istream& istr)
{
	if (!(istr >> mVal)) {
		throw InvalidInput("Key in 4 numbers");  // TODO: Make configurable
	}
	if (mVal > NB_VAL) {
		throw InvalidInput("Number should be between 1 and 6");  // TODO: Make configurable
	}
}

std::ostream& operator <<(std::ostream& ostr, const Row::CodePeg& cp)
{
	ostr << cp.mVal;
	return ostr;
}

/*****************************************************************************/

Row::Row()
{
	for (CodePeg& cp : mCodePegs) {
		cp.randomize();
	}
	cout << rep() << endl;
}

Row::Row(std::string str)
{
	istringstream buf(str);
	for (CodePeg& cp : mCodePegs) {
		cp.read(buf);
	}
}

Result Row::compare(const Row& r)
{
	Result res;
	auto tmp = mCodePegs;
	vector<CodePeg> checkForColor;

	// First check for position
	for (int i = 0; i<ROW_SIZE; i++) {
		if (r.mCodePegs[i] == tmp[i]) {
			res.incrPosition();
			tmp[i].erase();     // This element should not be tested again
		}
		else {
			// If the position is not right, the color must be checked
			checkForColor.push_back(r.mCodePegs[i]);
		}
	}
	for (CodePeg cp :checkForColor) {
		auto it = find(tmp.begin(), tmp.end(), cp);
		if (it != tmp.end()) {
			res.incrColor();
			it->erase();     	// This element should not be tested again
		}
	}

	return res;
}

std::string Row::rep()
{
	ostringstream  buf;
	for (const CodePeg& cp : mCodePegs) {
		buf << cp << " ";
	}
	return buf.str();
}

bool Row::operator==(const Row& other)
{
	for (int i=0; i<ROW_SIZE; i++) {
		if (!(mCodePegs[i] == other.mCodePegs[i]))
			return false;
	}
	return true;
}

/*****************************************************************************/

#ifdef UNITTEST_ROW
#include <cassert>

int main()
{
	Row secret1("1 2 3 4");
	Row secret2("1 1 3 4");
	Row secret3("4 3 4 4");

	Row guess1("1 2 3 4");

	Row guess5("1 1 2 2");
	Row guess6("1 2 3 5");
	Row guess7("4 3 2 1");
	Row guess8("5 6 5 6");

	Row guess9("2 2 1 1");
	Row guess10("2 1 1 1");
	Row guess11("3 3 4 4");

	assert(guess7.rep()=="4 3 2 1 ");
	try {
		Row guess2("1 2 3");
		cout << "Should not go here" << endl;
		exit(1);
	}
	catch (InvalidInput e) {

	}
	try {
		Row guess3("1 2 a 6");
		cout << "Should not go here" << endl;
		exit(1);
	}
	catch (InvalidInput e) {

	}
	try {
		Row guess4("1 2 7 4");
		cout << "Should not go here" << endl;
		exit(1);
	}
	catch (InvalidInput e) {

	}

	assert(secret1.compare(guess1).rep()=="<IIII>");
	assert(secret1 == guess1);
	assert(secret1.compare(guess5).rep()=="<IO>");
	assert(secret1.compare(guess6).rep()=="<III>");
	assert(secret1.compare(guess7).rep()=="<OOOO>");
	assert(secret1.compare(guess8).rep()=="<>");
	assert(secret2.compare(guess9).rep()=="<OO>");
	assert(secret2.compare(guess10).rep()=="<IO>");
	assert(secret3.compare(guess11).rep()=="<III>");

	return 0;
}

#endif
