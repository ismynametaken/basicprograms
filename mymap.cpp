// CPP program to demonstrate working of map 
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>

using namespace std; 

int main() 
{ 
    set<string> st;
    st.insert("tom");
    st.insert("hello");
    st.insert("abc");

    for(auto it:st)
       cout << it <<  endl;
    st.clear();

    cout << "After Clear" << endl;
    
    for(set<string>::iterator it = st.begin(); it < st.end(); it++)
       cout << st. <<  endl;
    return(0);

} 