#ifndef DASHBOARDSCENE_H
#define DASHBOARDSCENE_H

#include <QGraphicsScene>
#include "dashboard/dashboarditem.h"
#include "dashboard/dashboardconfigurationwidget.h"

class DashboardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DashboardScene(QGraphicsView *view);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QHash<QString, QString> getItemList() { return m_dashboardItemList; }
    void addItemToList(QString name, QString text) { m_dashboardItemList.insert(name, text); }
    void addItemToConfig(QString name, QString text, QString icon, QString runtxt);
    QList<QGraphicsProxyWidget*> dashboardItem;

signals:
    void sendMenuCommand(QString cmd);
    void updateItems();

private:
    QHash<QString, QString> m_dashboardItemList;
    DashboardConfigurationWidget *m_dashboardConfigWidget;
};

#endif // DASHBOARDSCENE_H
