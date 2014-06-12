#include "htmleditor.h"
#include "models/dialog.h"

#include <QDebug>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QFontDatabase>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QApplication>
#else
#include <QtWidgets/QApplication>
#endif
#include <QLabel>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextImageFormat>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QCloseEvent>
#include <QAction>
#include "models/webbrowser.h"

HtmlEditor::HtmlEditor(QWidget *parent)
    : QMainWindow(parent)
{
    mEdit = new QTextEdit();
    mEdit->setFont (QFont("Verdana", 11));
    mFontSizeCombo = new QComboBox();

    mTextIsModified  = 0;
    imageCounter     = 1;
    editorIsFinished = 0;
    mCloseEditor     = 0;

    QToolBar *toolbar = new QToolBar();
    QVBoxLayout *vLayout = new QVBoxLayout();

    QPushButton *fontBold = new QPushButton(tr("B"));
    fontBold->setMaximumWidth(35);
    fontBold->setStyleSheet(" QPushButton { font-weight: bold; font-size: 16px;} ");


    QPushButton *italicBold = new QPushButton(tr("K"));
    italicBold->setMaximumWidth(35);
    italicBold->setStyleSheet(" QPushButton { font-style: italic; font-size: 16px;} ");

    textColorButton = new QPushButton();
    textColorButton->setStyleSheet(" QPushButton { background-color: black;}" );

    QPushButton *screenshot = new QPushButton("Picture");
    QPushButton *preview = new QPushButton("Preview");

    connect(screenshot, SIGNAL(clicked()), this, SLOT(appendScreenshot()));
    connect(preview, SIGNAL(clicked()), this, SLOT(showPreview()));
    connect(mFontSizeCombo, SIGNAL(activated(QString)), this, SLOT(textSize(QString)));
    connect(textColorButton, SIGNAL(clicked()), this, SLOT(textColor()));
    connect(italicBold, SIGNAL(clicked()), this, SLOT(italicClicked()));
    connect(fontBold, SIGNAL(clicked()), this, SLOT(boldClicked()));
    connect(mEdit, SIGNAL(textChanged()), this, SLOT(textIsChanged()));


    QFontDatabase db;
    foreach(int size, db.standardSizes())
    {
        mFontSizeCombo->addItem(QString::number(size));
    }
    mFontSizeCombo->setCurrentIndex(mFontSizeCombo->findText(QString::number(QApplication::font().pointSize())));

    toolbar->addWidget(fontBold);
    toolbar->addWidget(italicBold);
    toolbar->addSeparator();
    toolbar->addWidget(mFontSizeCombo);
    toolbar->addSeparator();
    toolbar->addWidget(textColorButton);
    toolbar->addSeparator();
    toolbar->addWidget(screenshot);
    toolbar->addSeparator();
    toolbar->addWidget(preview);

    vLayout->addWidget(mEdit);
    vLayout->addWidget(preview,0,Qt::AlignRight);

    setWindowTitle("VDC HTML Editor");
    addToolBar(toolbar);
    setCentralWidget(mEdit);
    resize(800,600);
}

void HtmlEditor::showPreview()
{
    QString fileName = QDir::tempPath() + "/" + "preview" + mFileName;
    QFile file(fileName);

    QTextStream stream(&file);
    stream.setCodec("ISO-8859-1");

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "failed to save preview";
    }

    stream << mEdit->toHtml();
    file.close();
    WebBrowser *p_browser = new WebBrowser();
    p_browser->createBrowser();
    p_browser->loadUrl(QUrl(fileName));
    p_browser->show();
}

void HtmlEditor::textIsChanged()
{
    this->setWindowTitle("VDC HTML Editor - Modified");
    mTextIsModified = 1;
}

