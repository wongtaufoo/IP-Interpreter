all:
	gcc -Wall -pedantic -g main.c variable.c commands.c fetch.c memory.c   -o interpreter

clean: 
rm -f interpreter *.o




