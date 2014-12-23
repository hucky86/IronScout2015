// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          CMainWindow
// 
// Beschreibung:    Interface zur Verwaltung des Programms. Verwaltung
//                  der Menüleiste sowie des CCentralWidget.
//                  
//************************************************************************

#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <qstring.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidget>
#include <QStackedLayout>
#include <QWidget>

#include "CCentralWidget.h"

class CMainWindow : public QMainWindow
{
  Q_OBJECT
  
private:
  
  // Hauptmenüeinträge
  QWidget* centralWidget_;
  QStackedLayout* centralLayout_;
  CCentralWidget* centralStation_;
  CCentralWidget* centralRunner_;
  QMenuBar* menu_;
  
  // Menüleiste erzeugen
  QMenuBar* createMenuBar ();
  
public:
  CMainWindow();
  ~CMainWindow();

private slots:
  void closeWindow();
  void saveFile();
  void loadFile();
  void changeToStation();
  void changeToRunner();
  
  
signals:
  
};

#endif // CMAINWINDOW_H