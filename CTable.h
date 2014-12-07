#ifndef CTABLE_H
#define CTABLE_H

#include <QTableWidget>
#include <QLabel>
#include <QHeaderView>


class CTable	:	public QTableWidget
{
  Q_OBJECT
  
public:
  CTable();
 
private:
  
  // Name der Tabelle
  QLabel* name_;
  const QStringList names_;
  
private slots:
 
signals:
  
};

#endif //CTABLE_H