#include<iostream>
#include "stock00.h"

int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("nanosmart",20,12.50);
    fluffy_the_cat.show();
    std::cout<<"-----------"<<'\n';
    fluffy_the_cat.buy(15,18.125);
    fluffy_the_cat.show();
    std::cout<<"-----------"<<'\n';
    fluffy_the_cat.sell(400,20.00);
    fluffy_the_cat.show();
    std::cout<<"-----------"<<'\n';
    fluffy_the_cat.buy(3000000,40.125);
    fluffy_the_cat.show();
    std::cout<<"-----------"<<'\n';
    fluffy_the_cat.sell(3000000,0.125);
    fluffy_the_cat.show();

    return 0;
}
