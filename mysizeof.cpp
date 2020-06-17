#include <iostream>
using namespace std;

#define my_sizeof(a) ((char*)(&a+1) - (char*) &a)

int main(void)
{
    double a[2];
    double* pb1 = &a[0];
    double* pb2 = &a[0]+1; 
    double c; 
    cout << "Size : " << my_sizeof(c) << endl;
    cout << "First : " << &a << endl << "Second: " << &a+1 << endl;
    cout << "Difference: " << (char*)pb2 - (char*)pb1 << endl;
    return(0);
}

