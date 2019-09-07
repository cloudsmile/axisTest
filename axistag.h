#ifndef AXISTAG_H
#define AXISTAG_H

#include <QObject>
#include "qcustomplot.h"




class AxisTag : public QObject
{
    Q_OBJECT
public:
    explicit AxisTag(QCPAxis *parentAxis);
    virtual ~AxisTag();
    //explicit AxisTag(QObject *parent = 0);

    // setters:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setText(const QString &text);

    // getters:
    QPen pen() const { return mLabel->pen(); }
    QBrush brush() const { return mLabel->brush(); }
    QString text() const { return mLabel->text(); }

    // other methods:
    void updatePosition(double value);

  protected:
    QCPAxis *mAxis;
    QPointer<QCPItemTracer> mDummyTracer;
    QPointer<QCPItemLine> mArrow;
    QPointer<QCPItemText> mLabel;

signals:

public slots:
};






#endif // AXISTAG_H
