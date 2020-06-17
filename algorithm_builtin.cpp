#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool greater_than(const int& a, const int& b)
{
  return a > b;
}

bool less_than(const int& a, const int& b)
{
  return a < b;
}


int main()
{
  vector<int> v = {5, 1, 2, 4, 3};
  sort(v.begin(), v.end(), greater_than);
  for(auto it: v)
    cout << it << ' ';
  sort(v.begin(), v.end(), less_than);
  for(auto it: v)
    cout << it << ' ';

}