#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//decoding the input stored in struct fetched_command fc
void decode(struct fetched_command fc) {
    if (strcmp(fc.OpName, "Mal") == 0) {
        // Call Mal in memory.c to get space 
        Var *new_mem = Mal(fc.par1, fc.ipar2);
        // Call var_set from variable.c to register the name and range
        var_set(fc.par1, new_mem->start, new_mem->end);
        free(new_mem); 
        return;
    }

    // Get the primary variable 'x' from the variable tracker
    Variable *x = var_get(fc.par1);
    if (x == NULL) return; 

    // Ass x n
    if (strcmp(fc.OpName, "Ass") == 0) {
        Memory[x->start] = fc.ipar2;
    }
    // Inc x n
    else if (strcmp(fc.OpName, "Inc") == 0) {
        Memory[x->start + fc.ipar2]++;
    }
    // Dec x n
    else if (strcmp(fc.OpName, "Dec") == 0) {
        Memory[x->start + fc.ipar2]--;
    }
    // Pri x n
    else if (strcmp(fc.OpName, "Pri") == 0) {
        printf("%d\n", Memory[x->start + fc.ipar2]);
    }
    // Add x y
    else if (strcmp(fc.OpName, "Add") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) Memory[x->start] = Memory[x->start] + Memory[y->start];
    }
    // Sub x y
    else if (strcmp(fc.OpName, "Sub") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) Memory[x->start] = Memory[x->start] - Memory[y->start];
    }
    // Mul x y
    else if (strcmp(fc.OpName, "Mul") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) Memory[x->start] = Memory[x->start] * Memory[y->start];
    }
    // And x y (x[i] = (x[i] * y[i]) %2)
    else if (strcmp(fc.OpName, "And") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            int len = x->end - x->start; 
            for (int i = 0; i < len; i++) {
                Memory[x->start + i] = (Memory[x->start + i] * Memory[y->start + i]) % 2;
            }
        }
    }
    // Xor x y (x[i] = (x[i] + y[i]) %2)
    else if (strcmp(fc.OpName, "Xor") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            int len = x->end - x->start;
            for (int i = 0; i < len; i++) {
                Memory[x->start + i] = (Memory[x->start + i] + Memory[y->start + i]) % 2;
            }
        }
    }
    // Fre x
    else if (strcmp(fc.OpName, "Fre") == 0) {
        var_delete(fc.par1); // delete from variable tracking
    }
    // Pra x
    else if (strcmp(fc.OpName, "Pra") == 0) {
        printf("[ ");
        for (int i = x->start; i < x->end; i++) {
            printf("%d ", Memory[i]);
        }
        printf("]\n");
    }
}
