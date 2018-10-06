﻿#ifndef CHAIN_H
#define CHAIN_H
//#pragma once
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include"linerList.h"
#include <algorithm>
#include<string>
#include<iterator>
using namespace std;


//链表节点的结构表示
template <class T>
struct chainNode
{
    //数据域
    T element;
    //指针域
    chainNode<T> *nextNode;

    //默认构造函数
    chainNode(){}
    //构造函数
    chainNode(const T&element){this->element=element;}
    chainNode(const T& element,chainNode<T>*next)
    {
        this->element=element;
        this->nextNode=next;
    }
};

template<class T>
class chain:public linerList<T>
{
public:
    //构造函数，复制构造函数和析构函数
    chain(int initialCapacity=10);
    chain(const chain<T>&theList);
    ~chain();

    //抽象数据类型的ADT方法
    //判断线性表是否为空，若为空返回true
    bool empty() const{return listSize==0;}
    //返回线性表的元素个数
    int size() const{return listSize;}
    //返回索引为theIndex的元素
    T &get(int theIndex)const;
    //返回元素theElement第一次出现的索引
    int indexof(const T&theElement)const;
    //删除索引为theIndex的元素
    void erase(int theIndex);
    // 把theElement插入到索引为theIndex的位置上
    void insert(int theIndex,const T &theElement);
    //输出元素
    void output(ostream &out)const;

    //其他方法
    //清空表
    void clear();

protected:
    //如果索引无效，抛出异常
    void checkIndex(int theIndex)const;
    //指向链表的第一个节点的指针
    chainNode<T>*firstNode;
    //线性表中元素个数
    int listSize;


};


template<class T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity<1)
    {
        cerr << "Initial Capacity=" << initialCapacity << "must be>0";
        exit(0);
    }
    firstNode=NULL;
    listSize=0;

}

//复制构造函数
template<class T>
chain<T>::chain(const chain<T> &theList)
{
    listSize=theList.listSize;
    //链表为空时
    if(listSize==0)
    {
        firstNode=NULL;
        return;
    }

    //链表非空时  迷糊
    //复制链表theList的firstNode
    chainNode<T>* sourceNode = theList.firstNode;
    //复制链表theList的首元素
    firstNode = new chainNode<T>(sourceNode->element);
    //复制链表theList的nextNode
    //sourceNode = sourceNode->nextNode;
    nextNode = sourceNode->nextNode;

    chainNode<T>*targetNode = firstNode;
    while (sourceNode!=NULL) {
        targetNode->nextNode = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->nextNode;
        sourceNode = sourceNode->nextNode;
    }
    targetNode->next=NULL;

}
//析构函数,删除所有节点，最后firstNode为NULL
template <class T>
chain<T>::~chain()
{
    while(firstNode!=NULL)
    {
        chainNode<T>*nextNode=firstNode->nextNode;
        delete firstNode;
        firstNode=nextNode;
    }
}
//找到索引为theIndex的元素
template<class T>
T &chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T> *currentNode=firstNode;

    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->nextNode;

    return currentNode->element;

}
//返回元素theElement首次出现的索引，没找到返回-1
template<class T>
int chain<T>::indexof(const T &theElement) const
{
    chainNode<T>*currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL && currentNode->element!=theElement)
    {
        currentNode=currentNode->nextNode;
        index++;
    }

    if(currentNode==NULL)
        return -1;
    else
        return index;
}
//删除索引为theIndex的元素
template<class T>
void chain<T>::erase(int theIndex)
{
    //索引无效的情况
    checkIndex(theIndex);
    //索引有效
    chainNode<T>*deleteNode;
    //如果在首位置，删除首节点
    if(theIndex==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->nextNode;
    }
    else//找到位置后删除节点，p指向删除节点的前驱
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex;i++)
            p=p->nextNode;//假设是5，则p是指的4，p的下一个才是要删除的5
        deleteNode=p->nextNode;
        //删除指针
        p->nextNode=p->nextNode->nextNode;

    }

    listSize--;
    delete deleteNode;

}
//插入元素theElement并使其索引为theIndex
template<class T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    if(theIndex<0 || theIndex>listSize)
    {

        cerr << "index:" << theIndex << " must be > 0 and <= " << listSize;
        exit(0);
    }

    if(theIndex==0)//在表头插入
        firstNode=new chainNode<T>(theElement,firstNode);
    else//先找到位置，p为指示器在p后面插入
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
            p=p->nextNode;
        p->nextNode=new chainNode<T>(theElement,p->nextNode);

    }
    listSize++;
}
//输出链表
template<class T>
void chain<T>::output(ostream &out) const
{
    for(chainNode<T>* currentNode=firstNode;currentNode!=NULL;currentNode=currentNode->nextNode)
        out << currentNode->element << " ";
}
//清空
template<class T>
void chain<T>::clear()
{
    while (firstNode!=NULL) {
        chainNode<T> *nextNode1=firstNode->nextNode;
        delete firstNode;
        firstNode=nextNode1;
    }
}
//输出链表
template<class T>
ostream& operator <<(ostream &out,const chain<T>& x)
{
    x.output(out);
    return out;
}
//确定索引在0和listSize-1 之间
template<class T>
void chain<T>::checkIndex(int theIndex) const
{
    if(theIndex<0 || theIndex >=listSize)
    {
        cerr << "index:" << theIndex << " must be > 0 and <= " << listSize;
        exit(0);
    }
}




#endif // CHAIN_H