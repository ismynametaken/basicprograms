#include <iostream>
#include <vector>
using namespace std;
#define INITIAL_SIZE 0
#define INVALID_INT -999999
class stack
{
private:
    int currentSize;
    vector<char> chararray;
    bool isFull();
    bool isEmpty();
public: 
    stack(int n);
    char pop(void);
    bool push(char c);
    int findSize(void);
    bool checkMatch(char c);
};


stack::stack(int n):currentSize(0)
{
    chararray.resize(n);
}

bool stack::isEmpty()
{
    return(currentSize==INITIAL_SIZE);
}

bool stack::isFull()
{
    return(currentSize==chararray.size());
}
char stack::pop(void)
{
    if(isEmpty())
    {
        return((char)NULL);
    }
    else
    {
        return(chararray[--currentSize]);
    }

}

bool stack::push(char c)
{
     if(isFull())
    {
        return(false) ;
    }
    else
    {
        chararray[currentSize++] = c;
        return(true);
    }
}

int stack::findSize(void)
{
    return(currentSize);
}

class parser
{
    private: 
        char* pString;
    public:
        parser(char *s);
        ~parser();
        bool checkMatch(void);
};

parser::parser(char *s)
{
    pString = new char[strlen(s)];
    strcpy(pString, s);
}

parser::~parser()
{
    delete[] pString;
}

bool parser::checkMatch(void)
{
    int len = strlen(pString);
    stack st(len);

    for(int i=0; i < len; i++)
    {
        char ch;
        switch(pString[i])
        {
            case '{':
            case '[':
            case '(':
                st.push(pString[i]);
                break;
            case '}':
            case ']':
            case ')':
                ch = st.pop();
                cout << "Stack Length: " << st.findSize() << endl;
                if(
                    (ch == char(NULL))
                        ||
                    (
                        (pString[i]== '}' && ch!='{') ||
                        (pString[i]== ']' && ch!='[') ||
                        (pString[i]== ')' && ch!='(')

                    )
                )
                    return(false);
                else
                    break;
            default:
                break;
        }
    }

    if(st.findSize()== 0)
        return(true);
    else
        return(false);

}


int main(int argc, char* argv[])
{
    parser p(argv[1]);

    cout <<  p.checkMatch() << " is the status" << endl;
    return(0);
}