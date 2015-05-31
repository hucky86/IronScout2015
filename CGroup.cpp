#include "CGroup.h"

CGroup::CGroup(string name, int number)
{
  name_ = name;
  number_ = number;
  
  pointSum_ = 0;
}
//---------------------------------------------------------------------------------------

int CGroup::getNumber()
{
  return number_;
}
//---------------------------------------------------------------------------------------

string CGroup::getName()
{
  return name_;
}


