#include "ganttTable.h"
#include "ganttnode.h"

#include <KDGanttGlobal>
#include <KDGanttStyleOptionGanttItem>
#include <KDGanttConstraintModel>
#include <KDGanttItemDelegate>
#include <QItemSelectionModel>

using namespace KDGantt;


GanttTable::GanttTable( QObject* parent ): QAbstractItemModel( parent )
{
    m_root = new Node();
}

GanttTable::~GanttTable()
{
    delete m_root;
}


int GanttTable::rowCount( const QModelIndex& parent ) const
{
    if ( parent.isValid() ) return static_cast<Node*>( parent.internalPointer() )->childCount();
    else return m_root->childCount();
}

int GanttTable::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED(parent);
    return 7;
}

QModelIndex GanttTable::index( int row, int col, const QModelIndex& parent ) const
{
    Node* node = m_root;
    if ( parent.isValid() ) {
        node = static_cast<Node*>( parent.internalPointer() );
    }
    if ( row < 0 || row >= node->childCount() ) return QModelIndex();
    else return createIndex( row, col, node->child( row ) );
}

QModelIndex GanttTable::parent( const QModelIndex& child ) const
{
    if ( !child.isValid() ) return QModelIndex();

    Node* n = static_cast<Node*>( child.internalPointer() );

    Node* node = n->getParent();
    if ( node==m_root ) return QModelIndex();

    Node* nodeParent = node->getParent();

    return createIndex( nodeParent->childIndex( node ), 0, node );
}

QVariant GanttTable::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if ( orientation != Qt::Horizontal || role != Qt::DisplayRole ) {
        return QVariant();
    }
    switch( section ) {
    case NAME:          return tr( "Name" );
    case TYPE:          return tr( "Typ" );
    case START_TIME:    return tr( "Start" );
    case END_TIME:      return tr( "Ende" );
    case COMPLETION:    return tr( "Erledigt %" );
    case TASK_NUMBER:   return tr( "Task_nr");
    case DEPEND_TASK:   return tr( "next Task" );
    default:            return QVariant();
    }
}

QVariant GanttTable::data( const QModelIndex& index, int role ) const
{
    if ( !index.isValid() ) {
        return QVariant();
    }

    Node* node = static_cast<Node*>( index.internalPointer() );

    if ( index.column() == NAME ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return node->getLabel();
        case KDGantt::TextPositionRole:
            return node->getPosition();
        }
    } else if ( index.column() == TYPE ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return qVariantFromValue<int>( node->getType() );
        }
    } else if ( index.column() == START_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
            return node->getStartTime().date().toString("dd.MM.yyyy");
        case Qt::EditRole:
        case KDGantt::StartTimeRole:
            return node->getStartTime();
        }
    } else if ( index.column() == END_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
            return node->getEndTime().date().toString("dd.MM.yyyy");
        case Qt::EditRole:
        case KDGantt::EndTimeRole:
            return node->getEndTime();
        }
    } else if ( index.column() == COMPLETION && node->getCompletion() >= 0 ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return node->getCompletion();
        }
    } else if ( index.column() == TASK_NUMBER ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return node->getTaskNr();
        }
    } else if ( index.column() == DEPEND_TASK ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return node->getDependTask();
        }
    }
    return QVariant();
}

bool GanttTable::setData( const QModelIndex& index,  const QVariant& value, int role )
{
    if ( !index.isValid() ) return false;

    Node* node = static_cast<Node*>( index.internalPointer() );

    if ( index.column() == NAME ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            node->setLabel( value.toString() );
            emit dataChanged( index, index );
            break;
        case KDGantt::TextPositionRole:
            node->setPosition( static_cast<KDGantt::StyleOptionGanttItem::Position>(value.toInt()) );
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == TYPE ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            node->setType( value.toInt() );
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == START_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        case KDGantt::StartTimeRole:
            node->setStartTime(value.toDateTime());
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == END_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        case KDGantt::EndTimeRole:
            node->setEndTime(value.toDateTime());
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == COMPLETION ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        case KDGantt::TaskCompletionRole:
            node->setCompletion(value.toInt());
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == TASK_NUMBER ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            node->setTaskNr(value.toString());
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() == DEPEND_TASK ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            node->setDependTask(value.toString());
            emit dataChanged( index, index );
            break;
        }
    }

    return true;
}

bool GanttTable::insertRows( int row, int count, const QModelIndex& parent )
{
    beginInsertRows( parent, row, row+count-1 );
    Node* node = m_root;
    if ( parent.isValid() ) node = static_cast<Node*>( parent.internalPointer() );

    for ( int i = 0; i < count; ++i ) {
        Node* new_node = new Node;
        node->insertChild( row+i, new_node );
    }
    endInsertRows();
    return true;
}

