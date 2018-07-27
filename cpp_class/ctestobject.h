#ifndef CTESTOBJECT_H
#define CTESTOBJECT_H
#include <string>

class CTestObject
{
public:
    CTestObject();
    virtual ~CTestObject();

public:
    void Set_test_object_name(const std::string& test_object_name);

    void Get_test_object_name(std::string& test_object_name) const ;

    void Set_test_object_match(const std::string & test_object_match);

    void Get_test_object_match(std::string & test_object_match) const;

    void Show_test_object_secret(const std::string &test_object_match) const;

protected:
    void Set_test_object_asset(const std::string& test_object_asset);

    void Get_test_object_asset(std::string& test_object_asset) const ;

private:

    void Set_test_object_secret(const std::string& test_object_secret);

    void Get_test_object_secret(std::string& test_object_secret) const ;

private:
     std::string  test_object_name_;
     std::string  test_object_asset_;
     std::string  test_object_secret_;
     std::string  test_object_match_;


};

#endif // CTESTOBJECT_H
