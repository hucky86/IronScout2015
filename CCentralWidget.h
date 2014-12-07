
#ifndef CCENTRALWIDGET_H
#define CCENTRALWIDGET_H
 
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include <QLabel>
#include <QList>

#include "CTable.h"
 
class CCentralWidget : public QWidget
{
  Q_OBJECT
 
  public:
    CCentralWidget();

 
  private:
    QVBoxLayout* Vlayout_;
    QHBoxLayout* HLayout_;
    QList<CTable*> tableList_;
    
 
  private slots:
 
  signals:

 
};
 
#endif // COUNTERBUTTON_H