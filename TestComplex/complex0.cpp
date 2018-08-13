#include "complex0.h"
using namespace std;

complex0::complex0()
{
    _x=_y=0;
}

complex0::complex0(double x, double y)
{
    _x=x;
    _y=y;

}

complex0 complex0::operator +(const complex0 &c) const
{
    //重载加法运算符
    complex0 sum;
    sum._x=_x+c._x;
    sum._y=_y+c._y;
    return sum;

}

complex0 complex0::operator +(double n) const
{
    complex0 sum;
    sum._x=this->_x+n;
    sum._y=this->_y;
    return sum;

}

complex0 complex0::operator -(const complex0 &c) const
{
    //重载减法运算符
    complex0 tot;
    tot._x=_x-c._x;
    tot._y=_y-c._y;
    return tot;
}

complex0 complex0::operator *(const complex0 &c) const
{
    //重载乘法运算符
    complex0 multiplication;
    multiplication._x = _x * c._x - _y * c._y;
    multiplication._y = _x * c._y + _y * c._x;
    return multiplication;
}

complex0 complex0::operator *(double n) const
{
    //重载乘法运算符:复数乘以基本类型值
    complex0 multiplication1;
    multiplication1._x = _x * n;
    multiplication1._y = _y * n;
    return multiplication1;
}





complex0 complex0::operator ~ () const
{
    complex0 temp;
    temp._x = _x;
    temp._y = -_y;
    return temp;
}

ostream &operator<<(ostream &os, const complex0 &c)
{
    os << "(" << c._x << "," << c._y << "i)" << endl;
    return os;
}



istream &operator>>(istream &is, complex0 &c)
{
    is >> c._x >> c._y ;
    return is;
}

complex0::~complex0()
{

}
