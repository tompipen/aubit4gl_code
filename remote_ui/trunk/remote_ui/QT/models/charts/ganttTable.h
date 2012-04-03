#ifndef GANTTTABLE_H
#define GANTTTABLE_H

#include "ganttnode.h"
#include <KDGanttView>

#include <QAbstractItemModel>

class GanttTable : public QAbstractItemModel {

public:
    enum GanttType{
        NAME,
        TYPE,
        START_TIME,
        END_TIME,
        COMPLETION
    };

    explicit GanttTable( QObject* parent = 0 );
    ~GanttTable();

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;

    QModelIndex index( int row, int col, const QModelIndex& parent = QModelIndex() ) const;
    QModelIndex parent( const QModelIndex& child ) const;

    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    QVariant data( const QModelIndex& idx, int role = Qt::DisplayRole ) const;
    bool setData( const QModelIndex& idx,  const QVariant& value, int role = Qt::DisplayRole );
    bool insertRows( int row, int count, const QModelIndex& parent = QModelIndex() );

    bool readCSV(GanttTable* model, KDGantt::View* view, const QString &filename);
    void newRow(GanttTable *model, KDGantt::View *view);
    void appendRow(GanttTable* model, KDGantt::View *view);

    Qt::ItemFlags flags( const QModelIndex& ) const;

    QModelIndex indexForNode(Node *node) const;

private:
    Node* m_root;
};

#endif // GANTTTABLE_H
