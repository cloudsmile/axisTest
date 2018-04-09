#ifndef TAGAXIS_H
#define TAGAXIS_H

#include <QObject>
#include "qcustomplot.h"

class TagAxis : public QObject
{
    Q_OBJECT
public:
    explicit TagAxis(QCPAxis *parentAxis);
    virtual ~TagAxis();

    // setters:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setTextY1(const QString &text);
    void setTextY2(const QString &text);
    void setTextX(const QString &text);

    void updatePosition(double valueY1,double valueY2,double valueX);

signals:

public slots:

protected:
    QCPAxis *mAxis;
    int yAxisCount;
    QPointer<QCPItemTracer> mDummyTracerY1;
    QPointer<QCPItemText> mLabelY1;
    QPointer<QCPItemTracer> mDummyTracerY2;
    QPointer<QCPItemText> mLabelY2;
    QPointer<QCPItemTracer> mDummyTracerX;
    QPointer<QCPItemText> mLabelX;
};

#endif // TAGAXIS_H
