#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "variable.h"


static Variable *head = NULL;


void variables_init(void) {
    head = NULL;
}

Variable* var_get(char name) {
    Variable *cur = head;
    while (cur) {
        if (cur->name == name)
            return cur;
        cur = cur->next;
    }
    return NULL;// variable does not exist
}


void var_set(char name, AssignedBlock *b) {
    Variable *v = malloc(sizeof(Variable));
    if (!v) exit(0);

    v->name = name;
    v->start = b->start;
    v->end = b->end;
    v->next = head;
    head = v;

    free(b);
}


AssignedBlock* var_delete(char name) {
    Variable *cur = head;
    Variable *prev = NULL;

    while (cur) {
        if (cur->name == name) {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;

            AssignedBlock *b = malloc(sizeof(AssignedBlock));
            if (!b) exit(0);

            b->start = cur->start;
            b->end   = cur->end;

            free(cur);
            return b;
	 }
        prev = cur;
        cur = cur->next;
    }
    return NULL;
}

void variables_free(void) {
    Variable* cur = head;

    while (cur) {
        Variable* next = cur->next;

        AssignedBlock* block = malloc(sizeof(AssignedBlock));
        if (block){
            block->start = cur->start;
            block->end = cur->end;

            free_block(block);
        }
        free(cur);

        cur = next;
    }

    head = NULL;
}


