#ifndef GANTTTABLE_H
#define GANTTTABLE_H

#include "ganttnode.h"
#include <KDGanttView>

#include <QAbstractItemModel>
#include <QComboBox>
#include <KDGanttGlobal>
#include <KDGanttView>
#include <KDGanttItemDelegate>
#include <KDGanttDateTimeGrid>
#include <KDGanttStyleOptionGanttItem>
#include <KDGanttConstraintModel>
#include <KDGanttGraphicsView>

class GanttTable : public QAbstractItemModel {

public:
    enum GanttType{
        NAME,
        TYPE,
        START_TIME,
        END_TIME,
        COMPLETION,
        TASK_NUMBER,
        DEPEND_TASK
    };
public:
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

    bool readCSV(GanttTable* model, KDGantt::View* view, QString &filename);
    bool saveCSV(GanttTable* model, QString &filename);
    void newRow(GanttTable *model, KDGantt::View *view);
    void appendRow(GanttTable* model, KDGantt::View *view);
    void incrementColumnCount( int newColumns );
    void decrementColumnCount();
    void resetConstraintsInModel();

    Qt::ItemFlags flags( const QModelIndex& ) const;

    QModelIndex indexForNode(Node *node) const;
    bool saveConstraintToModel(GanttTable* model, KDGantt::View* view);

private:
    Node* m_root;
    int columns;      // number of columns
    static const int defaultColumns = 7;
};

class ItemTypeComboBox : public QComboBox {
    Q_OBJECT
    Q_PROPERTY( KDGantt::ItemType itemType READ itemType WRITE setItemType )
public:
    explicit ItemTypeComboBox( QWidget* parent=0 );

    KDGantt::ItemType itemType() const;
public slots:
    void setItemType( KDGantt::ItemType typ );
};

class MyItemDelegate : public KDGantt::ItemDelegate {
public:
    explicit MyItemDelegate( QObject* parent=0 );

    /*reimp*/ QWidget* createEditor( QWidget* parent,
                                     const QStyleOptionViewItem& option,
                                     const QModelIndex& idx ) const;
    /*reimp*/ void setEditorData( QWidget* editor, const QModelIndex& index ) const;
    /*reimp*/ void setModelData( QWidget* editor, QAbstractItemModel* model,
                  const QModelIndex & index ) const;
protected:
    /*reimp*/void drawDisplay( QPainter* painter, const QStyleOptionViewItem & option,
                   const QRect& rect, const QString& text ) const;
private:
    bool m_isitemtype; // Nasty!
};

#endif // GANTTTABLE_H
