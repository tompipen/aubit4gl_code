#include "models/webbrowser.h"
#include "models/dialog.h"
#include "mainframe.h"

#include <QTextEdit>

/*WebBrowser::WebBrowser()
{

}*/

void WebBrowser::createBrowser()
{
MainFrame::vdcdebug("createBrowser","~createBrowser()", "");
    mTb = NULL;
    //QUrl url = QUrl("http://www.google.de");
    _scalefactor = 1;
    QNetworkProxyFactory::setUseSystemConfiguration(true);

    WebView = new MyWebBrowser(this);
    //WebView->load(url);
    connect(WebView, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
    connect(WebView, SIGNAL(titleChanged(QString)), SLOT(adjustTitle(QString)));
    connect(WebView, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(WebView, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));

    toolBar = addToolBar(tr("Navigation"));
    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    locationEdit->resize(500, 25);
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));
    setNavigationIcons();

    //WebView->page()->settings()->fontSize(QWebSettings::DefaultFontSize)

    fontSize = WebView->page()->settings()->fontSize(QWebEngineSettings::DefaultFontSize);
    defaultFontSize = fontSize;

    setWindowTitle("VENTAS.browser");

    QMenu *effectMenu = menuBar()->addMenu(tr("&Select"));
    effectMenu->addAction(tr("Mark all links..."), this, SLOT(highlightAllLinks()));

    setCentralWidget(WebView);
    setUnifiedTitleAndToolBarOnMac(true);

    QAction *sAction = new QAction(tr("Search"), this);
    QList<QKeySequence> shortcuts;
    shortcuts << Qt::CTRL + Qt::Key_F;
    shortcuts << Qt::Key_F9;
    sAction->setShortcuts(shortcuts);
    this->addAction(sAction);
    connect(sAction, SIGNAL(triggered()), this, SLOT(openSearch()));
    //this->show();
}
void WebBrowser::loadUrl(const QUrl &http)
{
MainFrame::vdcdebug("WebBrowser","loadUrl", "");
  m_file = http.toString();

  if(QFile::exists(QDir::tempPath() + "/" + m_file))
  {
     m_file = QDir::tempPath() + "/" + m_file;
  }

  QFile fileRead(m_file);
  if(!fileRead.open(QIODevice::ReadOnly))
  {
    qDebug() << QString("WEBBROWSER: Cannot open file %").arg(m_file);
  }

  if(!m_file.contains("https://") && !m_file.contains("http://") && !m_file.contains("www."))
  {
      WebView->page()->load(m_file);
  } else {
     QUrl nurl(m_file, QUrl::TolerantMode);
     WebView->setUrl(nurl);
  }

  locationEdit->setText(m_file);
}

void WebBrowser::adjustLocation()
{
MainFrame::vdcdebug("WebBrowser","adjustLocation", "");
    locationEdit->setText(WebView->url().toString());
}

void WebBrowser::closeBrowser()
{
MainFrame::vdcdebug("WebBrowser","closeBrowser", "");
    this->close();
}

void WebBrowser::changeLocation()
{
MainFrame::vdcdebug("WebBrowser","changeLocation", "");
    QString value = locationEdit->text();
    if(!value.startsWith("http://") && !value.startsWith("https://")) {
        value.prepend("http://");
    }

    QUrl url = QUrl(value, QUrl::TolerantMode);
    WebView->setUrl(url);
}


void WebBrowser::adjustTitle(QString title)
{
MainFrame::vdcdebug("WebBrowser","adjustTitle", "");
    setWindowTitle(title);
}

void WebBrowser::setProgress(int p)
{
    Q_UNUSED(p);
}

void WebBrowser::finishLoading(bool)
{
    //WebView->page()->mainFrame()->evaluateJavaScript(jQuery);

}

