#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <qglobal.h>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QtGui/QMainWindow>
#else
#include <QtWidgets/QMainWindow>
#endif
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>

class TextEditorWidget : public QMainWindow
{
    Q_OBJECT

public:
    TextEditorWidget(QObject *parentObj, QMainWindow *parent = 0);
    ~TextEditorWidget();
    void initToolBar();
    void loadFileFromLocal();

    int getIsEditorFinished() {return mIsEditFinished; };

    void setFileName(QString fileName) { mFileName = fileName; };

    void closeEvent(QCloseEvent *);

    void setText(QString);
    void openFile(QString);

    void setWrapMode(int);

    void setIsoEncoding(bool encoding ) { mSetIsoEncoding = encoding; }
    void saveWindowSettings();

public slots:
        void readWindowSettings();
        void textIsChanged();
        void saveAsFile();
        void saveFile();
        void openFileFromLocal();
        void openSearch();
        void searchTextChanged(QString);
        void forwardBackwardSearch(QString);
        void closeEditor();
        void closeOnAccept();
        void insertDate();

private:

    QPlainTextEdit *mTextEdit;
    bool mTextIsChanged;
    QToolBar *searchToolBar;
    int mIsEditFinished;
    QString mFileName;
    QString mSearchText;
    int mCloseTextEdit;

    bool mSetIsoEncoding;

    QObject *m_parentObj;

};


class TextEditor : public QPlainTextEdit
{
    Q_OBJECT;

public:
    TextEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *lineNumberArea;
};

class LineNumberArea : public QWidget
 {
 public:
     LineNumberArea(TextEditor *editor) : QWidget(editor) {
         mTextEditor = editor;
     }

     QSize sizeHint() const {
         return QSize(mTextEditor->lineNumberAreaWidth(), 0);
     }

 protected:
     void paintEvent(QPaintEvent *event) {
         mTextEditor->lineNumberAreaPaintEvent(event);
     }

 private:
     TextEditor *mTextEditor;
 };

class TextHighlighting : public QSyntaxHighlighter
{
public:
    explicit TextHighlighting(QTextDocument *document);
protected:
    void highlightBlock(const QString &text);

private:
    QTextEdit *mTextEdit;
};

#endif // TEXTEDITOR_H
