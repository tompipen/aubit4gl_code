#ifndef WEBBROWSER_H
#define WEBBROWSER_H
#include <QMainWindow>
#include <QtGui>
#include <QtWebKit>
#include <QUrl>



class WebBrowser : public QMainWindow
{
    Q_OBJECT;


public:
    //WebBrowser();
    void createBrowser();
    void loadUrl(const QUrl&);
    void closeBrowser();

protected slots:

    void adjustLocation();
    void changeLocation();
    void adjustTitle();
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

};

#endif // WEBBROWSER_H
