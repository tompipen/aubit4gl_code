#ifndef CHARTINTERFACE_H
#define CHARTINTERFACE_H
#include <KDChart/KDChartChart.h>
#include <KDChart/KDChartCartesianAxis.h>
#include <KDChart/KDChartMarkerAttributes.h>
#include <KDChart/KDChartLegend.h>
#include <KDChart/KDChartPosition.h>
#include <KDChart/KDChartAbstractDiagram>
#include <KDChart/KDChartBarDiagram>
#include <KDChart/KDChartPieDiagram>
#include <KDChart/KDChartWidget>
#include <QAbstractItemModel>
#include <QPointer>
#include <QGraphicsView>
#include <KDGantt/KDGanttGraphicsView>
#include "chartTableModel.h"


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
        DIAG_PIE,
        DIAG_GANTT,
        DIAG_BAR,
        DIAG_LINE,
        DIAG_POLAR,
        DIAG_RING,
        DIAG_STOCK,
        DIAG_AREA
    };

    ChartInterface( ChartType type );
    ~ChartInterface();

    KDChart::Chart* chart() const;
    KDGantt::GraphicsView* GanttChart() const;
    KDChart::AbstractDiagram* getDiagram();

    void createGantt();
    bool displayChart();
    bool displayChart(int width, int height);
    void initPie(KDChart::PieDiagram *m_pie );
    void initBar(KDChart::BarDiagram *m_bar );
    static void removeChart(KDChart::Chart* );

    void setModel (ChartTableModel *myModel);
    bool setHeader(KDChart::Chart*, KDChart::Position, ChartTableModel&);

    void saveAs(const QString& fileName);

    void addAxis( KDChart::CartesianAxis::Position );
    void addLegend (KDChart::Position, KDChart::Legend::LegendStyle, Qt::Orientation, const QString& );

    void changeBackground( const QBrush&, ChartArea );
    void setDiagramColor(ChartTableModel *);
    void changeColor(int reihe, int feld, const QPen&, const QBrush& );
    void changeColor( int reihe, const QPen&, const QBrush& );

    void changeMarker( int position, const KDChart::MarkerAttributes& );
    void changeMarker( int position, int feld, const KDChart::MarkerAttributes& );

    void set3D(int depth, ChartType type);




protected:
    KDChart::Chart* createChart( ChartType );
    QPointer< KDChart::Chart> m_chart;
    QPointer< KDGantt::GraphicsView> m_gantt;
    KDChart::AbstractDiagram *dia;
public slots:
    void createChart123(ChartType);


};

#endif // CHARTINTERFACE_H
