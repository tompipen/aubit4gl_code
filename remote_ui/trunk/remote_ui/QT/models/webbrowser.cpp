#include "models/webbrowser.h"


/*WebBrowser::WebBrowser()
{

}*/

void WebBrowser::createBrowser()
{
    QFile file;
    file.setFileName(":/jquery.min.js");
    file.open(QIODevice::ReadOnly);
    jQuery = file.readAll();
    file.close();
    //QUrl url = QUrl("http://www.google.de");
    _scalefactor = 1;
    QNetworkProxyFactory::setUseSystemConfiguration(true);

    WebView = new QWebView(this);
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


    setWindowTitle("VENTAS.browser");

    QMenu *effectMenu = menuBar()->addMenu(tr("&Auswahl"));
    effectMenu->addAction("Alle Links hervorheben...", this, SLOT(highlightAllLinks()));

    setCentralWidget(WebView);
    setUnifiedTitleAndToolBarOnMac(true);

    QAction *sAction = new QAction(tr("Search"), this);
    sAction->setShortcut(Qt::CTRL + Qt::Key_F);
    this->addAction(sAction);
    connect(sAction, SIGNAL(triggered()), this, SLOT(openSearch()));
    this->show();
}
void WebBrowser::loadUrl(const QUrl &http)
{
  QString file = http.toString();


  if(QFile::exists(QDir::tempPath() + "/" + file))
  {
      #ifdef Q_WS_WIN
         file = QDir::tempPath() + "/" + file;
      #else
         file = "file://" +  QDir::tempPath() + "/" + file;
      #endif
  }
  QUrl nurl(file, QUrl::TolerantMode);

    WebView->setUrl(nurl);
}

void WebBrowser::adjustLocation()
{
    locationEdit->setText(WebView->url().toString());
}

void WebBrowser::closeBrowser()
{
    this->close();
}

void WebBrowser::changeLocation()
{
    QUrl url = QUrl(locationEdit->text());
    WebView->load(url);
    WebView->setFocus();
}


void WebBrowser::adjustTitle(QString title)
{
    setWindowTitle(title);
}

void WebBrowser::setProgress(int p)
{
    Q_UNUSED(p);
}

void WebBrowser::finishLoading(bool)
{
    WebView->page()->mainFrame()->evaluateJavaScript(jQuery);

}

void WebBrowser::printpage()
{
  QPrinter printer(QPrinter::HighResolution);

  QPrintDialog dialog(&printer, this);

  if(dialog.exec() == QDialog::Accepted)
  {
     WebView->print(&printer);
  }
}

void WebBrowser::highlightAllLinks()
{
    QString code = "$('a').each( function () { $(this).css('background-color', 'yellow') } )";
    WebView->page()->mainFrame()->evaluateJavaScript(code);
}


void WebBrowser::openSearch()
{
    if(mTb)
    {
        mTb->close();
        mTb = NULL;
        return;
    }
    mTb = new QToolBar(this);

    QAction *close_tb = new QAction("X", mTb);

    QLineEdit *search_field = new QLineEdit(this);
    search_field->setMaximumWidth(200);
    QSignalMapper *sMapper = new QSignalMapper;

    QAction *fAction = new QAction(tr("Forward"), mTb);
    fAction->setIcon(QIcon(":/pics/vor.png"));
    connect(fAction, SIGNAL(triggered()), sMapper, SLOT(map()));
    sMapper->setMapping(fAction, "forward");

    QAction *bAction = new QAction(tr("backward"), mTb);
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

void WebBrowser::forBackSearch(QString searchRichtung)
{
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
    mSearchString = search;
    this->WebView->page()->findText(search, QWebPage::FindWrapsAroundDocument | QWebPage::FindBackward);

}

void WebBrowser::searchForward(QString search = "")
{
    mSearchString = search;
    this->WebView->page()->findText(search, QWebPage::FindWrapsAroundDocument);

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
  //Getting Actions
  QAction *print = new QAction("Drucken", this);
  QAction *backward = WebView->pageAction(QWebPage::Back);
  QAction *forward = WebView->pageAction(QWebPage::Forward);
  QAction *reload = WebView->pageAction(QWebPage::Reload);
  QAction *stop = WebView->pageAction(QWebPage::Stop);
  QAction *plus = new QAction("Zoom +", this);
  QAction *minus = new QAction("Zoom -", this);
  QAction *reset = new QAction("Zoom reset", this);



  QPixmap back(("pics:browser-zurueck.png"));
  QPixmap forw(("pics:browser-vor.png"));
  QPixmap relo(("pics:browser-neuladen.png"));
  QPixmap st(("pics:browser-abbrechen.png"));
  QPixmap dr(("pics:browser-drucken.png"));
  QPixmap mi(("pics:browser-kleiner.png"));
  QPixmap pl(("pics:browser-groesser.png"));
  QPixmap re(("pics:browser-reset.png"));

  //Override

  backward->setIcon(QIcon(back));
  forward->setIcon(QIcon(forw));
  reload->setIcon(QIcon(relo));
  stop->setIcon(QIcon(st));
  print->setIcon(QIcon(dr));
  minus->setIcon(QIcon(mi));
  reset->setIcon(QIcon(re));
  plus->setIcon(QIcon(pl));

  connect(minus, SIGNAL(triggered()), this, SLOT(decreaseSize()));
  connect(plus, SIGNAL(triggered()), this, SLOT(increaseSize()));
  connect(reset, SIGNAL(triggered()), this, SLOT(resetSize()));
  connect(print, SIGNAL(triggered()), this, SLOT(printpage()));



  toolBar->addAction(backward);
  toolBar->addAction(forward);
  toolBar->addAction(reload);
  toolBar->addAction(stop);
  toolBar->addAction(print);
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

  QAction *sAction = new QAction(tr("Suchen"), this);
  sAction->setIcon(QIcon(":/pics/browser-suchen.png"));
  connect(sAction, SIGNAL(triggered()), this, SLOT(openSearch()));


  toolBar->addWidget(locationEdit);
  toolBar->addAction(sAction);

}

void WebBrowser::increaseSize()
{
  WebView->setZoomFactor(WebView->zoomFactor() + 0.1);
}

void WebBrowser::decreaseSize()
{

  WebView->setZoomFactor(WebView->zoomFactor() - 0.1);
}

void WebBrowser::resetSize()
{
  WebView->setZoomFactor(1);
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


  QPixmap back(("pics:browser-zurueck.png"));
  QPixmap forw(("pics:browser-vor.png"));
  QPixmap relo(("pics:browser-neuladen.png"));
  QPixmap st(("pics:browser-abbrechen.png"));


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
