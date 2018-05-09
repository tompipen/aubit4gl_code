//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : login.cpp
// Description  : contains login class logic
//------------------------------------------------------------------------------
//
// This file may be used under the terms of the GNU General Public
// License version 2.0 as published by the Free Software Foundation
// (http://www.gnu.org/licenses/gpl-2.0.html)
//
// This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// If you need professional Support please3 contact us at www.ventas.de
// Enjoy using it!
//
//------------------------------------------------------------------------------
#include <QtGui>
#include <QFile>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QHeaderView>
#include <QAction>
#include <QLineEdit>
#include <QTcpSocket>
#include "masterupdate.h"
#include <qtelnet/qttelnet.h>
#if QT_VERSION >= 0x040600
#include <QProcessEnvironment>
#endif
#include "revision.h"
#include "login.h"
#include "mainframe.h"
#include "include/vdc.h"
#ifdef SSH_USE
#include "vssh.h"
#endif

//------------------------------------------------------------------------------
// Method       : LoginForm()
// Filename     : login.cpp
// Description  : constructor for the instances
//                LoginForm represents the shortcuts configure window
//------------------------------------------------------------------------------

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
{

    waitToSendMessage = false;

    MainFrame *mainFrame = (MainFrame*) parent;
    QMenuBar *menuBar = mainFrame->menuBar();

    errorMessageLoginForm = new QErrorMessage(this);

    QTabWidget *tWidget = new QTabWidget(this);
    QWidget *userWidget = new QWidget();
    QWidget *adminWidget = new QWidget();

    QVBoxLayout *loginLayout = new QVBoxLayout;
    QVBoxLayout *tabWidgetLayout = new QVBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *adminLayout = new QVBoxLayout;
    QVBoxLayout *labelLayout = new QVBoxLayout;
    QHBoxLayout *connectionLayout = new QHBoxLayout;
    QHBoxLayout *methodLayout = new QHBoxLayout;
    QHBoxLayout *debugLayout = new QHBoxLayout;
    QVBoxLayout *applicationLayout = new QVBoxLayout;
    QVBoxLayout *serverLayout = new QVBoxLayout;


    createMenu(menuBar);

    portLabel           = new QLabel(tr("Port: (Default 22)"));
    portLineEdit        = new QLineEdit();

    applicationLabel    = new QLabel(tr("Application:"));
    applicationLineEdit = new QLineEdit;
    applicationLineEdit->setText("vdc");

    serverLabel         = new QLabel(tr("Server:"));
    serverLineEdit      = new QLineEdit;

    QGroupBox *bg_other = new QGroupBox("");
    logVDC              = new QCheckBox("Debug", bg_other);
    connect(logVDC, SIGNAL(clicked()), mainFrame, SLOT(enableDebugModus()));
    cb                  = new QCheckBox("Save &Password?", bg_other);

    int port = VDC::readSettingsFromLocalIni("", "sshport").toInt();
    if(port <= 0) {
        port = 22;
    }

    portLineEdit->setText(QString::number(port));

    if(VDC::readSettingsFromLocalIni("", "debugVDC").toInt() == 1)
    {
        logVDC->setChecked(true);
    }

    bg_connection = new QGroupBox("Connection Method:");
    rb_proxy  = new QRadioButton("Proxy", bg_connection);
    rb_proxy->setChecked(true);
    rb_telnet = new QRadioButton("Telnet", bg_connection);
    #ifdef SSH_USE
    rb_ssh    = new QRadioButton("SSH", bg_connection);
    #endif

    methodLayout->addWidget(rb_proxy);
    methodLayout->addWidget(rb_telnet);
#ifdef SSH_USE
	methodLayout->addWidget(rb_ssh);
#endif
    bg_connection->setLayout(methodLayout);

    debugLayout->addWidget(cb);
    debugLayout->addWidget(logVDC);
    bg_other->setLayout(debugLayout);

    connectionLayout->addWidget(bg_connection);

    labelLayout->addWidget(portLabel);
    labelLayout->addWidget(portLineEdit);

    applicationLayout->addWidget(applicationLabel);
    applicationLayout->addWidget(applicationLineEdit);

    serverLayout->addWidget(serverLabel);
    serverLayout->addWidget(serverLineEdit);

    adminLayout->addLayout(connectionLayout);
    adminLayout->addLayout(serverLayout);
    adminLayout->addLayout(labelLayout);
    adminLayout->addLayout(applicationLayout);
    adminLayout->addWidget(bg_other);
    adminLayout->insertSpacing(0,13); //NS

    adminWidget->setLayout(adminLayout);

    //User TabWidget

    usernameLabel       = new QLabel(tr("User:"));
    usernameLineEdit    = new QLineEdit;
    setFocusProxy(usernameLineEdit);
    usernameLineEdit->setMaximumWidth(125);


    passwordLabel       = new QLabel(tr("Password:"));
    passwordLineEdit    = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMaximumWidth(125);

    //User TabWidget

    loadSettings();

    loginLayout->addWidget(usernameLabel);
    loginLayout->addWidget(usernameLineEdit);
    loginLayout->addWidget(passwordLabel);
    loginLayout->addWidget(passwordLineEdit);
    loginLayout->addStretch(1);
    loginLayout->addLayout(buttonLayout);
    loginLayout->insertSpacing(0, 13); //NS

    QList<QKeySequence> ql_shortcuts;
    ql_shortcuts << QKeySequence("Return");
    ql_shortcuts << QKeySequence("Enter");
    ql_shortcuts << QKeySequence("F12");

    QAction *okAction = new QAction(tr("Connect"), this);
    okAction->setShortcuts(ql_shortcuts);
    connect(okAction, SIGNAL(triggered()), this, SLOT(okPressed()));

    QAction *cancelAction = new QAction(tr("Cancel"), this);
    cancelAction->setShortcut(Qt::Key_F12);
    connect(cancelAction, SIGNAL(triggered()), mainFrame, SLOT(closeAction()));

    usernameLineEdit->addAction(okAction);
    passwordLineEdit->addAction(okAction);
    serverLineEdit->addAction(okAction);
    applicationLineEdit->addAction(okAction);


    // instantiating the buttons
    //
    QPushButton *okButton     = new QPushButton(tr("OK"));
    connect(okButton, SIGNAL(pressed()), this, SLOT(okPressed()));
    okButton->setIcon(QIcon(QString(":pics/ok_gruen.png")));
    okButton->setIconSize(QSize(53,37));
    okButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
    okButton->addAction(okAction);

    QPushButton *cancelButton = new QPushButton(tr("&Cancel"));
    connect(cancelButton, SIGNAL(pressed()), mainFrame, SLOT(closeAction()));
    cancelButton->setIcon(QIcon(QString(":pics/escape.png")));
    cancelButton->setIconSize(QSize(53,37));
    cancelButton->setShortcut(Qt::Key_Escape);
    cancelButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
    cancelButton->addAction(cancelAction);

    buttonLayout->addWidget(okButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(loginLayout);

    userWidget->setLayout(mainLayout);

    tWidget->addTab(userWidget, tr("&User"));
    tWidget->addTab(adminWidget, tr("&Admin"));

    tabWidgetLayout->addWidget(tWidget);


    //QtWidget->setStyleSheet("background-image: url(:pics/VENTAS_11_bg.png); ");

    this->setLayout(tabWidgetLayout);

    this->setStyleSheet("QTabWidget::pane { border: 0px; top: 4px;  }" "QTabWidget::tab-bar { left: 9px; top:14px; }"
                                     "QTabBar::tab { color: #005a9f; min-width: 44px; padding: 5.5px 6px 5.5px 6px; border: 1px solid #005a9f; border-bottom: 1px solid #005a9f; background-color: white; }"
                                     "QTabBar:tab:first { border-top-left-radius: 4.2px; border-bottom-left-radius: 4.2px; }"
                                     "QTabBar:tab:last { border-top-right-radius: 4.2px; border-bottom-right-radius: 4.2px; }"
                                     "QTabBar::tab:selected { color: white; background-color: #005a9f; }"
                                     "QTabBar::tab:hover:!selected { background-color: #f7f7f7; }");
}

void LoginForm::createMenu(QMenuBar *menu)
{
    QMenu *options = new QMenu(tr("&Options"), this);

    QAction *checkVersion = new QAction(tr("&Search for Update"), this);
    checkVersion->setStatusTip(tr("Checks for new VDC updates"));
    connect(checkVersion, SIGNAL(triggered()), this, SLOT(checkForUpdate()));
    options->addAction(checkVersion);
    options->addSeparator();

    QAction *ooStdProg = new QAction(tr("&Change Default Office Software"), this);
    connect(ooStdProg, SIGNAL(triggered()), this, SLOT(setOfficeInstallation()));
    options->addAction(ooStdProg);

    settingsServer = new QAction(tr("&Form Settings on Server"), this);
    connect(settingsServer, SIGNAL(triggered()), this, SLOT(saveSettingsOnServer()));
    settingsServer->setCheckable(true);
    if(VDC::readSettingsFromLocalIni("", "saveSettingsOnServer").toInt() <= 0)
    {
        settingsServer->setChecked(true);
    }

    options->addAction(settingsServer);
    options->addSeparator();

    QAction *sshCompAction = new QAction(tr("SSH Compression"), this);
    connect(sshCompAction, SIGNAL(triggered()), this, SLOT(openCompOptions()));
    #ifdef SSH_USE
        options->addAction(sshCompAction);
    #endif
    options->addSeparator();

    QAction *font = new QAction(tr("&Font"), this);
    font->setStatusTip(tr("Opens the font settings"));
    connect(font, SIGNAL(triggered()), this, SLOT(font()));
    options->addAction(font);
    options->addSeparator();

    options->addSeparator();

    QString screenFormat = VDC::readSettingsFromLocalIni("","screenFormat");
    QString seperator = VDC::readSettingsFromLocalIni("","setDBMONEY");

    if(screenFormat == "-1") {
        screenFormat = "##,###,###,###,##&.&&&&&&&&&&&&&&&&";
        seperator = ",";

        VDC::saveSettingsToLocalIni("","screenFormat", screenFormat);
        VDC::saveSettingsToLocalIni("","setDBMONEY", seperator);

    }

    QMenu *format = new QMenu(tr("&Format in Screen Forms"), this);
    format->setStatusTip(tr("Set the Format"));

    QSignalMapper* formatSignalMapper = new QSignalMapper (this);

    format1 = new QAction("&1.234,56", this);
    format1->setCheckable(true);
    connect(format1, SIGNAL(triggered()), formatSignalMapper, SLOT(map()));
    formatSignalMapper->setMapping(format1, "##,###,###,###,##&.&&&&&&&&&&&&&&&&|,");

    format->addAction(format1);

    format2 = new QAction("&1,234.56", this);
    format2->setCheckable(true);
    connect(format2, SIGNAL(triggered()), formatSignalMapper, SLOT(map()));
    formatSignalMapper->setMapping(format2, "##,###,###,###,##&.&&&&&&&&&&&&&&&&|.");

    format->addAction(format2);

    format3 = new QAction("&1234,56", this);
    format3->setCheckable(true);
    connect(format3, SIGNAL(triggered()), formatSignalMapper, SLOT(map()));
    formatSignalMapper->setMapping(format3, "-|,");

    format->addAction(format3);

    format4 = new QAction("&1234.56", this);
    format4->setCheckable(true);
    connect(format4, SIGNAL(triggered()), formatSignalMapper, SLOT(map()));
    formatSignalMapper->setMapping(format4, "--|.");

    format->addAction(format4);

    if(screenFormat == "##,###,###,###,##&.&&&&&&&&&&&&&&&&" && seperator == ",")
    {
        format1->setChecked(true);
        format2->setChecked(false);
        format3->setChecked(false);
        format4->setChecked(false);
    }

    if(screenFormat == "##,###,###,###,##&.&&&&&&&&&&&&&&&&" && seperator == ".")
    {
        format1->setChecked(false);
        format2->setChecked(true);
        format3->setChecked(false);
        format4->setChecked(false);
    }

    if(screenFormat == "-")
    {
        format1->setChecked(false);
        format2->setChecked(false);
        format3->setChecked(true);
        format4->setChecked(false);
    }

    if(screenFormat == "--")
    {
        format1->setChecked(false);
        format2->setChecked(false);
        format3->setChecked(false);
        format4->setChecked(true);
    }

    connect(formatSignalMapper, SIGNAL(mapped(QString)), this, SLOT(setFormat(QString)));

    options->addMenu(format);
    options->addSeparator();

    QSignalMapper* signalMapper = new QSignalMapper (this);

    QAction *feldplus = new QAction(tr("Fieldwidth + "), this);
    connect(feldplus, SIGNAL(triggered()), signalMapper, SLOT(map()));
    feldplus->setStatusTip(tr("Increase the form field width in the screen forms"));
    signalMapper->setMapping(feldplus,  "0.1");
    options->addAction(feldplus);

    QAction *feldminus = new QAction(tr("Fieldwidth - "), this);
    connect(feldminus, SIGNAL(triggered()), signalMapper, SLOT(map()));
    feldminus->setStatusTip(tr("Decrease the form field width in the screen forms"));
    signalMapper->setMapping(feldminus, "-0.1");
    options->addAction(feldminus);

    QAction *feldreset = new QAction(tr("Default Fieldwidth"), this);
    connect(feldreset, SIGNAL(triggered()), this, SLOT(resetFactor()));
    feldreset->setStatusTip(tr("Restore the default fieldwidth settings for the screen forms"));
    options->addAction(feldreset);
    options->addSeparator();

    QAction *removeIni = new QAction(tr("Reset Screen Forms"), this);
    connect(removeIni, SIGNAL(triggered()), this, SLOT(removeIni()));
    removeIni->setStatusTip(tr("Reset the settings.ini from the VDC"));
    options->addAction(removeIni);
    options->addSeparator();

    autoUpdateAction = new QAction(tr("Install Updates Automatically"), this);
    autoUpdateAction->setCheckable(true);

    if(VDC::readSettingsFromLocalIni("", "updateWithoutAsk").toInt() == 2) {
        autoUpdateAction->setChecked(false);
    } else {
        autoUpdateAction->setChecked(true);
    }
    connect(autoUpdateAction, SIGNAL(triggered()), this, SLOT(setAutoUpdate()));
    options->addAction(autoUpdateAction);
    options->addSeparator();

    rememberMenuAction = new QAction(tr("Remember Main Menu"), this);
    rememberMenuAction->setCheckable(true);

    if(VDC::readSettingsFromLocalIni("","rememberMainMenu").toInt() != 2) {
        rememberMenuAction->setChecked(true);
    } else {
        rememberMenuAction->setChecked(false);
    }
    connect(rememberMenuAction, SIGNAL(triggered()), this, SLOT(setRememberMenu()));
    options->addAction(rememberMenuAction);


    QString menuType = VDC::readSettingsFromLocalIni("", "startMenuPosition");

    if(menuType == "tree" || menuType.isEmpty() || menuType == "-1")
    {
        m_mainMenu = new QAction(tr("Main Menu: Pulldown"), this);
        connect(m_mainMenu, SIGNAL(triggered()), this, SLOT(setMainMenu()));
        options->addAction(m_mainMenu);
    } else if(menuType == "menu") {
        m_mainMenu = new QAction(tr("Main Menu: Explorer"), this);
        connect(m_mainMenu, SIGNAL(triggered()), this, SLOT(setMainMenu()));
        options->addAction(m_mainMenu);
    }


    toggledebug = new QAction(tr("&Toggle Debug"), this);
    connect(toggledebug, SIGNAL(toggled(bool)), this, SLOT(debugToggle(bool)));
    toggledebug->setCheckable(true);

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(setFactorWidth(QString)));

    options->addSeparator();
    convertText = new QAction(tr("Convert UTF-8 to ISO-8859-1"), this);
    connect(convertText, SIGNAL(triggered()), this, SLOT(convertTextToIso()));
    convertText->setCheckable(true);

    if(VDC::readSettingsFromLocalIni("","convertText").toInt() != 2) {
        convertText->setChecked(true);
    }

    options->addAction(convertText);

    menu->addMenu(options);

    QMenu *help = new QMenu("&Help");

    QAction *documentation = new QAction(tr("&Documentation"), this);
    connect(documentation, SIGNAL(triggered()), this, SLOT(showDocumentation()));

    help->addAction(documentation);
    help->addSeparator();
    help->addAction(toggledebug);
    help->addSeparator();

    QAction *sendMsg = new QAction(tr("Send message to VENTAS"), this);
    connect(sendMsg, SIGNAL(triggered()), this, SLOT(sendMessageWidget()));
    help->addAction(sendMsg);


//derzeit nur fuer Windows
    QAction *quicksupport = new QAction(tr("&QuickSupport"), this);
    connect(quicksupport, SIGNAL(triggered()), this, SLOT(openQuickSupport()));

    help->addAction(quicksupport);

    QAction *vdc2 = new QAction(tr("&Start VDC2"), this);
    connect(vdc2, SIGNAL(triggered()), this, SLOT(openVdc2()));

    help->addAction(vdc2);

    help->addSeparator();
    QAction *about = new QAction(tr("&About VDC"), this);
    connect(about, SIGNAL(triggered()), this, SLOT(aboutVDC()));
    help->addAction(about);

    menu->addMenu(help);

}

