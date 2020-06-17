#include <iostream>
#include <vector>

using namespace std;
#define SIZEOFHASH 100

typedef struct
{
    int key;
    string value;
} keyValue ;


class HashTable
{
    public:
        HashTable(int size)
        {
            kvp.resize(size);
            for(int i = 0; i < kvp.size(); i++)
            {
                kvp[i].key = -1;
                kvp[i].value = "";
            }
        }
        bool insert(const keyValue &);
        bool remove(int key);
        keyValue find(int key);
        void printhashtable(void);
    private:
        vector<keyValue> kvp;
        int hashFunction(int);
};


void HashTable::printhashtable(void)
{
    for(int i = 0 ; i < SIZEOFHASH; i++)
    {
        if(kvp[i].key != -1)
        {
            cout << "Index: " << i << "   Key: " << kvp[i].key << "  Value: " << kvp[i].value << endl;
        }
    }
}
int HashTable::hashFunction(int key)
{
    return(key%SIZEOFHASH);
}
bool HashTable::insert(const keyValue &kv)
{
    int hashIndex = hashFunction(kv.key);
    int startIndex = hashIndex;
    while((kvp[hashIndex].key!=-1))  //Increment index till an empty slot is found
    {
        (++hashIndex)%SIZEOFHASH;
        if(hashIndex==startIndex)  //Avoid repeated search cycle
            return false;
    }
    kvp[hashIndex] = kv;
    cout << kv.key << ": Started search at " << startIndex << "  and Inserted at: " << hashIndex << endl;
    return(true);

}

bool HashTable::remove(int key)
{
    int hashIndex = hashFunction(key);
    int startIndex = hashIndex;
    while((kvp[hashIndex].key!=key) && (kvp[hashIndex].key!=-1))
    {
        (++hashIndex)%SIZEOFHASH;
        if(hashIndex==startIndex)  //Avoid repeated search cycle
            return false;
    }
    if(kvp[hashIndex].key == -1)
        return false;
    else if(kvp[hashIndex].key == key)
    {
        kvp[hashIndex].key = -1;
        kvp[hashIndex].value = "";
    }

    return true;
}

keyValue HashTable::find(int key)
{
    int hashIndex = hashFunction(key);
    int startIndex = hashIndex;
    keyValue kv = {-1, ""};
    while((kvp[hashIndex].key!=key) && (kvp[hashIndex].key!=-1))
    {
        (++hashIndex)%SIZEOFHASH;
        if(hashIndex==startIndex)  //Avoid repeated search cycle
            return kv;

    }
    if(kvp[hashIndex].key == -1)
        return kv;
    else if(kvp[hashIndex].key == key)
    {
        return(kvp[hashIndex]);
    }
}


int main(void)
{
    HashTable myhash(SIZEOFHASH);
    cout << boolalpha <<  myhash.insert({1, "One"}) << endl;
    cout << myhash.insert({501, "Five zero One"}) << endl;
    cout << myhash.insert({20, "Twenty"}) << endl;
    srand((unsigned int)time(NULL));
    for(int i= 0; i < 100;i++)
    cout << boolalpha <<  myhash.insert({rand()%100, "Something"}) << endl;
    myhash.printhashtable();

    cout << "Find 20: " << myhash.find(20).key << endl;
    cout << "Find 21: " << myhash.find(21).key << endl;
    cout << "Remove 501: " << myhash.remove(501) << endl; 
    myhash.printhashtable();
    return(0);
}


