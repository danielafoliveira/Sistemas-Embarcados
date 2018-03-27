#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	int fp;

	fp = open("ola_mundo.txt", O_RDWR | O_CREAT);

	if(fp == -1){
		printf("Erro na abeertura do arquivo!\n");
		exit(-1);
	}

	write(fp, "Ola Mundo\n", 9*sizeof(char));

	close(fp);

	return 0;

}