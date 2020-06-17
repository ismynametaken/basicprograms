// CPP program to demonstrate working of map 
#include <iostream>
#include <unordered_set>
#include <string>
#include <utility>

using namespace std; 

int main() 
{ 
    unordered_set<string> st;
    string s[] = { "Ram", "Raavan", "Bob", "Hi","Ann"};
    s[0].append("AndLaxman");
    for(string i:s)
    {
        auto it =st.emplace(i);
        if(!it.second)
        {
            cout << i <<" :Could not insert: " << i << endl;
        }
        else
            cout << i << " :Inserted at: " << distance(st.begin(), it.first) << endl;  
    }

    for(auto it2:st)
       cout << it2 <<  endl;
    
    cout << "********************************" << endl;
    st.insert("abc");
    st.insert("tom");
    st.erase("tom");
    st.insert("hello");

    for(unordered_set<string>::iterator it = st.begin(); it != st.end(); it++)
       cout << *it <<  endl; 
    
    st.clear();

    cout << "After Clear: Size = " << st.size() << endl; 
    st.emplace("Ram");
    st.emplace("Ann");
    st.emplace("Bob");
    st.emplace("Ram");
    st.emplace("");
    for(auto it2:st)
       cout << it2 <<  endl;
    return(0);

} 