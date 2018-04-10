#ifndef DASHBOARDCONFIGURATIONWIDGET_H
#define DASHBOARDCONFIGURATIONWIDGET_H

#include <QWidget>
#include <QListWidget>

#include "dashboard/dashboarditem.h"

class DashboardConfigurationWidget : public QWidget
{
    Q_OBJECT
public:
    DashboardConfigurationWidget();
    void createWidget();
    //void loadItemsToList();
    void saveSettings();
    void addItem(QString objectName, QString text, QString icon, QString runtxt);
    QHash<QString,QString> m_itemList;

    void hideEvent(QHideEvent *event);

    bool ignoreChanges() { return m_ignoreChanges; }
private:
    void setIgnoreChanges(bool ignoreChanges) { m_ignoreChanges = ignoreChanges; }

signals:
    void updateItems();

public slots:
    void closeWithoutSave();
private:
    QListWidget *m_listWidget;
    QString m_runInfo;
    bool m_ignoreChanges;
};

#endif // DASHBOARDCONFIGURATIONWIDGET_H
