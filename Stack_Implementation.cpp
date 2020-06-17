#include <iostream>
using namespace std;
#define INITIAL_SIZE 0
#define INVALID_INT -999999
class stack
{
private:
    int currentSize;
    int maxSize;
    int* array;
    bool isFull();
    bool isEmpty();
public: 
    stack(int n);
    ~stack();
    int pop(void);
    bool push(int n);
    int findSize(void);
};

stack::stack(int n):maxSize(n), currentSize(INITIAL_SIZE)
{
    array = new int[maxSize];
}

stack::~stack()
{
    delete []array;
}

bool stack::isEmpty()
{
    return(currentSize==INITIAL_SIZE);
}

bool stack::isFull()
{
    return(currentSize==maxSize);
}
int stack::pop(void)
{
    if(isEmpty())
    {
        return(INVALID_INT);
    }
    else
    {
        return(array[--currentSize]);
    }

}

bool stack::push(int n)
{
     if(isFull())
    {
        return(false) ;
    }
    else
    {
        array[currentSize++] = n;
        return(true);
    }
}

int stack::findSize(void)
{
    return(currentSize);
}

int main()
{
    stack s(10);
    int a[] = { 15, 14, 13, 12, 11};
    for(int i = 0; i < 5; i++ )
    {
        if(!s.push(a[i]))
            break;
        cout << "Size of Q after Enqueue = " << s.findSize()<< endl;
    }
    
    while(s.findSize())
    {
        cout << "Popped: " << s.pop() << endl;
        cout << "Size of Q after Dequeue = " << s.findSize()<< endl;
    }

    return(0);
}