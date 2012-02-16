#include "models/chartInterface.h"
#include <KDChart/KDChartAbstractCoordinatePlane>
#include <KDChart/KDChartAbstractCartesianDiagram>
#include <KDChart/KDChartDataValueAttributes>
#include <KDChart/KDChartBackgroundAttributes>
#include <KDChart/KDChartBarDiagram>
#include <KDChart/KDChartPieDiagram>
#include <KDGantt/KDGanttGraphicsView>
#include <KDGantt/KDGanttGraphicsScene>
#include <KDChart/KDChartLineDiagram>
#include <QPrinter>
#include <QAbstractTableModel>

using namespace KDChart;

class TestModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TestModel( QObject *parent = 0 );
    virtual int rowCount(const QModelIndex&) const;
    virtual int columnCount(const QModelIndex&) const;
    virtual int insertRow(int row, const QModelIndex &parent);
    virtual QVariant data(const QModelIndex&, int) const;
};

int TestModel::rowCount(const QModelIndex& index ) const
{
    if ( index.isValid() )
        return 0;
    return 5;
}
int TestModel::columnCount(const QModelIndex& index ) const
{
    if ( index.isValid() )
        return 0;
    return 2;
}
int TestModel::insertRow(int row, const QModelIndex &parent)
{
    beginInsertRows(parent, 2, 3);

    return 0;

}
QVariant TestModel::data(const QModelIndex& index, int role ) const
{
    if ( role == Qt::DisplayRole )
    {
        qDebug() << index.row();
        if ( !index.isValid() )
            return QVariant();
        else
            return index.row()+1;
    }
    else
        return QVariant();
}

TestModel::TestModel( QObject *parent )
    : QAbstractTableModel( parent )
{

}


ChartInterface::ChartInterface( ChartType type )
{
    if(type == Gantt)
    {
        createGantt();
    } else {
        m_chart = createChart( type );
        setModel( new TestModel());
    }

}

KDChart::Chart* ChartInterface::chart() const
{
    return m_chart.data();
}

KDGantt::GraphicsView* ChartInterface::GanttChart() const
{
    return m_gantt.data();
}

void ChartInterface::addAxis( KDChart::CartesianAxis::Position position )
{
    if(m_chart) {
        if(m_chart->coordinatePlane()->diagram() != NULL)
        {
            AbstractCartesianDiagram* dia = dynamic_cast<AbstractCartesianDiagram*> (m_chart->coordinatePlane()->diagram());

            if( dia )
            {
                CartesianAxis *axis = new CartesianAxis( dia );
                axis->setPosition(position);
                dia->addAxis(axis);

            } else {
                qWarning( "Das Diagramm ist kein Cartesian Diagramm.");
            }

        } else {

            qWarning( "Es ist kein Diagramm vorhanden");

        }
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }

}

void ChartInterface::changeColor( int reihe, int feld, const QPen& myPen , const QBrush& myBrush )
{
    if(m_chart)
    {
        AbstractDiagram *diagram = m_chart->coordinatePlane()->diagram();
        if(diagram)
        {
            if(diagram->model())
            {
                const QModelIndex diagIndex = diagram->model()->index(reihe, feld);

                diagram->setBrush(diagIndex, myBrush);
                diagram->setPen(diagIndex, myPen);

            }

        } else {
            qWarning() << "Es ist kein Diagramm vorhanden";
        }
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }

}

void ChartInterface::changeColor( int reihe, const QPen& myPen, const QBrush& myBrush )
{
    if(m_chart) {
        AbstractDiagram *diagram = m_chart->coordinatePlane()->diagram();
        if(diagram)
        {

            diagram->setBrush(reihe, myBrush);
            diagram->setPen(reihe, myPen);

        } else {
            qWarning() << "Es ist kein Diagramm vorhanden";
        }
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }

}
void ChartInterface::changeMarker( int position, const KDChart::MarkerAttributes&  marker)
{
    if(m_chart) {
        AbstractDiagram *diagram = m_chart->coordinatePlane()->diagram();
        if(diagram)
        {
            DataValueAttributes attributes = diagram->dataValueAttributes(position);

            if(marker.isVisible())
            {
                diagram->dataValueAttributes().setVisible(true);
            }

            attributes.setMarkerAttributes(marker);
            diagram->setDataValueAttributes(position, attributes);


        } else {
            qWarning() << "Es ist kein Diagramm vorhanden";
        }
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }



}
void ChartInterface::changeMarker( int position, int feld, const KDChart::MarkerAttributes& marker )
{
    if(m_chart)
    {
        AbstractDiagram *diagram = m_chart->coordinatePlane()->diagram();
        if(diagram)
        {
            if(diagram->model())
            {
                const QModelIndex diagIndex = diagram->model()->index(position, feld);

                DataValueAttributes attributes = diagram->dataValueAttributes(diagIndex);

                if(marker.isVisible())
                {
                    diagram->dataValueAttributes().setVisible(true);
                }

                attributes.setMarkerAttributes(marker);
                diagram->setDataValueAttributes(diagIndex, attributes);
            }

        } else {
            qWarning() << "Es ist kein Diagramm vorhanden";
        }
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }

}

