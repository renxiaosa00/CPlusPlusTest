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
//    cout << this->test_objcet_name_ << endl;
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
//    this->Set_test_object_secret(object_secret);
}

void CTestPrivateObject::ShowTestObjectSecret()
{
    std::string object_secret;
    //想想注释的这句有什么问题？
//    this->Get_test_object_secret(object_secret);
}
