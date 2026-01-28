#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#define TotalMemory 100


typedef struct Mem{
    int *m;// pointer to heaps
    int avail_cells;
    EmptyBlock *head;
    } Mem;

typedef struct AssignedBlock{ //filled block
    int start;
    int end;
    } AssignedBlock;

typedef struct EmptyBlock{
    int start;
    int end;
    int size=end-start;
    struct EmptyBlock *next; //pointer to next freeblock
}

Mem * Memory;

void init_memory{

    Memory = malloc(sizeof(Mem));

    if (Memory==NULL){ // allocation fail
        fprintf(stderr, "Not enough memory.\n");
        exit(0);
    }

    Memory->m = malloc(TotalMemory*sizeof(int));

    if (Memory->m==NULL){ //point to nothing i.e. allocation fail
        fprintf(stderr, "Not enough memory.\n");
        free(Memory);
        exit(0);
    }

    Memory->head= malloc(sizeof(EmptyBlock));

    if (Memory->head==NULL){ //fail allocation
        fprintf(stderr, "Not enough memory.\n");
        free(Memory->m);
        free(Memory);
        exit(0);
    }

    Memory->avail_cells=TotalMemory;
    Memory->head->start=0;
    Memory->head->end=TotalMemory;
    Memory->head->next=NULL;
    }

AssignedBlock * allocate(int n){
    if (n>avail){
        return NULL;
    }
    EmptyBlock **prev= &Memory->head;
    EmptyBlock *current= Memory->head;

    while (current!=NULL){
        int size= current->end-current->start;
        if (n<=size){
            AssignedBlock *New = malloc(sizeof(AssignedBlock));
            New->start= current->start;
            New->end=New->start+n;

            //if empty block larger than needed, block is split and start of empty block updated
            if (n<size)){
                current->start+=n;
            }
            else{ // perfect fit, current cell is now assigned
                *prev=current->next;
                free(current);
            }
            Memory->avail_cells-=n;
            return New;
        }
        // check next empty block until a block with a size large enough is found
        prev = &current->next;
        current=current->next;
    }
    return NULL; //no empty block found
}

void free_block(AssignedBlock *b){
    if (b==NULL)return;

    EmptyBlock *newFree=malloc(sizeof(EmptyBlock));
    newFree->start=b->start;
    newFree->end=b->end;

    newFree->next=Memory->head; //add to beginning of empty block list
    Memory->head=newFree;
    int size= b->start-b->end
    Memory->avail_cells+=size;

    free(b);
}

int read(int position){
    if (position>=TotalMemory)}

