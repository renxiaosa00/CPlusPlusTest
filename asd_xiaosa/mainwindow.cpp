#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _read_asd = new ReadAsd();
    ui->table_asd_data->setRowCount(4);
    ui->table_asd_data->setColumnCount(2);
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("p_tagSpectral"));
    ui->table_asd_data->setItem(0, 0, newItem);
    newItem = new QTableWidgetItem(tr("p_x"));
    ui->table_asd_data->setItem(0, 1, newItem);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_btn_clicked()
{
    QString path_file_name = QFileDialog::getOpenFileName(Q_NULLPTR,QObject::tr("Open ASD "),
                                                          "./", QObject::tr("ASD Files (*.asd )"));
    ui->asd_listWidget->addItem(path_file_name);
    _read_asd->addFileToAsdData(path_file_name.toStdString());

}

void MainWindow::on_rm_btn_clicked()
{
    ui->asd_listWidget->clear();
    _read_asd->clearAllFile();
}

void MainWindow::on_asd_listWidget_doubleClicked(const QModelIndex &index)
{
    QVariant data_item = index.data();
    QString data_str = data_item.toString();
    double* p_tagSpectral = nullptr;// _read_asd->getTagSpectralFromAsdFile(data_str.toStdString());
    double* p_x = nullptr;// _read_asd->getxFromAsdFile(data_str.toStdString());
    _read_asd->getTagSpectralAndx(data_str.toStdString(),p_tagSpectral,p_x);
    int row_count = ui->table_asd_data->rowCount();
    if (row_count < ASDROWCOUT+1)
    {
        ui->table_asd_data->setRowCount(ASDROWCOUT+2);
    }
    for (int i=0 ;i<ASDROWCOUT;i++)
    {
        QString str_tagSpectral = tr(std::to_string(p_tagSpectral[i]).c_str());
        QString str_x = tr(std::to_string(p_x[i]).c_str());
        QTableWidgetItem* tag_spectral = new QTableWidgetItem(str_tagSpectral);
        QTableWidgetItem* x_value = new QTableWidgetItem(str_x);

        ui->table_asd_data->setItem(i+1, 1, tag_spectral);
        ui->table_asd_data->setItem(i, 2, x_value);

    }
}
