#include<stdio.h>
#include<stdlib.h>
#include"bib_arqs.h"
#include<string.h>

int main(int argc, char *argv[])
{
	char conteudo[100];
	char aux[100];


	le_arq_texto(argv[2],conteudo);

	int tamanho_palavra = strlen(argv[1]);


	printf("%d\n", tamanho_palavra);



	for (int i = 0; i < tamanho_palavra; ++i)
	{
		aux[i] = conteudo[i];
	}




	return 0;
}