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

void WebBrowser::highlightAllLinks()
{
    QString code = "$('a').each( function () { $(this).css('background-color', 'yellow') } )";
    WebView->page()->mainFrame()->evaluateJavaScript(code);
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
  QAction *backward = WebView->pageAction(QWebPage::Back);
  QAction *forward = WebView->pageAction(QWebPage::Forward);
  QAction *reload = WebView->pageAction(QWebPage::Reload);
  QAction *stop = WebView->pageAction(QWebPage::Stop);


  QPixmap back(("pics:browser-zurueck.png"));
  QPixmap forw(("pics:browser-vor.png"));
  QPixmap relo(("pics:browser-neuladen.png"));
  QPixmap st(("pics:browser-abbrechen.png"));


  //Override

  backward->setIcon(QIcon(back));
  forward->setIcon(QIcon(forw));
  reload->setIcon(QIcon(relo));
  stop->setIcon(QIcon(st));






  toolBar->addAction(backward);
  toolBar->addAction(forward);
  toolBar->addAction(reload);
  toolBar->addAction(stop);

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


  toolBar->addWidget(locationEdit);

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
