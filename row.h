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
#include <exception>

const int ROW_SIZE = 4;
const int NB_VAL = 6;

struct InvalidInput : std::exception {
	InvalidInput(const char* errTxt) : mErrTxt(errTxt) {}
	virtual const char* what() const noexcept { return mErrTxt; }
	const char* mErrTxt;
};

class Row {
public:
	Row();
	Row(std::string str);
	Result compare(const Row& r);
	std::string rep();
	bool operator==(const Row&);
private:
	class CodePeg {
	public:
		void read(std::istream& istr);
		void randomize();
		void erase() { mVal = 0; }
		bool operator==(const Row::CodePeg& other) const { return mVal == other.mVal; }
		int mVal = 0;
	};
	std::array<CodePeg,ROW_SIZE> mCodePegs;
	friend std::ostream& operator <<(std::ostream& ostr, const Row::CodePeg&);
};

std::ostream& operator <<(std::ostream& ostr, const Row::CodePeg&);

#endif /* ROW_H_ */
