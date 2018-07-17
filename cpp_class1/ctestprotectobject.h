#ifndef CTESTPROTECTOBJECT_H
#define CTESTPROTECTOBJECT_H
#include "ctestobject.h"

class CTestProtectObject:protected CTestObject
{
public:
    CTestProtectObject();
    ~CTestProtectObject();
public:
    void  ConsoleInputTestObjectName();
    void  ShowTestObjectName();

    void  ConsoleInputTestObjectAsset();
    void  ShowTestObjectAsset();

    void  ConsoleInputTestObjectSecret();
    void  ShowTestObjectSecret();
};

#endif // CTESTPROTECTOBJECT_H
