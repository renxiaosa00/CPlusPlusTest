#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readasd.h"

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
    void on_add_btn_clicked();

    void on_rm_btn_clicked();

    void on_asd_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    ReadAsd* _read_asd;
};

#endif // MAINWINDOW_H
