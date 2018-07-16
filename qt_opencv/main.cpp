#include "mainwindow.h"
#include <QApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cv::Mat image;
    std::string path;
    image = cv::imread(path);
    MainWindow w;
    w.show();

    return a.exec();
}
