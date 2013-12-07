/*
 * row.h
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */

#ifndef ROW_H_
#define ROW_H_

#include "result.h"

class Row {
public:
	Row();
	Row(std::string str);
	bool valid() { return true; }
	Result compare(const Row& r);
	std::string rep();
	friend bool operator==(const Row&, const Row&);
};

bool operator==(const Row&, const Row&);

#endif /* ROW_H_ */
