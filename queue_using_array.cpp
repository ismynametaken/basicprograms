#include <iostream>
#include <vector>
using namespace std;

class queue
{
    private:
        int maxSize;
        int currentSize;
        int insertIndex;
        int deleteIndex;
        int *array;
        bool isEmpty();
        bool isFull();
    public:
        queue(int size);
        ~queue();
        bool enqueue(int);
        bool dequeue(int&);

};

queue::queue(int size):currentSize(0), maxSize(size), insertIndex(0), deleteIndex(0)
{
    array = new int[size];
}

queue::~queue()
{
    delete[] array;
}

bool queue::isEmpty()
{
    if(currentSize == 0)
        return(true);
    else
        return(false);
}

bool queue::isFull()
{
    if(currentSize==maxSize)
        return true;
    else
        return false;
}
bool queue::enqueue(int a)
{
    if(isFull())
        return false;
    else
    {
        array[insertIndex++] = a;        
        insertIndex%=maxSize;
        currentSize++;
        return true;
    }

}

bool queue::dequeue(int &a)
{
    if(isEmpty())
        return false;
    else
    {
       a = array[deleteIndex++];
       deleteIndex%=maxSize;
       currentSize--;;
       return true;
    }

}
int main(void)
{
    queue q(5);
    int b;
    
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(20) << endl;
    cout << q.enqueue(30) << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout << q.enqueue(40) << endl;
    cout << q.enqueue(50) << endl;
    cout << q.enqueue(60) << endl;
    cout << q.enqueue(70) << endl;
    cout << q.enqueue(80) << endl;
    cout << q.enqueue(90) << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    return(0);
}