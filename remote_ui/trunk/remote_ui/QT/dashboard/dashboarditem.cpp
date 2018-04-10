#include "dashboarditem.h"
#include "include/vdc.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QPalette>
#include <QSpacerItem>
//#include <QTimer>
#include <QGraphicsLinearLayout>

#include <dashboard/dashboardview.h>

DashboardItem::DashboardItem(QString aktivitaet, QString icon, QString text, QString runtxt, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    m_textLabel = new QLabel(text);

    if(m_defaultText.isEmpty()) {
        m_defaultText = text;
    }    
        m_runtxt = runtxt;

    if( icon == "neue-aufgabe") {
        this->setStyleSheet("* {color: #005a9f; font-weight: 700;}");
    }

    //closeLabel->setStyleSheet("background-color: #000;");

    m_widgetIcon = icon;
    icon = ":/pics/dashboard/" + icon + ".png";

    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(icon)))));
    this->window()->setPalette(*palette);

    this->setObjectName(aktivitaet);

    //this->setStyleSheet(QString("background-image: url('%1'); background-repeat: no-repeat; background-attachment: fixed; background-position: right bottom;").arg(icon));

    vBoxLayout->setMargin(0);
    vBoxLayout->insertSpacing(0, 28);
    vBoxLayout->addWidget(m_textLabel, 0, Qt::AlignTop);
    vBoxLayout->setContentsMargins(15,0,0,0);
    this->setLayout(vBoxLayout);

    this->setFixedSize(183,80);
}

DashboardItem::~DashboardItem() {

}
