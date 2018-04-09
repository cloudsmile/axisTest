#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mPlot(0),
//    mTag1(0),
//    mTag2(0),
    tagAxis(0)
{
    ui->setupUi(this);
    mPlot = new QCustomPlot(this);
    setCentralWidget(mPlot);
    //mPlot->legend->setVisible(true);

    // configure plot to have two right axes:
    //mPlot->yAxis->setTickLabels(false);
    connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis2, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    mPlot->yAxis2->setVisible(true);
    //      mPlot->axisRect()->addAxis(QCPAxis::atRight);
    //      mPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(0); // add some padding to have space for tags
    //      mPlot->axisRect()->axis(QCPAxis::atRight, 1)->setPadding(10); // add some padding to have space for tags

    // create graphs:
//    mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
//    mGraph2 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
//    mGraph1->setPen(QPen(QColor(250, 120, 0)));
//    mGraph2->setPen(QPen(QColor(0, 180, 60)));

    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
   // mTag1 = new AxisTag(mGraph1->valueAxis());
//    mTag1->setPen(mGraph1->pen());
    //      mTag2 = new AxisTag(mGraph2->valueAxis());
    //      mTag2->setPen(mGraph2->pen());

    //      connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    //      mDataTimer.start(400);
    mPlot->addGraph();
    mPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    mPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    mPlot->addGraph();
    mPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):

    tagAxis = new TagAxis(mPlot->graph(0)->valueAxis());
    tagAxis->setPen(mPlot->graph(0)->pen());

    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    mPlot->xAxis2->setVisible(true);
    mPlot->xAxis2->setTickLabels(false);
    mPlot->yAxis2->setVisible(true);
    mPlot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(mPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), mPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(mPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    mPlot->graph(0)->setData(x, y0);
    mPlot->graph(1)->setData(x, y1);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    mPlot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    mPlot->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    mPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    tagAxis->setTextY1("-0.3");
    tagAxis->setTextY2("0.6");
    tagAxis->setTextX("125");
    tagAxis->updatePosition(-0.3,0.6,125);

    mPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot()
{
  // calculate and add a new data point to each graph:
  mGraph1->addData(mGraph1->dataCount(), qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);
  mGraph2->addData(mGraph2->dataCount(), qCos(mGraph2->dataCount()/50.0)+qSin(mGraph2->dataCount()/50.0/0.4364)*0.15);

  // make key axis range scroll with the data:
  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);
  mGraph2->rescaleValueAxis(false, true);
  mPlot->xAxis->setRange(mPlot->xAxis->range().upper, 100, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
//  double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
//  double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    double graph1Value = mGraph1->dataCount()-1;
    double graph2Value = mGraph2->dataCount()-1;
 // mTag1->updatePosition(graph1Value);
 // mTag2->updatePosition(graph2Value);
 // mTag1->setText(QString::number(graph1Value, 'f', 2));
 // mTag2->setText(QString::number(graph2Value, 'f', 2));

  mPlot->replot();
}
