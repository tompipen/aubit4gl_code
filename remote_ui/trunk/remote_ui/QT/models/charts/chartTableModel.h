#ifndef CHARTTABLEMODEL_H
#define CHARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QVariant>

class ChartTableModel : public QAbstractTableModel {

public:
    ChartTableModel(QObject * parent = 0);
    ChartTableModel(int rows, int columns, QObject *parent = 0);
    ~ChartTableModel();

    // Implementationen von QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    bool insertRows(int row, int count, const QModelIndex &parent);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;


    bool loadData(const QString &filename);// laden aus Datei
    bool addChartData(const QString& name, const QString& wert);
    bool setData(const QModelIndex &, const QVariant&, int role);

    void setTitelText(const QString&);
    QString getTitelText();



    QStringList v_AxisText;
    QStringList h_AxisText;

private:
    int rows;
    int columns;
    QString titelText;
    QVector< QVector <QVariant> > dataVector;



};

#endif // CHARTTABLEMODEL_H
