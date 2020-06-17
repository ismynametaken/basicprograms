// CPP program to demonstrate working of map 
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>

using namespace std; 

int main() 
{ 
    map<int, pair<int, string>> m;
    m.insert({3, {3, "Three"}});
    pair<int, string> p = {1, "One"};
    pair<int, string> p2 = make_pair(2, "Two");
    m.insert(make_pair(1, p));
    m.insert(make_pair(3, p2));
    for(auto it:m)
        cout << '[' << it.first << ", { " << it.second.first << ", " << it.second.second << "} ]" << endl;
    return(0);

} 