bool GanttTable::readCSV( GanttTable* model, KDGantt::View* view, QString &filename) {
    QFile datei(QDir::tempPath() + "/" + filename);
    QStringList strList;
    QHash<QString, int> currentTask, dependTask;
    QString dependString, currentString;
    //model->newRow( model, view );

    if( datei.open(QIODevice::ReadOnly)){

        while( !datei.atEnd() ) {
            QString str = QString::fromUtf8( datei.readLine() );
            strList.append( str );
        }

        if( strList.size() > 0 ) {
            view->setConstraintModel(new KDGantt::ConstraintModel(view));
            view->setSelectionModel( new QItemSelectionModel(model));
            for( int row = 0; row < strList.size(); row++ ){
                model->appendRow( model , view);
                QStringList zeilenLeiste = strList.at( row ).split( QString( "|" ));
                Node *node = new Node();

                node->setType( 1 ); // hardcoded for task
                bool ok;

                QDateTime time;

                for( int column = 0; column < zeilenLeiste.size(); column++ ) {
                    QString strWert ( zeilenLeiste.at(column).simplified());
                    if( column == 0 ) {
                        node->setLabel(strWert);
                    }
                    if( column == 1 ) {
                        node->setStartTime(time.fromString(strWert, "dd.MM.yyyy"));
                    }
                    if( column == 2 ) {
                        node->setEndTime(time.fromString(strWert, "dd.MM.yyyy"));
                    }
                    if( column == 3 ) {  // completion
                        node->setCompletion(strWert.toInt( &ok, 10));
                    }
                    if( column == 4 ) { // number of current task
                        if( strWert.toInt( &ok, 10)) {
                            node->setTaskNr( strWert );
                            currentString = strWert;
                            currentTask.insert(currentString, row);
                        }
                    }
                    if( column == 5 ) { // number of depending task
                        if( strWert.toInt( &ok, 10)) {
                            node->setDependTask( strWert );
                            dependString = strWert;
                            dependTask.insert(dependString, row);
                        }
                    }
                }
                // save to model
                model->setData(model->index(row, GanttTable::NAME, QModelIndex()),
                                                qVariantFromValue( node->getLabel() ) );
                model->setData(model->index(row, GanttTable::TYPE, QModelIndex()),
                                                qVariantFromValue( node->getType() ), KDGantt::ItemTypeRole);
                model->setData(model->index(row, GanttTable::START_TIME, QModelIndex()),
                                                qVariantFromValue( node->getStartTime() ),KDGantt::StartTimeRole);
                model->setData(model->index(row, GanttTable::END_TIME, QModelIndex()),
                                                qVariantFromValue( node->getEndTime() ),KDGantt::EndTimeRole);
                model->setData(model->index(row, GanttTable::COMPLETION, QModelIndex()),
                                                qVariantFromValue( node->getCompletion() ),KDGantt::TaskCompletionRole );
                model->setData(model->index(row, GanttTable::TASK_NUMBER, QModelIndex()),
                                                qVariantFromValue( node->getTaskNr() ) );
                model->setData(model->index(row, GanttTable::DEPEND_TASK, QModelIndex()),
                                                qVariantFromValue( node->getDependTask() ) );
            }
            //  set constraints
            QHash<QString,int>::iterator it;
            foreach(QString str, dependTask.keys()){
                for(it = currentTask.begin(); it != currentTask.end(); it++) {
                    if( str == it.key()){
                        view->constraintModel()->addConstraint(KDGantt::Constraint(model->index(dependTask.value(it.key()),0,QModelIndex()),
                                                                                   model->index(it.value(),0,QModelIndex())));
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << "Datei nicht gefunden.";
    }
    return false;
}

bool GanttTable::saveCSV(GanttTable* model, QString &filename){
    QFile datei(QDir::tempPath() + "/" + filename);
    if( datei.open(QIODevice::WriteOnly)) {

        QTextStream stream( &datei );
        QStringList strList;

        for( int row = 0; row < model->rowCount(QModelIndex()); ++row )
        {
            strList.clear();
            for( int column = 0; column < model->columnCount(QModelIndex()); ++column )
            {
                QModelIndex index = model->index(row, column, QModelIndex() );
                strList << model->data(index, Qt::DisplayRole).toString();
            }
            stream << strList.join( "|" )+"\n";
        }
        datei.close();
        return true;
    } else {
        return false;
    }
}

bool GanttTable::saveConstraintToModel(GanttTable* model, KDGantt::View* view){

    QList<Constraint> constraintList = view->constraintModel()->constraints();
    foreach( Constraint cons, constraintList){
        int startIdx = static_cast<int>(cons.startIndex().row());
        int endIdx = static_cast<int>(cons.endIndex().row());
        QModelIndex taskIdx = model->index( startIdx, TASK_NUMBER, QModelIndex());
        QModelIndex dependIdx = model->index( endIdx, DEPEND_TASK, QModelIndex());

        model->setData( taskIdx, qVariantFromValue(model->data(taskIdx, Qt::DisplayRole ) ) );
        model->setData( dependIdx, qVariantFromValue(model->data(dependIdx, Qt::DisplayRole ) ) );

    }
    return true;
}

Qt::ItemFlags GanttTable::flags( const QModelIndex& index ) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags( index );
    if( index.isValid()) {
        return flags | Qt::ItemIsEditable;
    }
    return flags;
}

QModelIndex GanttTable::indexForNode(Node *node) const
{
    if(node == m_root) {
        return QModelIndex();
    }
    int row = node->getParent()->getChildren().indexOf( node );
    int column = 0;
    return createIndex(row, column, node);
}

void GanttTable::newRow(GanttTable* model, KDGantt::View* view)
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->insertRows( 0, 1, model->index( idx.row(),0,idx.parent() ) );
    } else {
        model->insertRows( 0, 1, view->rootIndex() );
    }
}

void GanttTable::appendRow( GanttTable* model, KDGantt::View* view )
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->insertRows( model->rowCount( idx ), 1, model->index( idx.row(),0,idx.parent() ) );
    } else {
        model->insertRows( model->rowCount( view->rootIndex() ), 1, view->rootIndex() );
    }
}

