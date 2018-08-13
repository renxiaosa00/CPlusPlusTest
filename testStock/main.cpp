#include <QCoreApplication>
#include <iostream>
#include "stock20.h"
using namespace std;
const int STKS=4;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stock20 stocks[STKS]={
        stock20("nanosmart",12,20.0),
        stock20("boffo objects",200,2.0),
        stock20("monolithic obelisks",130,3.25),
        stock20("fleep enterprises",60,6.5)

    };

    std::cout<<"stock holdings:\n";
    int st;
    for(st=0;st<STKS;st++)
        cout<<stocks[st];

    const stock20 *top = &stocks[0];
    for(st=1;st<STKS;st++)
        top=&top->topval(stocks[st]);

    cout<<"\nmost valuable holding:\n";
    cout<<top;


    return 0;
}
