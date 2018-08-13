#include <QCoreApplication>
#include <complex0.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    complex0 aa(3.0,4.0);
    complex0 c;
    complex0 temp;

    cout<<"enter a complex number (q to quit): \n";

    while (cin>>c) {
        cout << "c is "<< c << '\n';
        cout << "complex conjugate is " << ~c <<'\n';
        cout << "aa is: " << aa << '\n';
        cout << "aa+c is: " << aa+c << '\n';
        cout << "aa-c is: " << aa-c << '\n';
        cout << "aa*c is: " << aa*c << '\n';
        cout << "c*2 is: " << c*2 << '\n';

        cout << "2.0*c is: " << 2*c << '\n';

        cout << "c+2 is: " << c+2 << '\n';

        cout << "enter a complex number (q to quit): \n";

    }
    cout <<"done !\n";
    return 0;


    return a.exec();
}
