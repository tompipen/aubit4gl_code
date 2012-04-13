#ifndef NODE_H
#define NODE_H

#include <QtCore>
#include <KDGanttGlobal>
#include <KDGanttStyleOptionGanttItem>

class Node  {

public:

    Node( Node* parent = 0 );
    ~Node();

    void addChild( Node* );
    void insertChild( int i, Node* );
    void removeChild( Node* );

    int childCount();
    int childIndex( Node* n );

    Node* child( int i );

    void setParent( Node* parent ) ;

    void setStartTime( const QDateTime& dateTime ) ;
    void setEndTime( const QDateTime& dateTime );
    void setLabel( const QString& str ) ;
    void setType( int type ) ;
    void setCompletion( int completion ) ;
    void setPosition( KDGantt::StyleOptionGanttItem::Position pos ) ;
    void setTaskNr( const QString& str);
    void setDependTask( const QString& str);

    void addDependList( const QString& str);
    void insertDependList (int index, const QString& str);
    void clearDependList();

    Node* getParent() const;
    QList<Node*> getChildren();

    QDateTime getStartTime() const;
    QDateTime getEndTime() const;
    QString   getLabel() const;
    KDGantt::ItemType getType() const;
    int getCompletion() const;
    KDGantt::StyleOptionGanttItem::Position getPosition() const ;
    QString   getTaskNr() const;
    QString   getDependTask() const;
    QList<QString> getDependList() const;

private:
    Node* m_parent;
    QList<Node*> m_children;
    KDGantt::ItemType m_itemType;
    QDateTime m_startTime, m_endTime;
    QString m_label;
    int m_completion;
    QString m_taskNr, m_dependTask;
    KDGantt::StyleOptionGanttItem::Position m_position;
    QList<QString> m_dependList;

};

#endif // NODE_H
