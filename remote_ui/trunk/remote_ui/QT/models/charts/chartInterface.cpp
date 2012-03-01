#include "chartInterface.h"
#include "chartTableModel.h"
#include <KDChart/KDChartAbstractCoordinatePlane>
#include <KDChart/KDChartAbstractCartesianDiagram>
#include <KDChart/KDChartDataValueAttributes>
#include <KDChart/KDChartBackgroundAttributes>
#include <KDChart/KDChartBarDiagram>
#include <KDChart/KDChartPieDiagram>
#include <KDChart/KDChartPieAttributes>
#include <KDChart/KDChartThreeDPieAttributes>
#include <KDGantt/KDGanttGraphicsView>
#include <KDGantt/KDGanttGraphicsScene>
#include <KDChart/KDChartLineDiagram>
#include <KDChart/KDChartHeaderFooter>
#include <QPrinter>
#include <QAbstractTableModel>
#include <QDebug>
#include <QDir>

using namespace KDChart;

/*class TestModel : public QAbstractTableModel
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

}*/


ChartInterface::ChartInterface( ChartType type )
{
    if(type == DIAG_GANTT)
    {
        createGantt();
    } else {
        m_chart = createChart( type );
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
qDebug() << "CI Diagram" <<diagram;
        if(diagram)
        {
            AbstractAreaBase *baseArea = 0;
            switch(area)
            {
            case AxisX:

                baseArea = findAxis(dia, CartesianAxis::Bottom);

                break;
            case AxisY:
                baseArea = findAxis(dia, CartesianAxis::Left);

                break;
            case AxisH:
                baseArea = findAxis(dia, CartesianAxis::Top);

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
                qWarning("changeBackground: BaseArea ist nicht vorhanden");
            }


        }

    } else {
        qWarning( "changeBackground: Es ist kein Chart vorhanden");
    }

}

void ChartInterface::addLegend( Position myPosition, Legend::LegendStyle myStyle, Qt::Orientation myOrientation, const QString &myTitel)
{
    if(m_chart)
    {
        KDChart::Legend *myLegend = new KDChart::Legend(dia, m_chart );
        myLegend->setPosition(myPosition);
        myLegend->setLegendStyle(myStyle);
        myLegend->setTitleText( myTitel );

        myLegend->setOrientation( myOrientation );

        TextAttributes lta( myLegend->textAttributes() );
        lta.setPen( QPen( Qt::darkGray ) );
        Measure me( lta.fontSize() );
        me.setValue( me.value() * 1.5 );
        lta.setFontSize( Measure( 10, KDChartEnums::MeasureCalculationModeAbsolute ) );
        myLegend->setTextAttributes(  lta );

        myLegend->size();
        // adjust the legend title's font:
        lta = myLegend->titleTextAttributes();
        lta.setPen( QPen( Qt::black ) );
        me = lta.fontSize();
        me.setValue( me.value() * 1.5 );
        lta.setFontSize( me );
        myLegend->setTitleTextAttributes(  lta );

        m_chart->addLegend(myLegend);

        //qDebug()<<"addLegend " << m_chart;
    } else {
        qWarning("addLegend:  Es ist kein Chart vorhanden");
    }

}

