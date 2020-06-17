#include <iostream>

using namespace std;


class c1
{
    public:
        int i;
        int j;
        c1(int x ) { i = x; j = 5*x;}
        int double_val() { return(i+i);}
};

int main()
{
    c1 ob1(1), ob2(2), ob3(3);
    int* p = &ob2.i;
    cout << "value at p = " << *p << endl;

    int c1::*cp; 
    int c1::*cp2; 
    int (c1::*fp)();
    c1 *ptr;

    cp = &c1::i;
    cp2 = &c1::j;
    fp = &c1::double_val;
    ptr = &ob3; 

    cout << "Offset of i = " << cp << endl;
    cout << "Offset of j = " << cp2 << endl;
    cout << "Offset of double_val = " << fp << endl;

    cout << ob1.*cp << endl;
    cout << (ob2.*fp)() << endl;
    cout << ptr->*cp << endl;
    cout << (ptr->*fp)() << endl;

    return 0;
}