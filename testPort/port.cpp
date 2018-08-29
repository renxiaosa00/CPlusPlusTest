#include "port.h"
#include "iostream"



Port::Port(const char *br, const char *st, int bo)
{
    brand=new char[std::strlen(br)+1];
    std::strcpy(brand,br);
    std::strcpy(style,st);
    bottles=bo;
}

Port::Port(const Port &p)
{
    brand=new char[std::strlen(p.brand)+1];
    std::strcpy(brand,p.brand);
    std::strcpy(style,p.style);
    bottles=p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if(this==&p)
        return *this;

    delete []brand;
    brand=new char[std::strlen(p.brand)+1];
    std::strcpy(brand,p.brand);
    std::strcpy(style,p.style);
    bottles=p.bottles;
}

Port &Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}

Port &Port::operator-=(int b)
{
    bottles-=b;
    return *this;
}

void Port::show() const
{
    std::cout<<"brand: "<<brand<<std::endl;
    std::cout<<"style: "<<style<<std::endl;
    std::cout<<"bottles: "<<bottles<<std::endl;

}

std::ostream & operator <<(std::ostream &os, const Port &p)
{
    os<<p.brand<<","<<p.style;
    return os;
}




VintagePort::VintagePort()
    :Port()
{
    nickname=new char[1];
    nickname='\0';
    year=1;
}

//注意参数个数，书上少一个st的参数
VintagePort::VintagePort(const char *br, const char *st,int b, const char *nn, int y)
    :Port(br,st,b)
{
    nickname=new char[std::strlen(nn)+1];
    std::strcpy(nickname,nn);
    year=y;
}

VintagePort::VintagePort(const VintagePort &vp)
    :Port(vp)
{
    nickname=new char[std::strlen(vp.nickname)+1];
    std::strcpy(nickname,vp.nickname);
    year=vp.year;
}

VintagePort &VintagePort::operator =(const VintagePort &vp)
{
    if(this==&vp)
        return *this;

    Port::operator =(vp);
    delete []nickname;

    nickname=new char[std::strlen(vp.nickname)+1];
    std::strcpy(nickname,vp.nickname);
    year=vp.year;
}

void VintagePort::Show() const
{
    Port::show();
    std::cout<<"nickname: "<<nickname<<std::endl;
    std::cout<<"year: "<<year<<std::endl;

}

std::ostream &operator <<(std::ostream &os, const VintagePort &vp)
{
    os<<(const Port &)vp;
    os<<","<<vp.nickname<<","<<vp.year;
    return os;
}
