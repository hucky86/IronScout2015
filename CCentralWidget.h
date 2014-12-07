
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

#include "CTable.h"
 
class CCentralWidget : public QWidget
{
  Q_OBJECT
 
  public:
    CCentralWidget();

 
  private:
    QVBoxLayout* vLayout_;
    QHBoxLayout* hLayout_;
    
    QList<CTable*> tableList_;
    QPushButton* button_;
    QComboBox* dropDown_;
    QLabel* name_;
    
  private slots:
 
  signals:

 
};
 
#endif // COUNTERBUTTON_H