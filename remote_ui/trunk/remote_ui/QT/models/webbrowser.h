#ifndef WEBBROWSER_H
#define WEBBROWSER_H
#include <QMainWindow>
#include <QtGui>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QtWebKit>
#else
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebFrame>
#endif
#include <QUrl>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QNetworkProxyFactory>
#include <QPrintDialog>
#include <QPrinter>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>

class MyWebBrowser : public QWebView
{
    Q_OBJECT;
public:
    MyWebBrowser(QWidget *parent=0);
    void contextMenuEvent(QContextMenuEvent *);
};



class WebBrowser : public QMainWindow
{
    Q_OBJECT


public:
    //WebBrowser();
    void createBrowser();
    void loadUrl(const QUrl&);
    void closeBrowser();

    void setNavigationIcons();

protected slots:
    void printpage();
    void searchForward(QString search);
    void searchBackward(QString search);
    void adjustLocation();
    void changeLocation();
    void adjustTitle(QString title);
    void setProgress(int p);
    void finishLoading(bool);
    void saveAsFile();
    void increaseSize();
    void decreaseSize();
    void resetSize();
    void openSearch();
    void forBackSearch(QString);

    //void slotSourceDownloaded();

    void highlightAllLinks();
    /*void rotateImages(bool invert);
    void removeGifImages();
    void removeInlineFrames();
    void removeObjectElements();
    void removeEmbeddedElements();*/

private:
    QString jQuery;
    QWebView* WebView;
    QLineEdit *locationEdit;
    QAction *rotateAction;

    QToolBar *toolBar;

    qreal _scalefactor;
    QString mSearchString;
    QToolBar *mTb;



};

#endif // WEBBROWSER_H
