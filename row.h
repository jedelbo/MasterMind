/*
 * row.h
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */

#ifndef ROW_H_
#define ROW_H_

#include "result.h"
#include <array>
#include <iostream>

const int ROW_SIZE = 4;
const int NB_VAL = 6;

class Row {
public:
	Row();
	Row(std::string str);
	bool valid() { return mValid; }
	Result compare(const Row& r);
	std::string rep();
	bool operator==(const Row&);
private:
	class CodePeg {
	public:
		bool read(std::istream& istr);
		void randomize();
		void erase() { mVal = 0; }
		bool operator==(const Row::CodePeg& other) const { return mVal == other.mVal; }
		int mVal = 0;
	};
	bool mValid = false;
	std::array<CodePeg,ROW_SIZE> mCodePegs;
	friend std::ostream& operator <<(std::ostream& ostr, const Row::CodePeg&);
};

std::ostream& operator <<(std::ostream& ostr, const Row::CodePeg&);

#endif /* ROW_H_ */
