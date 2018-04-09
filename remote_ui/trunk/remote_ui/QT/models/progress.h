#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>
#include <QtGui>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>

class Progress : public QFrame
{
  Q_OBJECT
public:
  explicit Progress(QWidget *parent = 0);
  
  void showImageProgressbar();
  void hideImageProgressbar();

  void showNativeProgressbar();
  void hideNativeProgressbar();

  void showProgressBar(bool b1);
  void setTitle(QString t2);
  void setText1(QString t1);
  void setText1(int, QString t1);
protected:
  QHBoxLayout *main_layout;
  QVBoxLayout *information_layout;
  QLabel *text1;
  QLabel *title;
  QLabel *progressbar;
  QProgressBar *progressLabel;


signals:
  
public slots:
  
};

#endif // PROGRESS_H
