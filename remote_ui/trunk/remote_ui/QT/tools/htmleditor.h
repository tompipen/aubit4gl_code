#ifndef HTMLEDITOR_H
#define HTMLEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>

class HtmlEditor : public QMainWindow
{
    Q_OBJECT

public:
    HtmlEditor(QWidget *parent = 0);
    void closeEvent(QCloseEvent *);
    int getEditorStatus() { return editorIsFinished; }
    void setFileName(QString fileName) { mFileName = fileName; };
    void loadIntoEditor();
    QString ventasFilter(QString);

    ~HtmlEditor();

public slots:
    void underlineClicked();
    void boldClicked();
    void italicClicked();
    void textSize(QString);
    void textColor();
    void appendScreenshot();
    void textIsChanged();
    void showPreview();
    void closeEditor();
    void closeEditorWithoutSave();
    void setTitle(int);

private:
    QTextEdit *mEdit;
    QComboBox *mFontSizeCombo;
    QComboBox *mUeberschriftCombo;
    QPushButton *textColorButton;
    int mTextIsModified;
    int imageCounter;
    int editorIsFinished;
    int mCloseEditor;
    QString mFileName;
};

#endif // HTMLEDITOR_H
