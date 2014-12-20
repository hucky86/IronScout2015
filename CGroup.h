
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
    
    CTable* getTable();
    QLabel* getName();

 
  private:
    
    // Gruppenname
    QLabel* name_;
    
    // Gruppennummer
    int number_;
    
    // Zugehoerige Tabelle mit allen Informationen
    CTable* table_;
    
    // Layout für Name und Tabelle
    QVBoxLayout* vLayout_;
    
    // Layout für die Eingabe eines neuen Eintrages
    QGridLayout* gLayout_;
    
private slots:
  
signals:
    
};
 
#endif // CGROUP_H