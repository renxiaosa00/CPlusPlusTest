#ifndef STOCK20_H
#define STOCK20_H

#include <iostream>

class stock20
{
private:
    char *company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val=shares*share_val;}


public:
    stock20();
    stock20(const char *com,long num=0, double sh_val=0);
    ~stock20();
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);

    friend std::ostream & operator<<(std::ostream & os, const stock20 & st);

    const stock20 &topval(const stock20 &s)const;


};

#endif // STOCK20_H
