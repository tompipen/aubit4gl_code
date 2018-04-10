#ifndef DASHBOARDVIEW_H
#define DASHBOARDVIEW_H

#include <QGraphicsView>

#include "dashboard/dashboardscene.h"
#include "dashboard/dashboarditem.h"


class DashboardView : public QGraphicsView
{
    Q_OBJECT
public:
    DashboardView();
    void addWidgetToScene(DashboardItem *item, QPoint pos, QString runtxt);
    void updateWidgetFromScene(QGraphicsProxyWidget *pProxy, QString icon, QString text, QString runtxt);
    DashboardScene* getScene() { return m_dashboardScene; }
    QRect getLastPosFromItem() { return mLastInsertPos; }
    void resizeEvent(QResizeEvent *event);

public slots:
    void refreshItems();
    void updateItems();

private:
    DashboardScene *m_dashboardScene;
    QList<DashboardItem*> m_dashboardItems;
    QRect mLastInsertPos;
};

#endif // DASHBOARDVIEW_H
