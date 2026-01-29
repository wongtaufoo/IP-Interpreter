#include <stdio.h>
#include <stdlib.h>
#include "memory.h"


Mem* Memory;

void init_memory(void){

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
        free(Memory->m);
        free(Memory);
        fprintf(stderr, "Not enough memory.\n");
        exit(0);
    }

    Memory->avail_cells=TotalMemory;
    Memory->head->start=0;
    Memory->head->end=TotalMemory;
    Memory->head->next=NULL;
    }

AssignedBlock * allocate(int n){
    if (n>Memory->avail_cells || n<=0 || Memory==NULL){
        return NULL;
    }
    EmptyBlock **prev= &Memory->head;
    EmptyBlock *current= Memory->head;

    while (current!=NULL){
        int size= current->end-current->start;
        if (n<=size){
            AssignedBlock *New = malloc(sizeof(AssignedBlock));
            if (New==NULL){
                fprintf(stderr, "Not enough memory.\n");
                exit(0);
            }
            New->start= current->start;
            New->end=New->start+n;

            //if empty block larger than needed, block is split and start of empty block updated
            if (n<size){
                current->start+=n;
            }else{ // perfect fit, current cell is now assigned
                *prev=current->next;
                free(current);
            }
            for (int i = New->start; i < New->end; i++) {
                Memory->m[i] = 0;
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
    if (b==NULL||Memory==NULL)return;

    EmptyBlock *newFree=malloc(sizeof(EmptyBlock));
    if (newFree==NULL){
        fprintf(stderr, "Not enough memory.\n");
        exit(0);
    }
    newFree->start=b->start;
    newFree->end=b->end;

    newFree->next=Memory->head; //add to beginning of empty block list
    Memory->head=newFree;
    int size= b->end-b->start;
    Memory->avail_cells+=size;

    free(b);
}

int read_cell(int position){
    if (position>=TotalMemory||position<0){
        fprintf(stderr,"Wrong Memory Access.\n");
        exit(0);
    }
    return Memory->m[position];
}

void write_cell(int position, int value){
    if (position>=TotalMemory||position<0){
        fprintf(stderr,"Wrong Memory Access.\n");
        exit(0);
    }
    if(position>=0 && position<TotalMemory){
        Memory->m[position]=value;
    }
    return;
}


void free_memory(void) {
    if (Memory==NULL) return;

    // free the linked list of empty blocks
    EmptyBlock *cur = Memory->head;
    while (cur) {
        EmptyBlock *next = cur->next;
        free(cur);
        cur = next;
    }
    free(Memory->m);
    free(Memory);
    Memory = NULL;
}

