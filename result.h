/*
 * result.h
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */

#ifndef RESULT_H_
#define RESULT_H_

#include <string>

class Result {
public:
  Result();
  void incrPosition() { rightPosition++; }
  void incrColor() { rightColor++; }
  std::string rep();
private:
  int rightColor;
  int rightPosition;
};

#endif /* RESULT_H_ */
