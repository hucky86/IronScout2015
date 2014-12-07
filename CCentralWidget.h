
// CounterButton.h
#ifndef COUNTERBUTTON_H
#define COUNTERBUTTON_H
 
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
 
class CCentralWidget : public QWidget   // von QPushButton ableiten -> indirekt von QObject abgeleitet
{
 
  Q_OBJECT
 
  public:
    CCentralWidget();

 
  private:
    QVBoxLayout* layout_;
    QTableWidget* table_;
    
    const QStringList names_;
    
 
  private slots:
 
  signals:

 
};
 
#endif // COUNTERBUTTON_H