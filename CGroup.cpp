#include "CGroup.h"

CGroup::CGroup(string name, int number)
{
  name_ = name;
  number_ = number;
}
//---------------------------------------------------------------------------------------

int CGroup::getNumber()
{
  return number_;
}

