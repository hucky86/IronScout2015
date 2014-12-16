
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

#include "CGroup.h"

 
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
    
    QPushButton* button_;
    QComboBox* dropDown_;
    QLabel* name_;
    
    QList<CGroup*> groupList_;
    
  private slots:
    void addGroup();
    void changeGroup(int index);
 
  signals:

 
};
 
#endif // CCENTRALWIDGET_H