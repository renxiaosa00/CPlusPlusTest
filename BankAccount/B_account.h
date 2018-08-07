#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class B_account
{

private:
    std::string name_;
    std::string account_;
    double deposit_;



public:
    B_account();
   // B_account(const std::string name, const std::string account, double deposit);
    B_account(const std::string name="", const std::string account="", double deposit=0.0);


    void showName() ;
    void showName(const std::string name="");
    void showAccount() ;
    void showDeposit() ;
    void showBaccount() ;

    void addDeposit(const double deposit);
    void takeDeposit(double deposit);

    enum
    {
        sex_boy=1,
        sex_girl=2
    };


};

#endif // ACCOUNT_H
