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

	char texto_arq[100];

	printf("Digite o texto:\n");
	scanf("%s", texto_arq);
	fputs(texto_arq,fp);


	fclose(fp);

	int tamanho;

	tamanho = tam_arq_texto(nome_arquivo);

	printf("Tamanho do arquivo: %d bytes\n", tamanho);

	char conteudo[100];

	le_arq_texto(nome_arquivo,conteudo);


	printf("%s\n", conteudo);

	return 0;
}