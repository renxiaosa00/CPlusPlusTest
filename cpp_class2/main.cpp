#include <QCoreApplication>
#include "ctestobject.h"
#include "ctestprivateobject.h"
#include "ctestprotectobject.h"
#include "ctestpublicobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CTestPrivateObject private_object;
    std::string object_name = "test";
    std::string object_name_show;



    //想想如果我放开注释，下面这几行代码编译时为什么会报错。
    // CTestPrivateObject是私有继承，CTestObject的公有成员和保护成员变成派生类内的私有成员，
    //CTestPrivateObject 类体内可以访问CTestObject类的公有成员和保护成员，但是不能在CTestPrivateObject类体外通过private_object对象访问CTestObject的公有成员和保护成员
    //CTestPrivateObject不可访问CTestObject类的私有成员

    //private_object.Set_test_object_name(object_name);
    //private_object.Get_test_object_name(object_name_show);

    private_object.ConsoleInputTestObjectName();
    private_object.ShowTestObjectName();

    //私有继承下，无法通过私有类对象private_object 访问 基类的保护成员
    //private_object.Get_test_object_asset(object_name);


     CTestProtectObject protect_object;
     std::string object_asset="asset";
     std::string object_asset_show;

     //想想如果我放开注释，下面这几行代码编译时为什么会报错。
     //CTestProtectObject是保护继承，CTestObject的公有成员和保护成员变成派生类内的保护成员，CTestObject私有成员不被访问

 //    protect_object.Set_test_object_name(object_name);
 //    protect_object.Get_test_object_name(object_name_show);

     //CTestProtectObject 类体内可以访问CTestObject的公有成员和保护成员，但是不能在CTestProtectObject类体外通过CTestProtectObject类对象访问CTestObject的公有成员和保护成员
//     protect_object.Set_test_object_asset(object_asset);
//     protect_object.Get_test_object_asset(object_asset_show);

     protect_object.ConsoleInputTestObjectName();
     protect_object.ShowTestObjectName();

     //protect_object对象无法访问基类的保护成员
     //protect_object.Get_test_object_asset(object_asset);


     CTestPublicObject public_object;
     std::string test_object_asset1;
     //想想如果我放开注释，下面这几行代码编译时为什么不会报错。
     //CTestPublicObject是公有继承，CTestObject的公有成员和保护成员变成CTestPublicObject类内的公有成员和保护成员，访问权限不变，可在CTestPublicObject类体内 访问公有成员和保护成员
     //CTestObject的私有成员依然不被CTestPublicObject对象、甚至类体内访问
     //CTestObject的保护成员不被CTestPublicObject对象访问

     public_object.Set_test_object_name(object_name);
     public_object.Get_test_object_name(object_name_show);

     public_object.ConsoleInputTestObjectName();
     public_object.ShowTestObjectName();

     public_object.Set_test_object_match("sss");
     public_object.Show_test_object_secret("sdf");
     public_object.Show_test_object_secret("sss");

     //公有继承下，派生类对象 无法访问 保护成员
     //public_object.Get_test_object_asset(test_object_asset1);


    //
   // return a.exec();
    return 1;
}
