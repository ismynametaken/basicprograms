#include <iostream>
#include <vector>
using namespace std;

class queue
{
    private:
        int maxSize;
        int currentSize;
        int *array;
        bool isEmpty();
        bool isFull();
    public:
        queue(int size);
        ~queue();
        bool enqueue(int);
        bool dequeue(int&);
        void printQueue(void);

};

queue::queue(int size):currentSize(0), maxSize(size)
{
    array = new int[size];
}

queue::~queue()
{
    delete[] array;
}

void queue::printQueue()
{
    cout << "Queue: ";
    for (int i = 0; i < currentSize; i++)
    {
        cout << array[i] << " " ; 
    }
    cout << endl;
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
    else if (currentSize==0)
    {
        array[currentSize++] = a;
        return true;
    }  
    else
    {   
        int i;
        for( i=currentSize-1; i>=0; i--)
        {
            if(a>array[i])
            {
                array[i+1] = array[i];
            }
            else
                break;
            
                        
        }
        array[i+1] = a;
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

       a = array[--currentSize];
       return true;
    }

}
int main(void)
{
    queue q(5);
    int b;
    
    cout << q.enqueue(5) << endl;
    cout << q.enqueue(30) << endl;
    cout << q.enqueue(20) << endl;
    q.printQueue();
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(30) << endl;
    cout << q.enqueue(20) << endl;
    cout << q.enqueue(50) << endl;
    cout << q.enqueue(50) << endl;
    q.printQueue();
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    cout <<  q.dequeue(b) << ": " << b << endl;
    return(0);
}