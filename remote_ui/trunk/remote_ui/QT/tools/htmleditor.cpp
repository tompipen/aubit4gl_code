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
    mFontSizeCombo = new QComboBox();
    mUeberschriftCombo = new QComboBox();

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

    QAction *okAction = new QAction(tr("&Ok"), toolbar);
    okAction->setShortcut(Qt::Key_F12);
    okAction->setIcon(QIcon(":pics/editor-ok.png"));

    QAction *cancAction = new QAction(tr("&Quit"), toolbar);
    cancAction->setShortcut(Qt::Key_Escape);
    cancAction->setIcon(QIcon(":pics/editor-beenden-ohne-speichern.png"));


    connect(screenshot, SIGNAL(clicked()), this, SLOT(appendScreenshot()));
    connect(preview, SIGNAL(clicked()), this, SLOT(showPreview()));
    connect(mFontSizeCombo, SIGNAL(activated(QString)), this, SLOT(textSize(QString)));
    connect(textColorButton, SIGNAL(clicked()), this, SLOT(textColor()));
    connect(italicBold, SIGNAL(clicked()), this, SLOT(italicClicked()));
    connect(fontBold, SIGNAL(clicked()), this, SLOT(boldClicked()));
    connect(mEdit, SIGNAL(textChanged()), this, SLOT(textIsChanged()));
    connect(mUeberschriftCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setTitle(int)));

    connect(okAction, SIGNAL(triggered()), this, SLOT(closeEditor()));
    connect(cancAction, SIGNAL(triggered()), this, SLOT(close()));



    QFontDatabase db;
    foreach(int size, db.standardSizes())
    {
        mFontSizeCombo->addItem(QString::number(size));
    }
    mFontSizeCombo->setCurrentIndex(mFontSizeCombo->findText(QString::number(QApplication::font().pointSize())));

    for(int i=1; i < 5; i++)
    {
        QString value = "Ueberschrift " + QString::number(i);
        mUeberschriftCombo->addItem(value);
    }

    toolbar->addWidget(fontBold);
    toolbar->addWidget(italicBold);
    toolbar->addSeparator();
    toolbar->addWidget(mFontSizeCombo);
    toolbar->addSeparator();
    toolbar->addWidget(textColorButton);
    toolbar->addSeparator();
    toolbar->addWidget(mUeberschriftCombo);
    toolbar->addSeparator();
    toolbar->addWidget(screenshot);
    toolbar->addSeparator();
    toolbar->addWidget(preview);
    toolbar->addSeparator();
    toolbar->addAction(okAction);
    toolbar->addSeparator();
    toolbar->addAction(cancAction);

    vLayout->addWidget(mEdit);
    vLayout->addWidget(preview,0,Qt::AlignRight);

    setWindowTitle("VDC HTML Editor");
    addToolBar(toolbar);
    setCentralWidget(mEdit);
    resize(800,600);

    mEdit->setStyleSheet("* { color:#000000; text-decoration:none; font-family:'Verdana'; font-weight:350; font-size:15; margin-left:10px; }");
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

    stream << mEdit->toHtml();;
    file.close();
    WebBrowser *p_browser = new WebBrowser;
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

    QString htmlString = ventasFilter(in.readAll());

    mEdit->setHtml(htmlString);
   this->setWindowTitle("VDC HTML Editor");
    mTextIsModified = 0;

}

