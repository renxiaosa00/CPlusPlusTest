#ifndef CTESTPUBLICOBJECT_H
#define CTESTPUBLICOBJECT_H
#include "ctestobject.h"

class CTestPublicObject:public CTestObject
{
public:
    CTestPublicObject();
    ~CTestPublicObject();
public:
    void  ConsoleInputTestObjectName();
    void  ShowTestObjectName();

    void  ConsoleInputTestObjectAsset();
    void  ShowTestObjectAsset();

    void  ConsoleInputTestObjectSecret();
    void  ShowTestObjectSecret();
};

#endif // CTESTPUBLICOBJECT_H
