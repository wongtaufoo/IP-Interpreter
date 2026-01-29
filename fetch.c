#include <stdio.h>
#include <string.h>
#include "fetch.h"

struct fetched_command fc;

//var names

char Ass[] = "Ass"; //char int	2
char Inc[] = "Inc"; //char int	2
char Dec[] = "Dec"; //char int	2
char Mal[] = "Mal"; //char int	2
char Pri[] = "Pri"; //char int	2
char Add[] = "Add"; //char char 2
char Sub[] = "Sub"; //char char 2
char Mul[] = "Mul"; //char char 2
char And[] = "And"; //char char 2
char Xor[] = "Xor"; //char char 2
char Fre[] = "Fre"; //char 1
char Pra[] = "Pra"; //char 1

int amount_commands(const char* filename){ //returns the amount of commands, in main the fetching of commands can be done trhough a for loop i<amount of commands, making sure every command gets read.

	FILE* file = fopen(filename, "r");
	if (file == NULL){
		printf("error");
		return 1;
	}
	int n = 0;
	char line[256];
	while (fgets(line, sizeof(line), file)!=NULL){
		n++;
	}
	fclose(file);
	return n;
}


struct fetched_command fetching(const char* filename, int line_number){ //add line number

	//opening and reading the files

	FILE* file =fopen(filename, "r");
	//checking
	if (file==NULL){
		printf("error fopen");
		return fc;
	}
	//
	char line[256];
	int current_line =0;
	// while loop
	while(fgets(line, sizeof(line), file)!= NULL && current_line < line_number){
			current_line++;
		}

	sscanf(line, "%4s", fc.OpName);	//reading first the command


// if operation is fre or par & only has one parameter
	if ((strcmp(fc.OpName, Fre) == 0) || (strcmp(fc.OpName, Pra) == 0)){
			sscanf(line, "%4s %c", fc.OpName, &fc.par1 );
			}

// if operation is ass, inc, dec, mal, pri & takes par1 as char and par2 as int
	if ((strcmp(fc.OpName, Ass) == 0)||(strcmp(fc.OpName, Inc) == 0)||(strcmp(fc.OpName, Dec) == 0)||(strcmp(fc.OpName, Mal) == 0)||(strcmp(fc.OpName, Pri) == 0)){
			sscanf(line, "%4s %c %d", fc.OpName, &fc.par1, &fc.ipar2);
			}

// if operation is add, sub, mul, and, xor & takes par1 and par2 as chars
	if ((strcmp(fc.OpName, Add) == 0)||(strcmp(fc.OpName, Sub) == 0)||(strcmp(fc.OpName, Mul) == 0)||(strcmp(fc.OpName, And) == 0)||(strcmp(fc.OpName, Xor) == 0)){
		sscanf(line, "%4s %c %c", fc.OpName, &fc.par1, &fc.cpar2);
		}

	fclose(file);
	return fc;

}

//for in the main	variables can be accesed using struct
/*int main (){
	int n = amount_commands("test.txt");
	for (int i=0; i<n;i++){
		fetching("test.txt", i);
	}
	return 0;
}*/
