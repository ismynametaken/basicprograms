#include <iostream>

using namespace std;

typedef unsigned char BOOL; 
typedef union 
{
    struct
    {
        unsigned char a:2;
        BOOL b:1;
        unsigned int :4;
        BOOL c:1;
    }st ;
    unsigned char it; 
}str; 

struct s2
{ 
    unsigned int d;
    unsigned char a:2;
    BOOL b:1;
    unsigned char :0;
    unsigned char c:1;
    unsigned char :0;
}__attribute__((aligned(32)));


int main(void)
{

 str s;
 s2 a;
 s.it = 0;
 s.st.a = 2; 
 s.st.b = 1;
 s.st.c = 1;

 cout << (int) s.it << endl;
 cout << sizeof(a)<< endl; 
}