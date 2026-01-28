#ifndef MEMORY_H
#define MEMORY_H

#define TOTAL_MEMORY 100

typedef struct EmptyBlock{
    int start;
    int end;
    struct EmptyBlock *next; //pointer to next freeblock
} EmptyBlock;

typedef struct Mem{
    int *m;// pointer to heaps
    int avail_cells;
    EmptyBlock *head;
    } Mem;

typedef struct AssignedBlock{ //filled block
    int start;
    int end;
    } AssignedBlock;

void init_memory(void);
AssignedBlock* allocate(int n);
void free_block(AssignedBlock* b);
int read_cell(int pos);
void write_cell(int pos, int val);

extern Mem* Memory;

#endif
