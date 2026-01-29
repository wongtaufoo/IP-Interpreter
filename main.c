#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "fetch.h"
#include "commands.h"
#include "variable.h"

int main(cons char* fileName){
    //initial Memory heap + the empty Variable list
    init_memory();      // From memory.c
    variables_init();   // From variable.c

    const char* filename = fileName;
    int n = amount_commands(filename);
    for (int i = 0; i <= n-1; i++) {                 // start at 0
        struct fetched_command fc = fetching(filename, i);
        decode(fc);
    }
    // Free the linked list and the heap memory before exiting
    variables_free();
    return 0;
}