void HtmlEditor::textColor()
{
    QColor col = QColorDialog::getColor(mEdit->textColor(), this);
    if (!col.isValid())
    {
        return;
    }

    QTextCharFormat fmt;
    fmt.setForeground(col);
    mEdit->mergeCurrentCharFormat(fmt);
    textColorButton->setStyleSheet(" QPushButton { background-color:" + col.name() + ";}" );

}

void HtmlEditor::appendScreenshot()
{
    QString fileName = QFileDialog::getOpenFileName(NULL, "Open File",
                                                    "",
                                                    "Images (*.png *.gif *.jpg *.tif)");

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        QFileInfo htmlFile(mFileName);

        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "cannot open file for read";
        }

        file.copy(QDir::tempPath() + "/" + htmlFile.baseName() + "-" + QString::number(imageCounter) + ".png");

        QTextImageFormat format;
        format.setName(htmlFile.baseName() + "-" + QString::number(imageCounter) + ".png");
        mEdit->textCursor().insertImage(format);
        file.close();
        imageCounter++;

    }

}

void HtmlEditor::textSize(QString size)
{
    qreal pointSize = size.toFloat();
    if (size.toFloat() > 0) {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        mEdit->mergeCurrentCharFormat(fmt);
    }
}

void HtmlEditor::boldClicked()
{
    QTextCharFormat fmt;
    QTextCursor cursor = mEdit->textCursor();
    if (!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }

    if( cursor.charFormat().fontWeight() == QFont::Bold  )
    {
        fmt.setFontWeight( QFont::Normal);
    }
    else
    {
       fmt.setFontWeight( QFont::Bold);
    }

    cursor.mergeCharFormat( fmt );
    mEdit->mergeCurrentCharFormat(fmt);
}

void HtmlEditor::italicClicked()
{
    QTextCharFormat fmt;
    QTextCursor cursor = mEdit->textCursor();
    bool enable = cursor.charFormat().fontItalic();

    if (!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }

    if(!enable)
    {
        fmt.setFontItalic(true);
    } else {
        fmt.setFontItalic(false);
    }

    cursor.mergeCharFormat( fmt );
    mEdit->mergeCurrentCharFormat(fmt);
}

void HtmlEditor::loadIntoEditor()
{
    QFile file(QDir::tempPath() + "/" + mFileName);
    QTextStream in(&file);
    in.setCodec("ISO-8859-1");

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "cannot open file for read";
    }

    mEdit->insertHtml(in.readAll());

}

void HtmlEditor::closeEvent(QCloseEvent *event)
{
    if(mTextIsModified && !mCloseEditor)
    {
        Dialog *dialog = new Dialog(tr("File is modified"), tr("Do you want to save changes?"), "", "critical", this, Qt::WindowStaysOnTopHint);
        dialog->createButton(1, "Ok", "OK", "ok_gruen.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("OK")))
        {
            action->setShortcut(Qt::Key_F12);
        }

        dialog->createButton(2, tr("Cancel"), "CANCEL", "abbrechen_rot.png");

        if(QAction *action = qobject_cast<QAction*> (dialog->getAction("CANCEL")))
        {
            action->setShortcut(Qt::Key_Escape);
        }

        connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(closeEditor()));
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), this, SLOT(closeEditorWithoutSave()));
        connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();

        event->ignore();
        return;
    }
}
void HtmlEditor::closeEditor()
{
    QFile file(QDir::tempPath() + "/" + mFileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "cannot open html file for save.";
        editorIsFinished = 1;
        return;
    }

    QTextStream outStream(&file);
    outStream.setCodec("ISO-8859-1");
    outStream << mEdit->toHtml();
    file.close();

    mCloseEditor = 1;
    mTextIsModified = 0;
    editorIsFinished = 1;
    this->close();
}

void HtmlEditor::closeEditorWithoutSave()
{
    mCloseEditor = 1;
    mTextIsModified = 0;
    editorIsFinished = 1;
    this->close();
}

HtmlEditor::~HtmlEditor()
{
    delete mEdit;
    delete mFontSizeCombo;
    delete textColorButton;
}


