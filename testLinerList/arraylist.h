#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "linerlist.h"
//#pragma once
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <algorithm>
#include<string>
#include<iterator>

using namespace std;

template <class T>
class arrayList:public linerList<T>
{
public:

    //构造函数，复制构造函数和析构函数
    arrayList(int initCapacity=10);
    arrayList(const arrayList<T> &theList);
    ~arrayList(){delete[] element;}

    //添加
    bool empty() const{return listSize==0;}
    int size() const{return listSize;}
    T &get(int theIndex)const;
    int indexof(const T &theElement)const;
    void erase(int theIndex);
    void insert(int theIndex,const T&theElement);
    void output(ostream &out) const;
    //friend ostream& operator<<(ostream &out,const arrayList<T> &x);

    //其他方法
    //返回数组的长度，即线性表的容量
    int capacity() const{return arrayLength;}

protected:
    //检测索引正确性，若索引无效抛出异常
    void checkIndex(int theIndex) const;

    // 一维数组存储线性表
    T *element;
    //一维数组的长度
    int arrayLength;
    //线性表的元素个数
    int listSize;
};

template<class T>
arrayList<T>::arrayList(int initCapacity)
{
    if(initCapacity<1)
    //如果initialCapacity不正确，抛出异常
    {
        cerr<<"Initial Capacity="<<initCapacity<<"must be >0";
        exit(0);

    }
    arrayLength=initCapacity;
    element=new T[arrayLength];
    listSize=0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{
    arrayLength=theList.arrayLength;
    listSize=theList.listSize;
    element=new T[arrayLength];
    /拷贝数组元素，利用STL中copy算法
            copy(theList.element,theList.element+listSize,element);
}


//返回索引值为theIndex的元素，如果索引不存在抛出异常
template<class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

//返回theElement第一次出现时的索引，如果元素不存在返回-1
template<class T>
int arrayList<T>::indexof(const T &theElement) const
{
    //先查找，利用STl中的find算法
    int theIndex=(int)(find(element,element+listSize,theElement)-element);

    if(theIndex==listSize)
        return -1;
    else
        return theIndex;

}

// 删除索引theIndex的元素
template <class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);

    //索引有效的情况下。移动大于索引的元素
    copy(element+theIndex+1,element+listSize,element+theIndex);
    //调用析构函数
    element[--listSize].~T();
}

//插入操作
template<class T>
void arrayList<T>::insert(int theIndex, const T &theElement)
{
    if(theIndex=0 || theIndex>listSize)
    {
        cerr<<"index:"<<theIndex<<" must be > 0 and <= " << listSize;
        exit(0);
    }
    //数组已满，扩充数组
    if(theIndex==arrayLength)
    {
        addLength1D(element,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    //将元素右移一个位置
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex]=theElement;
    //std::cout<<element[theIndex]<<","<<endl;
    listSize++;
}

//输出，为什么要这样，有什么优点呢？
template<class T>
//把线性表插入输入输出流
void arrayList<T>::output(ostream &out) const
{
    copy(element,element+listSize,ostream_iterator<T>(out," "));
}

template<class T>
ostream& operator<<(ostream &out,const arrayList<T> &x)
{
    x.output(out);
    return out;
}

//确定索引在0和listSize-1之间，
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex<0 || theIndex>=listSize)
    {
        cerr<<"index:"<<theIndex<<" must be > 0 and <= "<<listSize;
        exit(0);
    }
}


//当数组长度不够时，通过该函数扩展存储空间
template<class T>
void addLength1D(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        cerr<<"new length must be >=0";
    //新数组
    T *temp=new T[newLength];
    //需要复制的元素的个数
    int number=min(oldLength,newLength);
    //复制元素
    copy(a,a+number,temp);
    //释放旧的元素内存空间
    delete[] a;
    a=temp;
}



#endif // ARRAYLIST_H


