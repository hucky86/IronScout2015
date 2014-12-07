#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{
  layout_ = new QVBoxLayout;
  table_ = new QTableWidget;
  
  QStringList names_ = QStringList() << "Stationsname" << "#" 
    << "Laeufername" << "#" << "Punkte 1" << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  table_->setColumnCount(8);
  table_->setRowCount(3);
  table_->setHorizontalHeaderLabels(names_);
  
  table_->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  table_->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
  
  layout_->addWidget(table_);
  this->setLayout(layout_);
}
