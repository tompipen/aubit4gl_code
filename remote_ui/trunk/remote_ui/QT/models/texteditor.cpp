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
#include <QSignalMapper>
#include <QDateTime>

#include "mainframe.h"
#include "include/vdc.h"
#include "models/dialog.h"
#include "tools/umlauts.h"

TextEditorWidget::TextEditorWidget(QMainWindow *parent)
    : QMainWindow(parent)
{
    mTextEdit = new TextEditor;
    mTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    mTextEdit->setFont(QFont("Courier"));
    searchToolBar = NULL;
    mIsEditFinished = 0;
    mCloseTextEdit = 0;

    TextHighlighting *syntax = new  TextHighlighting(mTextEdit->document());
    Q_UNUSED(syntax);

    this->setCentralWidget(mTextEdit);
    this->resize(600, 400);
    this->setWindowTitle("VENTAS - Text Editor");

    this->initToolBar();
    connect(mTextEdit, SIGNAL(textChanged()), this, SLOT(textIsChanged()));

}

void TextEditorWidget::textIsChanged()
{
    this->setWindowTitle(tr("VENTAS - Text Editor - modified"));
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
    //searchAction->setShortcut(Qt::CTRL + Qt::Key_F);
    QList<QKeySequence> shortcuts;
    shortcuts << Qt::CTRL + Qt::Key_F;
    shortcuts << Qt::Key_F9;
    searchAction->setShortcuts(shortcuts);
    searchAction->setIcon(QIcon(":pics/editor-suchen.png"));
    connect(searchAction, SIGNAL(triggered()), this, SLOT(openSearch()));
    tb->addAction(searchAction);

    tb->addSeparator();

    QAction *insertDateAction = new QAction(tr("&Insert Date"), tb);
    insertDateAction->setIcon(QIcon(":pics/editor-anwender-datum.png"));
    insertDateAction->setShortcut(Qt::Key_F7);
    connect(insertDateAction, SIGNAL(triggered()), this, SLOT(insertDate()));
    tb->addAction(insertDateAction);

    tb->addSeparator();

    QAction *okAction = new QAction(tr("&Ok"), tb);
    okAction->setShortcut(Qt::Key_F12);
    okAction->setIcon(QIcon(":pics/editor-ok.png"));
    connect(okAction, SIGNAL(triggered()), this, SLOT(closeOnAccept()));
    tb->addAction(okAction);

    QAction *cancAction = new QAction(tr("&Quit"), tb);
    cancAction->setShortcut(Qt::Key_Escape);
    cancAction->setIcon(QIcon(":pics/editor-beenden-ohne-speichern.png"));
    connect(cancAction, SIGNAL(triggered()), this, SLOT(close()));
    tb->addAction(cancAction);

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

        int enableFilter = VDC::readSettingsFromIni("","convertText").toInt();

        QString filterText;
        QTextStream in(&file);
#ifndef Q_OS_WIN
        out.setCodec("ISO-8859-15");
#endif

        if(enableFilter != 2) {
            filterText = Tools::filterUmlauts(in.readAll());
        } else {
            filterText = in.readAll();
        }

        this->mTextEdit->setPlainText(filterText);

        file.close();

        this->setCursor(Qt::ArrowCursor);
        this->setWindowTitle("VENTAS - Text Editor");
        mTextIsChanged = false;
    }
}

void TextEditorWidget::saveFile()
{
    QString fileName = QDir::tempPath() + "/" + mFileName;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Kann Datei nicht zum lesen oeffnen";
    }

    QTextStream out(&file);
    out.setCodec("ISO-8859-15");

    QString filterText;

    int enableFilter = VDC::readSettingsFromIni("","convertText").toInt();

    if(enableFilter != 2) {
        filterText = Tools::filterUmlauts(mTextEdit->toPlainText());
    } else {
        filterText = mTextEdit->toPlainText();
    }

    out << filterText;
    file.close();

    this->setWindowTitle("VENTAS - Text Editor");
    mTextIsChanged = false;
}

void TextEditorWidget::saveAsFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "ASCII-Report.txt",
                                                    tr("Text Files(*.txt *.html)"));
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Kann Datei nicht zum lesen oeffnen";
    }

    QTextStream out(&file);
    out.setCodec("ISO-8859-15");

    if(fileName.contains(".html") || fileName.contains(".htm")) {
        out << mTextEdit->document()->toHtml();
    } else {
        out << mTextEdit->toPlainText();
    }

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

    QTextStream in(&file);
    in.setCodec("ISO-8859-15");

    mTextEdit->setPlainText(in.readAll());

    file.close();
}

void TextEditorWidget::setWrapMode(int digits)
{
    mTextEdit->setWordWrapMode(QTextOption::WordWrap);
    mTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    QFontMetrics fm = mTextEdit->fontMetrics();
    int w = digits*fm.averageCharWidth()+15;
    this->resize(w,600);
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
void TextEditorWidget::closeOnAccept()
{
    emit saveFile();
    this->close();
}

void TextEditorWidget::closeEvent(QCloseEvent *event)
{
    if(mTextIsChanged && !mCloseTextEdit)
    {
        Dialog *dialog = new Dialog(tr("File is modified"), tr("Do you want to apply the changes before the Editor will be closed?"), "", "stop", this, Qt::WindowStaysOnTopHint);
        dialog->createButton(1, tr("Apply"), "APPLY", "ok_gruen.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("OK")))
        {
            action->setShortcut(Qt::Key_F12);
        }

        dialog->createButton(2, tr("Discard"), "DISCARD", "");

        dialog->createButton(2, tr("Cancel"), "CANCEL", "abbrechen_rot.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("DISCARD")))
        {
            action->setShortcut(Qt::Key_Escape);
        }

        connect(dialog->getAction("APPLY"), SIGNAL(triggered()), this, SLOT(closeOnAccept()));
        connect(dialog->getAction("APPLY"), SIGNAL(triggered()), dialog, SLOT(close()));
        connect(dialog->getAction("DISCARD"), SIGNAL(triggered()), this, SLOT(closeEditor()));
        connect(dialog->getAction("DISCARD"), SIGNAL(triggered()), dialog, SLOT(close()));
        connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), dialog, SLOT(close()));

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

        QAction *cancAction = new QAction(tr("&Quit"), searchToolBar);
        cancAction->setIcon(QIcon(":pics/editor-beenden-ohne-speichern.png"));
        connect(cancAction, SIGNAL(triggered()), searchToolBar, SLOT(close()));
        searchToolBar->addAction(cancAction);

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

void TextEditorWidget::insertDate()
{
    QString user;
    int cursorPos = mTextEdit->textCursor().position();
    int destPos = cursorPos + 19 + user.length();

    QDateTime date = QDateTime::currentDateTime();

    QString text = mTextEdit->toPlainText();

    if(MainFrame *main = qobject_cast<MainFrame*> (MainFrame::lastmainframe))
    {
        user = main->getUserName();
    }

    text.insert(cursorPos, date.toString("dd.MM.yyyy hh:mm") + " " + user + ": ");

    mTextEdit->setPlainText(text);

    QTextCursor cursor = mTextEdit->textCursor();
    cursor.setPosition(destPos + user.length());
    mTextEdit->setTextCursor(cursor);
}

TextEditor::TextEditor(QWidget *parent)
{
    Q_UNUSED(parent);

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

