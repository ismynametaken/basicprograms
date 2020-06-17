#include <iostream>
#include <vector>

using namespace std;


void myswap(vector<int> &arr, int pivotIndex,  int start)
{
    int elemToFix = arr[pivotIndex];
    arr[pivotIndex] = arr[start];
    arr[start] = elemToFix;

}

void merge(vector<int> &arr, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    vector<int> buf; 
    while((i<=mid)&&(j<=end))
    {
        if(arr[i]<= arr[j])
        {
            buf.push_back(arr[i]);
            i++;
        }
        else
        {
            buf.push_back(arr[j]);
            j++;            /* code */
        } 
    }
    while(i<=mid)
    {
        buf.push_back(arr[i]);
        i++; 
    }
    while(j<=end)
    {
        buf.push_back(arr[j]);
        j++; 
    }  

    for(int i = 0; i <= end-start; i++)
    {
        arr[start+i] = buf[i];
    }
}

void mergesorthelper(vector<int> &arr, int start, int end)
{
    if(start>=end)
        return;
    
    int mid = (start+end)/2;

    mergesorthelper(arr, start, mid);
    mergesorthelper(arr, mid+1, end);

    merge(arr, start, mid, end);
}

void mergesort(vector<int> &arr)
{   
    mergesorthelper(arr, 0, arr.size()-1);
}

int main(void)
{
    vector<int> arr = {4, 2, 10, 8, 7, 1, 9, 0, 1,2, 2, 5, 6};

    mergesort(arr);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;
    return(0);
}

