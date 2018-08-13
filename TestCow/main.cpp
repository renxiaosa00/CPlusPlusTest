#include <QCoreApplication>
#include "cow.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cow c1;
    c1.ShowCow();

    Cow c2("c2-name","c2-hobby",56.66);
    c2.ShowCow();

    Cow c3(c2);
    c3.ShowCow();

    c3=c2=c1;
    std::cout<<"c3=c2=c1: "<<std::endl;
    c2.ShowCow();
    c3.ShowCow();

    return a.exec();
}
