#include <iostream>
using namespace std;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp; 
}
void bubble_sort(int *a, int n)
{
    for(int i = n-1; i >=1; i--)
    {
        for(int j = 0; j<i; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a+j, a+j+1);
            }
        }
    }
}

void selection_sort(int *a, int n)
{
    int  min_index;

    for(int i = 0; i < n-1; i++)
    {
        min_index = i;
        for(int j=i+1;j< n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        swap(a+i, a+min_index);
    }
    
}


void insertion_sort(int *a, int n)
{
    int ele;
    for(int i = 1; i <=n-1; i++)
    {
        ele = a[i];
        int j=i-1;
        for(; (j>=0) && (a[j] > ele);j--)
        {
            a[j+1] = a[j]; 
        }
        a[j+1] = ele;
    }
}

int main(void)
{
    int a[] = {14, 12, 4, 3, 18, 23, 7, 6};
    int b[] = {14, 12, 4, 3, 18, 23, 7, 6};
    int c[] = {14, 12, 4, 3, 18, 23, 7, 6}; 
    int n = sizeof(a)/sizeof(int);
    cout << "Array Size = " << n << endl;

    bubble_sort(a, n);
    insertion_sort(b,n);
    selection_sort(c,n);
    
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    for(int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;


    return(0);
}