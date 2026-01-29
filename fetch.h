#ifndef FETCH
#define FETCH

typedef struct fetched_command{
	char OpName[4];
	char par1;
	char cpar2;
	int ipar2;
}fetched_command;



// takes a file & reads and counts how many lines (aka how many commands in this case) it contains.It will return the amount of commands
int amount_commands(const char* filename);

//takes a file and a line number. It will read the file and read at the line number given.It will return a struct with the Operation Name & the parameters.
struct fetched_command fetching(const char* filename, int line_number);

void decode(struct fetched_command fc);
#endif
