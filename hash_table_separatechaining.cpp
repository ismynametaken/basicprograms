#include <iostream>
#include <list>

using namespace std;
#define SIZEOFHASH 50

typedef struct keyValue
{
    int key;
    string value;
} keyValue ;


class HashTable
{
    public:
        HashTable(int size);
        bool insert(const keyValue &);
        bool remove(int key);
        keyValue find(int key);
        void printhashtable(void);
        ~HashTable();

    private:
        list<keyValue> *bucket;
        int bucketsize;
        int hashFunction(int);
};

HashTable::HashTable(int size):bucketsize(size)
{
    bucket = new list<keyValue>[size];
}

HashTable::~HashTable()     
{ 
    for(int i=0; i <bucketsize; i++)
    {
        bucket[i].clear();       
    }

    delete[] bucket;
}

int HashTable::hashFunction(int key)
{
    return(key%bucketsize);
}

void HashTable::printhashtable(void)
{
     for(int i=0; i <bucketsize; i++)
    {
        cout << "Bucket[" << i << "]" << endl;
        for(auto iter = bucket[i].begin(); iter != bucket[i].end(); iter++)
        {
            cout << "Key: " << iter->key << "   Value: " << iter->value << endl;
        }      
    }   
}
bool HashTable::insert(const keyValue &kv)
{
    if(find(kv.key).key != -1)
    {
        cout << kv.key << " - Key Already found, not inserting" << endl;
        return(false);
    }
    cout << kv.key << " - Key Not found, inserting" << endl;
    int hashIndex = hashFunction(kv.key);
    bucket[hashIndex].push_back(kv);
    return(true);
}

bool HashTable::remove(int key)
{
    int hashIndex = hashFunction(key);
    for(auto iter = bucket[hashIndex].begin(); iter !=bucket[hashIndex].end();iter++)
    {
        if(iter->key == key)
        {
            bucket[hashIndex].erase(iter);
            return(true);
        }
    }
    return false;
}

keyValue HashTable::find(int key)
{
    int hashIndex = hashFunction(key);
    keyValue kvfound = {-1, ""};

    for(auto iter = bucket[hashIndex].begin(); iter !=bucket[hashIndex].end();iter++)
    {
        if(iter->key == key)
        {
            kvfound = *iter;
        }
    }
    return kvfound;
}


int main(void)
{
    HashTable myhash(SIZEOFHASH);
    srand((unsigned int)time(NULL));
    for(int i= 0; i < 100;i++)
    myhash.insert({rand()%100, "Something"});
    myhash.printhashtable();

    cout << "Find 20: " << myhash.find(20).key << endl;
    cout << "Find 21: " << myhash.find(21).key << endl;
    cout << "Remove 501: " << myhash.remove(501) << endl; 
    myhash.printhashtable();
    return(0);
}