void WebBrowser::printpage()
{
MainFrame::vdcdebug("WebBrowser","printpage", "");
  QPrinter printer;
  QPrintDialog dialog(&printer, this);
  QString filePath = m_file;

  printer.setPageSize(QPrinter::A4);
  printer.setPageMargins(-0.6, -0.4, -0.8, -0.8, QPrinter::Inch);

  if(filePath.contains("www") || filePath.contains("http://")) {
      Dialog *dialog = new Dialog("VENTAS", "Printing is only allowed for local files.", "", "information", this, Qt::WindowStaysOnTopHint);
      QPalette palette;
      palette.setBrush(this->backgroundRole(), QBrush(QImage(":pics/VENTAS_11_bg.png")));
      dialog->setPalette(palette);
      dialog->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");;
      dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
      dialog->getAction("OK")->setShortcut(Qt::Key_F12);
      connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
      dialog->show();
      return;
  }

  if(dialog.exec() == QDialog::Accepted)
  {
      //Qt5.6 - printing is not supportet only with version 5.8
      /*QTextEdit *textEdit = new QTextEdit;
      WebView->page()->toHtml([textEdit](const QString &result){ textEdit->setHtml(result); });*/

      if(QFile::exists(filePath))
      {
          QFile file(filePath);
          if(!file.open(QIODevice::ReadOnly)) {
              qDebug() << "cannot open file for printing";
              return;
          }

          QFont font;
          font.setFamily("Courier");
          font.setPointSize(fontSize-8);
          QTextEdit *text = new QTextEdit;
          text->setHtml(file.readAll());
          text->setFont(font);
          text->print(&printer);
      }
  }
}

void WebBrowser::highlightAllLinks()
{
MainFrame::vdcdebug("WebBrowser","highlightAllLinks", "");
    QString code = "$('a').each( function () { $(this).css('background-color', 'yellow') } )";
    //WebView->page()->mainFrame()->evaluateJavaScript(code);
}


void WebBrowser::openSearch()
{
MainFrame::vdcdebug("WebBrowser","openSearch", "");
    if(mTb)
    {
        mTb->close();
        mTb = NULL;
        delete mTb;
        return;
    } else {

        mTb = new QToolBar(this);

        QAction *close_tb = new QAction(tr("Close"), mTb);
        close_tb->setIcon(QIcon(":/pics/abbrechen_rot.png"));

        QLineEdit *search_field = new QLineEdit(this);
        search_field->setMaximumWidth(200);
        QSignalMapper *sMapper = new QSignalMapper;

        QAction *fAction = new QAction(tr("Vorwaerts"), mTb);
        fAction->setIcon(QIcon(":/pics/vor.png"));
        connect(fAction, SIGNAL(triggered()), sMapper, SLOT(map()));
        sMapper->setMapping(fAction, "forward");

        QAction *bAction = new QAction(tr("Backward"), mTb);
        bAction->setIcon(QIcon(":/pics/zurueck.png"));
        connect(bAction, SIGNAL(triggered()), sMapper, SLOT(map()));
        sMapper->setMapping(bAction, "backward");

        connect(sMapper, SIGNAL(mapped(QString)), this, SLOT(forBackSearch(QString)));


        mTb->addAction(close_tb);

        mTb->addWidget(search_field);
        mTb->addAction(bAction);
        mTb->addAction(fAction);

        connect(close_tb, SIGNAL(triggered()), mTb, SLOT(close()));
        //connect(close_tb, SIGNAL(triggered()), this, SLOT(search(QString)));

        connect(search_field, SIGNAL(textChanged(QString)), this, SLOT(searchForward(QString)));
        this->addToolBar(Qt::BottomToolBarArea, mTb);

        search_field->setFocus();
    }
}

void WebBrowser::forBackSearch(QString searchRichtung)
{
MainFrame::vdcdebug("WebBrowser","forBackSearch", "");
    if(searchRichtung == "forward")
    {
        emit searchForward(mSearchString);
    }else if(searchRichtung == "backward")
    {
        emit searchBackward(mSearchString);
    }
}

void WebBrowser::searchBackward(QString search = "")
{
MainFrame::vdcdebug("WebBrowser","searchBackward", "");
    mSearchString = search;
    this->WebView->page()->findText(search, QWebEnginePage::FindBackward);

}

void WebBrowser::searchForward(QString search = "")
{
MainFrame::vdcdebug("WebBrowser","searchForward", "");
    mSearchString = search;
    this->WebView->page()->findText(search);

}

/*void MainWindow::rotateImages(bool invert)
{
    QString code;
    if (invert)
        code = "$('img').each( function () { $(this).css('-webkit-transition', '-webkit-transform 2s'); $(this).css('-webkit-transform', 'rotate(180deg)') } )";
    else
        code = "$('img').each( function () { $(this).css('-webkit-transition', '-webkit-transform 2s'); $(this).css('-webkit-transform', 'rotate(0deg)') } )";
        view->page()->mainFrame()->evaluateJavaScript(code);
}    toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(WebView->pageAction(QWebPage::Back));
    toolBar->addAction(WebView->pageAction(QWebPage::Forward));
    toolBar->addAction(WebView->pageAction(QWebPage::Reload));
    toolBar->addAction(WebView->pageAction(QWebPage::Stop));
    toolBar->addWidget(locationEdit);

void MainWindow::removeGifImages()
{
    QString code = "$('[src*=gif]').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeInlineFrames()
{
    QString code = "$('iframe').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeObjectElements()
{
    QString code = "$('object').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeEmbeddedElements()
{
    QString code = "$('embed').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}*/