void LoginForm::openVdc2()
{
    QString program = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/VDC_backup.exe");

    qDebug() << "starting program: " << program;
    QProcess process;
    QStringList args;
    args << "-squish";
    process.startDetached(QString(program), args);

    QTimer::singleShot(5000, QApplication::instance(), SLOT(quit()));
}

void LoginForm::openQuickSupport()
{
#ifdef Q_OS_WIN
    QString program;
    const QString vdcInstallDir = VDC::readSettingsFromLocalIni("","vdcInstallDir");
    QDir dir(vdcInstallDir);
    dir.cdUp();
    dir.cd("Fernwartung");

    program = QDir::toNativeSeparators(dir.absolutePath() + "/VENTAS_QS.exe");

    qDebug() << "starting program: " << program;
    QProcess process;
    process.startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( program));
#endif

#ifdef Q_OS_MAC
    QString program;
    const QString vdcInstallDir = VDC::readSettingsFromLocalIni("","vdcInstallDir");

    program = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/TeamViewerQS.app");

    qDebug() << "starting program: " << program;
    QProcess process;
    process.startDetached(QString("open \"%1\"").arg( program));
#endif
}

void LoginForm::showDocumentation()
{

#ifdef Q_OS_WIN
    QSettings settings("general");
#else
    QSettings settings(QDir::homePath() + "/.general/general.ini", QSettings::IniFormat);
#endif
    int vdcIsActivated = settings.value("vdcIsActivated").toInt();

    if(!vdcIsActivated)
    {
        Dialog *dialog = new Dialog("VENTAS", "Please register first to use this function.", "", "stop", this, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        return;
    }

    WebBrowser *browser = new WebBrowser();
    browser->createBrowser();
    browser->loadUrl(QUrl("http://www.ventas.de/vdc-documentation/"));
    browser->show();

}

void LoginForm::sendMessageToVentas()
{

    if(waitToSendMessage)
    {
        Dialog *dialog = new Dialog("VENTAS", "Please wait 5 minutes until you send a message again", "", "stop", ventasMessage, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkRequest req;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readMessageReply(QNetworkReply*)));

#ifdef Q_OS_WIN
    QSettings settings("general");
#else
    QSettings settings(QDir::homePath() + "/.general/general.ini", QSettings::IniFormat);
#endif
    QString email = settings.value("email").toString();

    qDebug() << "ventasMessage->toPlainText()" << ventasMessage->toPlainText();
    QByteArray postData;
    postData.append("msg=" + ventasMessage->toPlainText().trimmed());
    postData.append("&email=" + email);
    req.setUrl(QUrl("http://www.ventas.de/register-vdc/sendmessage.php?"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    qDebug() << "postData: " << postData;

    manager->post(req, postData);

}

void LoginForm::removeMessageWaitTimer()
{
    waitToSendMessage = false;
}

void LoginForm::readMessageReply(QNetworkReply *reply)
{
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(removeMessageWaitTimer()));
    timer->start(300000);

    if(reply->error())
    {
        Dialog *dialog = new Dialog("VENTAS", "Unable to send message. Error Code:  " + reply->errorString(), "", "stop", ventasMessage, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        return;
    }

    QString errorCode = reply->readAll();

    qDebug() << "errorCode: " << errorCode;

    if(errorCode == "true")
    {
        Dialog *dialog = new Dialog("VENTAS", "Message has been send to VENTAS.", "", "information", ventasMessage, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        waitToSendMessage = true;
        return;
    } else {
        Dialog *dialog = new Dialog("VENTAS", "Unable to send message. Error Code:  " + reply->errorString(), "", "stop", ventasMessage, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        return;
    }

}

void LoginForm::sendMessageWidget()
{

#ifdef Q_OS_WIN
    QSettings settings("general");
#else
    QSettings settings(QDir::homePath() + "/.general/general.ini", QSettings::IniFormat);
#endif
    int vdcIsActivated = settings.value("vdcIsActivated").toInt();

    if(!vdcIsActivated)
    {
        Dialog *dialog = new Dialog("VENTAS", "Please register first to use this function.", "", "stop", this, Qt::WindowStaysOnTopHint, true);
        QPalette palette;
        palette.setBrush(dialog->backgroundRole(), Qt::white);
        dialog->setPalette(palette);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->show();
        return;
    }
    QWidget *widget = new QWidget();
    QVBoxLayout *vLayout = new QVBoxLayout();

    QPushButton *sendButton = new QPushButton(tr("&Send"));

    QLabel *msgLabel = new QLabel(tr("Maximum: 500 Characters."));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessageToVentas()));
    connect(sendButton, SIGNAL(clicked()), widget, SLOT(close()));
    ventasMessage = new QTextEdit();
    ventasMessage->setMinimumWidth(400);
    connect(ventasMessage, SIGNAL(textChanged()), SLOT(ventasMessageChanged()));

    vLayout->addWidget(ventasMessage);
    vLayout->addWidget(msgLabel);
    vLayout->addWidget(sendButton, 0, Qt::AlignRight);
    widget->setLayout(vLayout);

    widget->show();
    widget->adjustSize();
}

void LoginForm::ventasMessageChanged()
{
    if(ventasMessage->toPlainText().length() > 500)
    {
        ventasMessage->textCursor().deletePreviousChar();
    }
}

void LoginForm::compression()
{
    if(compCb->isChecked())
    {
        VDC::saveSettingsToLocalIni("", "compression", QString::number(2));
    } else {
        VDC::saveSettingsToLocalIni("", "compression", QString::number(1));
    }
}

void LoginForm::openCompOptions()
{
    QWidget *widget = new QWidget();
    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QHBoxLayout *hLayout1 = new QHBoxLayout(widget);
    QSlider *compLevel = new QSlider(Qt::Horizontal, widget);
    QPushButton *okButton = new QPushButton(tr("OK"), widget);
    okButton->setIcon(QIcon(QString(":pics/ok_gruen.png")));
    okButton->setIconSize(QSize(53,37));

    compCb = new QCheckBox(tr("Enable Compression"));

    if(VDC::readSettingsFromLocalIni("", "compression").toInt() == 0 || VDC::readSettingsFromLocalIni("", "compression").toInt() == 2)
    {
        compCb->setChecked(true);
    }

    QPalette palette;
    palette.setBrush(this->backgroundRole(), Qt::white);
    widget->setPalette(palette);
    widget->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

    QLabel *infoLabel = new QLabel(tr("Lowest "));
    QLabel *infoLabel1 = new QLabel(tr("Highest "));

    QLabel *label0 = new QLabel("0");
    label0->setMaximumWidth(25);

    QLabel *label1 = new QLabel("1");
    label1->setMaximumWidth(25);

    QLabel *label2 = new QLabel("2");
    label2->setMaximumWidth(25);

    QLabel *label3 = new QLabel("3");
    label3->setMaximumWidth(25);

    QLabel *label4 = new QLabel("4");
    label4->setMaximumWidth(25);

    hLayout1->addWidget(infoLabel, 0, Qt::AlignLeft);
    hLayout1->addWidget(infoLabel1, 0, Qt::AlignRight);

    hLayout->addWidget(label0);
    hLayout->addWidget(label1);
    hLayout->addWidget(label2);
    hLayout->addWidget(label3);
    hLayout->addWidget(label4);

    connect(compLevel, SIGNAL(valueChanged(int)), this, SLOT(saveCompression(int)));
    connect(okButton, SIGNAL(pressed()), this, SLOT(compression()));
    connect(okButton, SIGNAL(pressed()), widget, SLOT(close()));
    okButton->setMaximumWidth(100);
    okButton->setShortcut(Qt::Key_F12);
    compLevel->setRange(0, 4);
    compLevel->setMaximumWidth(150);

    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(compLevel);
    vLayout->addWidget(compCb);
    vLayout->addWidget(okButton, 0, Qt::AlignHCenter);

    int sliderValue = VDC::readSettingsFromLocalIni("VENTAS AG", "sshSliderValue").toInt();
    if(sliderValue <= 0)
    {
        compLevel->setValue(1);
    } else {
        compLevel->setValue(sliderValue-1);
    }

    widget->show();

}
void LoginForm::saveCompression(int value)
{
    int factor = 2.25*value;
    VDC::setSSHCompressionsLevel(factor);
    VDC::saveSettingsToLocalIni("VENTAS AG", "sshSliderValue", QString::number(value+1));
}

void LoginForm::removeIni()
{
    Dialog *dialog = new Dialog(tr(" "), tr("Do you really want to reset all screen forms?"), "", "critical", this, Qt::WindowStaysOnTopHint, true);
    QPalette palette;
    palette.setBrush(dialog->backgroundRole(), Qt::white);
    dialog->setPalette(palette);

    dialog->createButton(1, "Yes", "YES", "ok_gruen.png");
    dialog->getAction("YES")->setShortcut(Qt::Key_F12);
    connect(dialog->getAction("YES"), SIGNAL(triggered()), this, SLOT(clearIniFile()));
    connect(dialog->getAction("YES"), SIGNAL(triggered()), dialog, SLOT(close()));

    dialog->createButton(2, "No", "NO", "abbrechen_rot.png");
    dialog->getAction("NO")->setShortcut(Qt::Key_Escape);
    connect(dialog->getAction("NO"), SIGNAL(triggered()), dialog, SLOT(close()));
    dialog->show();

}

void LoginForm::saveSettingsOnServer()
{
    if(!settingsServer->isChecked())
    {
        VDC::saveSettingsToLocalIni("", "saveSettingsOnServer", QString::number(1));
    } else {
        VDC::removeSettingsFromLocalIni("","saveSettingsOnServer");
    }
}

void LoginForm::setAutoUpdate()
{
    if(autoUpdateAction->isChecked()) {
        VDC::saveSettingsToLocalIni("", "updateWithoutAsk", QString::number(1));
    } else {
        VDC::saveSettingsToLocalIni("", "updateWithoutAsk", QString::number(2));
    }
}

void LoginForm::setRememberMenu()
{
    if(rememberMenuAction->isChecked()) {
        VDC::removeSettingsFromLocalIni("", "rememberMainMenu");
    } else {
        VDC::saveSettingsToLocalIni("", "rememberMainMenu", QString::number(2));
    }

}
void LoginForm::clearIniFile()
{
    #ifdef Q_OS_WIN
        #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
           QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #else
           QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
    #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
    #endif

    settings.remove("");
}

void LoginForm::aboutVDC(QWidget *parent)
{

    QFile file;
    QString clientOs;
    QList<QString> textList;
    QList<QList<QString> > returnList;

    file.setFileName(QApplication::applicationDirPath() + "/versions.xml");

    if(file.open(QIODevice::ReadOnly))
    {
        #ifdef Q_OS_WIN
            clientOs = "WINDOWS";
        #endif
        #ifdef Q_OS_MAC
            clientOs = "MAC";
        #endif
        #ifdef Q_OS_LINUX
            clientOs = "LINUX";
        #endif

        QDomDocument doc;
        doc.setContent(&file);

        QDomElement root = doc.documentElement();
        QDomNode node = root.firstChildElement();
        while(!node.isNull() && node.isElement())
        {
            QDomElement secElement = node.toElement();
            if(!secElement.isNull())
            {
                if(secElement.nodeName() == clientOs)
                {
                    QDomNode child = secElement.firstChild();
                    while(!child.isNull())
                    {
                        QDomElement text = child.toElement();
                        textList << text.text();
                        child = child.nextSibling();
                    }
                    returnList.insert(returnList.count(), textList);
                    textList.clear();
                }

            }
            node = node.nextSiblingElement();
        }

        file.close();
    }

    QWidget *widget = new QWidget(parent);
    QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->insertSpacing(0,55); //NS
    QLabel *labeltext = new QLabel();
    QLabel *labellogo = new QLabel();
    QLabel *space = new QLabel(widget);
    QPixmap pix(":pics/VENTAS_11_logo-about.png");

    QList<QKeySequence> ql_shortcuts;
    ql_shortcuts << QKeySequence("F12");
    ql_shortcuts << QKeySequence("Enter");
    ql_shortcuts << QKeySequence("Return");
    ql_shortcuts << QKeySequence("Escape");

    QPushButton *okButton = new QPushButton("&OK");
    okButton->setIcon(QIcon(QString(":pics/ok_gruen.png")));
    okButton->setIconSize(QSize(53,37));
    okButton->setFixedWidth(96);
    QAction *action = new QAction(tr("&OK"), this);
    action->setShortcuts(ql_shortcuts);
    okButton->addAction(action);
    connect(action, SIGNAL(triggered()), widget, SLOT(close()));
    connect(okButton, SIGNAL(clicked()), widget, SLOT(close()));


    //int date = QDate::currentDate().year();
    //QPixmap qpm = pix.scaled(80,80,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labellogo->setPixmap(pix);
    labellogo->setAlignment(Qt::AlignTop);
    space->setFixedWidth(25);
    QString a4glVersionClient = VDC::readSettingsFromIni("", "a4gl_version", "unknown");
    QString xmlVersionClient = VDC::readSettingsFromIni("", "xml_version", "unknown");

    QString releaseDate;
    if(!returnList.isEmpty()) {
        if(!returnList.at(0).isEmpty()) {
            releaseDate =returnList.at(0).at(0);
        } else {
            releaseDate = "unknown";
        }
    } else {
        releaseDate = "unknown";
    }

    labeltext->setText(QString("<p style=\"font-weight: bold;\">VDC - VENTAS Desktop Client for A4GL</p> \
    Client Revisions number: %1<br> \
    Release Date: %2<br> \
    A4GL Version: %3<br> \
    XML Protocol Version: %4<br> \
    Qt Version: %5<br><br> \
    Copyright by VENTAS AG Hamburg. All Rights Reserved.<br><br> \
    The program is provided as is with no warranty of any kind,<br>  \
    including the warranty of design,<br> \
    merchantability and fitness for a particular purpose. <br> \
    You can get professional support (info@ventas.de)").arg(GIT_REVISION_NUMBER).arg(releaseDate).arg(a4glVersionClient).arg(xmlVersionClient).arg(QT_VERSION_STR));

    layout->addWidget(labellogo);
    layout->addWidget(space);
    layout->addWidget(labeltext);
    mainlayout->addLayout(layout);
    mainlayout->addWidget(okButton, 0, Qt::AlignCenter);
    widget->setLayout(mainlayout);

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":pics/VENTAS_11_bg.png")));
    widget->setPalette(palette);

    widget->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
    widget->show();
    widget->adjustSize();
}

