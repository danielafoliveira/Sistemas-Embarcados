#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int main(){

	int tamanho = tam_arq_texto("vitor.txt");
	printf("Tamanho do arquivo = %d bytes.\n", tamanho);

	char conteudo[100];

	le_arq_texto("vitor.txt", conteudo);
	printf("%s\n", conteudo);
}