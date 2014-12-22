
#include "CStation.h"

CStation::CStation(QStringList parameter, QString name): CGroup(name)
{
  // Parameter Liste anlegen TODO: in const auslagern
  parameter_ = parameter;
  
  // Bauen des TableWidget
  buildTable();
  vLayout_->addWidget(table_);
}

void CStation::buildTable()
{
  // Table anlegen
  table_ = new QTableWidget;
  
  // Größe der Tabelle setzen
  table_->setColumnCount(6);
  table_->setRowCount(0);
  
  // Spaltenüberschriften setzen 
  //(Muss nach setColumnCount geschehen. Sonst wird es wieder überschrieben)
  table_->setHorizontalHeaderLabels(parameter_);
  
  // Verhalten der Tabelle definieren
  table_->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  table_->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
}



