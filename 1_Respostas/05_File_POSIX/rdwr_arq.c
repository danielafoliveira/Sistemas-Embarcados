#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "num_caracs.h"
#include "rdwr_arq.h"	
#include <string.h>

void rdwr_arq(char* nome, char* idade){
	int fp;

	char nome_arquivo[100];
	strcpy(nome_arquivo,nome);
	strcat(nome_arquivo,".txt");

	fp = open(nome_arquivo, O_RDWR | O_CREAT);

	if(fp == -1){
		printf("Erro na abeertura do arquivo!\n");
		exit(-1);
	}

	char linha_1[100] = "Nome: ";
	strcat(linha_1, nome);

	char linha_2[100] = "Idade: ";
	strcat(linha_2, idade);

	int tam_l1 = Num_Caracs(linha_1);
	int tam_l2 = Num_Caracs(linha_2);

	write(fp, linha_1, tam_l1*sizeof(char));
	write(fp, "\n", 1);
	write(fp, linha_2, tam_l2*sizeof(char));
	write(fp, "\n", 1);

}