//Range based for loop 
#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main()
{
    enum class colors {violet, indigo, blue, green, yellow, orange, red};
    enum color {violet, indigo, blue, green, yellow, orange, red};
    colors c = colors::violet; 
    color co = violet; 
    int x = indigo;

    vector<int> a = {6, 7, 8, 9, 10};

    for(unsigned int i: a)
        cout << i << " "; 

    exit(0);
}