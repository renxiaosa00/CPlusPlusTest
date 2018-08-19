#include "mainwindow.h"
#include <QApplication>
#include "readasd.h"
#include <QFileDialog>
#include <qstring.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    ReadAsd read_asd;
//    QString path_file_name = QFileDialog::getOpenFileName(Q_NULLPTR,QObject::tr("Open ASD "),
//                                                          "./", QObject::tr("ASD Files (*.asd)"));
//    std::cout << "path_file_name:" << path_file_name.toStdString() << std::endl;
//    read_asd.addFileToAsdData(path_file_name.toStdString());
    MainWindow w;
    w.show();

    return a.exec();
}
