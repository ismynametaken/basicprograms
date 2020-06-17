#include <iostream>
#include <vector>

using namespace std;


void myswap(vector<int> &arr, int pivotIndex,  int start)
{
    int elemToFix = arr[pivotIndex];
    arr[pivotIndex] = arr[start];
    arr[start] = elemToFix;

}

int partition(vector<int> &arr, int start, int end, int pivotIndex)
{
    myswap(arr, pivotIndex, start);

    int lt = start, gt = start+1;

    while(gt<=end)
    {
        if(arr[gt] > arr[start])
            gt++;
        else //lt or equal
        {
            lt++;
            myswap(arr, lt, gt);
            gt++;
        }
    }
    
    myswap(arr, start, lt);

    return(lt);
}

void quicksorthelper(vector<int> &arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int pivotIndex;
    int sortedIndex;
    srand((unsigned int)time(NULL));
    pivotIndex = start + rand()%(end-start+1);
    cout << "Start: " << start << "  End: " << end << "  Pivot Index: " << pivotIndex << endl; 
    sortedIndex = partition(arr, start, end, pivotIndex);
    quicksorthelper(arr, start, sortedIndex-1);
    quicksorthelper(arr, sortedIndex+1, end);
}

void quicksort(vector<int> &arr)
{   
    quicksorthelper(arr, 0, arr.size()-1);
}


int main(void)
{
    vector<int> arr = {4,2,10,8,7,1, 9, 0, 1,2, 2, 5, 6};

    quicksort(arr);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;
    return(0);
}

