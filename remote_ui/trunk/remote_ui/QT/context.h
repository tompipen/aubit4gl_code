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
   bool arrlinechanged(){ if(b_arrlinech) { b_arrlinech = false; return true; } else { return false; } }
   bool scrlinechanged(){ if(b_scrlinech) { b_scrlinech = false; return true; } else { return false; } }
   bool arrcountchanged(){ if(b_arrcountch) { b_arrcountch = false; return true; } else { return false; } } //ONLY ONE CALL IN RESPONSE, OTHERWISE ITS FORBIDDEN TO CALL THIS FUNCTION!
   QStringList getScreenRecordValues(int);
   bool b_arrlinech;
   bool b_scrlinech;
   bool b_arrcountch;
   void sendBeforeEvent();
   void sendAfterEvent();
   void checkOptions();
   void setConstrained(bool value) { b_constrained = value; }
   bool getConstrained() { return b_constrained; }
   void setLastFocusWidget(QWidget*);
   QWidget *lastFocusWidget();
   QList<QWidget*> ql_formFields;
   QList<Fgl::Event> ql_pendingEvents;
   /*
   void restoreFieldPalette();
   void setPaletteList();
   void setPaletteForWidget(QWidget*);
   */

   void refreshInputArrayAttributes();

private:
   Fgl::State fgl_state;
   QList<QWidget*> ql_fieldList;
   QHash<QString, int> qh_options;
   //QHash<QString, QPalette> qh_palette;
   void setRowChanged();
   int rowChangedCnt;
   QWidget *qw_lastfocus;
   bool b_constrained;

public slots:
   void screenRecordRowChanged(const QModelIndex &current, const QModelIndex &previous);
   void screenRecordColumnChanged(const QModelIndex &current, const QModelIndex &previous);
   void focusChanged();

signals:
   void fieldEvent(Fgl::Event);
    
};

#endif
