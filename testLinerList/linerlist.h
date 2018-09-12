#ifndef LINERLIST_H
#define LINERLIST_H
//线性表的抽象基类，函数均为虚函数
//#pragma once
#include <iostream>

using namespace std;

template<class T>
class linerList
{
public:
    //删除后就可以实现  奇怪
    //模板类必须在内部实现  为啥？！
    linerList(){cout<<"linerList()"<<endl;}


    virtual ~linerList(){}
    //判断线性表是否为空，若为空返回true
    virtual bool empty() const=0;
    //返回线性表的元素个数
    virtual int size() const=0;
    //返回索引为theIndex的元素
    virtual T &get(int theIndex) const=0;
    //返回元素theElement第一次出现的索引
    virtual int indexof(const T &theElement) const=0;
    //删除索引为theIndex的元素
    virtual void erase(int theIndex)=0;
    // 把theElement插入到索引为theIndex的位置上
    virtual void insert(int theIndex,const T &theElement)=0;
    //输出元素
    virtual void output(ostream &out) const=0;




};

#endif // LINERLIST_H
