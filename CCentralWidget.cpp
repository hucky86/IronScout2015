#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  HLayout_ = new QHBoxLayout;
  
  tableList_.append(new CTable);
  
  // Anlegen der Layouts
  HLayout_->addWidget(tableList_.at(0));
  this->setLayout(HLayout_);
}
