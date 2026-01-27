#include <stdio.h>
#include <string.h>

struct fetched_command{
	char 	OpName;
	char	par1;
	char 	cpar2;
	int	ipar2;
}
struct fetched_command fc; // <- pointer for return

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



//opening and reading the files
FILE* file =fopen(<filename>, "r");
fscanf(file, "%s", fc.OpName);	//reading first the command

// if operation is fre or par & only has one parameter
if ((strcmp(fc.OpName, Fre) == 0) || (strcmp(fc.OpName, Pra) == 0){
		fscanf(file, "%s %c", fc.OpName fc.par1 );
		}
// if operation is ass, inc, dec, mal, pri & takes par1 as char and par2 as int
if ((strcmp(OpName, Ass) == 0)||(strcmp(OpName, Inc)|| (strcmp(OpName, Dec)||(strcmp(OpName, Mal)||(strcmp(OpName, Pri)){
		fscanf(file, "%s %c %d", fc.OpName, fc.par1, fc.ipar2);

		/*if (strcmp(OpName, Ass) == 0){
	       		Ass(par1, par2);
			}
		if (strcmp(OpName, Inc ) == 0){
	       		Inc(par1, par2);
			}
		if (strcmp(OpName, Dec) == 0){
	       		Mal(par1, par2);
			}
		if (strcmp(OpName, Mal) == 0){
	       		Pri(par1, par2);
			}i
		if (strcmp(OpName, Pri) == 0){
	       		Ass(par1, par2);
			}*/
}

// if operation is add, sub, mul, and, xor & takes par1 and par2 as chars
if ((strcmp(OpName, Aff) == 0)||(strcmp(OpName, Sub)|| (strcmp(OpName, Mul)||(strcmp(OpName, And)||(strcmp(OpName, Xor)){
		fscanf(file, "%s %c %c", fc.OpName, &OpName,fc.par1, fc.cpar2);			
		
		/*if (strcmp(OpName, Add) == 0){
	       		Add(par1, par2);
			}
		if (strcmp(OpName, Sub) == 0){
	       		Sub(par1, par2);
			}
		if (strcmp(OpName, Mul) == 0){
	       		Mul(par1, par2);
			}
		if (strcmp(OpName, And) == 0){
	       		And(par1, par2);
			}
		if (strcmp(OpName, Xor) == 0){
	       		Xor(par1, par2);
			}*/
}
return fc;
fclose(file);
