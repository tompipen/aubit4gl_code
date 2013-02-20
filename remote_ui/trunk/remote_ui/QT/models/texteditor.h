#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QtGui/QMainWindow>
#include <QPlainTextEdit>

class TextEditorWidget : public QMainWindow
{
    Q_OBJECT

public:
    TextEditorWidget(QMainWindow *parent = 0);
    ~TextEditorWidget();
    void initToolBar();
    void loadFileFromLocal();

    int getIsEditorFinished() {return mIsEditFinished; };

    void setFileName(QString fileName) { mFileName = fileName; };

    void closeEvent(QCloseEvent *);

    void setText(QString);
    void openFile(QString);
public slots:
        void textIsChanged();
        void saveAsFile();
        void saveFile();
        void openFileFromLocal();
        void openSearch();

private:

    QPlainTextEdit *mTextEdit;
    bool mTextIsChanged;
    QToolBar *searchToolBar;
    int mIsEditFinished;
    QString mFileName;

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

#endif // TEXTEDITOR_H
