#include <stdio.h>
#include <stdlib.h>

// Mal x n
void op_mal(Variable *v, char name, int n, int start_index) {
    v->name = name;
    v->start = start_index;
    v->end = start_index + n - 1;
    
    for (int i = v->start; i <= v->end; i++) {
        memory[i] = 0;
    }
}

// Ass x n
void op_ass(Variable *v, int n) {
    memory[v->start] = n;
}


// Inc x n
void op_inc(Variable *v, int n) {
    memory[v->start + n]++;
}

// Dec x n
void op_dec(Variable *v, int n) {
    memory[v->start + n]--;
}

// Pri x n
void op_pri(Variable *v, int n) {
    printf("%d\n", memory[v->start + n]);
}

void op_add(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] + memory[y->start];
}

void op_sub(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] - memory[y->start];
}

void op_mul(Variable *x, Variable *y) {
    memory[x->start] = memory[x->start] * memory[y->start];
}


// x[i] = (x[i] * y[i]) 
void op_and(Variable *x, Variable *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        memory[x->start + i] = (memory[x->start + i] * memory[y->start + i]) % 2;
    }
}

// x[i] = (x[i] + y[i]) 
void op_xor(Variable *x, Variable *y) {
    int len = x->end - x->start + 1;
    for (int i = 0; i <= len; i++) {
        memory[x->start + i] = (memory[x->start + i] + memory[y->start + i]) % 2;
    }
}



// Fre x
void op_fre(Variable *v) {
    
    v->start = -1;
    v->end = -1;
}

// Pra x
void op_pra(Variable *v) {
    printf("[");
    for (int i = v->start; i <= v->end; i++) {
        printf("%d", memory[i]);
    }
    printf("]\n");
}
