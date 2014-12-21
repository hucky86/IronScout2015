
#ifndef CCENTRALWIDGET_H
#define CCENTRALWIDGET_H
 
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include <QLabel>
#include <QList>
#include <QComboBox>
#include <QPushButton>
#include <QStackedLayout>
#include <QInputDialog>
#include <QDebug>

#include "CGroup.h"
#include "CRunner.h"
#include "CStation.h"

 
class CCentralWidget : public QWidget
{
  Q_OBJECT
 
  public:
  // Konstruktoren
    // leerer Standartkonstruktor
    CCentralWidget(QString analysis);

 
  private:
  
  // Widgets
    // neue Gruppe anlegen
    QPushButton* button_;
    
    // Gruppe anwählen
    QComboBox* dropDown_;
    
    // Liste aller Gruppen
    QList<CGroup*> groupList_;
    
  // Layouts
    // QVBoxLayout für dropDown_ und button_
    QVBoxLayout* vLayout_;
    
    // QStackedLayout für alle CGroup
    QStackedLayout* sLayout_;
    
    // QHBoxLayout für vLayout_ und sLayout_
    QHBoxLayout* hLayout_;
    
    // Zugehörigkeit der Auswertungsart
    QString analysis_;
    
  private slots:
    
    // hinzufügen einer Gruppe
    void addGroup();
    
    // ändern der angewählten Gruppe
    void changeGroup(int index);
 
  signals:
};
 
#endif // CCENTRALWIDGET_H