// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralWidget
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Wird als "Station"- oder "Läufer"-Auswertung
//                  initialisiert.
// 
//************************************************************************

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
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralWidget(QString analysis);

 
  private:
  
// Widgets:
    // neue Gruppe anlegen
    QPushButton* bNew_;
    // Gruppe anwählen
    QComboBox* dropDown_;
    // Button zur Bestätigung eines Eintrages in die Tabelle
    QPushButton* bInputNew_;
    // Button zum löschen eines Eintrages in der Tabelle
    QPushButton* bInputDelete_;
    // Button zum Bearbeiten eines Eintrages in der Tabelle
    QPushButton* bEdit_;
    
// Layouts:
    // QVBoxLayout für dropDown_ und bNew_
    QVBoxLayout* vLayout_;
    // QStackedLayout für alle CGroup
    QStackedLayout* sLayout_;
    // QHBoxLayout für vLayout_ und sLayout_
    QHBoxLayout* hLayout_;
    // Layout für die Eingabe eines neuen Eintrages
    QGridLayout* gLayout_;
    
//Membervariablen:
    // Zugehörigkeit der Auswertungsart
    QString analysis_;
    // Parametersatz dieses Widgets
    QStringList parameter_;
    // Hält die Referenzen zu allen Eingabeparametern
    QList<QLineEdit*> inputList_;
    
//Memberfunktionen:
    // bauen des GridLayouts mit allen Eingabefeldern
    void buildInputLayout();
    // Leeren der Inputfelder
    void emptyInput();
  

private slots:
    
    // hinzufügen einer Gruppe
    void addGroup();
    // ändern der angewählten Gruppe
    void changeGroup(int index);
    // Eintrag zum table hinzufügen
    void addEntry();
    // Eintrag im table löschen
    void deleteEntry();
    // Aktuelle CGroup
    CGroup* getCurrentGroup();
    // Bearbeiten-Modus öffnen
    void editInput();
    // Bearbeiten-Modus schließen
    void resumeEditInput();
    
signals:
};
 
#endif // CCENTRALWIDGET_H