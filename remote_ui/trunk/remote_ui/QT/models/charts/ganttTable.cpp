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
    columns = defaultColumns;
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
    return columns;
}

void GanttTable::incrementColumnCount(int newColumns){
    columns += newColumns;
}

void GanttTable::decrementColumnCount(){
    columns--;
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
    case PARENT:        return tr( "Parent" );
    case DEPEND_TASK:   return tr( "Depend" );
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
            return node->getType();
        }
    } else if ( index.column() == START_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
            return node->getStartTime().toString("dd.MM.yyyy hh:mm");
        case Qt::EditRole:
        case KDGantt::StartTimeRole:
            return node->getStartTime();
        }
    } else if ( index.column() == END_TIME ) {
        switch( role ) {
        case Qt::DisplayRole:
            return node->getEndTime().toString("dd.MM.yyyy hh:mm");
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
    } else if ( index.column() == PARENT ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return node->getParentNr();
        }
    } else if ( index.column() >= DEPEND_TASK ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            int dependListIdx = index.column() - DEPEND_TASK; // an index in dependList
            QVariant value = "";
            QList<QString> list = node->getDependList();
            if ( list.size() > 0 && dependListIdx <= list.size() -1) {
                value = qVariantFromValue(list.at( dependListIdx ) );
            }
            return value;
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
        case KDGantt::ItemTypeRole:
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
            int wert = value.toInt();
            if(wert <= 0){
                wert = -1;
            }
            node->setCompletion(wert);
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
    } else if ( index.column() == PARENT ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            node->setParentNr(value.toString());
            emit dataChanged( index, index );
            break;
        }
    } else if ( index.column() >= DEPEND_TASK ) {
        switch( role ) {
        case Qt::DisplayRole:
        case Qt::EditRole:
            QList<QString> list = node->getDependList();
            if( value.toString() != "" && !list.contains(value.toString())) {
                node->addDependList(value.toString());
                emit dataChanged( index, index );
            }
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
                Node::nodeCount++;
                QStringList zeilenLeiste = strList.at( row ).split( QString( "|" ));
                QList<QString> dependList;
                Node *node = new Node();
                bool ok;

                QDateTime time;

                for( int column = 0; column < zeilenLeiste.size(); column++ ) {
                    QString strWert ( zeilenLeiste.at(column).simplified());
                    if( column == NAME ) {
                        node->setLabel(strWert);
                    }
                    if( column == TYPE ) {
                        node->setType(strWert.toInt());
                    }
                    if( column == START_TIME ) {

                        node->setStartTime(time.fromString(strWert, "dd.MM.yyyy hh:mm"));
                    }
                    if( column == END_TIME ) {
                        node->setEndTime(time.fromString(strWert, "dd.MM.yyyy hh:mm"));
                    }
                    if( column == COMPLETION ) {
                        node->setCompletion(strWert.toInt( &ok, 10));
                    }
                    if( column == TASK_NUMBER ) {
                        if( strWert.toInt( &ok, 10)) {
                            node->setTaskNr( strWert );
                            currentTask.insert( strWert, row);
                        }
                    }
                    if( column == PARENT ) {
                        node->setParentNr(strWert);
                    }
                    if( column >= DEPEND_TASK ) {
                        if( strWert.toInt( &ok, 10)) {
                            dependTask.insertMulti( strWert, row );
                            dependList.append( strWert);
                        }
                    }
                }
                // save node to model
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
                model->setData(model->index(row, GanttTable::PARENT, QModelIndex()),
                               qVariantFromValue( node->getParentNr() ) );
                for( int i = 0; i < dependList.size() ; i++ ){
                    model->setData(model->index(row, GanttTable::DEPEND_TASK + i, QModelIndex()),
                                   qVariantFromValue( dependList.at( i ) ) );
                }
            }
            //  set constraints to constraintModel
            QHash<QString,int>::iterator it;
            for(it = dependTask.begin(); it != dependTask.end(); it++) {
                int taskIdx = it.value();
                int dependIdx = currentTask.value( it.key() );
                view->constraintModel()->addConstraint(KDGantt::Constraint(model->index(taskIdx,0,QModelIndex()),
                                                                           model->index(dependIdx,0,QModelIndex())));
            }
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << " file not found ";
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


/*--------------------------------------------------------------
     because tasks and constraints have not the same model
     you have to use this method before saving to reflect
     the changing of constraints
  --------------------------------------------------------------*/
bool GanttTable::saveConstraintToModel(GanttTable* model, KDGantt::View* view){

    int dependCounter = 1;   // needed for index when there are multiple constraints
    QMap<int, int> constraintMap; // multiple values for each constraint possible
    QList<Constraint> constraintList = view->constraintModel()->constraints();

    foreach( Constraint cons, constraintList){           // fill constraintMap
        int startIdx = static_cast<int>(cons.startIndex().row());
        int endIdx = static_cast<int>(cons.endIndex().row());
        constraintMap.insertMulti(startIdx, endIdx);

    }

    foreach( Constraint cons, constraintList){
        int startIdx = static_cast<int>(cons.startIndex().row());
        int endIdx = static_cast<int>(cons.endIndex().row());

        QModelIndex dependDataIdx = model->index(endIdx, TASK_NUMBER, QModelIndex());
        QVariant dependData = qVariantFromValue(model->data(dependDataIdx, Qt::DisplayRole ) );

        int numberOfConstraints = constraintMap.count( startIdx );
        if( numberOfConstraints >= 0 ){
            int currentColumns = model->columnCount( QModelIndex() );
            int neededColumns = ( DEPEND_TASK ) + numberOfConstraints;

            if( currentColumns < neededColumns){  // insert columns if additional columns are needed
                int numberOfNeededColumns = neededColumns - currentColumns;
                model->insertColumns( currentColumns, numberOfNeededColumns );
                incrementColumnCount( numberOfNeededColumns );
            }

            QModelIndex taskDependIdx = model->index( startIdx, DEPEND_TASK + dependCounter, QModelIndex());
            model->setData( taskDependIdx, dependData );
            dependCounter++;

        } else {
            dependCounter=1; // reset dependCounter
        }
    }
    return true;
}

// clear m_dependList for every row
void GanttTable::resetConstraintsInModel(){

    for( int i = 0; i < this->rowCount(QModelIndex()); i++){
            QModelIndex index = this->index(i,0);
            Node* node = static_cast<Node*>( index.internalPointer() );
            node->clearDependList();
    }
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
    addItem( tr( "Multi") , QVariant( KDGantt::TypeMulti ) );
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

