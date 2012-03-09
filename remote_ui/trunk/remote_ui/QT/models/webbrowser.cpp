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

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    locationEdit->resize(500, 25);
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

    QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(WebView->pageAction(QWebPage::Back));
    toolBar->addAction(WebView->pageAction(QWebPage::Forward));
    toolBar->addAction(WebView->pageAction(QWebPage::Reload));
    toolBar->addAction(WebView->pageAction(QWebPage::Stop));
    toolBar->addWidget(locationEdit);

    QMenu *effectMenu = menuBar()->addMenu(tr("&Auswahl"));
    effectMenu->addAction("Alle Links hervorheben...", this, SLOT(highlightAllLinks()));

    setCentralWidget(WebView);
    setUnifiedTitleAndToolBarOnMac(true);
    this->show();
}
void WebBrowser::loadUrl(const QUrl &http)
{
    WebView->setUrl(http);
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
}

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

