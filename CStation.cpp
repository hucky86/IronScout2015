
#include "CStation.h"

CStation::CStation(QString name): CGroup(name)
{
  // Parameter Liste anlegen TODO: in const auslagern
  parameters_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  // Bauen des TableWidget
  buildTable();
  vLayout_->addWidget(table_);

  // Bauen des Eingabefeldes
  // Hinzufügen der Label
  for (int i = 0; i < parameters_.size(); i++)
  {
    gLayout_->addWidget(new QLabel(parameters_.at(i)),0,i);
  }
  
  // Hinzufügen der Eingabefelder
  for (int i = 0; i < parameters_.size(); i++)
  {
    gLayout_->addWidget(new QLineEdit,1,i);
  }
  
  // Hinzufügen des Bestätigungs-Buttons
  inputButton_ = new QPushButton("Eintrag hinzufügen");
  gLayout_->addWidget(inputButton_,1,parameters_.size());
  
  vLayout_->addLayout(gLayout_);
}

void CStation::buildTable()
{
  // Table anlegen
  table_ = new QTableWidget;
  
  // Größe der Tabelle setzen
  table_->setColumnCount(6);
  table_->setRowCount(3);
  
  // Spaltenüberschriften setzen 
  //(Muss nach setColumnCount geschehen. Sonst wird es wieder überschrieben)
  table_->setHorizontalHeaderLabels(parameters_);
  
  // Verhalten der Tabelle definieren
  table_->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  table_->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
}



