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


    void openSearch();

protected slots:
    void printpage();
    void search(QString search);
    void adjustLocation();
    void changeLocation();
    void adjustTitle(QString title);
    void setProgress(int p);
    void finishLoading(bool);
    void increaseSize();
    void decreaseSize();
    void resetSize();

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



};

#endif // WEBBROWSER_H
