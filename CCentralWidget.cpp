#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  // Anlegen der Layouts
  layout_ = new QVBoxLayout;
  table_ = new QTableWidget;;
  
  layout_->addWidget(table_);
  this->setLayout(layout_);
}
