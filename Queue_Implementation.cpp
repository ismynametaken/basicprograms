#include <iostream>
using namespace std;

struct node
{
    int value; 
    node* next;
};

class queue
{
private:
    int currentQSize;
    node *head;
    node *tail;
public:
    queue(void);
    int dequeue(void);
    bool enqueue(int n);
    int findSize(void);
};

queue::queue(void):currentQSize(0), head(NULL), tail(NULL)
{
}

int queue::dequeue(void)
{
    //Empty Q
    if(head==NULL)
    {
        cout << "No element to be returned" << endl;
        return(-1);

    }
    else
    {
        int val = head->value;
        node* temp = head;
        head = head->next;
        delete temp;
        currentQSize--;
        return(val);
    }
}

bool queue::enqueue(int n)
{
    node* newNode = new node;
    newNode->value = n;
    newNode->next = NULL;
    
    //No elements
    if((head==NULL) && (tail==NULL))
    {
        head = newNode; 
    }
    else //More than one element 
    {
     tail->next = newNode;
    }
    tail = newNode;
    currentQSize++;
    return(true);
}

int queue::findSize(void)
{
    return(currentQSize);
}

int main()
{
    queue q;
    int qSize;
    int a[] = { 5, 4, 3, 2, 1};
    for(int i = 0; i < 5; i++ )
    {
        if(!q.enqueue(a[i]))
            break;
        cout << "Size of Q after Enqueue = " << q.findSize()<< endl;
    }
    
    while(q.findSize())
    {
        cout << q.dequeue() << endl;
        cout << "Size of Q after Dequeue = " << q.findSize()<< endl;
    }

    return(0);
}