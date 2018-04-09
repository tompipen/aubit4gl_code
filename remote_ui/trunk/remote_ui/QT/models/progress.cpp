#include "progress.h"

Progress::Progress(QWidget *parent) :
  QFrame(parent)
{


    main_layout = new QHBoxLayout(this);
    this->text1 = new QLabel(this);
    this->title = new QLabel(this);
    progressLabel = new QProgressBar(this);

    QLabel *icon = new QLabel(this);
    QPixmap pm(":pics/vdc.png");
    QPixmap scaled_pixmap = pm.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    icon->setPixmap(scaled_pixmap);
    main_layout->addWidget(icon);

    QFont font = this->title->font();
    font.setWeight(QFont::Bold);

    this->title->setFont(font);
    this->progressbar = new QLabel(this);
    this->progressbar->hide();

    QMovie *movie = new QMovie(this->progressbar);
    movie->setFileName(":pics/progressbar.gif");
    this->progressbar->setMovie(movie);
    movie->start();

    information_layout = new QVBoxLayout(this);
    information_layout->addWidget(this->title);
    information_layout->addWidget(this->text1);
    main_layout->addLayout(information_layout);

  this->setLayout(main_layout);
  showProgressBar(true);

  this->setFrameStyle(QFrame::Panel | QFrame::Raised);
  this->setLineWidth(3);
  this->setMidLineWidth(3);
}

void Progress::showImageProgressbar()
{
    hideNativeProgressbar();
    information_layout->addWidget(progressbar);
}

void Progress::hideImageProgressbar()
{
    progressbar->hide();
    progressLabel->show();
    this->adjustSize();
}

void Progress::showNativeProgressbar()
{
    progressLabel->setStyleSheet(" QProgressBar {  border: 2px solid #b9b9b9; border-radius: 5px; text-align: center } QProgressBar::chunk { background-color: #fcb10e; } ");
    progressLabel->setFixedWidth(250);
    progressLabel->setMaximumHeight(20);

    hideImageProgressbar();
    information_layout->addWidget(progressLabel);
}

void Progress::hideNativeProgressbar()
{
    progressbar->show();
    progressLabel->hide();
    this->adjustSize();
}

void Progress::setText1(QString t1)
{
  this->text1->setText(t1);
  this->adjustSize();
}

void Progress::setText1(int value, QString t1)
{
    this->progressLabel->setValue(value);
    this->text1->setText(t1);
    this->adjustSize();
}

void Progress::setTitle(QString t2)
{
  this->setWindowTitle(t2);
   //this->title->setText(t2);
}

void Progress::showProgressBar(bool b1)
{
  this->progressbar->setVisible(b1);
}
