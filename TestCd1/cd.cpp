#include "cd.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;


Cd::Cd()
{
    performers=new char[1];
    performers[0]='p';
    label=new char[1];
    label[0]='l';
    selections=0;
    playtime=0.0;
}

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers=new char[std::strlen(s1)+1];
    label=new char[std::strlen(s2)+1];
    std::strcpy(performers,s1);
    std::strcpy(label,s2);
    selections=n;
    playtime=x;
}

Cd::Cd(const Cd &d)
{
    performers=new char[std::strlen(d.performers)+1];
    label=new char[std::strlen(d.label)+1];
    std::strcpy(performers,d.performers);
    std::strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;

}

Cd::~Cd()
{
    cout<<"Cd构造函数"<<endl;
    delete [] performers;
    delete [] label;

}

void Cd::Report() const
{
    cout<<"Cd:"<<endl;
    cout<<"performers: "<<performers<<endl;
    cout<<"label: "<<label<<endl;
    cout<<"selections: "<<selections<<endl;
    cout<<"playtime: "<<playtime<<endl;

}

Cd &Cd::operator =(const Cd &d)
{
    if(this==&d)
        return *this;

    delete []performers;
    delete []label;
    performers=new char[std::strlen(d.performers)+1];
    label=new char[std::strlen(d.label)+1];
    std::strcpy(performers,d.performers);
    std::strcpy(label,d.label);
    selections=d.selections;
    //因这里赋值错误，故产生多次释放
    //label=d.label;
    playtime=d.playtime;

    return *this;

}

Classic::Classic()
    :Cd()
{
    work=new char[1];
    work[0]='w';
}

Classic::Classic(const char *c1, const char *s1, const char *s2, int n, double x)
    :Cd(s1,s2,n,x)
{
    work=new char[std::strlen(c1)+1];
    std::strcpy(work,c1);
}

Classic::Classic(const Classic &c)
    :Cd(c)
{
    work=new char[std::strlen(c.work)+1];
    std::strcpy(work,c.work);
}

Classic::~Classic()
{
    cout<<"Classic析构函数"<<endl;
    delete[]work;
}

void Classic::Report() const
{
    cout<<"Classic: "<<endl;

    Cd::Report();
    cout<<"work: "<<work<<endl;
}

Classic &Classic::operator =(const Classic &c)
{
    if(this==&c)
        return *this;

    //Cd::operator =(c);
    Cd::operator =(dynamic_cast<const Cd &>(c));

    delete []work;

    work=new char[std::strlen(c.work)+1];
    std::strcpy(work,c.work);
    return *this;
}














