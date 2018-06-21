#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rdwr_arq.h"

int Num_Caracs(char *string){
	int i = 0;
	while(string[i] != '\0'){
		i++;
	}
	return i-1;

}

void rdwr_arq(char* conteudo){
	int fp;

	fp = open("historico.txt", O_RDWR | O_CREAT);

	if(fp == -1){
		printf("Erro na abeertura do arquivo!\n");
		exit(-1);
	}

	int tam = Num_Caracs(conteudo);

	write(fp, conteudo, tam*sizeof(char));

}
