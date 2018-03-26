#include<stdio.h>
#include<stdlib.h>
#include"bib_arqs.h"

int main()
{
	char nome_arquivo[100];
	printf("Digite o nome do arquivo:\n");
	scanf("%s", nome_arquivo);


	FILE *fp;
	fp = fopen(nome_arquivo, "wr");

	char texto[100];

	printf("Digite o texto:\n");
	scanf("%s", texto);
	fprintf(fp, "%s\n", texto);

	fclose(fp);

	int tamanho;

	tamanho = tam_arq_texto(nome_arquivo);

	printf("Tamanho do arquivo: %d bytes\n", tamanho);

	return 0;
}