ItemTypeComboBox::ItemTypeComboBox( QWidget* parent )
    : QComboBox( parent )
{
    addItem( tr( "Task" ), QVariant( KDGantt::TypeTask ) );
    addItem( tr( "Event" ), QVariant( KDGantt::TypeEvent ) );
    addItem( tr( "Summary" ), QVariant( KDGantt::TypeSummary ) );
}

KDGantt::ItemType ItemTypeComboBox::itemType() const
{
    return static_cast<KDGantt::ItemType>( itemData( currentIndex() ).toInt() );
}

void ItemTypeComboBox::setItemType( KDGantt::ItemType typ )
{
    setCurrentIndex( typ-1 );
}

MyItemDelegate::MyItemDelegate( QObject* parent )
    : KDGantt::ItemDelegate( parent )
{
}

QWidget* MyItemDelegate::createEditor( QWidget* parent,
                                       const QStyleOptionViewItem& option,
                                       const QModelIndex& idx ) const
{
    qDebug() << "MyItemDelegate::createEditor("<<parent<<idx<<")";
    if ( idx.isValid() && idx.column() == 1 )
      return new ItemTypeComboBox(parent);
    return ItemDelegate::createEditor( parent, option, idx );
}

void MyItemDelegate::setEditorData ( QWidget* editor, const QModelIndex& index ) const
{
  ItemTypeComboBox* c;
  if( (c = qobject_cast<ItemTypeComboBox*>(editor)) && index.isValid() ) {
      c->setItemType(static_cast<KDGantt::ItemType>(index.data(Qt::EditRole).toInt()));
  } else {
      ItemDelegate::setEditorData(editor,index);
  }
}

void MyItemDelegate::setModelData ( QWidget* editor, QAbstractItemModel* model,
                  const QModelIndex & index ) const
{
  ItemTypeComboBox* c;
  if( (c = qobject_cast<ItemTypeComboBox*>(editor)) && index.isValid() ) {
      model->setData(index,c->itemType());
  } else {
      KDGantt::ItemDelegate::setModelData(editor,model,index);
  }
}

void MyItemDelegate::drawDisplay( QPainter* painter, const QStyleOptionViewItem& option,
                  const QRect& rect, const QString& text ) const
{
  //qDebug() << "MyItemDelegate::drawDisplay(" <<painter<<rect<<text<<")";
  KDGantt::ItemType typ = static_cast<KDGantt::ItemType>(text.toInt());
  QString str;
  switch(typ){
      case KDGantt::TypeTask: str = tr("Task"); break;
      case KDGantt::TypeEvent: str = tr("Event"); break;
      case KDGantt::TypeSummary: str = tr("Summary"); break;
      default: str = tr("None"); break;
  }
  ItemDelegate::drawDisplay(painter,option,rect,str);
}