void LoginForm::convertTextToIso()
{
    if(!convertText->isChecked())
    {
        VDC::saveSettingsToLocalIni("","convertText", QString("2"));
    } else {
        VDC::removeSettingsFromLocalIni("","convertText");
    }
}

void LoginForm::resetFactor()
{
    VDC::setFieldSizeFactor(1);
    qDebug() << "reset Factor to default: 1.0";
}

void LoginForm::setFactorWidth(QString factor)
{
    double wert = VDC::getFieldSizeFactor();
    QString zeichen;

    if(factor.contains("-"))
    {
        zeichen = "-";
        factor.remove(zeichen);
    }

    if(!zeichen.isEmpty())
    {
        wert = wert - factor.toDouble();
    } else {
        wert = wert + factor.toDouble();
    }
    qDebug() << "New Fieldwidth factor: " << wert;
    VDC::setFieldSizeFactor(wert);
}

void LoginForm::disableApp()
{
   applicationLineEdit->setEnabled(false);
}

void LoginForm::enableApp()
{
   applicationLineEdit->setEnabled(true);
}

void LoginForm::debugToggle(bool checked)
{
    MainFrame *mainFrame = (MainFrame*) parent();
MainFrame::vdcdebug("LoginForm","debugToggle", "bool checked");
    if(checked)
    {
        mainFrame->clientTcp->dw->setVisible(true);
    }
    if(!checked)
    {
        mainFrame->clientTcp->dw->setVisible(false);
    }

}