QString HtmlEditor::ventasFilter(QString htmlString)
{
    if(htmlString.contains("<h1>"))
    {
        htmlString.replace("<h1>", "<font font-size=24px color=#224488 font-family=Verdana margin-top=30><h1>");
        htmlString.replace("</h1>","</h1></font>");
    }
    if(htmlString.contains("<h2>"))
    {
        htmlString.replace("<h2>", "<font font-size=20px color=#224488 font-family=Verdana margin-top=20><h2>");
        htmlString.replace("</h2>","</h2></font>");
    }

    if(htmlString.contains("<h3>"))
    {
        htmlString.replace("<h3>", "<font font-size=18px color=#445599 font-style=italic margin-bottom=5px><h3>");
        htmlString.replace("</h3>","</h3></font>");
    }

    if(htmlString.contains("<h4>"))
    {
        htmlString.replace("<h4>", "<font font-size=18px color=#ee0000 font-style=italic font-weight=800 margin=10><h4>");
        htmlString.replace("</h4>","</h4></font>");
    }

    if(htmlString.contains("<span class=\"rot\">"))
    {
        htmlString.replace("class=\"rot\"", "style=\"color:#FF0000;\"");
    }

    if(htmlString.contains("<span class=\"blau\">"))
    {
        htmlString.replace("class=\"blau\"", "style=\"color:#0000FF;\"");
    }

    if(htmlString.contains("<span class=\"gelb\">"))
    {
        htmlString.replace("class=\"gelb\"", "style=\"color:#eecc00;\"");
    }

    if(htmlString.contains("<span class=\"gruen\">"))
    {
        htmlString.replace("class=\"gruen\"", "style=\"color:#00aa00;\"");
    }

    if(htmlString.contains("<span class=\"butt\">"))
    {
        htmlString.replace("class=\"butt\"", "style=\"color:#008989;font-weight:800;\"");
    }

    if(htmlString.contains("<span class=\"schwarz\">"))
    {
        htmlString.replace("class=\"schwarz\"", "style=\"color:#000000;\"");
    }

    if(htmlString.contains("<span class=\"logolink\">"))
    {
        htmlString.replace("class=\"logolink\"", "style=\"text-decoration:underline; color:#006699;\"");
    }

    if(htmlString.contains("<div id=\"text\">"))
    {
        htmlString.replace("id=\"text\"", "style=\"margin-left:30px; color:#000000; text-decoration:none; font-family:'Verdana'; font-weight:400;\"");
    }

    if(htmlString.contains("<div id=\"achtung\">"))
    {
        htmlString.replace("id=\"achtung\"", "style=\"color:#FF0000; font-size:18px; font-weight:800; font-style:italic;\"");
    }

   if(htmlString.contains("<div id=\"hinweis\">"))
   {
       htmlString.replace("id=\"hinweis\"", "style=\"color:#335599; font-size:18px; font-weight:500; font-style:italic;\"");
   }

   if(htmlString.contains("<div id=\"logo\">"))
   {
       htmlString.replace("id=\"logo\"", "style=\"border-top:1px solid #FFdd00;\"");
   }

   if(htmlString.contains("<li>"))
   {
       htmlString.replace("<li>", "<ul><li>");
   }

   if(htmlString.contains("</li>"))
   {
       htmlString.replace("</li>", "</ul></li>");
   }

   return htmlString;

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

    emit closeEditorWithoutSave();
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

    QString htmlString = mEdit->toHtml();
    htmlString.remove("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n");
    htmlString.remove("<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n");
    htmlString.remove("</style></head><body style=\" font-family:'Verdana'; font-size:11pt; font-weight:400; font-style:normal;\">\n");
    htmlString.remove("p, li { white-space: pre-wrap; }");
    htmlString.remove("</body></html>");

    htmlString.prepend("<iframe src=\"kopf.html\" width=\"100%\" min-height=\"200px\" />");
    htmlString.append("\n<iframe src=\"fuss.html\" width=\"100%\" min-height=\"200px\" />");

    outStream << htmlString;
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

void HtmlEditor::setTitle(int size)
{
    QTextCursor cursor = mEdit->textCursor();
    QString s=cursor.selectedText();
    cursor.insertHtml("<h" + QString::number(size) + ">" + s + "</h" + QString::number(size) + ">");
}

HtmlEditor::~HtmlEditor()
{
    delete mEdit;
    delete mFontSizeCombo;
    delete textColorButton;
}