void WebBrowser::setNavigationIcons()
{
MainFrame::vdcdebug("WebBrowser","setNavigationIcons", "");

  //Getting Actions
  QAction *print = new QAction(tr("Print"), this);
  QAction *saveAs = new QAction("Save As", this);
  QAction *backward = WebView->pageAction(QWebEnginePage::Back);
  QAction *forward = WebView->pageAction(QWebEnginePage::Forward);
  QAction *reload = WebView->pageAction(QWebEnginePage::Reload);
  reload->setToolTip("Neu laden");
  QAction *stop = WebView->pageAction(QWebEnginePage::Stop);
  QAction *plus = new QAction("Zoom +", this);
  QAction *minus = new QAction("Zoom -", this);
  QAction *reset = new QAction(tr("Reset zoom"), this);



  QPixmap back((":pics/browser-zurueck.png"));
  QPixmap forw((":pics/browser-vor.png"));
  QPixmap relo((":pics/browser-neuladen.png"));
  QPixmap st((":pics/browser-abbrechen.png"));
  QPixmap dr((":pics/browser-drucken.png"));
  QPixmap mi((":pics/browser-kleiner.png"));
  QPixmap pl((":pics/browser-groesser.png"));
  QPixmap re((":pics/browser-reset.png"));
  QPixmap sa((":pics/editor-speichern-unter.png"));

  //Override

  backward->setIcon(QIcon(back));
  forward->setIcon(QIcon(forw));
  reload->setIcon(QIcon(relo));
  stop->setIcon(QIcon(st));
  print->setIcon(QIcon(dr));
  minus->setIcon(QIcon(mi));
  reset->setIcon(QIcon(re));
  plus->setIcon(QIcon(pl));
  saveAs->setIcon(QIcon(sa));

  connect(minus, SIGNAL(triggered()), this, SLOT(decreaseSize()));
  connect(plus, SIGNAL(triggered()), this, SLOT(increaseSize()));
  connect(reset, SIGNAL(triggered()), this, SLOT(resetSize()));
  connect(print, SIGNAL(triggered()), this, SLOT(printpage()));
  connect(saveAs, SIGNAL(triggered()), this, SLOT(saveAsFile()));



  toolBar->addAction(backward);
  toolBar->addAction(forward);
  toolBar->addSeparator();
  toolBar->addAction(reload);
  toolBar->addAction(stop);
  toolBar->addSeparator();
  toolBar->addAction(print);
  toolBar->addAction(saveAs);
  toolBar->addSeparator();
  toolBar->addAction(minus);
  toolBar->addAction(reset);
  toolBar->addAction(plus);

  QWidget *qw_backward = toolBar->widgetForAction(backward);
  QWidget *qw_forward  = toolBar->widgetForAction(forward);
  QWidget *qw_reload   = toolBar->widgetForAction(reload);
  QWidget *qw_stop     = toolBar->widgetForAction(stop);
/*
  qw_backward->setFixedSize(back.rect().size());
  qw_forward->setFixedSize(forw.rect().size());
  qw_reload->setFixedSize(relo.rect().size());
  qw_stop->setFixedSize(st.rect().size());
*/
  qw_backward->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  qw_forward->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  qw_reload->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  qw_stop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  QAction *sAction = new QAction(tr("Search"), this);
  sAction->setIcon(QIcon(":/pics/browser-suchen.png"));
  connect(sAction, SIGNAL(triggered()), this, SLOT(openSearch()));


  toolBar->addWidget(locationEdit);
  toolBar->addAction(sAction);

}

