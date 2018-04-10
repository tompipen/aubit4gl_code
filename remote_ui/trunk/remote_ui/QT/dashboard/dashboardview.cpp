#include "dashboardview.h"
#include "include/vdc.h"

#include <QApplication>
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QTimer>

DashboardView::DashboardView()
{
    this->setMinimumSize(450,350);
    this->resize(800,600);

    m_dashboardScene = new DashboardScene(this);
    this->setSceneRect(0, 0, this->width(), this->height());
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setScene(m_dashboardScene);
    this->setStyleSheet("border-style: none; background-image: url(:pics/master11.png); background-repeat: no-repeat; background-attachment: fixed; background-position: right bottom;");
    mLastInsertPos = QRect(0,0,0,0);
}

void DashboardView::addWidgetToScene(DashboardItem *item, QPoint pos, QString runtxt)
{
//    QGraphicsRectItem *proxyControl = getScene()->addRect(pos.x(),pos.y(), 0, 0, QPen(Qt::white), QBrush(Qt::white));
//    Derzeit nicht moveable
//    proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
//    proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
//    proxyControl->setVisible(false);

    qDebug() << "bla: " << item->getText();
    if(runtxt == "neue-aufgabe") {
        getScene()->addItemToList(item->objectName(), item->getText());
    }else{
        getScene()->addItemToConfig(item->objectName(), item->getDefaultText(), item->getIcon(), runtxt);
        getScene()->addItemToList(item->objectName(), item->getText()); // to prevent items from being added twice in screenhandler
    }

    bool showItem = VDC::readSettingsFromIni("Dashboard", item->objectName()).toInt();

        QGraphicsProxyWidget *proxy = getScene()->addWidget(item);
        getScene()->dashboardItem.append(proxy);
    if(showItem || item->objectName() == "NEUE_AUFGABE") {
        proxy->setPos(pos.x(), pos.y());

        mLastInsertPos.setX(pos.x() + 195);
        mLastInsertPos.setY(pos.y());
    } else {
        proxy->setVisible(false);
    }
}

void DashboardView::updateWidgetFromScene(QGraphicsProxyWidget *pProxy, QString icon, QString text, QString runtxt)
{
    DashboardItem *item = qobject_cast<DashboardItem*>(pProxy->widget());

    item->setRuntxt(runtxt);
    item->setText(text);
}

void DashboardView::resizeEvent(QResizeEvent *resizeEvent)
{
    getScene()->setSceneRect(QRect(0,0, resizeEvent->size().width(), resizeEvent->size().height()));

    this->updateItems();
}

void DashboardView::refreshItems()
{
    QTimer::singleShot(50, this, SLOT(updateItems()));
}

void DashboardView::updateItems()
{       
    int posX = 21;
    int posY = 0;

    qDebug() << "refreshing items" << getScene()->dashboardItem;

    foreach (QGraphicsItem *item, getScene()->dashboardItem) {
        if(item->isWidget()) {

            //new line for the items if width is too wide
            if(posX + 195 > getScene()->width()) {
                posX = 21;
                posY = posY + 100;
            }
            QGraphicsProxyWidget* pProxy = qgraphicsitem_cast<QGraphicsProxyWidget*>(item);
            if(pProxy)
            {
                DashboardItem *dashItem = qobject_cast<DashboardItem*>(pProxy->widget());
                bool showItem = VDC::readSettingsFromIni("Dashboard", dashItem->objectName()).toInt();

                if(showItem || dashItem->objectName() == "NEUE_AUFGABE") {
                    item->setPos(QPointF(posX, posY));
                    dashItem->show();

                    getScene()->removeItem(item);
                    getScene()->addItem(item);

                    posX = posX + 195;

                } else {
                    getScene()->removeItem(item);
                    DashboardItem *dashItem = qobject_cast<DashboardItem*>(pProxy->widget());
                    getScene()->addItemToConfig(dashItem->objectName(), dashItem->getDefaultText(), dashItem->getIcon(), "");
                }
            }

        }
    }
}
