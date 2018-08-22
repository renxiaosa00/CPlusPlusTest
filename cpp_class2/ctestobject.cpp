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

void CTestObject::Set_test_object_match(const string &test_object_match)
{
    cout<<"CTestObject Set_test_object_match: "<<test_object_match<<endl;
    test_object_match_=test_object_match;
}

void CTestObject::Get_test_object_match(std::string & test_object_match) const
{
    //如果放开注释，为什么会报错？
    //test_object_asset_私有成员只能通过CTestObject类开放的公有接口访问，不能直接对私有成员进行操作
    //test_object_asset_="2";
    test_object_match=test_object_match_;
    cout<<"CTestObject Get_test_object_match: "<<test_object_match<<endl;

}

void CTestObject::Show_test_object_secret(const string &test_object_match) const
{
    if(test_object_match == test_object_match_)
    {
        cout<<test_object_secret_<<endl;

    }else
    {
        cout<<"don't match"<<endl;
    }
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
