#include "cow.h"

#include <iostream>
Cow::Cow()
{
    //错误，因为name指向数组首地址的指针
    //name="Cow Default";
    strcpy(name,"Cow Default");
    hobby=new char[1];
    hobby[0]='\0';
    weight=0.0;
    //len=0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    //name=new char[strlen(nm)+1];
    std::strcpy(name,nm);
    //下面出错的原因是？
//    for(int i=0;*nm!='\0';i++)
//    {
//        name[i]=nm[i];
//    }
    hobby=new char[strlen(ho)+1];
    strcpy(hobby,ho);
    weight=wt;
}

Cow::Cow(const Cow &c)
{
    int len=strlen(c.hobby);
//    name=new char[len+1];
    hobby=new char[len+1];
    strcpy(name,c.name);
    strcpy(hobby,c.hobby);
    weight=c.weight;
}

Cow::~Cow()
{

    delete []hobby;
}

Cow &Cow::operator=(const Cow &c)
{
    if(this==&c)
        return *this;
    delete [] hobby;
    int len=strlen(c.hobby);
    hobby=new char[len+1];
    strcpy(hobby,c.hobby);
    strcpy(name,c.name);
    weight=c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    std::cout<<"name: "<<name<<", "
       <<"hobby: "<<hobby<<", "
      <<"weight: "<<weight<<std::endl;
}
