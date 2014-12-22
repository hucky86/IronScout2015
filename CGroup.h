#ifndef CGROUP_H
#define CGROUP_H

#include <QLabel>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
 
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
    
protected:
    // Table Widget zur Speicherung aller Eingaben
    QTableWidget* table_;
    
    // Layout für Name und Tabelle
    QVBoxLayout* vLayout_;
    
    virtual void buildTable () = 0;
    
private slots:
  
signals:
    
};
 
#endif // CGROUP_H