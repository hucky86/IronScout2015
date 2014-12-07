#include "CTable.h"

CTable::CTable(): QTableWidget()
{
  // Größe der Tabelle setzen
  this->setColumnCount(6);
  this->setRowCount(3);
  
  // Tabelleneinträge
  QStringList names_ = QStringList() << "Laeufername" << "#" << "Punkte 1" 
  << "Punkte 2" << "Punkte 3" << "Punkte Gesamt"
  
  // Spaltenüberschriften setzen 
  //(Muss nach setColumnCount geschehen. Sonst wird es wieder überschrieben)
  this->setHorizontalHeaderLabels(names_);
  
  // Verhalten der Tabelle definieren
  this->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  this->horizontalHeader()->setResizeMode( QHeaderView::Stretch );
}
