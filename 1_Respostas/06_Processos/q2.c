#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char *argv[]){

	int ret;

	for (int i = 1; i < argc; ++i)
	{
		ret = system(argv[i]);
	}

	return 0;
}