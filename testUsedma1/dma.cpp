#include "dma.h"
#include <cstring>
#include <iostream>


dmaABC::dmaABC(const char *l, int r)
{
    label=new char[std::strlen(l)+1];
    strcpy(label,l);
    rating=r;
}

dmaABC::dmaABC(const dmaABC &rs)
{
    label=new char[std::strlen(rs.label)+1];
    strcpy(label,rs.label);
    rating=rs.rating;

}

dmaABC::~dmaABC()
{
    std::cout<<"dmaABC"<<std::endl;
    delete []label;
}

dmaABC &dmaABC::operator=(const dmaABC &rs)
{
    if(this==&rs)
        return *this;

    delete[] label;
    label=new char[std::strlen(rs.label)+1];
    std::strcpy(label,rs.label);
    rating=rs.rating;
    return *this;
}

void dmaABC::view() const
{
    std::cout<<"label: "<<label<<std::endl;
    std::cout<<"rating: "<<rating<<std::endl;

}

void baseDMA::view() const
{
    dmaABC::view();
}

lacksDMA::lacksDMA(const char *c, const char *l, int r)
    :dmaABC(l,r)
{
    std::strcpy(color,c);
}

lacksDMA::lacksDMA(const char *c, const dmaABC &rs)
    :dmaABC(rs)
{
    std::strcpy(color,c);
}

void lacksDMA::view() const
{
    dmaABC::view();
    std::cout<<"color: "<<color<<std::endl;

}

hasDMA::hasDMA(const char *s, const char *l, int r)
    :dmaABC(l,r)
{
    style=new char[std::strlen(s)+1];
    std::strcpy(style,s);
}

hasDMA::hasDMA(const char *s, const dmaABC &rs)
    :dmaABC(rs)
{
    style=new char[std::strlen(s)+1];
    std::strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA &hs)
    :dmaABC(hs)
{
    style=new char[std::strlen(hs.style)+1];
    std::strcpy(style,hs.style);
}

hasDMA::~hasDMA()
{
    std::cout<<"hasDMA析构函数"<<std::endl;
    delete []style;
}

hasDMA &hasDMA::operator =(const hasDMA &rs)
{
    if(this==&rs)
        return *this;
    //有疑问 522页
    dmaABC::operator =(dynamic_cast<const dmaABC &>(rs));
    delete[]style;
    style=new char[std::strlen(rs.style)+1];
    std::strcpy(style,rs.style);

    return *this;
}

void hasDMA::view() const
{
    dmaABC::view();
    std::cout<<"style: "<<style<<std::endl;

}



