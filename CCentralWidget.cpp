#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  
  dropDown_ = new QComboBox;
  button_ = new QPushButton("neue Station");
  name_ = new QLabel;
  
  // Anlegen der Layouts
  hLayout_->addWidget(name_);
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(button_);
  
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(sLayout_);
    
  this->setLayout(vLayout_);
  
  connect(button_, SIGNAL(clicked()), this, SLOT(addGroup()));
  connect(dropDown_, SIGNAL(activated(int)), this, SLOT(changeGroup(int)));
}

void CCentralWidget::addGroup()
{
  bool ok;
  QString text = QInputDialog::getText(this, tr("Erstellung einer neuen Station"),
                                       tr("neuer Stationsname:"), QLineEdit::Normal,QString(),&ok);
  if (ok)
  {
    CGroup* newGroup = new CGroup(text);
    
    groupList_.append(newGroup);
  
    sLayout_->addWidget(newGroup->getTable());
    
    sLayout_->setCurrentWidget(newGroup->getTable());
    name_->setText(newGroup->getName());
    
    dropDown_->addItem(text);
  }
}

void CCentralWidget::changeGroup(int index)
{
  sLayout_->setCurrentIndex(index);
  
  name_->setText(groupList_.at(index)->getName());
}


