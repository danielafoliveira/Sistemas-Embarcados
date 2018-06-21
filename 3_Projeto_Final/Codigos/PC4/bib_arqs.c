#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo){

	int fp;

	fp = open(nome_arquivo, O_RDONLY);

	if(fp == -1){
		printf("Erro na abeertura do arquivo!\n");
		exit(-1);
	}

	int tamanho = 0;

	char aux = '0';

//	read(fp, &aux , 1);

	while(read(fp, &aux , 1) != 0){  // read() retorna 0 quando EOF
		tamanho++;
		//printf("%c", aux);
	}

	close(fp);

	return tamanho;
}


void le_arq_texto(char *nome_arquivo, char *conteudo){

	int tamanho = tam_arq_texto(nome_arquivo);

	int fp;

	fp = open(nome_arquivo, O_RDONLY);

	if(fp == -1){
		printf("Erro na abeertura do arquivo!\n");
		exit(-1);
	}


	read(fp, conteudo, tamanho); //sem '&' porque da função ja recebe o endereço de "conteudo"

	close(fp);
}
