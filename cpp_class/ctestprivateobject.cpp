#include "ctestprivateobject.h"
#include <iostream>
using namespace std;

CTestPrivateObject::CTestPrivateObject()
{
    cout << "CTestPrivateObject init" << endl;
}

CTestPrivateObject::~CTestPrivateObject()
{
    cout << "CTestPrivateObject release" <<endl;
}

void CTestPrivateObject::ConsoleInputTestObjectName()
{
    cout << "CTestPrivateObject Input object name :" << endl;
    std::string object_name;
    cin >> object_name ;
    this->Set_test_object_name(object_name);
}

void CTestPrivateObject::ShowTestObjectName()
{
    std::string objectName ;
    //想想注释的这句有什么问题？
    //私有继承，私有成员test_objcet_name_在派生对象间是不可见的，没有权限，不能被访问的
//    cout << this->test_objcet_name_ << endl;
    //Get_test_object_name（）方法在私有继承下变成派生类的私有方法，只能在类体内  进行访问
    this->Get_test_object_name(objectName);
    cout <<  "CTestPrivateObject ShowTestObjectName :" << objectName << endl;
}

void CTestPrivateObject::ConsoleInputTestObjectAsset()
{
    std::string object_asset;
    cin >> object_asset;
    this->Set_test_object_asset(object_asset);
}

void CTestPrivateObject::ShowTestObjectAsset()
{
    std::string object_asset;
    this->Get_test_object_asset(object_asset);
}

void CTestPrivateObject::ConsoleInputTestObjectSecret()
{
    std::string object_secret;
    cin >> object_secret;
    //想想注释的这句有什么问题？
    //私有继承下，Set_test_object_secrets私有方法在派生类中成为私有方法，可在派生类 类体内 访问基类的公有方法，但不能通过派生类 对象访问
//    this->Set_test_object_secret(object_secret);
}

void CTestPrivateObject::ShowTestObjectSecret()
{
    std::string object_secret;
    //想想注释的这句有什么问题？
    //和上面的Set_test_object_secret方法效果一致
//    this->Get_test_object_secret(object_secret);
}
