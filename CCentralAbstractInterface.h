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
#include <fstream>
#include <string>
#include <sstream>

#include "CGroupInterface.h"
#include "CRunnerInterface.h"
#include "CStationInterface.h"

 
class CCentralAbstractInterface : public QWidget
{
  Q_OBJECT
 
  public:
// Konstruktoren:
    // leerer Standartkonstruktor
    CCentralAbstractInterface();
    
// Get/Set-Funktionen
    // Rückgabe der Gruppenanzahl
    int getGroupNumber ();
    // Speichern der Einträge
    void save(std::ofstream& saveFile);
    // Laden der Einträge
    void load(std::stringstream& loadFile);
 
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
    // Button zum Bearbeiten der properties der aktuellen Gruppe
    QPushButton* editProperties_;
    
// Layouts:
    // QVBoxLayout als zentrales Widget
    QVBoxLayout* vLayout_;
    // QStackedLayout für alle CGroupInterface
    QStackedLayout* sLayout_;
    // QHBoxLayout für bNew_, bDelete_ und dropDown_
    QHBoxLayout* hLayout_;
    // QHBoxLayout für Eigenschaften und Eintrag löschen
    QHBoxLayout* editLayout_;
    // Layout für die Input Daten
    QGridLayout* gLayout_;
    
//Membervariablen:
    // Parametersatz dieses Widgets
    QStringList parameter_;
    // Hält die Referenzen zu allen Eingabeparametern
    QList<QLineEdit*> inputList_;
    // Liste aller Gruppennamen der Bögen
    std::map<int, QString> firstNameList_;
    // Liste aller Gruppennamen der Eingabemaske
    std::map<int, QString> secondNameList_;
    
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
    virtual CGroupInterface* newGroup(QString name, int number) = 0;
    // Überprüft, ob Eintrag bereits vorhanden ist
    bool checkDoubleEntry();
    // Überprüft, ob Gruppe bereits vorhanden ist
    bool checkDoubleGroup(int number);
    // Baut die Maps mit allen Gruppennamen
    void buildNameLists();
    // Ordnet dem Interface die Gruppenlisten zu
    virtual void assignLists(std::map<int,QString> runner,std::map<int,QString> station) = 0;

public slots:
    // CGroupInterface bei index
    CGroupInterface* getGroupAt(int index);
    
private slots:
    
    // hinzufügen einer Gruppe
    void addGroup();
    // hinzufügen einer Grppe mit Namen und Nummer
    void addGroup(int number, QString name);
    // löschen der aktuellen Gruppe
    void deleteGroup();
    // ändern der angewählten Gruppe
    void changeGroup(int index);
    // Eintrag zum table hinzufügen
    void addEntry();
    // Eintrag im table löschen
    void deleteEntry();
    // Aktuelle CGroupInterface
    CGroupInterface* getCurrentGroup();
    // Bearbeiten-Modus öffnen
    void editInput();
    // Bearbeiten-Modus schließen
    void resumeEditInput();
    // Absenden der Änderungen
    void sendEditedInput();
    // Überprüft, ob Gruppenname bereits eingegeben wurde
    void checkGroupName(QString number);
    // Öffnet die Properties der aktuellen Gruppe
    void openProperties();
    
signals:
};
 
#endif // CCENTRALABSTRACTINTERFACE_H