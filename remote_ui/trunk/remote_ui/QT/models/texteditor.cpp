#include "models/texteditor.h"
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QTextBlock>
#include <QLineEdit>
#include <QSyntaxHighlighter>
#include "include/vdc.h"
#include <QSignalMapper>
#include "models/dialog.h"

TextEditorWidget::TextEditorWidget(QMainWindow *parent)
    : QMainWindow(parent)
{
    mTextEdit = new TextEditor;
    searchToolBar = NULL;
    mIsEditFinished = 0;
    mCloseTextEdit = 0;

    TextHighlighting *syntax = new  TextHighlighting(mTextEdit->document());

    this->setCentralWidget(mTextEdit);
    this->setMinimumSize(600, 400);
    this->setWindowTitle("VENTAS - Text Editor");

    this->initToolBar();

    connect(mTextEdit, SIGNAL(textChanged()), this, SLOT(textIsChanged()));

}

void TextEditorWidget::textIsChanged()
{
    this->setWindowTitle("VENTAS - Text Editor - modified");
    mTextIsChanged = true;
}

void TextEditorWidget::initToolBar()
{
    QToolBar *tb = new QToolBar(this);

    QAction *loadAction = new QAction(tr("&Load"), tb);
    loadAction->setIcon(QIcon(":pics/editor-oeffnen.png"));
    connect(loadAction, SIGNAL(triggered()), this, SLOT(openFileFromLocal()));
    tb->addAction(loadAction);

    tb->addSeparator();

    QAction *saveAsAction = new QAction(tr("&Save as"), tb);
    saveAsAction->setIcon(QIcon(":pics/editor-speichern-unter.png"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFile()));
    tb->addAction(saveAsAction);

    QAction *saveAction = new QAction(tr("&Save"), tb);
    saveAction->setIcon(QIcon(":pics/editor-speichern.png"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    tb->addAction(saveAction);

    tb->addSeparator();

    QAction *searchAction = new QAction(tr("&Search"), tb);
    searchAction->setShortcut(Qt::CTRL + Qt::Key_F);
    searchAction->setIcon(QIcon(":pics/editor-suchen.png"));
    connect(searchAction, SIGNAL(triggered()), this, SLOT(openSearch()));
    tb->addAction(searchAction);

    this->addToolBar(tb);
    this->raise();
    this->activateWindow();
}

void TextEditorWidget::loadFileFromLocal()
{
    if(!mFileName.isEmpty())
    {

        QString fileName = QDir::tempPath() + "/" + mFileName;

        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Kann Datei nicht zum lesen oeffnen";
        }
        this->mTextEdit->setPlainText(file.readAll());

        file.close();

        VDC::arrowCursor();
        this->setWindowTitle("VENTAS - Text Editor");
        mTextIsChanged = false;
    }
}

void TextEditorWidget::saveFile()
{
    QString fileName = QDir::tempPath() + "/" + mFileName;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Kann Datei nicht zum lesen oeffnen";
    }

    QTextStream out(&file);
    out.setCodec("ISO-8859-1");

    out << mTextEdit->toPlainText();
    file.close();

    this->setWindowTitle("VENTAS - Text Editor");
    mTextIsChanged = false;
}

void TextEditorWidget::saveAsFile()
{
    QFileDialog fileDialog(this, "Choose a file to save");
    QString fileName = fileDialog.getSaveFileName();
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Kann Datei nicht zum lesen oeffnen";
    }

    QTextStream out(&file);
    out.setCodec("ISO-8859-1");

    out << mTextEdit->toPlainText();

    file.close();

}

void TextEditorWidget::setText(QString text)
{
    mTextEdit->setPlainText(text);
}

void TextEditorWidget::openFile(QString fileName){
    fileName = QDir::tempPath() + "/" + fileName;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "konnte Datei nicht zum lesen oeffnen!!!";
    }

    mTextEdit->setPlainText(file.readAll());

    file.close();
}
void TextEditorWidget::openFileFromLocal()
{

    QString fileName = QFileDialog::getOpenFileName();

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "konnte Datei nicht zum lesen oeffnen!!!";
    }

    mTextEdit->setPlainText(file.readAll());

    file.close();
}

