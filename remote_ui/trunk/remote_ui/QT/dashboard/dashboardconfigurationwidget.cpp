#include "dashboardconfigurationwidget.h"
#include "include/vdc.h"
#include "mainframe.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

DashboardConfigurationWidget::DashboardConfigurationWidget()
{
    m_listWidget = new QListWidget;
    m_listWidget->setIconSize(QSize(37,28));

    createWidget();
    setIgnoreChanges(false);
}

void DashboardConfigurationWidget::createWidget()
{

    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *acceptButton = new QPushButton("Ok");
    acceptButton->setIconSize(QSize(53,37));
    acceptButton->setIcon(QIcon(QString(":pics/ok_F12.png")));
    acceptButton->setShortcut(Qt::Key_F12);
    acceptButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

    QPushButton *closeButton = new QPushButton("Abbruch");
    closeButton->setIconSize(QSize(53,37));
    closeButton->setIcon(QIcon(QString(":pics/escape.png")));
    closeButton->setShortcut(Qt::Key_Escape);
    closeButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");


    connect(acceptButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeWithoutSave()));

    hLayout->addWidget(acceptButton, 0, Qt::AlignRight);
    hLayout->addWidget(closeButton, 0, Qt::AlignLeft);

    vLayout->addWidget(m_listWidget);
    vLayout->addLayout(hLayout);

    this->setLayout(vLayout);
    this->resize(400,600);
    this->setWindowFlags(Qt::WindowStaysOnTopHint); 

    QPalette palette;
    palette.setBrush(this->backgroundRole(), Qt::white);
    this->setPalette(palette);
    m_listWidget->setStyleSheet("QListWidget { border: 1px solid #afafaf; border-radius: 2.2px }");
}

void DashboardConfigurationWidget::hideEvent(QHideEvent *event) {
    Q_UNUSED(event);
    if(!ignoreChanges()) {
        saveSettings();
        emit updateItems();
    }

}

void DashboardConfigurationWidget::saveSettings()
{
    bool refreshed = false;

    for(int i=0; i < m_listWidget->count(); i++ ) {
        QListWidgetItem *item = m_listWidget->item(i);
        QString objectName = m_itemList.key(item->text());
        qDebug() << "save name: " << objectName;
        if(item->checkState() == Qt::Checked) {
            VDC::saveSettingsToIni("Dashboard", objectName, QString::number(1));
            m_listWidget->takeItem(i);
            i--;
            if (refreshed == false) {
                refreshed = true;
                QString runInfo = m_runInfo;
                QString cmd = QString("<TRIGGERED ID=\"EXEC\" PROGRAMNAME=\"%1\"/>").arg(runInfo.prepend("fglgo p_dash_refresh"));
                QMetaObject::invokeMethod(MainFrame::lastmainframe->ql_screenhandler->last(), "sendDirect", Qt::QueuedConnection, Q_ARG(QString, cmd));
            }
        } else {
            VDC::removeSettingsFromIni("Dashboard", objectName);
        }
    }
}

void DashboardConfigurationWidget::addItem(QString objectName, QString text, QString icon, QString runtxt)
{
    qDebug() << "adding item to config widget: " << objectName;

    if(objectName != "NEUE_AUFGABE" && !m_itemList.contains(objectName)) {
        QListWidgetItem *item = new QListWidgetItem;
        bool show = VDC::readSettingsFromIni("Dashboard", objectName).toInt();

        icon = ":pics/dashboard/small_" + icon + ".png";
        item->setIcon(QIcon(icon));
        item->setText(text);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item->setCheckState(Qt::Unchecked);

        if(!show) {
            bool alreadyExists = false;
            for (int i = 0; i < m_listWidget->count(); i++) {
                if (m_listWidget->item(i)->text() == item->text()) {
                    alreadyExists = true;
                    break;
                }
            }
            if (alreadyExists == false) {
                m_listWidget->addItem(item);
            }
        }
        m_itemList.insert(objectName, text);

        if (m_runInfo.isEmpty()) {  //get r_firma.firma and g2_datenbank for fglgo
            for (int i = 9; i < runtxt.count(); i++) {
                if (runtxt.at(i) == ' ') {
                    m_runInfo = runtxt.right(i-1);
                    break;
                }
            }
        }
    }

}

void DashboardConfigurationWidget::closeWithoutSave()
{
    setIgnoreChanges(true);
    this->close();

}

// unused
//void DashboardConfigurationWidget::loadItemsToList()
//{
//    int i = 0;
//    foreach(const QString &key, m_itemList.keys()) {
//        qDebug() << "key: " << key << " - " << m_itemList.value(key);

//        bool show = VDC::readSettingsFromIni("Dashboard", key).toInt();
//        QListWidgetItem *item = new QListWidgetItem;

//        if(!show && key != "neue-aufgabe") {
//            item->setText(m_itemList.value(key));
//            item->setIcon(QIcon(":pics/dashboard/icon-small.png"));
//            item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
//            item->setCheckState(Qt::Unchecked);
//            m_listWidget->insertItem(i, item);
//            i++;
//        }

//    }
//}
