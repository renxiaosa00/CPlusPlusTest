#include "ctestpublicobject.h"
#include <iostream>
using namespace std;

CTestPublicObject::CTestPublicObject()
{
    cout << "CTestPublicObject init" <<  endl;
}

CTestPublicObject::~CTestPublicObject()
{
    cout << "CTestPublicObject Release" << endl;
}

void CTestPublicObject::ConsoleInputTestObjectName()
{
    cout << "CTestPrivateObject Input object name :" << endl;
    std::string object_name;
    cin >> object_name ;
    this->Set_test_object_name(object_name);
}

void CTestPublicObject::ShowTestObjectName()
{
    std::string objectName ;
    //想想注释的这句有什么问题？
    //公有继承情况下，CTestObject的私有成员test_objcet_name_在CTestPublicObject中是不可见的，没有权限被CTestPublicObject类访问
//    cout << this->test_objcet_name_ << endl;
    this->Get_test_object_name(objectName);
    //公有继承情况下，可以在派生类类体内  访问基类的保护成员
    this->Get_test_object_asset(objectName);
    cout <<  "CTestPrivateObject ShowTestObjectName :" << objectName << endl;
}

void CTestPublicObject::ConsoleInputTestObjectAsset()
{
    std::string object_asset;
    cin >> object_asset;
    this->Set_test_object_asset(object_asset);
}

void CTestPublicObject::ShowTestObjectAsset()
{
    std::string object_asset;
    this->Get_test_object_asset(object_asset);
}

void CTestPublicObject::ConsoleInputTestObjectSecret()
{
    std::string object_secret;
    cin >> object_secret;
    //想想注释的这句有什么问题？
    //公有继承情况下，CTestObject的私有方法Set_test_object_secret在CTestPublicObject类中无权限，不能被CTestPublicObject类访问
//    this->Set_test_object_secret(object_secret);
}

void CTestPublicObject::ShowTestObjectSecret()
{
    std::string object_secret;
    //想想注释的这句有什么问题？
    //公有继承情况下，CTestObject的私有方法Get_test_object_secret在CTestPublicObject类中无权限，不能被CTestPublicObject类访问
    //this->Get_test_object_secret(object_secret);
}
