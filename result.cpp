/*
 * result.cpp
 *
 *  Created on: 07/12/2013
 *      Author: Jørgen Edelbo
 */

#include "result.h"

using namespace std;

Result::Result() :
  rightColor(0),
  rightPosition(0)
{

}

std::string Result::rep()
{
  string val = "<";
  int i;

  for (i=0; i<rightPosition; i++) val += 'I';
  for (i=0; i<rightColor; i++) val += 'O';

  val += '>';
  return val;
}

#ifdef UNITTEST_RESULT
#include <cassert>

int main()
{
  Result res;
  assert(res.rep()=="<>");
  res.incrPosition();
  assert(res.rep()=="<I>");
  res.incrColor();
  res.incrPosition();
  assert(res.rep()=="<IIO>");

  return 0;
}

#endif
