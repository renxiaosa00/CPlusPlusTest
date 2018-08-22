#include "cd.h"
#include <iostream>
using std::cout;
using std::endl;


Cd::Cd(char *s1, char *s2, int n, double x)
{
    strcpy(performers,s1);
    strcpy(label,s2);
    selections=n;
    playtime=x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}

Cd::Cd()
{
    strcpy(performers,"s1");
    strcpy(label,"s2");
    selections=0;
    playtime=0.0;
}

Cd::~Cd()
{
    cout<<"Cd()的析构函数\n";
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

    strcpy(performers,d.performers);
    strcpy(label,d.label);

    selections=d.selections;
    playtime=d.playtime;
    return *this;
}

Classic::Classic(char *c1, char *s1, char *s2, int n, double x)
    :Cd(s1,s2,n,x)
{
    strcpy(work,c1);
}

Classic::Classic(const Classic &c)
    :Cd(c)
{
    strcpy(work,c.work);
}

Classic::Classic()
    :Cd()
{
    strcpy(work,"NULL");
}

Classic::~Classic()
{
    cout<<"Classic析构函数\n";
}

void Classic::Report() const
{
    cout<<"Classic:"<<endl;
    Cd::Report();

    cout<<"work: "<<work<<endl;

}

Cd &Classic::operator =(const Classic &c)
{
    if(this==&c)
        return *this;

    Cd::operator =(c);
    strcpy(work,c.work);
    return *this;
}
