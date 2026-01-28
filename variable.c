#include <stdlib.h>

typedef struct Variable {
    char name;
    int start;
    int end;               
    struct Variable *next;
} Variable;

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
    return NULL;
}


void var_set(char name, int start, int end) {
    Variable *v = malloc(sizeof(Variable));
    if (!v) exit(0);

    v->name = name;
    v->start = start;
    v->end = end;
    v->next = head;
    head = v;
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

