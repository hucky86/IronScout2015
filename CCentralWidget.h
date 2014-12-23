
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
#include <QGridLayout>
#include <QStringList>

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
    
  // Layouts
    // QVBoxLayout für dropDown_ und button_
    QVBoxLayout* vLayout_;
    
    // QStackedLayout für alle CGroup
    QStackedLayout* sLayout_;
    
    // QHBoxLayout für vLayout_ und sLayout_
    QHBoxLayout* hLayout_;
    
    // Zugehörigkeit der Auswertungsart
    QString analysis_;
    
    // Layout für die Eingabe eines neuen Eintrages
    QGridLayout* gLayout_;
    
    // Button zur Bestätigung eines Eintrages in die Tabelle
    QPushButton* inputButton_;
    
    // Parametersatz dieses Widgets
    QStringList parameter_;
    
    // bauen des GridLayouts mit allen Eingabefeldern
    void buildInputLayout();
    
    // Hält die Referenzen zu allen Eingabeparametern
    QList<QLineEdit*> inputList_;
  
    
  private slots:
    
    // hinzufügen einer Gruppe
    void addGroup();
    
    // ändern der angewählten Gruppe
    void changeGroup(int index);
    
    // Eintrag zum table hinzufügen
    void addEntry();
 
  signals:
};
 
#endif // CCENTRALWIDGET_H