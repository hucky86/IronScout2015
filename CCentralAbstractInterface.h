// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CCentralAbstractInterface
// 
// Beschreibung:    Zentrales Widget zur Verwaltung der Ein- und Ausgaben.
//                  Abstrakte Schnittstelle für Stationen und Läufer
// 
//************************************************************************

#ifndef CCENTRALABSTRACTINTERFACE_H
#define CCENTRALABSTRACTINTERFACE_H
 
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
#include <QMessageBox>

#include "CGroup.h"
#include "CRunner.h"
#include "CStation.h"

 
class CCentralAbstractInterface : public QWidget
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralAbstractInterface();

 
  protected:
  
// Widgets:
    // neue Gruppe anlegen
    QPushButton* bNew_;
    // Gruppe löschen
    QPushButton* bDelete_;
    // Gruppe anwählen
    QComboBox* dropDown_;
    // Button zur Bestätigung eines Eintrages in die Tabelle
    QPushButton* bInputNew_;
    // Button zum löschen eines Eintrages in der Tabelle
    QPushButton* bInputDelete_;
    // Button zum Bearbeiten eines Eintrages in der Tabelle
    QPushButton* bEdit_;
    
// Layouts:
    // QVBoxLayout als zentrales Widget
    QVBoxLayout* vLayout_;
    // QStackedLayout für alle CGroup
    QStackedLayout* sLayout_;
    // QHBoxLayout für bNew_, bDelete_ und dropDown_
    QHBoxLayout* hLayout_;
    // Layout für die Input Daten
    QGridLayout* gLayout_;
    
//Membervariablen:
    // Parametersatz dieses Widgets
    QStringList parameter_;
    // Hält die Referenzen zu allen Eingabeparametern
    QList<QLineEdit*> inputList_;
    
//Memberfunktionen:
    // bauen des GridLayouts mit allen Eingabefeldern
    void buildInputLayout();
    // Leeren der Inputfelder
    void emptyInput();
    // Ändern der Button Aktivität von bEdit_ und bInputNew_
    void changeToEditStatus(bool editStatus);
    // Schreiben der Input Daten in das table
    void writeToTable(int row);
    // Schreiben der table Daten in das Input Format
    void writeToInput();
    // Neue Gruppe anlegen
    virtual CGroup* newGroup(QString name, int number) = 0;
    // Überprüft, ob Eintrag bereits vorhanden ist
    bool checkDoubleEntry();
    // Überprüft, ob Gruppe bereits vorhanden ist
    bool checkDoubleGroup(int number);

private slots:
    
    // hinzufügen einer Gruppe
    void addGroup();
    // löschen der aktuellen Gruppe
    void deleteGroup();
    // ändern der angewählten Gruppe
    void changeGroup(int index);
    // Eintrag zum table hinzufügen
    void addEntry();
    // Eintrag im table löschen
    void deleteEntry();
    // Aktuelle CGroup
    CGroup* getCurrentGroup();
    // CGroup bei index
    CGroup* getGroupAt(int index);
    // Bearbeiten-Modus öffnen
    void editInput();
    // Bearbeiten-Modus schließen
    void resumeEditInput();
    // Absenden der Änderungen
    void sendEditedInput();
    // Wenn Joker auf "ja" gesetzt wird
    void setJoker(QString text);
    // Überprüft, ob Gruppenname bereits eingegeben wurde
    void checkGroupName(QString number);
    
signals:
};
 
#endif // CCENTRALABSTRACTINTERFACE_H