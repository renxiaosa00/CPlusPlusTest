#include <QCoreApplication>
#include "port.h"
#include "iostream"


int main(int argc, char *argv[])
{

    Port por1("Gallo","tawny",20);
    Port por2("Gallo2","tawny2",22);
    Port *ptr;
    ptr=&por1;
    ptr->show();
    //por1.show();
    std::cout<<por1<<std::endl;

    por1=por2;
    std::cout<<"por1=por2: "<<std::endl;
    por1.show();

    por1+=2;
    std::cout<<"-----------: "<<std::endl;
    std::cout<<"por1+=2: "<<std::endl;
    por1.show();

    por2-=2;
    std::cout<<"-----------: "<<std::endl;
    std::cout<<"por2-=2: "<<std::endl;
    por2.show();

    VintagePort Vin1("Gallo1","tawny1",21,"nickname1",21);
    VintagePort Vin2("Gallo2","tawny2",22,"nickname2",22);
    ptr=&Vin1;
    ptr->show();
    std::cout<<Vin1<<std::endl;

    Vin1=Vin2;
    std::cout<<"-----------: "<<std::endl;
    std::cout<<"Vin1=Vin2; "<<std::endl;
    std::cout<<Vin1<<std::endl;
    Vin1.Show();

    return 0;
}
