// CPP program to demonstrate working of map 
#include <iostream>
#include <set>
#include <string>
#include <utility>

using namespace std; 

int main() 
{ 
    set<string> st;
    st.insert("tom");
    st.insert("hello");
    st.insert("abc");

    for(set<string>::iterator it = st.begin(); it != st.end(); it++)
       cout << *it <<  endl; 
    
    st.clear();

    cout << "After Clear: Size = " << st.size() << endl; 
    st.emplace("Ram");
    st.emplace("Ann");
    st.emplace("Bob");
    
    pair<set<string>::iterator, bool> p;
    p = st.emplace("Ram");
    if (!p.second) 
    {
        cout << "value was already present in the set at " << distance(st.begin(),p.first) << endl;
    }   
    st.emplace("");

    string s[] = { "Ram", "Raavan", "Hello", "Hi","Ann"};
    for(string i:s)
    {
        set<string>::iterator it =st.find(i);
        if(it == st.end())
        {
            cout << "Not found" << endl;
        }
        else
            cout << "Found: " << distance(st.begin(), it) << endl;  
    }
    for(auto it2:st)
       cout << it2 <<  endl;

    cout << "********************************" << endl;
    
    for(string i:s)
    {
        auto it =st.insert(i);
        if(!it.second)
        {
            cout << i <<" :Could not insert: " << i << endl;
        }
        else
            cout << i << " :Inserted at: " << distance(st.begin(), it.first) << endl;  
    }

    for(auto it2:st)
       cout << it2 <<  endl;

return(0);
} 