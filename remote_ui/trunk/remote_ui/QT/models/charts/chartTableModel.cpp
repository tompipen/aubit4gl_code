#include "chartTableModel.h"
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <iostream>

ChartTableModel::ChartTableModel(int rows, int columns, QObject *parent) : QAbstractTableModel(parent), columns(columns)
{
   this->rows = 0;
   for(int i=0; i<rows; i++){
      insertRows(i, 1, QModelIndex());
   }

}


ChartTableModel::ChartTableModel(QObject *parent):QAbstractTableModel(parent){

}

ChartTableModel::~ChartTableModel(){

}

int ChartTableModel::columnCount(const QModelIndex &parent) const {
    if (dataVector.isEmpty()) {
        return(0);
    } else {
        return(dataVector[0].size());
    }
}

int ChartTableModel::rowCount(const QModelIndex &parent) const {
    return(dataVector.size());
}

QVariant ChartTableModel::data(const QModelIndex &index, int role) const {
    if( role == Qt::DisplayRole || role == Qt::EditRole ) {
        return dataVector[index.row()][index.column()];
    } else {
        return QVariant();
    }
}

QVariant ChartTableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
    QVariant axis_text;

    if (role == Qt::DisplayRole){
        if( orientation == Qt::Horizontal){
            axis_text = this->h_AxisText[section];
        } else {
            axis_text = this->v_AxisText[section];
        }
    }
    return axis_text;
}


void ChartTableModel::setTitelText(const QString& text){
    titelText = text;
}


QString ChartTableModel::getTitelText(){
    return titelText;
}


bool ChartTableModel::loadData( const QString &filename ) {
    QFile datei(filename);
    QStringList strList;


    if( datei.open(QIODevice::ReadOnly)){

        while( !datei.atEnd() ) {
            QString str = QString::fromUtf8( datei.readLine() );
            strList.append( str );
            qDebug() << str << "size: " << strList.size() << endl;
        }

        if( strList.size() > 0 ) {
             this->dataVector.resize ( strList.size() - 1 ); // minus horizontal header

            for( int row = 0; row < strList.size(); row++ ){
                QStringList zeilenLeiste = strList.at( row ).split( QString( "," ));// Zeile zerteilen

                QVector<QVariant> werteVector( zeilenLeiste.size()-1 ); // minus vertical header

                for( int column = 0; column < zeilenLeiste.size(); column++ ) {
                    QString strWert ( zeilenLeiste.at(column).simplified());

                    if(row == 0){ // horizontale row headers
                        if(column == 0){
                            setTitelText(strWert);
                        } else {
                            this->h_AxisText.append(strWert);
                        }
                    } else {
                        if ( column == 0 )
                        {   // vertikale row headers
                            this->v_AxisText.append( strWert );
                        } else {
                            // interpret cell values as floating point:
                            bool Ok = false;

                            double datenWert = strWert.toDouble( &Ok );
                            qDebug() << Ok;
                            if(Ok){ // konvertiert zu double
                                qDebug() << " QVariant: " << QVariant(datenWert);
                                werteVector[column-1] = QVariant(datenWert);
                                qDebug() << "Vector: "<< row <<" " << werteVector;
                            } else {
                                werteVector[column-1] = QVariant(strWert);

                            }
                        }
                    }

                }
                if( row > 0 ){
                    this->dataVector[row -1 ] = werteVector;
                    qDebug() << "datavektor:" << dataVector;
                }
            }

        reset();
        }
        return true;
    } else {
        return false;  //Dateifehler
    }

} // loadData


/*--------------------------------------------
  adding data to the table

  first vector "name" is the column-header
  both vectors should have the same length
---------------------------------------------*/
bool ChartTableModel::addChartData(const QVector<QVariant>& name, const QVector<QVariant>& wert )
{
    if(!name.isEmpty()){     // header
        this->h_AxisText.clear();
        for(int column = 0; column < name.size(); column++) {
            this->h_AxisText.append( name[column].toString() );
        }
        if(addChartData( wert ) ){    // datarow
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


/*-------------------------------------------------
  adding a row of data to the table

  first element of the vector is the row-header
---------------------------------------------------*/
bool ChartTableModel::addChartData(const QVector<QVariant> &wert)
{
    if(!wert.isEmpty())
    {
        QVector<QVariant> temp;
        for(int column = 0; column < wert.size(); column++)
        {
            if(column == 0){         // first element for header
                this->v_AxisText.append( wert.at(column).toString() );
            } else {
                temp.append(wert.at(column).toString());
            }
        }
        int size = this->dataVector.size();
        this->dataVector.resize( size + 1);
        this->dataVector[size] = temp;

        return true;
    } else {
        return false;
    }
}




bool ChartTableModel::addChartData(const QString& name, const QString& wert) {


    int rows = rowCount(QModelIndex());
    qDebug()<< "addChartData:  int rows "<< rows;

    if (insertRows(rows, 1, QModelIndex())) {
            this->v_AxisText.append(name);
        qDebug()<<"rowCount neu"<< rowCount();
           // this->dataVector[rows][0] = name;
           // qDebug()<< " name "<< this->dataVector[rows][0];
        qDebug()<< "dataVector " << dataVector;
            this->dataVector[rows][0] = wert;
            qDebug()<< " wert "<< this->dataVector[rows][0];
             qDebug()<< "dataVector " << dataVector;
            return true;
        } else {
            return false;
        }

}


bool ChartTableModel::insertRows(int position, int count, const QModelIndex &parent){

    int rows = dataVector.size();

    if(rows >= 0){
       //rows += count;
        qDebug()<<"insertRows " << rows;
        //dataVector.resize(dataVector.size() + count);
       beginInsertRows(QModelIndex(), position, position+count-1);

       for(int row=0; row < count; row++){
          qDebug() << "for insertRows " << dataVector.size();
          QVector<QVariant> colValues;
          int colCount = columnCount(QModelIndex());
          if(colCount ==0){
              colCount = 2;
          }

          for(int col=0; col < colCount; col++){
             colValues.insert(col, "");
          }
          qDebug() << "colValues " << colValues;
          this->dataVector.insert(rows, colValues);
          qDebug() << "insertRows nach insert " << dataVector.size();
       }

       endInsertRows();
       return true;
    }
    return false;

}

bool ChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && ( role == Qt::EditRole || role == Qt::DisplayRole ))
    {
       int row = index.row();
       int column = index.column();

       this->dataVector[row][column] = value.toString();
       emit dataChanged(index, index);
       return true;
    }
    return false;
}

void ChartTableModel::clear()
{
    this->dataVector.clear();
}
