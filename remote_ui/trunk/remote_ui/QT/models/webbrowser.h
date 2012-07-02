#ifndef WEBBROWSER_H
#define WEBBROWSER_H
#include <QMainWindow>
#include <QtGui>
#include <QtWebKit>
#include <QUrl>



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
    void adjustLocation();
    void changeLocation();
    void adjustTitle(QString title);
    void setProgress(int p);
    void finishLoading(bool);

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



};

#endif // WEBBROWSER_H
