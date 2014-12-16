#include "CGroup.h"

CGroup::CGroup(QString name)
:name_(name)
{
  table_ = new CTable;
}

CTable* CGroup::getTable()
{
  return table_;
}

QString CGroup::getName()
{
  return name_;
}