void LoginForm::welcomeBar()
{
showMessage("Welcome!");
MainFrame::vdcdebug("LoginForm","welcomeBar", "");

}
//Hosts Settings

void LoginForm::hosts()
{
   HostsData *hosts = new HostsData(this);
MainFrame::vdcdebug("LoginForm","hosts", "");
   hosts->show();
}




//Hosts Settings
HostsData::HostsData(QWidget *parent) : QDialog(parent)
{
       hostspath = checkOS();
MainFrame::vdcdebug("HostsData","HostsData", "QWidget *parent");
       if (!hostspath.at(0).isNumber())
          {
          QLabel *description = new QLabel(tr("<h2>Host Data</h2>"));
          QLabel *description2 = new QLabel(tr("<b>NOTE :</b> If you are not logged in as admin/root <br> you cannot edit these settings"));
          QVBoxLayout *mainLayout = new QVBoxLayout;
          hostsTable = new QTableWidget(this);
          QStringList labels;
          labels << tr("IP-Adress") << tr("Host-Name") << tr("Comments");
          hostsTable->setColumnCount(3);
          hostsTable->setHorizontalHeaderLabels(labels);
          hostsTable->verticalHeader()->hide();
          hostsTable->setShowGrid(false);
          hostsTable->resizeColumnsToContents();
          hostsTable->horizontalHeader()->setStretchLastSection(true);
          readHost();
          QPushButton *addButton = new QPushButton(tr("Add Host"));
          QPushButton *saveButton = new QPushButton(tr("Save Hosts Data"));
          connect(addButton, SIGNAL(clicked()), this, SLOT(addHost()));
          connect(saveButton, SIGNAL(clicked()), this, SLOT(saveHost()));
          mainLayout->addWidget(description);
          mainLayout->addWidget(description2);
          mainLayout->addWidget(hostsTable);
          mainLayout->addWidget(addButton);
          mainLayout->addWidget(saveButton);
          setLayout(mainLayout);
          setWindowTitle(tr("VDC - Hosts Settings"));
          move(QCursor::pos());
          show();
          }
       else
          {
          QString errorout;
          QVBoxLayout *errorlay   = new QVBoxLayout(this);
          errorout = tr("Your operating system is not supported. Please contact us! \n Error No. : ");
          errorout.append(hostspath);
          QLabel *errorlabel = new QLabel(errorout);
          errorlay->addWidget(errorlabel);
          setLayout(errorlay);
          setWindowTitle(tr("Error!"));
          }

}

