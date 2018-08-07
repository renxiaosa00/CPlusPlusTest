#include <QCoreApplication>
#include <string>
#include <iostream>
using namespace std;
struct student{
    int id;
    string name;

    student()
    {
        id =0;
    }
    void showStudent()
    {
        std::cout << " name is:" <<name;
    }

};

class student1 {

    int id_;
    string name_;

    const int age_=0;
public:

    int sex_;

    static void showVersion()
    {
        std::cout<<"this is version 1.";
    }


    //student1();
//    {
//        id_=0;
//        name_="";
//    }
    student1(int id=0)
    {
        id_=id;
    }
    student1(string name)
    {
        name_=name;
    }
//    student1(int id,string name);

    void showStudent()
    {
        std::cout << " name is:" <<name_;
    }

    void showId()
    {
        std::cout<<" id is: "<<id_;
    }

    void showSex()
    {
        std::cout<<" sex is: "<<sex_;
    }

    student1 operator +(int id)
    {
        student1 ret;
        ret.id_ = this->id_ +id;
        return ret;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //结构的默认访问类型是public
    student  one;
    one.name = "shuai";
    one.showStudent();

    //测试 默认构造函数（2种）和带参数的构造函数
    student1 st3;

    student1 st1(2);
    student1 st2 = st1 + 18;
    st1.showId();
    st2.showId();

    //showVersion是student1的静态成员方法，不属于某一个对象的方法，只能由类调用
    //st1.showVersion();
    student1::showVersion();


//    student1 st2(1);

    string name ="st4";
    student1 st4(name);
    st4.showStudent();

    //error: C2248: “student1::name_”: 无法访问 private 成员(在“student1”类中声明)
//    st1.name_="st1";
//    st1.showStudent();

    //可以访问student1 类的公有成员
    st1.sex_=18;
    st1.showSex();


    return a.exec();
}
