#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  
  dropDown_ = new QComboBox;
  button_ = new QPushButton("neue Station");
  name_ = new QLabel("Station");
  
  
  tableList_.append(new CTable);
  
  // Anlegen der Layouts
  hLayout_->addWidget(name_);
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(button_);
  
  vLayout_->addLayout(hLayout_);
  vLayout_->addWidget(tableList_.at(0));
    
  this->setLayout(vLayout_);
}
