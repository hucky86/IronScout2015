#include "CCentralWidget.h"

CCentralWidget::CCentralWidget()
{ 
  // Anlegen der Layouts
  hLayout_ = new QHBoxLayout;
  vLayout_ = new QVBoxLayout;
  sLayout_ = new QStackedLayout;
  
  // Anlegen der Widgets
  dropDown_ = new QComboBox;
  button_ = new QPushButton("neue Station");
  
  // Konfigurieren der Layouts
  hLayout_->addWidget(dropDown_);
  hLayout_->addWidget(button_);
  
  vLayout_->addLayout(hLayout_);
  vLayout_->addLayout(sLayout_);
    
  this->setLayout(vLayout_);
  
  // setzen der connections
  connect(button_, SIGNAL(clicked()), this, SLOT(addGroup()));
  connect(dropDown_, SIGNAL(activated(int)), this, SLOT(changeGroup(int)));
}

void CCentralWidget::addGroup()
{
  bool ok;
  
  // Eingabeauforderung des neuen Stationsnamens
  QString text = QInputDialog::getText(this, tr("Erstellung einer neuen Station"),
                                       tr("neuer Stationsname:"), QLineEdit::Normal,QString(),&ok);
  // Wenn durch "ok" bestätigt
  if (ok)
  {
    // Hinzufügen des items und aktiv setzen
    dropDown_->addItem(text);
    dropDown_->setCurrentIndex(dropDown_->count() - 1);
    
    // neue Gruppe anlegen und dem QStackedLayout hinzufügen
    CGroup* newGroup = new CGroup(text);
    groupList_.append(newGroup);
  
    sLayout_->addWidget(newGroup);
    sLayout_->setCurrentWidget(newGroup);
  }
}

void CCentralWidget::changeGroup(int index)
{
  sLayout_->setCurrentIndex(index);
}


