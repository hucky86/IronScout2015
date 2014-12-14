#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  
  dropDown_ = new QComboBox;
  button_ = new QPushButton("neue Station");
  name_ = new QLabel("Station");
  
  
  //tableList_.append(new CTable);
  
  // Anlegen der Layouts
  hLayout_->addWidget(name_);
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(button_);
  
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(sLayout_);
    
  this->setLayout(vLayout_);
  
  connect(button_, SIGNAL(clicked()), this, SLOT(addGroup()));
}

void CCentralWidget::addGroup()
{
  bool ok;
  QString text = QInputDialog::getText(this, tr("Erstellung einer neuen Station"),
                                       tr("neuer Stationsname:"), QLineEdit::Normal,QString(),&ok);
  if (ok)
  {
    CTable* newGroup = new CTable;
    bool ok;
  
    tableList_.append(newGroup);
  
    sLayout_->addWidget(newGroup);
    sLayout_->setCurrentWidget(newGroup);
  }
}

