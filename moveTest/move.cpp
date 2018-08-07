#include "Move.h"
#include <iostream>
using namespace std;
//Move::Move()
//{

//}

Move::Move(double a, double b)
{
    x=a;
    y=b;

}

void Move::showMove() const
{
    cout<<"x: "<<x<<"; "<<"y: "<<y;


}

//Move &Move::add(const Move &m) const
//{
//    Move* m1 = new Move;
//    m1->x+=m.x;
//    m1->y+=m.y;
//    return *m1;

//}

//Move Move::add(const Move &m) const
//{
//    Move m1;
//    m1.x+=m.x;
//    m1.y+=m.y;
//    return m1;

//}

void Move::reset(double a, double b)
{

    x=a;
    y=b;

}

Move Move::Add(const Move &m) const
{
    Move m1;
    //m1是中间值， 此处是将m的x，y与调用对象的x,y相加，返回给m1，不是将m的值和中间值的x，y相加
    //且m1是通过默认构造函数生成的x,y分别是0，0，所以下面代码不管怎么更新m，其x,y都是递增了0值
//    m1.x += m.x;
//    m1.y += m.y;

    m1.x=m.x+x;
    m1.y=m.y+y;
    //上述同加this的写法是一致的
//    m1.x=m.x+this->x;
//    m1.y=m.y+this->y;

    return m1;

}

//Move Move::Add1( Move &m)
//{
////    Move m1;
////    m1.x=m.x+x;
////    m1.y=m.y+y;
//    m.x+=x;
//    m.y+=y;

//    return m;

//}

void Move::Add2(double x1,double y1)
{
    //实验+=这个操作符
    x+=x1;
    y+=y1;

}

Move::~Move()
{


}
