#include <QCoreApplication>
#include <move.h>
using namespace std;
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Move move1(2,4);
    cout<<"initialization: ";
    move1.showMove();

    cout<<endl;
//    move1.reset(3,8);
//    cout<<"reset: ";
//    move1.showMove();
//    cout<<endl;

    //值得注意
    Move move2(4,3);
    Move temp;
    //因add是const成员函数，故不会修改调用const函数的 move1对象里面的值
    //move1.Add(move2);

    temp=move1.Add(move2);
    temp.showMove();
    cout<<endl;

    Move temp1;
    temp1=move1.Add(move2);
    temp1.showMove();
    cout<<endl;

    move1.Add2(2.0,2.0);
    move1.showMove();

    return 0;
}
