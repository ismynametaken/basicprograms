#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;


class mempool
{
   public:
    mempool(long unsigned poolsize, unsigned int blocksize);
    ~mempool();
    void* retrieveblock(void);
    void returnblock(void*);
  
   private:
     void initialize(void);
     int poolsize;
     int blocksize;
     list<unsigned int> freelist;
     unordered_set<unsigned int> allocatedlist;
     char* pPoolStart;
     bool isInitialized; 
};

mempool::mempool(long unsigned poolsize, unsigned int blocksize): poolsize(poolsize), blocksize(blocksize), isInitialized(false)
{
    pPoolStart = new char[poolsize];
}

mempool::~mempool()
{
    if(!allocatedlist.empty())
    {
        cout << "Not all the blocks have been returned" << endl;
    }

    delete[] pPoolStart;
}


void mempool::initialize(void)
{
   for(size_t i=0; i < poolsize/blocksize; i++)
   {
      freelist.push_back(i);
   }
}

void* mempool::retrieveblock()
{
  if(!isInitialized)
    initialize();
  if(!freelist.empty()) //Check if freelist is not empty
  {
     unsigned int blockId = freelist.front();
     cout << "Block allocated: " << blockId << endl;
     freelist.pop_front();
     allocatedlist.insert(blockId);
     return((void*)(pPoolStart + blockId*blocksize));
  }
  else
      return NULL;
}

void mempool::returnblock(void* pBlock)
{
    unsigned int blockId = ((char*)pBlock - pPoolStart)/blocksize;
    if(allocatedlist.find(blockId) != allocatedlist.end())  //found
    {
        allocatedlist.erase(blockId);
        freelist.push_back(blockId);
        cout << "Returned back to free list: " << blockId << endl;
    }
    else
    {
        cout << "Block Never Allocated: " << blockId << endl; 
    }    
}

#define BLOCKS_REQUESTED 10

// To execute C++, please define "int main()"
int main() {
  
  mempool myfirstpool(10000, 500);
    
  void* p[BLOCKS_REQUESTED];
    
  for(size_t i = 0; i < sizeof(p)/sizeof(void*); i++)
  {
    p[i] = myfirstpool.retrieveblock(); 
  }
    

  for(size_t i = 0; i < BLOCKS_REQUESTED; i++)
  {
      int blockIndex = rand()%BLOCKS_REQUESTED;
      cout << "Index: " <<  blockIndex << " "; 
      myfirstpool.returnblock(p[blockIndex]);
  }
  
  return 0;
}
