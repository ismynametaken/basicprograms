#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
    private:
        vector<int> heaparray;
        int smallerChild(int parentIndex);
    public:
        MinHeap(void) { heaparray.push_back(INT_MAX); } //Invalid entry, heap starts at 1 
        bool getMin(int &a);
        void insert(int);
        void heapify();
        void heapsort(const vector<int>&);
        void swap(const int a, const int b);
        void printheap(void);
};

int MinHeap::smallerChild(int parentIndex)
{
    if(2*parentIndex > (heaparray.size()-1))
        return(0);
    else if (2*parentIndex == (heaparray.size()-1)) //One child
    {
        return(2*parentIndex);
    }
    else if((2*parentIndex+1) <= (heaparray.size()-1)) //Two children
    {
        if(heaparray[2*parentIndex] <= heaparray[2*parentIndex+1])
            return(2*parentIndex);
        else
            return(2*parentIndex+1);
    }
    return(0);
}

void MinHeap::printheap(void)
{
    for(int i:heaparray)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool MinHeap::getMin(int &a)
{
    if(heaparray.size() <= 1) return false;

    a = heaparray[1];
    int parInd = 1;
    heaparray[1] = heaparray[heaparray.size()-1];
    heaparray.pop_back();
    int chiInd = smallerChild(parInd);
    while((heaparray[parInd] > heaparray[chiInd]) && (chiInd!=0))
    {
        swap(parInd, chiInd);
        parInd = chiInd;
        chiInd = smallerChild(parInd);
    }
    return(true);
    
}

void MinHeap::swap(const int i, const int j)
{
    int temp = heaparray[i];
    heaparray[i] = heaparray[j];
    heaparray[j] = temp;
}

void MinHeap::insert(int a)
{
    heaparray.emplace_back(a);

    int chiInd = heaparray.size()-1;
    int parInd = chiInd/2;

    while((heaparray[chiInd] < heaparray[parInd]) && (chiInd > 1))
    {
        swap(chiInd,parInd);
        chiInd/=2;
        parInd/=2;
    }
}

void MinHeap::heapify()
{
    int startIndex = (heaparray.size()-1)/2;
    int parInd = startIndex;
    int chiInd = smallerChild(parInd);
    while(startIndex >=1)
    { 
        while((heaparray[parInd] > heaparray[chiInd]) && (chiInd!=0))
        {
            swap(parInd, chiInd);
            parInd = chiInd;
            chiInd = smallerChild(parInd);
        }
        parInd = --startIndex;
        chiInd = smallerChild(parInd);
    }

}

void MinHeap::heapsort(const vector<int> &arr)
{
    heaparray.insert(heaparray.begin()+1, arr.begin(), arr.end());
    heapify();
}


int main(void)
{
    vector<int> A = {14, 12, 4, 3, 18, 23, 7, 6};
    MinHeap h1, h2;
    int min;
    vector<int> B = {4, 2, 10, 8, 7, 1, 2, 9, 0, 5, 0, 6};
    h1.heapsort(A);

    for(int i:B)
    {
        h2.insert(i);
    }

    cout << "Printing Heap H1" << endl;
    h1.printheap();

    cout << "Printing Sorted array H1" << endl;
    while(h1.getMin(min))
        cout << min << " " ;
    cout << endl;

    cout << "Printing Heap H2" << endl;
    h2.printheap();
 
   cout << "Printing Sorted array H2" << endl;
    while(h2.getMin(min))
        cout << min << " " ;
    cout << endl;

}