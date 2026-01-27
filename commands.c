#include <stdio.h>
#include <stdlib.h>

// Mal x n
void Mal(Var *v, char name, int n, int start) {
    v->name = name;
    v->start = start;
    v->end = start + n - 1;
    
    for (int i = v->start; i <= v->end; i++) {
        Memory[i] = 0;
    }
}

// Ass x n
void Ass(Var *v, int n) {
    Memory[v->start] = n;
}


// Inc x n
void Inc(Var *v, int n) {
    Memory[v->start + n]++;
}

// Dec x n
void Dec(Var *v, int n) {
    Memory[v->start + n]--;
}

// Pri x n
void Pri(Var *v, int n) {
    printf("%d\n", Memory[v->start + n]);
}

void Add(Var *x, Var *y) {
    Memory[x->start] = Memory[x->start] + Memory[y->start];
}

void Sub(Var *x, Var *y) {
    Memory[x->start] = Memory[x->start] - Memory[y->start];
}

void Mul(Var *x, Var *y) {
    Memory[x->start] = Memory[x->start] * Memory[y->start];
}


// x[i] = (x[i] * y[i]) 
void And(Var *x, Var *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        Memory[x->start + i] = (Memory[x->start + i] * Memory[y->start + i]) % 2;
    }
}

// x[i] = (x[i] + y[i]) 
void Xor(Var *x, Var *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        Memory[x->start + i] = (Memory[x->start + i] + Memory[y->start + i]) % 2;
    }
}

// Fre x
void Fre(Var *v) {
    
    v->start = -1;
    v->end = -1;
}

// Pra x
void Pra(Var *v) {
    printf("[");
    for (int i = v->start; i <= v->end; i++) {
        printf("%d", Memory[i]);
    }
    printf("]\n");
}
