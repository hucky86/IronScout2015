#include "CGroup.h"

CGroup::CGroup(QString name)
{
  name_ = new QLabel(name);
  vLayout_ = new QVBoxLayout;
  
  table_ = new CTable;
  
  vLayout_->addWidget(name_);
  vLayout_->addWidget(table_);
  
  setLayout(vLayout_);
}

CTable* CGroup::getTable()
{
  return table_;
}

QLabel* CGroup::getName()
{
  return name_;
}

