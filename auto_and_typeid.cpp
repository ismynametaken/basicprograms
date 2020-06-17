// C++ program to demonstrate working of auto 
// and type inference 
#include <typeinfo>
#include <iostream>
using namespace std; 
  
int 
main() 
{ 
    auto x = 4; 
    auto y = 3.37; 
    auto ptr = &x; 
    cout << typeid(x).name() << '\n'
         << typeid(y).name() << '\n' 
         << typeid(ptr).name() << endl; 
  
    return 0; 
} 