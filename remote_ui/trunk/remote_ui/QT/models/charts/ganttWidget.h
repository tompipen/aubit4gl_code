#ifndef GANTTWIDGET_H
#define GANTTWIDGET_H

#include <QStandardItem>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include "models/charts/chartInterface.h"
#include "models/charts/chartTableModel.h"
#include "models/charts/ganttTable.h"
#include "models/charts/ganttnode.h"

class GanttWidget : public QMainWindow
{
    Q_OBJECT;

public:
    GanttWidget(QWidget *parent);
    void createGanttWidget();
    void readCsv(QString);
    void closeEvent(QCloseEvent *);
    QWidget *p_fglform;

private slots:
    void slotFileQuit();
    void slotToolsNewItem();
    void slotToolsAppendItem();
    void slotCollapseAll();
    void slotExpandAll();

    void slotAlignLeft();
    void slotAlignCenter();
    void slotAlignRight();
    void slotAlignHidden();

signals:
    void closeSendResponse(QString);
private:
    GanttTable* model;
    KDGantt::View *view;
    QStandardItemModel gantt_model;
    //QPointer<ScreenHandler> p_screenhandler;
};

#endif // GANTTWIDGET_H
