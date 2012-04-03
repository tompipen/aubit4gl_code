#include "ganttnode.h"
#include <QtCore>


Node::Node( Node* parent )
    : m_parent( parent ),
      m_itemType( KDGantt::TypeTask ),
      m_startTime( QDateTime::currentDateTime() ),
      m_endTime( QDateTime::currentDateTime().addDays( 1 ) ),
      m_label( "Task" ),
      m_completion( -1 ),
      m_position( KDGantt::StyleOptionGanttItem::Right )
{
    if ( m_parent ) m_parent->addChild( this );
    qDebug()<<"new Node " << getLabel();
}

Node::~Node()
{
    qDeleteAll(m_children);
}


void Node::addChild( Node* child )
{
    child->setParent( this );
    m_children.push_back( child );
}

void Node::insertChild( int i, Node* child )
{
    child->setParent( this );
    m_children.insert( i, child );
}

void Node::removeChild( Node* child )
{
    child->setParent( 0 );
    m_children.removeAll( child );
}

int Node::childCount() {
    return m_children.count();
}

int Node::childIndex( Node* n ) {
    return m_children.indexOf( n );
}

Node* Node::child( int i ) {
    return m_children.at( i );
}

/* --------------------------------------
        setter-methods
----------------------------------------- */
void Node::setParent( Node* parent ) {
    m_parent = parent;
}

void Node::setStartTime( const QDateTime& dateTime ) {
    m_startTime = dateTime;
}

void Node::setEndTime( const QDateTime& dateTime ) {
    if ( m_endTime.isValid() )
    m_endTime = dateTime;
}

void Node::setLabel( const QString& str ) {
    m_label = str;
}

void Node::setType( int type ) {
    m_itemType = static_cast<KDGantt::ItemType>( type );
}

void Node::setCompletion( int completion ) {
    m_completion = completion;
}

void Node::setPosition( KDGantt::StyleOptionGanttItem::Position pos ) {
    m_position = pos;
}


/* --------------------------------------
        getter-methods
----------------------------------------- */
Node* Node::getParent() const {
    return m_parent;
}

QList<Node*> Node::getChildren() {
    return m_children;
}

QDateTime Node::getStartTime() const {
    return m_startTime;
}

QDateTime Node::getEndTime() const {
    return m_endTime;
}

QString Node::getLabel() const {
    return m_label;
}

KDGantt::ItemType Node::getType() const {
    return m_itemType;
}

int Node::getCompletion() const {
    return m_completion;
}

KDGantt::StyleOptionGanttItem::Position Node::getPosition() const {
    return m_position;
}
