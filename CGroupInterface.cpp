#include "CGroupInterface.h"

CGroupInterface::CGroupInterface(QStringList parameter, QString name, int number)
{
  number_ = number;
  parameter_ = parameter;
  description_ = new QLabel(name);
  vLayout_ = new QVBoxLayout;
  
   // Bauen des TableWidget
  buildTable();
  
  vLayout_->addWidget(description_);
  vLayout_->addWidget(table_);
  
  setLayout(vLayout_);
  
  // Ok Button für Gruppenspezifische Eingaben
  ok_ = new QPushButton;
  ok_->setText("OK");
  ok_->setAutoDefault(true);
  
  // connections
  connect(ok_, SIGNAL(clicked()), this, SLOT(closeProperties()));
}
//---------------------------------------------------------------------------------------

QTableWidget* CGroupInterface::getTable()
{
  return table_;
}
//---------------------------------------------------------------------------------------

void CGroupInterface::buildTable()
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
  
  // Sortieren aktivieren
  table_->sortByColumn(0,Qt::AscendingOrder);
}
//---------------------------------------------------------------------------------------

void CGroupInterface::addTableEntry(const QList<QLineEdit*> list)
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
    
    if(i == 0)
    {
      p->setData(Qt::DisplayRole, list.at(i)->text().toInt());
    }
    else
    {
      p->setText(list.at(i)->text());
    }
  }
}
//---------------------------------------------------------------------------------------

void CGroupInterface::deleteTableEntry()
{  
  table_->removeRow(table_->currentRow());
}
//---------------------------------------------------------------------------------------

bool CGroupInterface::checkEntryExist(int number)
{
  // Durch alle Tabelleneinträge der aktuellen Gruppe
  for (int i = 0; i < table_->rowCount(); i++)
  {
    // Wenn vorhandener Eintrag == number
    if (table_->item(i, 0)->text().toInt() == number)
    {
      return true;
    }
  }

  return false;
}
//---------------------------------------------------------------------------------------

int CGroupInterface::getRow(int number)
{
  int row = -1;
  
  // Durch alle Tabelleneinträge der aktuellen Gruppe
  for (int i = 0; i < table_->rowCount(); i++)
  {
    // Wenn vorhandener Eintrag == number
    if (table_->item(i, 0)->text().toInt() == number)
    {
      row = i;
    }
  }
  
  return row;
}
//---------------------------------------------------------------------------------------

void CGroupInterface::setRedRow(int row)
{
  QBrush red;
  red.setStyle(Qt::SolidPattern);
  red.setColor(QColor(255,0,0));
  
  for (int i = 0; i < table_->columnCount(); i++)
  {
    table_->item(row, i)->setBackground(red);
  }
}
//---------------------------------------------------------------------------------------

void CGroupInterface::setWhiteTable()
{
  QBrush white;
  white.setStyle(Qt::SolidPattern);
  white.setColor(QColor(255,255,255));
  
  for (int row = 0; row < table_->rowCount(); row++)
  {
    for (int column = 0; column < table_->columnCount(); column++)
    {
      table_->item(row, column)->setBackground(white);
    }
  }
}
//---------------------------------------------------------------------------------------

void CGroupInterface::closeProperties()
{
  properties_->close();
}
//---------------------------------------------------------------------------------------

int CGroupInterface::getNumber()
{
  return number_;
}
//---------------------------------------------------------------------------------------
QString CGroupInterface::getName()
{
  return description_->text();
}
//---------------------------------------------------------------------------------------

bool CGroupInterface::isdisqualified()
{
  bool disqualified = disqualified_->isChecked();
  
  return disqualified;
}

//---------------------------------------------------------------------------------------
void CGroupInterface::openProperties()
{
  properties_->setWindowFlags(Qt::WindowStaysOnTopHint);
  properties_->show();
}
//---------------------------------------------------------------------------------------

