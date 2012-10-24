#include "progress.h"

Progress::Progress(QWidget *parent) :
  QFrame(parent)
{

  main_layout = new QHBoxLayout(this);

  this->setLayout(main_layout);

  QLabel *icon = new QLabel(this);

  QPixmap pm("pics:vdc.png");

  QPixmap scaled_pixmap = pm.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  icon->setPixmap(scaled_pixmap);


  main_layout->addWidget(icon);


  this->text1 = new QLabel(this);





  this->title = new QLabel(this);
  QFont font = this->title->font();

  font.setWeight(QFont::Bold);
  this->title->setFont(font);
  this->progressbar = new QLabel(this);
  this->progressbar->hide();

  QMovie *movie = new QMovie(this->progressbar);
  movie->setFileName("pics:progressbar.gif");
  this->progressbar->setMovie(movie);
  movie->start();
  QVBoxLayout *information_layout = new QVBoxLayout(this);
  information_layout->addWidget(this->title);
  information_layout->addWidget(this->text1);

  information_layout->addWidget(this->progressbar);


  main_layout->addLayout(information_layout);


  showProgressBar(true);
 // this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
  //this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

  this->setFrameStyle(QFrame::Panel | QFrame::Raised);
  this->setLineWidth(3);
  this->setMidLineWidth(3);
}

void Progress::setText1(QString t1)
{
  this->text1->setText(t1);
}


void Progress::setTitle(QString t2)
{
  this->title->setText(t2);
}

void Progress::showProgressBar(bool b1)
{
  this->progressbar->setVisible(b1);
}
