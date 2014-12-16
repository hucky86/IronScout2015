#include "CGroup.h"

CGroup::CGroup()
{
  table_ = new CTable;
}

CTable* CGroup::getTable()
{
  return table_;
}


