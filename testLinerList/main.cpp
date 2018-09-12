#include <QCoreApplication>
#include "arraylist.h"

#include "chain.h"
#include "iostream"
using namespace std;

int main()
{
    //QCoreApplication a(argc, argv);

//    arrayList<double> list(10);
//    cout<<list.capacity();
//    cout<<endl;

//    list.insert(0, 0);
//    list.insert(1, 1);
//    list.insert(2, 2);
//    list.insert(3, 3);
//    list.insert(4, 4);
//    list.insert(5, 5);
//    list.insert(6, 6);
//    list.insert(7, 7);


////    list.insert(0, 7);
////    list.insert(1, 6);
////    list.insert(2, 5);
////    list.insert(3, 4);
////    list.insert(4, 3);
////    list.insert(5, 2);
////    list.insert(6, 1);
////    list.insert(7, 0);
//    cout << list;
//    cout << endl;

//    cout<<list.get(7)<<endl;

//    //对于插入有疑问
//    list.insert(4, 100);
//    cout << list;
//    cout << endl;

//    list.erase(2);
//    cout << list;
//    cout << endl;

//    cout<<list.indexof(8)<<endl;

//    list.insert(10, 7);
//    cout << list;
//    cout << endl;


    chain<int> list(10);
    for (int i = 0; i < 9; i++)
        list.insert(i,i);
    cout << list << endl;
    list.insert(4, 100);
    cout << list;
    cout << endl;
    list.erase(2);
    cout << list << endl;
    cout<<list.get(3)<<endl;
//    cout<<list.indexof(8)<<endl;
//    cout << list.empty() << endl;
//    list.clear();
//    cout << list << "        " << list.empty() << endl;

    return 0;
}
