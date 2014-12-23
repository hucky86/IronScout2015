#include "CGroup.h"

CGroup::CGroup(QStringList parameter, QString name)
{
  parameter_ = parameter;
  name_ = new QLabel(name);
  vLayout_ = new QVBoxLayout;
  
   // Bauen des TableWidget
  buildTable();
  
  vLayout_->addWidget(name_);
  vLayout_->addWidget(table_);
  
  setLayout(vLayout_);
}
//---------------------------------------------------------------------------------------

QTableWidget* CGroup::getTable()
{
  return table_;
}
//---------------------------------------------------------------------------------------

QLabel* CGroup::getName()
{
  return name_;
}
//---------------------------------------------------------------------------------------

void CGroup::buildTable()
{
  // Table anlegen
  table_ = new QTableWidget;
  
  // Größe der Tabelle setzen
  table_->setColumnCount(parameter_.size());
  table_->setRowCount(0);
  
  // Spaltenüberschriften setzen 
  //(Muss nach setColumnCount geschehen. Sonst wird es wieder überschrieben)
  table_->setHorizontalHeaderLabels(parameter_);
  
  // Verhalten der Tabelle definieren
  table_->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  table_->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
  
  // Nur Auswahl eines Items im table erlauben
  table_->setSelectionMode(QAbstractItemView::SingleSelection);
}
//---------------------------------------------------------------------------------------

void CGroup::addTableEntry(const QList<QLineEdit*> list)
{
  // Neue Zeile hinzufügen
  table_->insertRow(table_->rowCount());
  
  for (int i = 0; i < list.size(); i++)
  {    
    // Holen des TableWidgetItem
    QTableWidgetItem* p = new QTableWidgetItem;
    // Item read only
    p->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    
    // Einfügen in die Tabelle
    table_->setItem(table_->rowCount() - 1, i, p);
    p->setText(list.at(i)->text());
  }
}
//---------------------------------------------------------------------------------------


