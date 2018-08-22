#include <QCoreApplication>
#include <iostream>
#include <string>

#include "dma.h"

const int CLIENTS=4;

int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;
    using std::cin;

    dmaABC *p_clients[CLIENTS];
    //注意char *对应类型的写法
    char labelTemp[100];
    int ratingTemp;
    char kind;

    for(int i=0;i<CLIENTS;i++)
    {
        cout<<"Enter label: ";
        //getline(cin,labelTemp);
        cin>>labelTemp;

        cout<<"Enter ratingTemp: ";
        cin>>ratingTemp;

        cout<<"Enter 1 for baseDMA or 2 for lacksDMA or 3 for "
              "hasDMA: ";
        while (cin>>kind && (kind!='1' && kind!='2' && kind!='3'))
            cout<<"Enter either 1 or 2 or 3: ";
        if(kind == '1')
        {
            p_clients[i]=new baseDMA(labelTemp, ratingTemp);
        }
        else if(kind == '2')
        {
            char clolorTemp[100];
            cout<<"Enter color: ";
            cin>>clolorTemp;
            p_clients[i]=new lacksDMA(clolorTemp, labelTemp, ratingTemp);
        }
        else
        {
            char styleTemp[100];
            cout<<"Enter style: ";
            cin>>styleTemp;
            p_clients[i]=new hasDMA(styleTemp,labelTemp, ratingTemp);
        }

        while (cin.get()!='\n')
            continue;

    }

    cout<<endl;

    for(int i=0;i<CLIENTS;i++)
    {
        p_clients[i]->view();
        cout<<endl;
    }

    for(int i=0;i<CLIENTS;i++)
    {
        delete p_clients[i];
    }

    cout<<"Done.\n";


    return 0;
}
