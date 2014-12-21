
#ifndef CGROUP_H
#define CGROUP_H

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "CTable.h"
 
class CGroup : public QWidget
{
  Q_OBJECT
 
  public:
    CGroup(QString name);
    
    QTableWidget* getTable();
    QLabel* getName();

 
  private:
    
    // Gruppenname
    QLabel* name_;
    
    // Gruppennummer
    int number_;
    
    // Layout für die Eingabe eines neuen Eintrages
    QGridLayout* gLayout_;
    
protected:
    // Table Widget zur Speicherung aller Eingaben
    QTableWidget* table_;
    
    // Layout für Name und Tabelle
    QVBoxLayout* vLayout_;
    
private slots:
  
signals:
    
};
 
#endif // CGROUP_H