#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>
#include <QtGui>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>

class Progress : public QFrame
{
  Q_OBJECT
public:
  explicit Progress(QWidget *parent = 0);
  

  void showProgressBar(bool b1);
  void setTitle(QString t2);
  void setText1(QString t1);
protected:
  QHBoxLayout *main_layout;
  QLabel *text1;
  QLabel *title;
  QLabel *progressbar;


signals:
  
public slots:
  
};

#endif // PROGRESS_H
