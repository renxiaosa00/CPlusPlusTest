#ifndef COMPLEX0_H
#define COMPLEX0_H
#include <iostream>

class complex0
{

private:
    double _x,_y;
public:
    complex0();
    complex0(double x,double y);

    complex0 operator + (const complex0 &c) const;
    complex0 operator + (double n) const;

    complex0 operator - (const complex0 &c) const;
    complex0 operator * (const complex0 &c) const;

    complex0 operator * (double n) const;
    //与上面功能一致
    friend complex0 operator *(double n, const complex0 &c)
    {
        return c*n;
    }



    complex0 operator ~ () const;

    friend std::ostream & operator<< (std::ostream &os, const complex0 &c);
    friend std::istream & operator>> (std::istream &is, complex0 &c);
    ~complex0();
};

#endif // COMPLEX0_H
