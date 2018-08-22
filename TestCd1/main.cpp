#include <QCoreApplication>
#include <iostream>
#include "cd.h"

using  namespace std;

void Bravo(const Cd &disk);

int main(int argc, char *argv[])
{

    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2=Classic("Piano Sonata in B Flat,Fantasia in C","Alfred Brendel","Philips", 2, 57.17);

//    //Classic c22=("work22","rxs","jiayou",2,35.3);
//    Cd *pcd=&c1;

//    cout<<"Using object directly:\n";
//    c1.Report();
//    c2.Report();
//    //析构函数调用顺序：Classic-Cd-Cd

//    cout<<"Using type cd * pointer to objects:\n";
//    pcd->Report();
//    pcd=&c2;
//    pcd->Report();
//    //析构函数调用顺序：Classic-Cd-Cd

//    cout<<"Calling a function with a Cd reference argument:\n";
//    Bravo(c1);
//    Bravo(c2);
//    //析构函数调用顺序：Classic-Cd-Cd

    cout<<"Test assignment: ";
    Classic copy;
    //copy.Report();
    copy=c2;
    copy.Report();
    //析构函数的调用方式：Classic-Cd-Classic-Cd-Cd

    return 0;
}

void Bravo(const Cd &disk)
{
    disk.Report();
}
