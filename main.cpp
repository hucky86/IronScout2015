// IRON SCOUT AUSWERTUNG
//************************************************************************
// Klasse:          main
// 
// Beschreibung:    Einstiegspunkt des Programms.
//                  
//************************************************************************

#include <QApplication>
#include "CMainWindow.h"
#include "CCentralWidget.h"
 
int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  
  CMainWindow m;
  m.showMaximized();
  m.show();
 
  return app.exec();
}