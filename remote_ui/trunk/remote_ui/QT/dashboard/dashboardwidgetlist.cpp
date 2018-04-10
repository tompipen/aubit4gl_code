#include "dashboardwidgetlist.h"
#include "include/vdc.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

DashboardWidgetList::DashboardWidgetList()
{
    m_listWidget = new QListWidget;

    initialise();
}

void DashboardWidgetList::initialise()
{

    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *closeButton = new QPushButton("Fertig");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    layout->addWidget(m_listWidget);
    layout->addWidget(closeButton, 0, Qt::AlignRight);

    this->setLayout(layout);
    this->resize(400,600);
}

void DashboardWidgetList::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    saveSettings();
    emit updateItems();

}

void DashboardWidgetList::saveSettings()
{

    for(int i=0; i < m_listWidget->count(); i++ ) {
        QListWidgetItem *item = m_listWidget->item(i);

        if(item->checkState() == Qt::Checked) {
            VDC::saveSettingsToIni("Dashboard", item->text(), QString::number(1));
        } else {
            VDC::removeSettingsFromIni("Dashboard", item->text());
        }
    }

}

void DashboardWidgetList::loadItemsToList(QList<QString> items)
{
    for(int i=0; i < items.count(); i++) {
        QString objectname = items.at(i);
        bool show = VDC::readSettingsFromIni("Dashboard", objectname).toInt();
        QListWidgetItem *item = new QListWidgetItem;

        if(!show && objectname != "neue-aufgabe") {
            item->setText(objectname);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
            item->setCheckState(Qt::Unchecked);
            m_listWidget->insertItem(i, item);
        }
    }
}
