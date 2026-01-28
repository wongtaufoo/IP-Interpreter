#include <stdio.h>
#include <stdlin.h>

#include "memory.h"
#include "fetch.h"
#include "structField.h"
#include “commands.c"

#include "project.h"

int main(){
    //initial Memory heap + the empty Variable list
    init_memory();      // From memory.c
    variables_init();   // From variable.c 

    while (1) {
        struct fetched_command current_fc = fetching(argv[1]);
        // when reach the end of the input
        if (current_fc.OpName == NULL){
          break;
        }
        decode(current_fc);
    }

    // Free the linked list and the heap memory before exiting
    variables_free(); 
    return 0;
}
