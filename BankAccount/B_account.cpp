#include "B_account.h"
#include <iostream>
B_account::B_account()
{
    name_="";
    account_="";
    deposit_=0.0;
}

B_account::B_account(const std::string name, const std::string account, double deposit)
{
    name_=name;
    account_=account;
    deposit_=deposit;
}

void B_account::showName()
{
    std::cout<<"name: "<<name_<<std::endl;

}

void B_account::showName(const std::string name)
{
    std::cout<<"showName: "<<name_<<std::endl;
}

void B_account::showAccount()
{
    std::cout<<"account: "<<account_<<std::endl;
}

void B_account::showDeposit()
{
    std::cout<<"deposit: "<<this->deposit_<<std::endl;
}

void B_account::showBaccount()
{
    std::cout<<"name: "<<name_<<", ";
    std::cout<<"account: "<<account_<<", ";
    std::cout<<"deposit: "<<deposit_<<std::endl;

}

void B_account::takeDeposit(double deposit)
{
    deposit_-=deposit;

    std::cout<<"after take deposit: "<<deposit_<<std::endl;
}

void B_account::addDeposit(const double deposit)
{
//    B_account b_deposit;
//    b_deposit.deposit_+=deposit;
    deposit_+=deposit;
    std::cout<<"after add deposit: "<<deposit_<<std::endl;
}