static CartesianAxis* findAxis(AbstractCartesianDiagram *diag, CartesianAxis::Position position)
{

    CartesianAxis *result = 0;
    foreach( CartesianAxis *item, diag->axes())
    {
        if( item->position() == position )
        {
            result = item;
        }

    }
    return result;
}

void ChartInterface::changeBackground( const QBrush& myBrush, ChartArea area )
{
    if(m_chart)
    {
        AbstractDiagram *diagram = m_chart->coordinatePlane()->diagram();
        AbstractCartesianDiagram* dia = dynamic_cast<AbstractCartesianDiagram*> (m_chart->coordinatePlane()->diagram());

        if(diagram)
        {
            AbstractAreaBase *baseArea = 0;
            switch(area)
            {
            case AxisX:

                baseArea = findAxis(dia, CartesianAxis::Bottom);

                break;
            case AxisY:
                baseArea = findAxis(dia, CartesianAxis::Top);

                break;
            case AxisH:
                baseArea = findAxis(dia, CartesianAxis::Left);

                break;
            case AxisV:
                baseArea = findAxis(dia, CartesianAxis::Right);

                break;
            case Legend:
                baseArea = m_chart->legend();

                break;
            case CoordinatePlane:
                baseArea = m_chart->coordinatePlane();

                break;

            }
            if(baseArea)
            {

                BackgroundAttributes bgattributes = baseArea->backgroundAttributes();
                bgattributes.setBrush(myBrush);
                baseArea->setBackgroundAttributes(bgattributes);

            } else {
                qWarning("BaseArea ist nicht vorhanden");
            }


        }

    } else {
        qWarning( "Es ist kein Chart vorhanden");
    }

}

void ChartInterface::addLegend( Position myPosition, Legend::LegendStyle myStyle )
{
    if(m_chart)
    {
        KDChart::Legend *myLegend = new KDChart::Legend( m_chart );
        myLegend->setPosition(myPosition);
        myLegend->setLegendStyle(myStyle);
        m_chart->addLegend(myLegend);
    } else {
        qWarning("Es ist kein Chart vorhanden");
    }

}

KDChart::Chart* ChartInterface::createChart( ChartType type )
{
    Chart *newChart = new Chart;
    AbstractDiagram *dia = 0;
    switch ( type )
    {
        case PieDiagram:
            {
             dia = new KDChart::PieDiagram();
             PolarCoordinatePlane *newPlane = new PolarCoordinatePlane;
             newChart->replaceCoordinatePlane( newPlane );
            }
            break;

        case BarDiagram:
            dia = new KDChart::BarDiagram();
            break;

        case LineDiagram:
            dia = new KDChart::LineDiagram();
            break;
    default:
        break;
    }

    if(dia)
    {
        newChart->coordinatePlane()->replaceDiagram(dia);
    }

    return newChart;

}

ChartInterface::~ChartInterface()
{
    if ( m_chart && !m_chart->parent() )
        delete m_chart.data();
    if ( m_gantt && !m_gantt->parent() )
        delete m_gantt.data();
}

void ChartInterface::setModel( QAbstractItemModel *myModel)
{
    if(m_chart)
    {
        AbstractDiagram  *diagram =  m_chart->coordinatePlane()->diagram();
        if(diagram)
        {
            diagram->setModel(myModel);
        }
    } else if (m_gantt) {
        m_gantt->setModel(myModel);
    }
    else {
        qWarning(" Kein Chart vorhanden " );
    }

}

void ChartInterface::createGantt()
{
    m_gantt = new KDGantt::GraphicsView();

}

void ChartInterface::saveAs(const QString &fileName)
{
    if(m_chart)
    {
        if(fileName.endsWith(".pdf"))
        {
            QPrinter printer(QPrinter::HighResolution);
            printer.setOrientation(QPrinter::Landscape);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);
            QPainter painter;
            painter.begin(&printer);
            m_chart->paint(&painter, printer.pageRect());
            painter.end();



        } else {
            QPixmap pix = QPixmap(m_chart->size());
            QPainter painter ( &pix );
            m_chart->paint( &painter, QRect( 0, 0, pix.width(), pix.height() ) );
            pix.save(fileName);
        }

    } else if(m_gantt){
        if(fileName.endsWith(".pdf"))
        {
            QPrinter printer(QPrinter::HighResolution);
            printer.setOrientation(QPrinter::Landscape);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);
            printer.setPaperSize(QPrinter::A4);
            QPainter painter;
            painter.begin(&printer);
            m_gantt->render(&painter, printer.paperRect());
            //m_gantt->scene()->render();
            //m_gantt->paint(&painter, printer.pageRect());
            painter.end();



        } else {
            QPixmap pix = QPixmap(m_gantt->size());
            QPainter painter ( &pix );
            m_gantt->scene()->render( &painter, QRect( 0, 0, pix.width(), pix.height() ));
            pix.save(fileName);
        }

    }
}

#include "../chartInterface.moc"


