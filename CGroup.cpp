#include "CGroup.h"

CGroup::CGroup(QString name)
{
  name_ = new QLabel(name);
  vLayout_ = new QVBoxLayout;
  
  vLayout_->addWidget(name_);
  
  setLayout(vLayout_);
}

QTableWidget* CGroup::getTable()
{
  return table_;
}

QLabel* CGroup::getName()
{
  return name_;
}

