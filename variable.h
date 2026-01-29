#ifndef VARIABLE
#define VARIABLE

#include "memory.h"

//list of variables
typedef struct Variable {
    char name;
    int start;
    int end;
    struct Variable* next;
} Variable;

//
void variables_init(void);

//get struct variable
Variable* var_get(char name);

//assigning variable
void var_set(char name, AssignedBlock* block);

//removing variable
AssignedBlock* var_delete(char name);

//go through all variables and free them by calling free_block function from memory
void variables_free(void);

#endif

