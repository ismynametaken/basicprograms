#include <stdio.h>
#include <stdbool.h>

#define BLOCK_SIZE 20000

char memory[BLOCK_SIZE];

typedef struct mblock
{
    bool free;
    size_t size;
    struct mblock* next;
}memstruct;

memstruct *head = (memstruct *)memory;

void* mymalloc(size_t memsize);
void myfree(void*);
void initialize(void);
void split(memstruct *curr, size_t memsize);
void join(void);

void initialize(void)
{
    head->free = 1;
    head->size = BLOCK_SIZE - sizeof(memstruct);
    head->next = NULL;
    printf("Size of Struct: %lu\n", sizeof(memstruct));
}

void split(memstruct *curr, size_t memsize)
{
    memstruct *newblock = (memstruct*)(curr + sizeof(curr) + memsize);
    newblock->free = 1;
    newblock->next = curr->next;
    newblock->size = curr->size - (memsize+sizeof(memstruct)); //Subtract the old size minus the size allocated
    curr->size = memsize;
    curr->free = 0;
    curr->next = newblock;
    printf("Memory Split : New unallotted mem size = %zu\n", newblock->size );

}
void* mymalloc(size_t memsize)
{
    memstruct *prev, *curr;
    void* memallocated;
    if(memsize==0) return NULL;
    if(!head->size) initialize();

    prev = curr = NULL; 
    curr = head;

    while((curr->size < memsize || curr->free==0) && curr != NULL)
    {
        prev = curr;
        curr = curr ->next;
    }
    if(curr == NULL)
    {
        printf("Can't allocate Memory block of size %lu \n", memsize);
        return(NULL);
    }
    else //Memory found
    {
        if(curr->size == memsize)
        {
            printf("Requested size matches block size: %lu\n", memsize);
            curr->free = 0;
            memallocated = (void*)(++curr);
            return(memallocated);
        }
        else if(curr->size > memsize)
        {
           printf("Requested size %zu less than block size %zu, splitting\n", memsize, curr->size);
           split(curr, memsize);
           memallocated = (void*)(++curr);
           return(memallocated);
        }
    }
    

    return(NULL);
}

void join(void)
{
    memstruct *prev, *curr;
    prev = NULL;
    curr = head;

    while(curr!=NULL && curr->free != 1)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr==NULL)
    {
       printf("Nothing to merge\n");
    }
    else //Found a free block
    {
            prev = curr;
            curr = curr->next;
            while(curr->free == 1)
            {   
                printf("Merging ...\n Size b4 merge = %zu", prev->size);
                prev->size = prev->size + curr->size + sizeof(memstruct);
                printf("Merging ...\n Size after merge = %zu", prev->size);
                prev->next = curr->next;
                prev = curr;
                curr = curr->next;
            }
    }
    return;
}
void myfree(void* memtofree)
{
    memstruct  *curr;
    if(memtofree == NULL)
        return;
    curr = (memstruct*)memtofree--;
    curr->free = 1;
    join(); 
}

int main(void)
{
    initialize();
    void *m1, *m2, *m3, *m4;
    m1 = mymalloc(1000);
    m2 = mymalloc(10);
    myfree(m1);
    m3 = mymalloc(100);
    m4 = mymalloc(200);
    myfree(m2);
    myfree(m3);
    myfree(m4);
    return(0);
}
