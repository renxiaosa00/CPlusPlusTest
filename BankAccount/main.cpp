#include <QCoreApplication>
#include <B_account.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<"name: ";
    string name;
    cin>>name;
    cout<<"account: ";
    string account;
    cin>>account;
    cout<<"deposit: ";
    double deposit;
    cin>>deposit;
    B_account b1(name,account,deposit);

    int sex;
    cout<<"sex: ";
    cin>>sex;
    switch (sex) {
    //枚举类型 使用类作用域
    case B_account::sex_boy:
        cout<<"this is boy";
        break;
    case B_account::sex_girl:
        cout<<"this is girl";
    default:
        cout<<"this is't people";
        break;
    }

    //error: C2668: “B_account::B_account”: 对重载函数的调用不明确
   // B_account b2;
    //b3()编译时 根据参数列表，已确定调用哪个默认构造函数
    B_account b3();


    b1.showName("n1");

    b1.showAccount();

    b1.showDeposit();

    cout<<endl;
    b1.showBaccount();

    b1.addDeposit(20);

    b1.takeDeposit(1);

    return 0;
}
