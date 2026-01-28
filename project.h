#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//From fetch.c 
struct fetched_command {
    char* OpName;
    char   par1;
    char   cpar2;
    int ipar2;
};
struct fetched_command fetching(const char* filename);

//From memory.c 
typedef struct Var {
    int start;
    int end;
    struct Var* ptr; 
    char name;       //should name include here????????
} Var;

void init_memory(void);
Var* Mal(char c, int n);


//From variable.c / field.c 
typedef struct Variable {
    char name;
    int start;
    int end;
    struct Variable *next;
} Variable;

void variables_init(void);
void variables_free(void);
Variable* var_get(char name);
void var_set(char name, int start, int end);
void var_delete(char name);

//From command.c 
void decode(struct fetched_command fc);

#endif
