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
    //private_object.Set_test_object_name(object_name);
    //private_object.Get_test_object_name(object_name_show);

    private_object.ConsoleInputTestObjectName();
    private_object.ShowTestObjectName();


     CTestProtectObject protect_object;
     //想想如果我放开注释，下面这几行代码编译时为什么会报错。
 //    protect_object.Set_test_object_name(object_name);
 //    protect_object.Get_test_object_name(object_name_show);

     protect_object.ConsoleInputTestObjectName();
     protect_object.ShowTestObjectName();


     CTestPublicObject public_object;
     //想想如果我放开注释，下面这几行代码编译时为什么不会报错。
     public_object.Set_test_object_name(object_name);
     public_object.Get_test_object_name(object_name_show);

     public_object.ConsoleInputTestObjectName();
     public_object.ShowTestObjectName();


    //
   // return a.exec();
    return 1;
}
