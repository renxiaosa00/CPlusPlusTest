#ifndef CTESTPRIVATEOBJECT_H
#define CTESTPRIVATEOBJECT_H
#include "ctestobject.h"


class CTestPrivateObject:private CTestObject
{
public:
    CTestPrivateObject();
    ~CTestPrivateObject();
public:
    void  ConsoleInputTestObjectName();
    void  ShowTestObjectName();

    void  ConsoleInputTestObjectAsset();
    void  ShowTestObjectAsset();

    void  ConsoleInputTestObjectSecret();
    void  ShowTestObjectSecret();
};

#endif // CTESTPRIVATEOBJECT_H
