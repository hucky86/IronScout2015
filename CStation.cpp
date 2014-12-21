
#include "CStation.h"

CStation::CStation(QString name): CGroup(name)
{
  buildTable();
  
  vLayout_->addWidget(table_);
}

void CStation::buildTable()
{
  // Table anlegen
  table_ = new QTableWidget;
  
  // Größe der Tabelle setzen
  table_->setColumnCount(6);
  table_->setRowCount(3);
  
  // Tabelleneinträge
  QStringList names_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt";
  
  // Spaltenüberschriften setzen 
  //(Muss nach setColumnCount geschehen. Sonst wird es wieder überschrieben)
  table_->setHorizontalHeaderLabels(names_);
  
  // Verhalten der Tabelle definieren
  table_->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  table_->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );

}