int CGroupInterface::getNumberAt(int row)
{
  int number = table_->item(row,0)->text().toInt();
  
  return number;
}
//---------------------------------------------------------------------------------------

std::string CGroupInterface::getNameAt(int row)
{
  std:: string name = table_->item(row,1)->text().toStdString();
  
  return name;
}
//---------------------------------------------------------------------------------------

int CGroupInterface::getRowCount()
{
  int count = table_->rowCount();

  return count;
}
//---------------------------------------------------------------------------------------
void CGroupInterface::save(std::ofstream& saveFile)
{
  // Baum öffnen
  saveFile << "CGroupInterface" << "\t";
  
  // Nummer und Name des Tables
  saveFile << number_ << "\t" << description_->text().toStdString() << "\t";
  
  // Gruppenspezifische Daten speichern
  saveProperties(saveFile);
  
  // Alle Tabelleneinträge speichern
  for(int i = 0; i < getRowCount(); i++)
  { 
    // Alle Einträge abspeichern
    for(int j = 0; j < parameter_.size(); j++)
    {
      saveFile << table_->item(i,j)->text().toStdString() << "\t";
    }
  }
  
  // Baum schließen
  saveFile << "CGroupInterface" << "\t";
}
//---------------------------------------------------------------------------------------

void CGroupInterface::loadTable(std::stringstream& stream)
{
  while(true)
  {
    // Hält alle Tabelleneinträge
    QList<QLineEdit*> list;
    
    for(int i = 0; i < parameter_.size(); i++)
    {    
      // Laden der Einträge
      std::string parser;
      getline(stream,parser,'\t');
      
      // Abbruch wenn Ende der Tabelle erreicht
      if(parser == "CGroupInterface")
      {
        return;
      }
      
      list.push_back(new QLineEdit(QString(parser.c_str())));
    }
    
    // Anlegen des Tabelleneintrages
    addTableEntry(list);
  }
}

//---------------------------------------------------------------------------------------

bool CGroupInterface::compare(CGroupInterface* other)
{
  int thisNumber = this->getNumber();
  int otherNumber = other->getNumber();
  
  // Gruppennummer vergleichen
  if(thisNumber != otherNumber)
  {
    // Meldung
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Gruppennummern stimmen nicht überein");
    msgBox.setInformativeText("this: " + QString(QString::number(thisNumber))
      + "\nother: " + QString(QString::number(otherNumber)));
    msgBox.exec();
    
    return false;
  }
  
  // Properties Vergleichen
  if(this->compareProperties(other) == false)
  {
    // Meldung
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Gruppeneigenschaften stimmen nicht überein");
    msgBox.setInformativeText("this: " + this->getName()
      + "\nother: " + other->getName());
    msgBox.exec();
    
    return false;
  }
  
  // Tabelleneinträge vergleichen
  if(this->compareTable(other) == false)
  { 
    return false;
  }
  
  return true;
}
//---------------------------------------------------------------------------------------

bool CGroupInterface::compareTable(CGroupInterface* other)
{
  //Vergleich, ob die Anzahl der Einträge identisch ist
  if(this->getRowCount() != other->getRowCount())
  {
    // Meldung
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Unterschiedliche Anzahl der Tabelleneinträge");
    msgBox.setInformativeText("this: " + this->getName()
      + "\nother: " + other->getName());
    msgBox.exec();
    
    return false;
  }
    
  for(int i = 0; i < table_->rowCount(); i++)
  {
    for(int j = 0; j < table_->columnCount(); j++)
    {
      if(this->getTable()->item(i,j)->text() != other->getTable()->item(i,j)->text())
      {
        // Meldung
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Unterschiedlicher Tabelleneintrag");
        msgBox.setInformativeText("this: " + this->getName()
          + "\nother: " + other->getName()
          + "\n" + "Zeile: " + QString::number(i)
          + "\nSpalte: " + QString::number(j));
        msgBox.exec();
        
        return false;
      }
    }
  }
  return true;
}
