#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "variable.h"
#include "memory.h"
#include "fetch.h"

//decoding the input stored in struct fetched_command fc
void decode(struct fetched_command fc) {
    if (strcmp(fc.OpName, "Mal") == 0) {
        // Call Mal in memory.c to get space
        AssignedBlock *new_mem = allocate(fc.ipar2);
        if (new_mem==NULL){
            fprintf(stderr, "Not enough memory.\n");
            exit(0);
        }
        // Call var_set from variable.c to register the name and range
        var_set(fc.par1, new_mem);
        free(new_mem);
        return;
    }

    // Get the primary variable 'x' from the variable tracker
    Variable *x = var_get(fc.par1);
    if (x == NULL){
        fprintf(stderr, "Try to use a variable that does not exist.\n");
        exit(0);
    }

    // Ass x n
    if (strcmp(fc.OpName, "Ass") == 0) {
        Memory->m[x->start] = fc.ipar2;
    }
    // Inc x n
    else if (strcmp(fc.OpName, "Inc") == 0) {
        Memory->m[x->start + fc.ipar2]++;
    }
    // Dec x n
    else if (strcmp(fc.OpName, "Dec") == 0) {
        Memory->m[x->start + fc.ipar2]--;
    }
    // Pri x n
    else if (strcmp(fc.OpName, "Pri") == 0) {
        printf("%d\n", Memory->m[x->start + fc.ipar2]);
    }
    // Add x y
    else if (strcmp(fc.OpName, "Add") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            Memory->m[x->start] = Memory->m[x->start] + Memory->m[y->start];
        }
        else {
            fprintf(stderr,"Try to use a variable that does not exist.\n");
            exit(0);
        }
    }
    // Sub x y
    else if (strcmp(fc.OpName, "Sub") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            Memory->m[x->start] = Memory->m[x->start] - Memory->m[y->start];
        }
        else {
            fprintf(stderr,"Try to use a variable that does not exist.\n");
            exit(0);
        }
    }

    // Mul x y
    else if (strcmp(fc.OpName, "Mul") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            Memory->m[x->start] = Memory->m[x->start] * Memory->m[y->start];
        }
        else {
            fprintf(stderr,"Try to use a variable that does not exist.\n");
            exit(0);
        }
    }
    // And x y (x[i] = (x[i] * y[i]) %2)
    else if (strcmp(fc.OpName, "And") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            int len = x->end - x->start;
            int len2 = y->end - y->start;
            if (len!=len2){
                fprintf(stderr, "Logic operation between sequences of different length.\n");
                exit(0);
            }
            for (int i = 0; i < len; i++) {
                Memory->m[x->start + i] = (Memory->m[x->start + i] * Memory->m[y->start + i]) % 2;
            }
        }
        else {
            fprintf(stderr,"Try to use a variable that does not exist.\n");
            exit(0);
        }
    }
    // Xor x y (x[i] = (x[i] + y[i]) %2)
    else if (strcmp(fc.OpName, "Xor") == 0) {
        Variable *y = var_get(fc.cpar2);
        if (y) {
            int len = x->end - x->start;
            int len2 = y->end - y->start;
            if (len!=len2){
                fprintf(stderr, "Logic operation between sequences of different length.\n");
                exit(0);
            }
            for (int i = 0; i < len; i++) {
                Memory->m[x->start + i] = (Memory->m[x->start + i] + Memory->m[y->start + i]) % 2;
            }
        }
        else {
            fprintf(stderr,"Try to use a variable that does not exist.\n");
            exit(0);
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
            printf("%d ", Memory->m[i]);
        }
        printf("]\n");
    }
}
