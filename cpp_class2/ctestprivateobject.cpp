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
    //私有继承，CTestObject的 私有成员test_objcet_name_在CTestPrivateObject类体内是不可见的，没有权限，不能被访问的
//    cout << this->test_objcet_name_ << endl;
    //CTestObject的公有方法Get_test_object_name（）在私有继承下变成CTestPrivateObject类的私有方法，只能在类体内 进行访问
    this->Get_test_object_name(objectName);
    cout <<  "CTestPrivateObject ShowTestObjectName :" << objectName << endl;

    //私有继承下，派生类 类体内 可访问 基类的保护成员
    this->Get_test_object_asset(objectName);
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
    //私有继承下，CTestObject的Set_test_object_secrets私有方法在CTestPrivateObject类中没有访问权限
//    this->Set_test_object_secret(object_secret);
}

void CTestPrivateObject::ShowTestObjectSecret()
{
    std::string object_secret;
    //想想注释的这句有什么问题？
    //私有继承下，CTestObject的Get_test_object_secrets私有方法在CTestPrivateObject类中没有访问权限
//    this->Get_test_object_secret(object_secret);
}
