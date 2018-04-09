#include "tagaxis.h"

TagAxis::TagAxis(QCPAxis *parentAxis) : QObject(parentAxis),
    mAxis(parentAxis)
{
    mDummyTracerY1 = new QCPItemTracer(mAxis->parentPlot());
    mDummyTracerY1->setVisible(true);
    mDummyTracerY1->position->setTypeX(QCPItemPosition::ptAxisRectRatio);//QCPItemPosition::ptPlotCoords
    mDummyTracerY1->position->setTypeY(QCPItemPosition::ptPlotCoords);
    mDummyTracerY1->position->setAxisRect(mAxis->axisRect());
    mDummyTracerY1->position->setAxes(0, mAxis);

    mLabelY1 = new QCPItemText(mAxis->parentPlot());
    mLabelY1->setLayer("overlay");
    mLabelY1->setClipToAxisRect(false);
    mLabelY1->setPadding(QMargins(3, 0, 3, 0));
    mLabelY1->setBrush(QBrush(Qt::white));
    mLabelY1->setPen(QPen(Qt::blue));
    mLabelY1->setPositionAlignment(Qt::AlignRight|Qt::AlignVCenter);
    mLabelY1->position->setTypeX(QCPItemPosition::ptAxisRectRatio);//QCPItemPosition::ptPlotCoords
    mLabelY1->position->setTypeY(QCPItemPosition::ptPlotCoords);

    mDummyTracerY2 = new QCPItemTracer(mAxis->parentPlot());
    mDummyTracerY2->setVisible(true);
    mDummyTracerY2->position->setTypeX(QCPItemPosition::ptAxisRectRatio);//QCPItemPosition::ptPlotCoords
    mDummyTracerY2->position->setTypeY(QCPItemPosition::ptPlotCoords);
   // mDummyTracerY1->position->setAxisRect(mAxis->axisRect());
   // mDummyTracerY1->position->setAxes(0, mAxis);

    mLabelY2 = new QCPItemText(mAxis->parentPlot());
    mLabelY2->setLayer("overlay");
    mLabelY2->setClipToAxisRect(false);
    mLabelY2->setPadding(QMargins(3, 0, 3, 0));
    mLabelY2->setBrush(QBrush(Qt::white));
    mLabelY2->setPen(QPen(Qt::blue));
    mLabelY2->setPositionAlignment(Qt::AlignRight|Qt::AlignVCenter);
    mLabelY2->position->setTypeX(QCPItemPosition::ptAxisRectRatio);//QCPItemPosition::ptPlotCoords
    mLabelY2->position->setTypeY(QCPItemPosition::ptPlotCoords);

    mDummyTracerX = new QCPItemTracer(mAxis->parentPlot());
    mDummyTracerX->setVisible(true);
    mDummyTracerX->position->setTypeX(QCPItemPosition::ptPlotCoords);//QCPItemPosition::ptPlotCoords
    mDummyTracerX->position->setTypeY(QCPItemPosition::ptAxisRectRatio);
//    mDummyTracerX->position->setAxisRect(mAxis->axisRect());
//    mDummyTracerX->position->setAxes(0, mAxis);

    mLabelX = new QCPItemText(mAxis->parentPlot());
    mLabelX->setLayer("overlay");
    mLabelX->setClipToAxisRect(false);
    mLabelX->setPadding(QMargins(3, 0, 3, 0));
    mLabelX->setBrush(QBrush(Qt::white));
    mLabelX->setPen(QPen(Qt::blue));
    mLabelX->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    mLabelX->position->setTypeX(QCPItemPosition::ptPlotCoords);//QCPItemPosition::ptPlotCoords
    mLabelX->position->setTypeY(QCPItemPosition::ptAxisRectRatio);
}
TagAxis::~TagAxis()
{
    if (mDummyTracerY1)
        mDummyTracerY1->parentPlot()->removeItem(mDummyTracerY1);
    if (mLabelY1)
        mLabelY1->parentPlot()->removeItem(mLabelY1);

    if (mDummyTracerY2)
        mDummyTracerY2->parentPlot()->removeItem(mDummyTracerY2);
    if (mLabelY2)
        mLabelY2->parentPlot()->removeItem(mLabelY2);

    if (mDummyTracerX)
        mDummyTracerX->parentPlot()->removeItem(mDummyTracerX);
    if (mLabelX)
        mLabelX->parentPlot()->removeItem(mLabelX);
}

void TagAxis::setPen(const QPen &pen)
{
  mLabelY1->setPen(pen);
  mLabelY2->setPen(pen);
  mLabelX->setPen(pen);
}

void TagAxis::setBrush(const QBrush &brush)
{
  mLabelY1->setBrush(brush);
  mLabelY2->setBrush(brush);
  mLabelX->setBrush(brush);
}

void TagAxis::setTextY1(const QString &text)
{
  mLabelY1->setText(text);
}

void TagAxis::setTextY2(const QString &text)
{
  mLabelY2->setText(text);
}

void TagAxis::setTextX(const QString &text)
{
  mLabelX->setText(text);
}

void TagAxis::updatePosition(double valueY1,double valueY2,double valueX)
{
    mDummyTracerY1->position->setCoords(0, valueY1);
    mLabelY1->position->setCoords(0,valueY1);

    mDummyTracerY2->position->setCoords(0, valueY2);
    mLabelY2->position->setCoords(0,valueY2);

    mDummyTracerX->position->setCoords(valueX,1);
    mLabelX->position->setCoords(valueX,1);
}
