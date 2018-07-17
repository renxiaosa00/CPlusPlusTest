#include "ctestprotectobject.h"
#include <iostream>
using namespace std;

CTestProtectObject::CTestProtectObject()
{
    cout  << "CTestProtectObject init " <<endl;
}

CTestProtectObject::~CTestProtectObject()
{
     cout  << "CTestProtectObject release " <<endl;
}

void CTestProtectObject::ConsoleInputTestObjectName()
{
    cout << "CTestPrivateObject Input object name :" << endl;
    std::string object_name;
    cin >> object_name ;
    this->Set_test_object_name(object_name);
}

void CTestProtectObject::ShowTestObjectName()
{
    std::string objectName ;
    //想想注释的这句有什么问题？
    //CTestProtectObject是保护继承，test_objcet_name_是基类中的私有成员，不能被访问，
    //基类中的公有成员和保护成员在派生类中成为保护成员，可被派生类的成员函数和友元访问
//    cout << this->test_objcet_name_ << endl;
    this->Get_test_object_name(objectName);
    cout <<  "CTestPrivateObject ShowTestObjectName :" << objectName << endl;
}

void CTestProtectObject::ConsoleInputTestObjectAsset()
{
    std::string object_asset;
    cin >> object_asset;
    this->Set_test_object_asset(object_asset);
}

void CTestProtectObject::ShowTestObjectAsset()
{
    std::string object_asset;
    this->Get_test_object_asset(object_asset);
}

void CTestProtectObject::ConsoleInputTestObjectSecret()
{
    std::string object_secret;
    cin >> object_secret;
    //想想注释的这句有什么问题？
    //保护继承情况下，基类的私有方法Set_test_object_secret在派生类中是不被访问的，没有权限
//    this->Set_test_object_secret(object_secret);
}

void CTestProtectObject::ShowTestObjectSecret()
{
    std::string object_secret;
    //想想注释的这句有什么问题？
    //感觉和Set_test_object_secret这个方法效果一致
//    this->Get_test_object_secret(object_secret);
}
