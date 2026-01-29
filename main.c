#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "fetch.h"
#include "commands.h"
#include "variable.h"

int main(void){
    //initial Memory heap + the empty Variable list
    init_memory();      // From memory.c
    variables_init();   // From variable.c

    const char* filename = "test.txt";
    int n = amount_commands("test.txt");
    for (int i = 0; i <= n-1; i++) {                 // start at 0
        struct fetched_command fc = fetching(filename, i);
        decode(fc);
    }
    // Free the linked list and the heap memory before exiting
    variables_free();
    return 0;
}
