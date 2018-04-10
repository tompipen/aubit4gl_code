#include "dashboardscene.h"
#include "mainframe.h"

DashboardScene::DashboardScene(QGraphicsView *view) : QGraphicsScene ()
{
    this->setParent(view);
    m_dashboardConfigWidget = new DashboardConfigurationWidget();

    //setup refresh in case items get deleted or new ones added
    connect(m_dashboardConfigWidget, SIGNAL(updateItems()), parent(), SLOT(refreshItems()));
    connect(this, SIGNAL(updateItems()), parent(), SLOT(refreshItems()));
}

void DashboardScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsProxyWidget *proxyWidget = qgraphicsitem_cast<QGraphicsProxyWidget*> (this->itemAt(event->scenePos(), QTransform()));
    if(proxyWidget == NULL) {
        return;
    }

    if(DashboardItem *item = qobject_cast<DashboardItem*> (proxyWidget->widget())) {
        QPoint p = item->mapFromGlobal(QCursor::pos());
        QPolygon iconTriangle; //calculates the shape of the icon using the item-mapped coordinates
        iconTriangle.setPoints(3, 141, 80, 183, 80, 183, 43);

        if(item->getRuntxt() == "neue-aufgabe")
        {
            if(m_dashboardConfigWidget->isVisible()) {
                m_dashboardConfigWidget->activateWindow();
                m_dashboardConfigWidget->raise();
            } else {
                m_dashboardConfigWidget->show();
            }
        } else if (iconTriangle.containsPoint(p, Qt::OddEvenFill)) {
            proxyWidget->widget()->hide();
            VDC::removeSettingsFromIni("Dashboard", proxyWidget->widget()->objectName());
            m_dashboardConfigWidget->m_itemList.remove(proxyWidget->widget()->objectName());

            emit updateItems();
        } else {
            QString cmd = QString("<TRIGGERED ID=\"EXEC\" PROGRAMNAME=\"%1\"/>").arg(item->getRuntxt());
            QMetaObject::invokeMethod(MainFrame::lastmainframe->ql_screenhandler->last(), "sendDirect", Qt::QueuedConnection, Q_ARG(QString, cmd));
        }
    }
}

// adds item to Dashboard Config
void DashboardScene::addItemToConfig(QString name, QString text, QString icon, QString runtxt)
{
    m_dashboardConfigWidget->addItem(name, text, icon, runtxt);
}
