#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "fetch.h"
#include "commands.h"
#include "variable.h"

int main(const char* fileName){
    //initial Memory heap + the empty Variable list
    init_memory();      // From memory.c
    variables_init();   // From variable.c

    int n = amount_commands(fileName);
    for (int i = 0; i <= n-1; i++) {                 // start at 0
        struct fetched_command fc = fetching(fileName, i);
        decode(fc);
    }
    // Free the linked list and the heap memory before exiting
    variables_free();
    return 0;
}