QString HostsData::checkOS()
{
   QString pfad;
MainFrame::vdcdebug("HostsData","checkOS", "");
   pfad = "";
   #ifdef Q_OS_WIN
   int windows = QSysInfo::WindowsVersion;
   #if QT_VERSION >= 0x040600
      if(windows == QSysInfo::WV_VISTA){
         return "1";
      }
   #endif
   if (windows > 15 && windows < 159)
      {
        pfad = QProcessEnvironment::systemEnvironment().value("SYSTEMROOT", "");
        if (pfad == "")
           {
           return "1";
           }
        pfad += "\\system32\\drivers\\etc\\hosts";
       }
    if (windows > 1 && windows < 15)
       {
         QStringList system; //= QProcess::systemEnvironment();
         pfad = system.filter("WINDIR").at(0).split("=").at(1);
         if (pfad == "")
            {
            return "2";
            }
         pfad += "\\hosts";
       }
    return pfad;
    #endif

   #ifdef Q_OS_MAC
   pfad = "/private/etc/hosts";
   return pfad;
   #endif

   #ifdef Q_OS_LINUX
   pfad = "/etc/hosts";
   return pfad;
   #endif

   return "3";

  }


void HostsData::readHost()
{
     QFile file(hostspath);
MainFrame::vdcdebug("HostsData","readHost", "");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

     QTextStream in(&file);
     int rowcount = 0;
     QString feld;
     QStringList feldarray;
     QVector<QStringList> dateiarray;
     int feldcount = 0;
     while (!in.atEnd()) {
         QString line = in.readLine();

         for(int i=0; i<line.count(); i++){

             if(line.at(i).isSpace() || i+1 == line.count()){

                 if(i+1 == line.count())
                     feld += line.at(i);

                 if(!feld.isEmpty()){
                    feldarray.insert(feldcount,feld);
                    feldcount++;
                    feld.clear();
                 }
             }
             else{

                   feld += line.at(i);
             }

         }
         if(feldarray.count() > 0){

                 feldcount = 0;
                 dateiarray.insert(rowcount, feldarray);
                 rowcount++;
                 feldarray.clear();
         }

     }

hostsTable->setRowCount(rowcount);
QString addhost;
int check2 = 0;
for(int i=0; i < dateiarray.count(); i++)
{
     feldarray = dateiarray.at(i);
     for(int j=0; j<feldarray.count(); j++)
     {

         QString feld = feldarray.at(j);
         if (j > 1 && !feld.startsWith("#"))
         {
         check2--;

         addhost = hostsTable->item(i, check2)->text();
         addhost += "    ";
         addhost += feld;

         hostsTable->setItem(i ,check2, new QTableWidgetItem(addhost));
     check2++;
     }
         else
         {
             hostsTable->setItem(i, check2, new QTableWidgetItem(feld));
             check2++;
             if(j == 0 && feld.startsWith("#"))
             {
               hostsTable->hideRow(i);
             }

                             }

     }
     check2 = 0;
 }
  file.close();
}

