/* Klasse zur Darstellung einer Laeufergruppe */

#ifndef CRUNNER_H
#define CRUNNER_H

#include <QMainWindow>
#include <qstring.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidget>

#include "CCentralWidget.h"

class CMainWindow : public QMainWindow
{
  Q_OBJECT
  
private:
  
  // Hauptmenüeinträge
  CCentralWidget* central_;
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

#endif // CRUNNER_H