KDChart::Chart* ChartInterface::createChart( ChartType type )
{
    Chart *newChart = new Chart;

    if(!m_chart)
    {
        m_chart = newChart;
    }

    dia = 0;
    switch ( type )
    {
        case DIAG_PIE:
            {
             dia = new KDChart::PieDiagram();
             PolarCoordinatePlane *newPlane = new PolarCoordinatePlane;
             newChart->replaceCoordinatePlane( newPlane );

            }
            break;
        case DIAG_BAR:
            {
            dia = new KDChart::BarDiagram();
            CartesianCoordinatePlane *newPlane = new CartesianCoordinatePlane;
            newChart->replaceCoordinatePlane( newPlane );
            }
            break;

        case DIAG_LINE:
            dia = new KDChart::LineDiagram();
            break;
        case DIAG_POLAR:
            break;
        case DIAG_GANTT:
            break;
        case DIAG_RING:
            break;
        case DIAG_STOCK:
            break;
        case DIAG_AREA:
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

/*ChartInterface::~ChartInterface()
{
    if ( m_chart && !m_chart->parent() )
        delete m_chart.data();
    if ( m_gantt && !m_gantt->parent() )
        delete m_gantt.data();
}*/

void ChartInterface::setModel( ChartTableModel *myModel)
{
    if(m_chart)
    {
        AbstractDiagram  *diagram =  m_chart->coordinatePlane()->diagram();
        if(diagram)
        {
            diagram->setModel(myModel);
        }
        qDebug() << "Diagramm-Model " << diagram;
    } else if (m_gantt) {
        m_gantt->setModel(myModel);
    }
    else {
        qWarning(" setModel:  Kein Chart vorhanden " );
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
            printer.setOutputFileName(QDir::tempPath() + "/" + fileName);
            QPainter painter;
            painter.begin(&printer);
            m_chart->paint(&painter, printer.pageRect());
            painter.end();



        } else {
            QPixmap pix = QPixmap(m_chart->size());
            pix.fill(Qt::white);
            QPainter painter ( &pix );
            m_chart->paint( &painter, QRect( 0, 0, pix.width(), pix.height() ) );
            qDebug()<< "gespeichert? "<<   pix.save(QDir::tempPath() + "/" + fileName);
        }

    } else if(m_gantt){
        if(fileName.endsWith(".pdf"))
        {
            QPrinter printer(QPrinter::HighResolution);
            printer.setOrientation(QPrinter::Landscape);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(QDir::tempPath() + "/" + fileName);
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
            pix.save( QDir::tempPath() + "/" + fileName);
        }

    }
}

bool ChartInterface::displayChart() {
    if(m_chart){

        BackgroundAttributes c_brush(m_chart->backgroundAttributes());
        c_brush.setBrush(Qt::white);
        m_chart->setBackgroundAttributes(c_brush);
        m_chart->setVisible(true);
        m_chart->show();
        return true;
    } else {
        qWarning(" displayChart():  Kein Chart vorhanden " );
        return false;
    }
}

bool ChartInterface::displayChart( int width, int height) {
    if(m_chart){

        m_chart->resize(width, height);
        m_chart->setVisible(true);
        m_chart->show();
        //m_chart->setBackgroundAttributes(c_brush);
        return true;
    } else {
        qWarning(" displayChart():  Kein Chart vorhanden " );
        return false;
    }
}

void ChartInterface::removeChart(KDChart::Chart *chart) {

    if(chart){
        delete chart;
    }
}


bool ChartInterface::setHeader(KDChart::Chart* chart, KDChart::Position position, ChartTableModel &model){
    HeaderFooter* header = new HeaderFooter( chart );
    header->setPosition( position );
    //header->setText( model.getTitelText() );
    chart->addHeaderFooter( header );
    return true;
}


void ChartInterface::initPie(PieDiagram *m_pie){

    ThreeDPieAttributes attrs( m_pie->threeDPieAttributes() );
    attrs.setEnabled( true );
    attrs.setDepth( 40);
    m_pie->setThreeDPieAttributes( attrs );

    PieAttributes pa( m_pie->pieAttributes() );
    pa.setExplodeFactor( 0.2 );

    m_pie->setPieAttributes( 1, pa );
   // m_pie->setPieAttributes( 0, pa );
    qDebug() << "initPie " << m_pie;
    addLegend(Position::East, Legend::MarkersAndLines, Qt::Vertical, QString("Legende"));

    DataValueAttributes dva( m_pie->dataValueAttributes() );

    TextAttributes ta( dva.textAttributes() );

    ta.setFont( QFont( "Comic", 15 ) );
    ta.setPen( QPen( QColor( Qt::black ) ) );
    ta.setVisible( true );

    dva.setTextAttributes( ta );
    dva.setVisible( true );
    dva.setDecimalDigits( 2 );
    dva.dataLabel();
    m_pie->setDataValueAttributes( dva );

}

KDChart::AbstractDiagram* ChartInterface::getDiagram(){
    return dia;
}

void ChartInterface::setDiagramColor(ChartTableModel *m_model){
    QList<QColor> bcolor;
    bcolor.append(Qt::yellow);
    bcolor.append(Qt::green);
    bcolor.append(Qt::darkRed);
    bcolor.append(Qt::lightGray);
    for (int row=0; row < m_model->columnCount(QModelIndex()); ++row) {
        this->dia->setBrush(row, QBrush(bcolor[row]));
    }
}
//#include "../chartInterface.moc"


