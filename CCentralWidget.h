
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
#include <QGridLayout>
#include <QStackedLayout>
#include <QInputDialog>
#include <QDebug>

#include "CTable.h"
 
class CCentralWidget : public QWidget
{
  Q_OBJECT
 
  public:
    CCentralWidget();

 
  private:
    QVBoxLayout* vLayout_;
    QHBoxLayout* hLayout_;
    QStackedLayout* sLayout_;
    
    //TODO: Spaeter evtl. für Eingabefelder
    QGridLayout* gLayout_;
    
    QList<CTable*> tableList_;
    QPushButton* button_;
    QComboBox* dropDown_;
    QLabel* name_;
    
  private slots:
    void addGroup();
 
  signals:

 
};
 
#endif // CCENTRALWIDGET_H