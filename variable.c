#include <stdlib.h>
#include "memory.c" //memory.h 


typedef struct Variable {
    char name;
    int start;
    int size;
    struct Variable *next;
} Variable;

static Variable *head = NULL;

void variables_init(void) {
    head = NULL;
}


void variables_free(void) {
    Variable *cur = head;
    while (cur) {
        Variable *next = cur->next;
        free(cur);
        cur = next;
    }
    head = NULL;
}

Variable* var_get(char name) {
    Variable *cur = head;
    while (cur) {
        if (cur->name == name)
            return cur;
        cur = cur->next;
    }
    return NULL;
}


void var_set(char name, int start, int size) {
    Variable *v = malloc(sizeof(Variable));
    if (!v) {
         exit(0);
    }

    v->name = name;
    v->start = start;
    v->size = size;
    v->next = head;
    head = v;
}


void var_delete(char name) { //return start & end to free in memory 
    Variable *cur = head;
    Variable *prev = NULL;

    while (cur) {
        if (cur->name == name) {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;

            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

