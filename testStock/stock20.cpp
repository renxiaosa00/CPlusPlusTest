#include "stock20.h"
#include <iostream>
#include "stock20.h"

stock20::stock20()
{
    std::cout<<"default constructor called\n";
    company=new char[1];
    company[0]='\0';
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

stock20::stock20(const char *com, long num, double sh_val)
{
    std::cout<<"constructor using "<<com<<" called\n";
    int len=strlen(com);
    company=new char[len+1];
    strcpy(company,com);

    if(num<0)
    {
        std::cout<<"number of shares can't be negative;"
                <<company<<" shares set to 0.\n";
        shares=0;
    }
    else
        shares=num;
    share_val=sh_val;
    set_tot();

}

stock20::~stock20()
{
    std::cout<<"bye, "<<company<<"\n";
    delete []company;
}

void stock20::buy(long num, double price)
{
    if(num<0)
    {
        std::cout<<"number of shares purchased can't be "
                   "negative "<<" transaction is aborted.\n";
    }
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}

void stock20::sell(long num, double price)
{
    using std::cout;
    if(num<0)
    {
        cout<<"number of shares sold can't be negative."
           <<"transaction is aborted .\n";
    }
    else if(num>shares)
    {
        cout<<"you can't sell more than you have!"
           <<"transaction is aborted.\n";
    }
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}

void stock20::update(double price)
{
    share_val=price;
    set_tot();
}

std::ostream &operator<<(std::ostream & os, const stock20 & st)
{
    os<<st.company;
    return os;
}



const stock20 &stock20::topval(const stock20 &s) const
{
    if(s.total_val>total_val)
        return s;
    else
        return *this;
}


