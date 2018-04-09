#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "axistag.h"
#include "tagaxis.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void timerSlot();

private:
    Ui::MainWindow *ui;
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
//    AxisTag *mTag1;
//    AxisTag *mTag2;
    TagAxis *tagAxis;
    QTimer mDataTimer;
};

#endif // MAINWINDOW_H