void HostsData::saveHost()
{
MainFrame::vdcdebug("HostsData","saveHost", "");
   QFile file(hostspath);
   if (!file.open(QIODevice::WriteOnly))
   return;

  QTextStream stream(&file);
  for(int i=0; i < hostsTable->rowCount();i++)
  {
      for(int j=0; j < hostsTable->columnCount();j++)
      {
         QTableWidgetItem *item = hostsTable->item(i,j);
         if(item != NULL && item->text() != " " && !item->text().isNull() && !item->text().isEmpty())
         {
            QString txt = item->text();
            stream << txt << " ";
         }
        }
//      QTableWidgetItem *item = hostsTable->item(i,0);
//      if(item != NULL || item->text() != " " || item->text().isNull() || item->text().isEmpty())
//      {
        stream << "\n";
//     }
     }

           file.close();
           readHost();
  }


void HostsData::addHost()
{
MainFrame::vdcdebug("HostsData","addHost", "");
    QFile file(hostspath);
    if(!file.isWritable())
    {
        Dialog *p_dialog = new Dialog(tr("Warning"), tr("Please start the VDC with adminstrator privileges to edit the hosts file."), "dialog", "stop", NULL, NULL, true);
        p_dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        connect(p_dialog->getAction("OK"), SIGNAL(triggered()), p_dialog, SLOT(close()));
        p_dialog->setAttribute(Qt::WA_DeleteOnClose, true);
        p_dialog->show();
        return;
    }
        QDialog *hostsAdd = new QDialog(this);
        QVBoxLayout *mainLayoutAdd = new QVBoxLayout;
        QHBoxLayout *ipfeld = new QHBoxLayout;
        QHBoxLayout *ipfeldv4 = new QHBoxLayout;
        QHBoxLayout *ipfeldv6 = new QHBoxLayout;
        QHBoxLayout *select = new QHBoxLayout;
        QRadioButton *radioipv4 = new QRadioButton("Select IPv4", this);
        QRadioButton *radioipv6 = new QRadioButton("Select IPv6", this);
        QLabel *iplabel = new QLabel(tr("IP-Address :"));
        QLabel *hostnamelabel = new QLabel(tr("Hostnames :"));
        QLabel *commentlabel = new QLabel(tr("Comments :"));
        ipv4 = new QWidget(this);
        ipv6 = new QWidget(this);
        ipv4->setLayout(ipfeldv4);
        ipv6->setLayout(ipfeldv6);
        radioipv4->setChecked(true);
        firstip = new QLineEdit;
        seccondip = new QLineEdit;
        thirdip = new QLineEdit;
        fourthip = new QLineEdit;
        hostnames = new QLineEdit;
        comments = new QLineEdit;
        firstipv6 = new QLineEdit;
        seccondipv6 = new QLineEdit;
        thirdipv6 = new QLineEdit;
        fourthipv6 = new QLineEdit;
        fifthipv6 = new QLineEdit;
        sixthipv6 = new QLineEdit;
        seventhipv6 = new QLineEdit;
        eighthipv6 = new QLineEdit;
        ipfeld->addWidget(ipv4);
        ipfeld->addWidget(ipv6);

        QRegExp regExpv4("25[0-4]|2[0-4][0-9]|[01]?[0-9][0-9]");
        QRegExp regExpv6("[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]");
        firstip->setValidator(new QRegExpValidator(regExpv4, this));
        seccondip->setValidator(new QRegExpValidator(regExpv4, this));
        thirdip->setValidator(new QRegExpValidator(regExpv4, this));
        fourthip->setValidator(new QRegExpValidator(regExpv4, this));
        firstipv6->setValidator(new QRegExpValidator(regExpv6, this));
        seccondipv6->setValidator(new QRegExpValidator(regExpv6, this));
        thirdipv6->setValidator(new QRegExpValidator(regExpv6, this));
        fourthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        fifthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        sixthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        seventhipv6->setValidator(new QRegExpValidator(regExpv6, this));
        eighthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        QPushButton *add = new QPushButton(tr("Add Host"), hostsAdd);
        select->addWidget(radioipv4);
        select->addWidget(radioipv6);

        mainLayoutAdd->addLayout(select);
        connect(radioipv4,SIGNAL(clicked()), this, SLOT(checkipv4()));
        connect(radioipv6,SIGNAL(clicked()), this, SLOT(checkipv6()));
        mainLayoutAdd->addWidget(iplabel);

        //ipfeldv4

        ipfeldv4->addWidget(firstip);
        ipfeldv4->addWidget(new QLabel("<b>.</b>"));
        ipfeldv4->addWidget(seccondip);
        ipfeldv4->addWidget(new QLabel("<b>.</b>"));
        ipfeldv4->addWidget(thirdip);
        ipfeldv4->addWidget(new QLabel("<b>.</b>"));
        ipfeldv4->addWidget(fourthip);

        //ipfeldv6

        ipfeldv6->addWidget(firstipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(seccondipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(thirdipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(fourthipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(fifthipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(sixthipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(seventhipv6);
        ipfeldv6->addWidget(new QLabel("<b>:</b>"));
        ipfeldv6->addWidget(eighthipv6);


        checkipv4();

        mainLayoutAdd->addLayout(ipfeld);
        mainLayoutAdd->addWidget(hostnamelabel);
        mainLayoutAdd->addWidget(hostnames);
        mainLayoutAdd->addWidget(commentlabel);
        mainLayoutAdd->addWidget(comments);
        mainLayoutAdd->addWidget(add);
        connect(add, SIGNAL(clicked()), this, SLOT(writeHost()));
        hostsAdd->setLayout(mainLayoutAdd);
        hostsAdd->setWindowTitle(tr("VDC - Add Host"));
        hostsAdd->move(QCursor::pos());
        hostsAdd->show();
}

void HostsData::checkipv6()
{
ipcheck = false;
MainFrame::vdcdebug("HostsData","checkipv6", "");
ipv4->hide();
ipv6->show();
    }

void HostsData::checkipv4()
{
ipcheck = true;
MainFrame::vdcdebug("HostsData","checkipv4", "");
ipv6->hide();
ipv4->show();
}

void HostsData::writeHost()
{
   QString entry;
MainFrame::vdcdebug("HostsData","writeHost", "");
   QFile file(hostspath);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
   return;
  entry += "\n";
  if(ipcheck == true)
  {
  entry += firstip->text();
  entry +=  ".";
  entry += seccondip->text();
  entry +=  ".";
  entry += thirdip->text();
  entry += ".";
  entry += fourthip->text();
}
  if(ipcheck == false)
  {
  entry += firstipv6->text();
  entry +=  ":";
  entry += seccondipv6->text();
  entry +=  ":";
  entry += thirdipv6->text();
  entry +=  ":";
  entry += fourthipv6->text();
  entry +=  ":";
  entry += fifthipv6->text();
  entry +=  ":";
  entry += sixthipv6->text();
  entry +=  ":";
  entry += seventhipv6->text();
  entry +=  ":";
  entry += eighthipv6->text();
}
  entry += "  ";
  entry += hostnames->text();
  entry += "  ";
  entry += "#";
  entry += comments->text();
  QTextStream stream(&file);
  stream << entry;
  QDialog *dia = (QDialog*) QObject::sender()->parent();
  file.close();
  readHost();
  dia->close();

}
void LoginForm::setFormat(QString format)
{
    qDebug() << "format: " << format;

    QList<QString> params = format.split("|");
    VDC::saveSettingsToLocalIni("","screenFormat", params.at(0));

    if(params.count() > 0)
    {
        VDC::saveSettingsToLocalIni("","setDBMONEY", params.at(1));
    }

    if(params.at(0) == "##,###,###,###,##&.&&&&&&&&&&&&&&&&" && params.at(1) == ",")
    {
        format1->setChecked(true);
        format2->setChecked(false);
        format3->setChecked(false);
        format4->setChecked(false);
    }

    if(params.at(0) == "##,###,###,###,##&.&&&&&&&&&&&&&&&&" && params.at(1) == ".")
    {
        format1->setChecked(false);
        format2->setChecked(true);
        format3->setChecked(false);
        format4->setChecked(false);
    }

    if(params.at(0) == "-")
    {
        format1->setChecked(false);
        format2->setChecked(false);
        format3->setChecked(true);
        format4->setChecked(false);
    }

    if(params.at(0) == "--")
    {
        format1->setChecked(false);
        format2->setChecked(false);
        format3->setChecked(false);
        format4->setChecked(true);
    }
}

void LoginForm::font()
{
       OptionsTab *optionsTab = new OptionsTab();
MainFrame::vdcdebug("LoginForm","font", "");
       connect(optionsTab, SIGNAL(showMessage(QString)), this, SLOT(showMessage(QString)));
       optionsTab->setWindowTitle(tr("VDC - Font Settings"));

       optionsTab->move(QCursor::pos());
       optionsTab->show();


}


void LoginForm::showMessage(QString m)
{
   MainFrame *mf = (MainFrame*) this->parent();
MainFrame::vdcdebug("LoginForm","showMessage", "QString m");

   if(mf != NULL){
      mf->statusBar()->showMessage(m, 2000);
   }
}

//------------------------------------------------------------------------------
// Method       : void writeFile()
// Filename     : login.cpp
// Description  : opens a File for binary writing
//------------------------------------------------------------------------------

void LoginForm::writeFile(QString qs_filename)
{
   // instantiating from class QFile to handle a data stream
MainFrame::vdcdebug("LoginForm","writeFile", "QString qs_filename");
   //
   QFile file(qs_filename);

   // open the file for next procedure
   //
   if (!file.open(QIODevice::WriteOnly)){

       errorMessageLoginForm->showMessage(
                 tr("Error: Cannot open File for writing"));
   }else{

       // write the data out to file
       //
       QDataStream out(&file);
       out.setVersion(QDataStream::Qt_4_1);
   }
}
   #ifdef SSH_USE
void LoginForm::authfailed(int rc, QString err)
{
  Q_UNUSED(err);

  QString error = "";

  switch(rc)
  {
    case SSH_AUTH_DENIED:
      error = "Die Kombination aus Username und Passwort existiert nicht.";
      break;
    default:
      error = "Fehler beim Authentifizieren! Abbruch!";
      break;

  }

  error.append(" Fehlercode : " + QString::number(rc));

  this->error(error);

  removeCursor();

}

void LoginForm::commandfailed(int rc, QString err)
{
  Q_UNUSED(rc);

  this->error("Script : " + err + " nicht gefunden!");

  removeCursor();
}


void LoginForm::connectionfailed(int rc, QString err)
{
  QString error = "Verbindung zum Host : " + err + " fehlgeschlagen. Fehlercode : " + QString::number(rc);
  this->error(error);

  removeCursor();
}
#endif
void LoginForm::error(QString err)
{
  errorMessageLoginForm->showMessage(err);
}

//------------------------------------------------------------------------------
// Method       : void readEditFile()
// Filename     : login.cpp
// Description  : opens a File for binary reading
//------------------------------------------------------------------------------

void LoginForm::readEditFile(QString fname)
{
   QFile file(fname);
MainFrame::vdcdebug("LoginForm","readEditFile", "QString fname");

   // open the file for next procedure
   //
   if (!file.open(QIODevice::ReadOnly)){
    }else{
       QDataStream in(&file);
       in.setVersion(QDataStream::Qt_4_1);
   }
}


//------------------------------------------------------------------------------
// Method       : void saveEdits()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------

void LoginForm::saveEdits(){
   if(b_savefile){
      writeFile(qs_openFilename);
      b_savefile = false;
   }
}

//------------------------------------------------------------------------------
// Method       : void okPressed()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------
void LoginForm::okPressed()
{

   //hideLogin();
MainFrame::vdcdebug("LoginForm","okPressed", "");
   this->setCursor(Qt::WaitCursor);
   //VDC::waitCursor();
   QSettings settings;

   QString server = serverLineEdit->text();
   QString user   = usernameLineEdit->text();
   QString pass   = passwordLineEdit->text();
   QString app    = applicationLineEdit->text();
   int port       = portLineEdit->text().toInt();

   if(pass.isEmpty())
   {
      passwordLineEdit->setFocus();
      showMessage("Insert a Password!");
      removeCursor();
      return;
   }

   if(cb->isChecked())
   {
       settings.setValue("password", pass);
       settings.setValue("save", "yes");

   }
   else
   {
       settings.setValue("password", "");
       settings.setValue("save", "no");
   }

   settings.setValue("server", server);
   settings.setValue("user", user);
   settings.setValue("port", port);;
   settings.setValue("application", app);
   if(rb_telnet->isChecked())
     settings.setValue("checked", "telnet");
   #ifdef SSH_USE
   if(rb_ssh->isChecked())
     settings.setValue("checked", "ssh");
   #endif
   if(rb_proxy->isChecked())
     settings.setValue("checked", "proxy");


   settings.sync();
   if(rb_telnet->isChecked())
   {
      tn = new QtTelnet;
      connect(tn, SIGNAL(loginRequired()), this, SLOT(connectToTelnet()));
      tn->connectToHost(server, 23);
      connect(tn, SIGNAL(connectionError(QAbstractSocket::SocketError)), this, SLOT(removeCursor()));
      connect(tn, SIGNAL(loginFailed()), this, SLOT(removeCursor()));
      return;
   }
   #ifdef SSH_USE
   if(rb_ssh->isChecked())
   {
       //Initiliaze
       VDC::saveSettingsToIni("", "sshport", portLineEdit->text());
       VSSH *ssh = new VSSH(server, user, pass, app, this);
       connect(ssh, SIGNAL(connection_established()), this, SLOT(m_c_established()));
       connect(ssh, SIGNAL(authsuccess()), this, SLOT(m_c_success()));
       connect(ssh, SIGNAL(enviorment_set()), this, SLOT(m_c_envset()));
       connect(ssh, SIGNAL(command_executed(QString)), this, SLOT(m_c_executed(QString)));
       connect(ssh, SIGNAL(connectionfailed(int,QString)), this, SLOT(connectionfailed(int,QString)));
       connect(ssh, SIGNAL(authfailed(int,QString)), this, SLOT(authfailed(int,QString)));
       connect(ssh, SIGNAL(commandnotfound(int,QString)), this, SLOT(commandfailed(int,QString)));
       connect(ssh, SIGNAL(error(QString)), this, SLOT(error(QString)));
       ssh->start(QThread::NormalPriority);
       connect(ssh, SIGNAL(finished()), ssh, SLOT(deleteLater()));
       return;

   }
   #endif
   ClientSocket *socket = new ClientSocket(0, user, pass, applicationLineEdit->text());

   socket->connectToHost(server, 3490);
   if(!socket->waitForConnected(4000)){
      QErrorMessage *errorMsg = new QErrorMessage(this);
      errorMsg->showMessage(tr("Could not connect to Host"));
   }
   removeCursor();
}

void LoginForm::connectToTelnet()
{
   QString user   = usernameLineEdit->text();
   QString pass   = passwordLineEdit->text();
   tn->login(user, pass);
}

//------------------------------------------------------------------------------
// Method       : void cancelPressed()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------
/* replaced by MainFrame::closeAction()
void LoginForm::cancelPressed()
{
MainFrame::vdcdebug("LoginForm","cancelPressed", "");
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;

    if(ql_screenhandler)
    {
        if(ql_screenhandler->count() > 0)
        {
            Dialog *dialog = new Dialog("VDC - Ventas Desktop Client", tr("There are open connections.\nDo you really want to quit?"), "", "stop", this, Qt::WindowStaysOnTopHint);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage(":pics/VENTAS_11_bg.png")));

            dialog->setPalette(palette);
            dialog->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_blau.png); padding-top: -1; padding-right: 10; text-align: left; height: 36px; min-width: 50px; }");
            dialog->createButton(1, tr("Yes"), "Yes", "ja.png");
            dialog->getAction("Yes")->setShortcut(Qt::Key_F12);
            dialog->createButton(2, tr("No"), "No", "escape.png");
            dialog->getAction("No")->setShortcut(Qt::Key_Escape);
            connect(dialog->getAction("YES"), SIGNAL(triggered()), this, SLOT(closeVDC()));
            connect(dialog->getAction("NO"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
        } else {
            emit closeVDC();
        }
    }


}
*/
void LoginForm::closeVDC()
{
    MainFrame *mainFrame = (MainFrame*) parent();
    VDC::saveSettingsToIni("Ventas AG", "posX", QString::number(this->parentWidget()->pos().x()));
    VDC::saveSettingsToIni("Ventas AG", "posY", QString::number(this->parentWidget()->pos().y()));
    mainFrame->closeSSH = 1;
    exit(EXIT_SUCCESS);
}

void LoginForm::showLogin()
{
MainFrame::vdcdebug("LoginForm","showLogin", "");
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
      mainWin->setHidden(false);
   }
}

void LoginForm::hideLogin()
{
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
MainFrame::vdcdebug("LoginForm","hideLogin", "");
      mainWin->setHidden(true);
   }
}

void LoginForm::loadSettings()
{
   QSettings settings;
   MainFrame::vdcdebug("LoginForm","loadSettings", "");
   QString server = settings.value("server").toString();
   QString user = settings.value("user").toString();
   QString pass = settings.value("password").toString();
   QString app = settings.value("application").toString();

   QString checked = settings.value("checked").toString();

   QString save = settings.value("save").toString();

   if(save == "yes")
   {
      cb->setChecked(true);
   }

   if(checked == "ssh")
   {
      #ifdef SSH_USE
      rb_ssh->setChecked(true);
      if(app.isEmpty())
        app="vdc";
      #else
      rb_proxy->setChecked(true);
      #endif
   }

   if(checked == "telnet")
     rb_telnet->setChecked(true);

   if(checked == "proxy")
     rb_proxy->setChecked(true);

   if(!server.isEmpty()){
      serverLineEdit->setText(server);
   }
   if(!user.isEmpty()){
      usernameLineEdit->setText(user);
   }

   if(!pass.isEmpty()){
      passwordLineEdit->setText(pass);
   }

   if(!app.isEmpty()){
      applicationLineEdit->setText(app);
   }
}
void LoginForm::debugCheck()
{
   toggledebug->setChecked(false);
MainFrame::vdcdebug("LoginForm","debugCheck", "");
}
#ifdef SSH_USE
//Slots for SSH

void LoginForm::m_c_success()
{
  showMessage("Authentifizierung erfolgreich!");
  //removeCursor();
}

void LoginForm::m_c_established()
{
  showMessage("Verbindung hergestellt!");
}

void LoginForm::m_c_executed(QString cmd)
{
  QString message = "Script : \"" + cmd + "\" wird gestartet!";
  showMessage(message);
  removeCursor();
}

void LoginForm::m_c_envset()
{
  showMessage("Umgebung wurde gesetzt!");
}

#endif

void LoginForm::removeCursor()
{
  this->setCursor(Qt::ArrowCursor);
}

void LoginForm::setOfficeInstallation()
{
    int stdOfficeProg = VDC::readSettingsFromLocalIni("","officeStdProg").toInt();
    QWidget *widget = new QWidget;
    mOfficeComboBox = new QComboBox;
    QLabel *label = new QLabel;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();

    QPalette palette;
    palette.setBrush(this->backgroundRole(), Qt::white);
    widget->setPalette(palette);

    QPushButton *closeButton = new QPushButton(tr("&Cancel"));
    closeButton->setIcon(QIcon(QString(":pics/escape.png")));
    closeButton->setIconSize(QSize(53,37));
    QAction *cancelAction = new QAction(tr("&Cancel"), this);
    closeButton->addAction(cancelAction);
    QList<QKeySequence> shortcuts;
    shortcuts
    << Qt::Key_Escape // this is the primary shortcut
    << QKeySequence("ALT + Q"); // this is another valid shortcut but won't appear on a menu for exmple
    cancelAction->setShortcuts(shortcuts);
    closeButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
    connect(closeButton, SIGNAL(clicked()), widget, SLOT(close()));

    QPushButton *saveButton = new QPushButton(tr("&Apply"));

    QList<QKeySequence> ql_okShortcuts;
    ql_okShortcuts << QKeySequence("F12");
    ql_okShortcuts << QKeySequence("Enter");
    ql_okShortcuts << QKeySequence("Return");

    QAction *okAction = new QAction(tr("&Apply"), this);
    okAction->setShortcuts(ql_okShortcuts);

    saveButton->setIcon(QIcon(QString(":pics/ok_gruen.png")));
    saveButton->setIconSize(QSize(53,37));
    saveButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
    saveButton->addAction(okAction);
    connect(okAction, SIGNAL(triggered()), this, SLOT(saveOfficeInstallation()));
    connect(okAction, SIGNAL(triggered()), widget, SLOT(close()));

    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveOfficeInstallation()));
    connect(saveButton, SIGNAL(clicked()), widget, SLOT(close()));

    label->setText("Please choose an Office installation: ");
    mOfficeComboBox->addItem("Please choose...");
    mOfficeComboBox->addItem("Microsoft Office");
    mOfficeComboBox->addItem("Open/Libre Office");

    mOfficeComboBox->setCurrentIndex(stdOfficeProg);

    vLayout->addWidget(label);
    vLayout->addWidget(mOfficeComboBox);

    hLayout->addWidget(saveButton);
    hLayout->addWidget(closeButton);
    vLayout->addLayout(hLayout);

    widget->setLayout(vLayout);
    widget->show();
}

void LoginForm::saveOfficeInstallation()
{
    if(mOfficeComboBox)
    {
        if(mOfficeComboBox->currentIndex() > 0)
        {
            VDC::saveSettingsToLocalIni("","officeStdProg", QString::number(mOfficeComboBox->currentIndex()));
        } else {
            emit setOfficeInstallation();
        }
    }
}

void LoginForm::checkForUpdate()
{
    return;
}

void LoginForm::showUpdateError()
{
    Dialog *dialog = new Dialog(tr("VDC Update"), tr("VDC update available. Windows 7 or higher needed."), "", "stop", NULL, Qt::WindowStaysOnTopHint, true);
    dialog->setVentasStyle();

    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
    dialog->getAction("OK")->setShortcut(Qt::Key_F12);

    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
    connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

    dialog->move(600,400);
    dialog->show();
}

void LoginForm::setMainMenu()
{
    QString menuType = VDC::readSettingsFromLocalIni("", "startMenuPosition");

    if(menuType == "tree" || menuType.isEmpty() || menuType == "-1")
    {
        VDC::saveSettingsToLocalIni(QString(""), QString("startMenuPosition"), QString("menu"));
        m_mainMenu->setText("Main Menu vertical");
    } else if (menuType == "menu")
    {
        VDC::saveSettingsToLocalIni(QString(""), QString("startMenuPosition"), QString("tree"));
        m_mainMenu->setText("Main Menu horizontal");
    }
}