void TextEditorWidget::closeEvent(QCloseEvent *event)
{
    if(mTextIsChanged && !mCloseTextEdit)
    {
        Dialog *dialog = new Dialog("File is modified", "Do you realy want to close the Texteditor?", "", "critical", this, Qt::WindowStaysOnTopHint);
        dialog->createButton(1, "Ok", "OK", "ok_gruen.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("OK")))
        {
            action->setShortcut(Qt::Key_F12);
        }

        dialog->createButton(2, "Abbruch", "ABBRUCH", "abbrechen_rot.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("ABBRUCH")))
        {
            action->setShortcut(Qt::Key_Escape);
        }

        connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(closeEditor()));
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        connect(dialog->getAction("ABBRUCH"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();

        event->ignore();
        return;
    }
    mIsEditFinished = 1;
}

void TextEditorWidget::closeEditor()
{
    mCloseTextEdit = 1;
    this->close();
}

TextEditorWidget::~TextEditorWidget()
{
    delete mTextEdit;
}

void TextEditorWidget::openSearch()
{

    if(!searchToolBar)
    {
        searchToolBar = new QToolBar;
        QSignalMapper *sMapper = new QSignalMapper;


        QLineEdit *searchLineEdit = new QLineEdit;
        connect(searchLineEdit, SIGNAL(textChanged(QString)), this, SLOT(searchTextChanged(QString)));
        searchToolBar->addWidget(searchLineEdit);

        searchToolBar->addSeparator();

        QAction *backAction = new QAction(tr("&Backward"), searchToolBar);
        backAction->setIcon(QIcon(":pics/editor-zurueck.png"));
        searchToolBar->addAction(backAction);
        connect(backAction, SIGNAL(triggered()), sMapper, SLOT(map()));
        sMapper->setMapping(backAction, "backward");

        QAction *forwardAction = new QAction(tr("&Forward"), searchToolBar);
        forwardAction->setIcon(QIcon(":pics/editor-vor.png"));
        searchToolBar->addAction(forwardAction);
        connect(forwardAction, SIGNAL(triggered()), sMapper, SLOT(map()));
        sMapper->setMapping(forwardAction, "forward");

        this->addToolBar(Qt::BottomToolBarArea, searchToolBar);
        searchLineEdit->setFocus();

        connect(sMapper, SIGNAL(mapped(QString)), this, SLOT(forwardBackwardSearch(QString)));


    } else {
        searchToolBar->close();
        searchToolBar = NULL;
        delete searchToolBar;
    }
}

void TextEditorWidget::forwardBackwardSearch(QString value)
{
    if(value == "forward")
    {
        mTextEdit->find(mSearchText, QTextDocument::FindWholeWords);
    }

    if(value == "backward")
    {
        mTextEdit->find(mSearchText, QTextDocument::FindBackward);
    }
}

void TextEditorWidget::searchTextChanged(QString text)
{
    mSearchText = text;

    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!mTextEdit->isReadOnly())
    {
        mTextEdit->moveCursor(QTextCursor::Start);
        QColor color = QColor("#C0D9D9");
        while(mTextEdit->find(text))
        {
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);
            extra.cursor = mTextEdit->textCursor();
            extraSelections.append(extra);
        }

        mTextEdit->setExtraSelections(extraSelections);
    }
}

TextEditor::TextEditor(QWidget *parent)
{

    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(const QRect &, int)), this, SLOT(updateLineNumberArea(const QRect &, int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    emit updateLineNumberAreaWidth(0);
    emit highlightCurrentLine();

}

void TextEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        //QColor lineColor = QColor(Qt::yellow).lighter(160);

        //selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

int TextEditor::lineNumberAreaWidth()
 {
     int digits = 1;
     int max = qMax(1, blockCount());
     while (max >= 10) {
         max /= 10;
         ++digits;
     }

     int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

     return space;
 }

void TextEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void TextEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        emit updateLineNumberAreaWidth(0);
}

void TextEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void TextEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
 {
     QPainter painter(lineNumberArea);
     painter.fillRect(event->rect(), Qt::lightGray);


     QTextBlock block = firstVisibleBlock();
     int blockNumber = block.blockNumber();
     int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
     int bottom = top + (int) blockBoundingRect(block).height();

     while (block.isValid() && top <= event->rect().bottom()) {
         if (block.isVisible() && bottom >= event->rect().top()) {
             QString number = QString::number(blockNumber + 1);
             painter.setPen(Qt::black);
             painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                              Qt::AlignRight, number);
         }

         block = block.next();
         top = bottom;
         bottom = top + (int) blockBoundingRect(block).height();
         ++blockNumber;
     }
 }

TextHighlighting::TextHighlighting(QTextDocument *document) :
    QSyntaxHighlighter(document)
{

}

void TextHighlighting::highlightBlock(const QString &text) {
    for (int i=0; i < text.length(); i++)
    {
        if(text.mid(i, 2) == "/*")
        {
            setFormat(i, text.length() - i, Qt::blue);
        }
    }
}

