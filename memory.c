#include <stdio.h>
#include <stdlib.h>
#include <"memory.h>

#define TotalMemory 100

typedef struct Mem{
    int *m;// pointer to heaps
    } Mem;

typedef struct Var{
    int start;
    int end;
    Var* ptr;
    } Var;

int avail;
int avail_start;

void init_memory{
    Mem * Memory = malloc(sizeof(Mem));
    Memory->m = malloc(TotalMemory*sizeof(int));

    if (Memory->m==NULL){ //unallocated
        fprintf(stderr, "Not enough memory.\n");
        free(Memory);
        exit(0);
    avail=TotalMemory;
    avail_start=0;
    }
}

Var * Mal(char c,int n){
    if (n>avail){
        fprintf(stderr,"Not enough memory.\n");
        exit(0);
    }
    Var *x = malloc(sizeof(Var));
    //store new start and n in struct
    x->name=c;
    x->start=avail_start;
    x->end=avail_start+n;

    for (int i=x->start; i<x->end; i++){
        NewMemory->m[i]=0;
    }

    avail_start+=n;
    avail-=n;

    return x;
}


