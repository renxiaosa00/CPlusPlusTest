#include "ctestobject.h"
#include <iostream>
using namespace std;
CTestObject::CTestObject()
{
    cout  << " CTestObject init" << endl;
}

CTestObject::~CTestObject()
{
    cout << "CTestObject release" << endl;
}

void CTestObject::Set_test_object_name(const string &test_object_name)
{
    cout << "CTestObject  Set_test_object_name:" << test_object_name << std::endl;
    test_object_name_ = test_object_name;

}

void CTestObject::Get_test_object_name(string &test_object_name) const
{
    test_object_name = test_object_name_;
    cout << "CTestObject  Get_test_object_name:" << test_object_name << std::endl;
}

void CTestObject::Set_test_object_asset(const string &test_object_asset)
{
    cout << "CTestObject  Set_test_object_asset:" << test_object_asset << std::endl;
    test_object_asset_ = test_object_asset;
}

void CTestObject::Get_test_object_asset(string &test_object_asset) const
{
    test_object_asset = test_object_asset_;
    cout << "CTestObject  Get_test_object_asset:" << test_object_asset << std::endl;
}

void CTestObject::Set_test_object_secret(const string &test_object_secret)
{
    cout << "CTestObject  Set_test_object_secret:" << test_object_secret << std::endl;
    test_object_secret_ = test_object_secret;
}

void CTestObject::Get_test_object_secret(string &test_object_secret) const
{
    test_object_secret = test_object_secret_;
    cout << "CTestObject  Get_test_object_secret:" << test_object_secret << std::endl;
}
