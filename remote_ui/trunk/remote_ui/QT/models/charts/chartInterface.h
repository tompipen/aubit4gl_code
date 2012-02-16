#ifndef CHARTINTERFACE_H
#define CHARTINTERFACE_H
#include <KDChart/KDChartChart.h>
#include <KDChart/KDChartCartesianAxis.h>
#include <KDChart/KDChartMarkerAttributes.h>
#include <KDChart/KDChartLegend.h>
#include <KDChart/KDChartPosition.h>
#include <QAbstractItemModel>
#include <QPointer>
#include <QGraphicsView>
#include <KDGantt/KDGanttGraphicsView>


class ChartInterface
{


public:
    enum ChartArea{
        AxisX,
        AxisY,
        AxisH, // unten x axe
        AxisV, //oben x axe
        Legend,
        CoordinatePlane

    };

    enum ChartType {
        PieDiagram,
        Gantt,
        BarDiagram,
        LineDiagram

    };
    ChartInterface( ChartType type );
    ~ChartInterface();

    KDChart::Chart* chart() const;
    KDGantt::GraphicsView* GanttChart() const;

    void addAxis( KDChart::CartesianAxis::Position );
    void changeColor(int reihe, int feld, const QPen&, const QBrush& );
    void changeColor( int reihe, const QPen&, const QBrush& );
    void changeMarker( int position, const KDChart::MarkerAttributes& );
    void changeMarker( int position, int feld, const KDChart::MarkerAttributes& );
    void changeBackground( const QBrush&, ChartArea );
    void addLegend (KDChart::Position, KDChart::Legend::LegendStyle );
    void setModel (QAbstractItemModel *myModel);

    void saveAs(const QString& fileName);

    void createGantt();

protected:
    KDChart::Chart* createChart( ChartType );

private:
    QPointer< KDChart::Chart> m_chart;
    QPointer< KDGantt::GraphicsView> m_gantt;










};

#endif // CHARTINTERFACE_H
