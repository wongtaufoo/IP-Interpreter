#ifndef MEMORY
#define MEMORY

#define TotalMemory 100

//list of empty blocks
typedef struct EmptyBlock{
    int start;
    int end;
    struct EmptyBlock *next; //pointer to next freeblock
} EmptyBlock;

// memory created
typedef struct Mem{
    int *m;// pointer to heap
    int avail_cells;
    EmptyBlock *head;
    } Mem;

//list of filled blocks
typedef struct AssignedBlock{
    int start;
    int end;
    } AssignedBlock;

// use once in main to create memory
void init_memory(void);

// get empty memory block that can be allocated
AssignedBlock* allocate(int n);

// free assigned block and mark it as available for use
void free_block(AssignedBlock* b);

// get int stored in memory cell
int read_cell(int pos);

// write int into memory cell
void write_cell(int pos, int val);

//free all cells
void free_memory(void);

// make memory global for use in other files
extern Mem* Memory;

#endif
