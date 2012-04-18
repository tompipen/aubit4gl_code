#include "models/charts/ganttWidget.h"

void GanttWidget::createGanttWidget()
{
    model = new GanttTable(this);
    view = new KDGantt::View;

    view->setModel( model );
    view->setSelectionModel( new QItemSelectionModel(model));

    // slotToolsNewItem();
    view->leftView()->setItemDelegateForColumn( 1, new MyItemDelegate( this ) );
    view->leftView()->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded );

    view->graphicsView()->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded );

    view->setGrid(new KDGantt::DateTimeGrid());

    QMenuBar *mb = this->menuBar();

    QMenu *fileMenu = new QMenu( tr( "&File" ) );

    /*QAction* fileQuit =*/ fileMenu->addAction( tr( "&Quit" ), this, SLOT( slotFileQuit() ) );

    mb->addMenu( fileMenu );

    QMenu* toolsMenu = new QMenu( tr( "Tools" ) );

    toolsMenu->addAction( tr( "New Item" ), this, SLOT( slotToolsNewItem() ) );
    toolsMenu->addAction( tr( "Add Item" ), this, SLOT( slotToolsAppendItem() ) );
    toolsMenu->addSeparator();
    QMenu *alignMenu = toolsMenu->addMenu( tr( "Align" ) );
    alignMenu->addAction( tr( "Left" ), this, SLOT( slotAlignLeft() ) );
    alignMenu->addAction( tr( "Center" ), this, SLOT( slotAlignCenter() ) );
    alignMenu->addAction( tr( "Right" ), this, SLOT( slotAlignRight() ) );
    alignMenu->addAction( tr( "Hidden" ), this, SLOT( slotAlignHidden() ) );
    toolsMenu->addSeparator();
    toolsMenu->addAction( tr( "Collapse All" ), this, SLOT( slotCollapseAll() ) );
    toolsMenu->addAction( tr( "Expand All" ), this, SLOT( slotExpandAll() ) );

    mb->addMenu( toolsMenu );
    //mb->show();


    //slotToolsNewItem();
    //slotToolsNewItem();
    //slotToolsNewItem();
    for(int i = 0; i < 3; ++i) {
        model->setData(model->index(i,2,QModelIndex()), qVariantFromValue(QDateTime::currentDateTime().addDays(i)), KDGantt::StartTimeRole);
        model->setData(model->index(i,3,QModelIndex()), qVariantFromValue(QDateTime::currentDateTime().addDays(i+1)), KDGantt::EndTimeRole);
    }
    view->setConstraintModel(new KDGantt::ConstraintModel(view));
    view->constraintModel()->addConstraint(KDGantt::Constraint(model->index(0,0,QModelIndex()),model->index(1,0,QModelIndex())));
    view->constraintModel()->addConstraint(KDGantt::Constraint(model->index(1,0,QModelIndex()),model->index(2,0,QModelIndex())));
    Node *node1 = new Node();
    view->update();

    this->resize(800, 600);

    setCentralWidget(view);
}

void GanttWidget::readCsv(QString fileName)
{
    GanttTable *p_ganttTable = new GanttTable();
    p_ganttTable->readCSV(model, view, fileName);
}
void GanttWidget::closeEvent(QCloseEvent *)
{
    qDebug() << "Bin dran" << "";
    emit closeSendResponse("<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(0) + "</SV></SVS></TRIGGERED>");
    //p_fglform
    //screenhandler->fglFormResponse("<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(ganttId) + "</SV></SVS></TRIGGERED>");
}

void GanttWidget::slotFileQuit()
{
    // TODO
    //QApplication::instance()->quit();
    this->centralWidget()->close();
}

void GanttWidget::slotToolsNewItem()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        qDebug() << "GanttWidget::slotToolsNewItem" << idx;
        model->insertRows( 0, 1, model->index( idx.row(),0,idx.parent() ) );
    } else {
        model->insertRows( 0, 1, view->rootIndex() );
    }
}

void GanttWidget::slotToolsAppendItem()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        qDebug() << "GanttWidget::slotToolsAppendItem" << idx;
        model->insertRows( model->rowCount( idx ), 1, model->index( idx.row(),0,idx.parent() ) );
    } else {
        model->insertRows( model->rowCount( view->rootIndex() ), 1, view->rootIndex() );
    }
}

void GanttWidget::slotCollapseAll()
{
    // don't use the treeview's collapseAll/expandAll methods but use the one provided by the
    // view cause that one will take care to update everyt6hing as needed.
    //QTreeView* view = qobject_cast<QTreeView*>( view->leftView() );
    //view->collapseAll();

    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() )
        view->collapseAll();
}

void GanttWidget::slotExpandAll()
{
    // don't use the treeview's collapseAll/expandAll methods but use the one provided by the
    // view cause that one will take care to update everyt6hing as needed.
    //QTreeView* view = qobject_cast<QTreeView*>( view->leftView() );
    //view->expandAll();

    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() )
        view->expandAll();
}

void GanttWidget::slotAlignLeft()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->setData( idx, KDGantt::StyleOptionGanttItem::Left, KDGantt::TextPositionRole );
    }
}

void GanttWidget::slotAlignCenter()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->setData( idx, KDGantt::StyleOptionGanttItem::Center, KDGantt::TextPositionRole );
    }
}

void GanttWidget::slotAlignRight()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->setData( idx, KDGantt::StyleOptionGanttItem::Right, KDGantt::TextPositionRole );
    }
}

void GanttWidget::slotAlignHidden()
{
    QModelIndex idx = view->selectionModel()->currentIndex();
    if ( idx.isValid() ) {
        model->setData( idx, KDGantt::StyleOptionGanttItem::Hidden, KDGantt::TextPositionRole );
    }
}
