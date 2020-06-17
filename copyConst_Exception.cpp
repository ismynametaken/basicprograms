#include <iostream>

using namespace std;


class myclass
{
    private:
        int *arr;
        int size;

    public:
        myclass(const myclass& a)
        {
            size = a.size;
            try
            {
                arr = new int[a.size];
            }
            catch(bad_alloc e)
            {
                exit(EXIT_FAILURE);
            }
        }

}; 
int main(void)
{

    

    return(0);
}