MyWebBrowser::MyWebBrowser(QWidget *parent)
{
    Q_UNUSED(parent);
}
void MyWebBrowser::contextMenuEvent(QContextMenuEvent *event)
{
MainFrame::vdcdebug("WebBrowser","contextMenuEvent", "");
    QMenu *menu = new QMenu();

    QAction *reload = this->pageAction(QWebEnginePage::Reload);
    reload->setToolTip("Reload");
    QAction *selectAll = this->pageAction(QWebEnginePage::SelectAll);
    selectAll->setToolTip(tr("Select All"));
    QAction *copySelected = this->pageAction(QWebEnginePage::Copy);
    selectAll->setToolTip(tr("Copy selected Text"));

    menu->addAction(reload);
    menu->addSeparator();
    menu->addAction(selectAll);
    menu->addAction(copySelected);

    menu->exec(event->globalPos());
}

void WebBrowser::saveAsFile()
{
MainFrame::vdcdebug("WebBrowser","saveAsFile", "");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "ASCII-Report.txt",
                                                    tr("Text Files(*.txt *.html)"));
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QFile file1(m_file);
    if(!file1.open(QIODevice::ReadOnly))
    {
        return;
    }

    QTextStream out(&file);
    out.setCodec("ISO-8859-15");

    if(fileName.contains(".html") || fileName.contains(".htm")) {
        out << file1.readAll();
    } else {
        QTextEdit edit;
        edit.setHtml(file1.readAll());
        out << edit.toPlainText();
    }

    file.close();

}

void WebBrowser::increaseSize()
{
MainFrame::vdcdebug("WebBrowser","increaseSize", "");
   fontSize = fontSize + 2;
   WebView->settings()->setFontSize(QWebEngineSettings::DefaultFontSize, fontSize);
}

void WebBrowser::decreaseSize()
{
MainFrame::vdcdebug("WebBrowser","decreaseSize", "");
    fontSize = fontSize - 2;
    WebView->settings()->setFontSize(QWebEngineSettings::DefaultFontSize, fontSize);
}

void WebBrowser::resetSize()
{
MainFrame::vdcdebug("WebBrowser","resetSize", "");
    fontSize = defaultFontSize;
    WebView->settings()->setFontSize(QWebEngineSettings::DefaultFontSize, fontSize);
}

/*
void WebBrowser::inittoolbar()
{
  toolBar = addToolBar(tr("Navigation"));

  QWidget *qw_base = new QWidget(toolBar);
  QHBoxLayout *hb_lay = new QHBoxLayout(qw_base);
  qw_base->setLayout(hb_lay);
  toolBar->addWidget(qw_base);


  //Getting Actions
  QAction *backward = WebView->pageAction(QWebPage::Back);
  QAction *forward = WebView->pageAction(QWebPage::Forward);
  QAction *reload = WebView->pageAction(QWebPage::Reload);
  QAction *stop = WebView->pageAction(QWebPage::Stop);


  QPixmap back((":pics/browser-zurueck.png"));
  QPixmap forw((":pics/browser-vor.png"));
  QPixmap relo((":pics/browser-neuladen.png"));
  QPixmap st((":pics/browser-abbrechen.png"));


  //Set Icons for Actions
  backward->setIcon(QIcon(back));
  forward->setIcon(QIcon(forw));
  reload->setIcon(QIcon(relo));
  stop->setIcon(QIcon(st));

  //Getting QToolBarButtons

  QWidget *qw_backward = toolBar->widgetForAction(backward);
  QWidget *qw_forward  = toolBar->widgetForAction(forward);

  qw_backward->setFixedWidth(back.rect().width());
  qw_forward->setFixedWidth(forw.rect().width());


  QPushButton *qpb_backward = new QPushButton(toolBar);
  QPushButton *qpb_forward  = new QPushButton(toolBar);
  QPushButton *qpb_reload   = new QPushButton(toolBar);
  QPushButton *qpb_stop     = new QPushButton(toolBar);

  qpb_backward->setIcon(backward->icon());
  connect(qpb_backward, SIGNAL(clicked()), backward, SLOT(trigger()));
  qpb_forward->setIcon(forward->icon());
  connect(qpb_forward, SIGNAL(clicked()), forward, SLOT(trigger()));
  qpb_reload->setIcon(reload->icon());
  connect(qpb_reload, SIGNAL(clicked()), reload, SLOT(trigger()));
  qpb_stop->setIcon(stop->icon());
  connect(qpb_stop, SIGNAL(clicked()), stop, SLOT(trigger()));

  hb_lay->addWidget(qpb_backward);
  hb_lay->addWidget(qpb_forward);
  hb_lay->addWidget(qpb_reload);
  hb_lay->addWidget(qpb_stop);
  hb_lay->addWidget(locationEdit);
}*/
