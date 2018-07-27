#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow ::InitAPlot()
{

    QCustomPlot *p = ui->plot;

    p->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);   //可拖拽+可滚轮缩放

    p->legend->setVisible(true);
    p->xAxis->setLabel(QStringLiteral("X轴文字"));
    p->yAxis->setLabel(QStringLiteral("Y轴文字"));

    p->xAxis->setRange(0,100);
    p->yAxis->setRange(0,10);

    p->addGraph();
    p->addGraph();
    p->graph(0)->setPen(QPen(Qt::red));
    p->graph(1)->setPen(QPen(Qt::blue));

    for(int i=0;i<100;i++)
    {
        p->graph(0)->addData(i, i%10);
        p->graph(1)->addData(i, (double)i/10.0);
    }

    p->plottable();
}
