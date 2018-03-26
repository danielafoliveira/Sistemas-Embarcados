#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[])
{
	
	char nome_arquivo[100];
	strcpy(nome_arquivo, argv[1]);
	strcat(nome_arquivo,".txt");

	FILE *fp;

	fp = fopen(nome_arquivo,"w");

	if (!fp)
	{
		printf("Erro da abertura do arquivo!\n");
		exit(-1);
	}

	fprintf(fp,"Nome: %s\n", argv[1]);
	fprintf(fp,"Idade: %s\n", argv[2]);

	fclose(fp);


	return 0;
}