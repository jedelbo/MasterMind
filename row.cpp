/*
 * row.cpp
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */



#include "row.h"

using namespace std;

Row::Row()
{

}

Row::Row(std::string str)
{

}

Result Row::compare(const Row& r)
{
	Result res;
	return res;
}

std::string Row::rep()
{
	return "1 2 3 4";
}

bool operator==(const Row&, const Row&)
{
	return true;
}

#ifdef UNITTEST_ROW
#include <cassert>

int main()
{
	Row secret1("1 2 3 4");
	Row secret2("1 1 3 4");
	Row secret3("4 3 4 4");

	Row guess1("1 2 3 4");
	Row guess2("1 2 3");
	Row guess3("1 2 a 6");
	Row guess4("1 2 7 4");

	Row guess5("1 1 2 2");
	Row guess6("1 2 3 5");
	Row guess7("4 3 2 1");
	Row guess8("5 6 5 6");

	Row guess9("2 2 1 1");
	Row guess10("2 1 1 1");
	Row guess11("3 3 4 4");

	assert(guess1.valid());
	assert(guess7.rep()=="4 3 2 1 ");
	assert(!guess2.valid());
	assert(!guess3.valid());
	assert(!guess4.valid());

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
