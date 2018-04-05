#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char *argv[]){

	int ret;

	for (int i = 1; i < argc; ++i)
	{
		if(fork() == 0){	// processo filho
 			execvp(argv[i], argv[i+1]);
 			return 0;
		}		
	}

	return 0;
}