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

bool Row::valid()
{
	return true;
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
