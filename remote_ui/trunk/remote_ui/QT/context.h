#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include <QHash>
#include <QModelIndex>
#include <QItemSelection>
#include <include/fgl.h>

class Context : public QObject
{

   Q_OBJECT;

public:
   Context(QObject *parent = NULL);
   Context(Fgl::State, QObject *parent = NULL);
   ~Context();
   Fgl::State state() { return fgl_state; };
   void setState(Fgl::State s) { fgl_state = s; };
   void addField(QWidget*);
   void addScreenRecord(QWidget*, bool input);
   QList<QWidget*> fieldList();
   void setOption(QString, int);
   int getOption(QString name) { return qh_options[name]; };
   QStringList getScreenRecordValues(int);
   void setScreenRecordValues(int, QStringList);

   void sendBeforeEvent();
   void sendAfterEvent();

private:
   Fgl::State fgl_state;
   QList<QWidget*> ql_fieldList;
   QHash<QString, int> qh_options;
   void setRowChanged();
   int rowChangedCnt;

public slots:
   void screenRecordRowChanged(const QModelIndex &current, const QModelIndex &previous);
   void screenRecordColumnChanged(const QModelIndex &current, const QModelIndex &previous);

signals:
   void fieldEvent(Fgl::Event);
    
};

#endif
