void TableView::nextfield()
{
MainFrame::vdcdebug("TableView","nextfield", "");
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->b_input){
      int currentRow = currentIndex().row();
      //int rowCount = table->rowCount(QModelIndex());

      int currentCol = currentIndex().column();
      int colCount = table->columnCount(QModelIndex());
      
      if(currentCol < colCount-1){
         QModelIndex tindex = table->index(currentRow, currentCol+1);
         QModelIndex index = proxyModel->mapFromSource(tindex);

         setCurrentIndex(index);
      }
      else{
         QModelIndex tindex = table->index(currentRow+1, 0);
         QModelIndex index = proxyModel->mapFromSource(tindex);

         setCurrentIndex(index);
      }
   }
   else{
      int currentRow = currentIndex().row();
      int rowCount = table->rowCount(QModelIndex());

      if(currentRow <= rowCount){
         selectRow(currentRow+1);
      }
   }
}

void TableView::prevfield()
{
MainFrame::vdcdebug("TableView","prevfield", "");
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->b_input){
      this->focusPreviousChild();
   }
   else{
      int currentRow = currentIndex().row();

      if(currentRow > 0){
         selectRow(currentRow-1);
      }
   }
}
