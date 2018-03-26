#include"bib_arqs.h"
#include<stdio.h>

int tam_arq_texto(char *nome_arquivo){
	
	FILE *fp;
	fp = fopen(nome_arquivo,"r");

	int i=0;
	int aux;

	while( !feof(fp) ){
		aux = fgetc(fp);
		i++;
	}

	fclose(fp);
	int tamanho = i*sizeof(char);


	return tamanho;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){
		
	FILE *fp;
	fp = fopen(nome_arquivo,"r");

	int tamanho = tam_arq_texto(nome_arquivo);
	for (int i = 0; i < tamanho; ++i)
	{
		fread(conteudo,1,tamanho,fp);
	}

	fclose(fp);

}