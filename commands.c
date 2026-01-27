#include <stdio.h>
#include <stdlib.h>

// Mal x n
void Mal(Var *v, char name, int n, int start) {
    v->name = name;
    v->start = start;
    v->end = start + n - 1;
    
    for (int i = v->start; i <= v->end; i++) {
        memory[i] = 0;
    }
}

// Ass x n
void Ass(Variable *v, int n) {
    memory[v->start] = n;
}


// Inc x n
void Inc(Variable *v, int n) {
    memory[v->start + n]++;
}

// Dec x n
void Dec(Variable *v, int n) {
    memory[v->start + n]--;
}

// Pri x n
void Pri(Variable *v, int n) {
    printf("%d\n", memory[v->start + n]);
}

void Add(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] + memory[y->start];
}

void Sub(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] - memory[y->start];
}

void Mul(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] * memory[y->start];
}


// x[i] = (x[i] * y[i]) 
void And(Variable *x, Variable *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        memory[x->start + i] = (memory[x->start + i] * memory[y->start + i]) % 2;
    }
}

// x[i] = (x[i] + y[i]) 
void Xor(Variable *x, Variable *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        memory[x->start + i] = (memory[x->start + i] + memory[y->start + i]) % 2;
    }
}

// Fre x
void Fre(Variable *v) {
    
    v->start = -1;
    v->end = -1;
}

// Pra x
void Pra(Variable *v) {
    printf("[");
    for (int i = v->start; i <= v->end; i++) {
        printf("%d", memory[i]);
    }
    printf("]\n");
}
