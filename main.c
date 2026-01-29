#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "fetch.h"
#include "commands.h"
#include "variable.h"

int main(int argc, char* argv[]){   // int argc is the number of arguments passed
    // char* argv is array of strings
    if (argc!= 2) return 0;

    const char * fileName = argv[1];
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
    free_memory();
    return 0;
}
