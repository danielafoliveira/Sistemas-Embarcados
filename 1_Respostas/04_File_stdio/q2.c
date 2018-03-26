#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	
	char nome[100];
	int idade;

	printf("Digite seu nome: ");
	scanf("%s", nome);

	printf("Digite sua idade: ");
	scanf("%d", &idade);


	char nome_arquivo[100];
	strcpy(nome_arquivo,nome);
	strcat(nome_arquivo,".txt");

	FILE *fp;

	fp = fopen(nome_arquivo,"w");

	if (!fp)
	{
		printf("Erro da abertura do arquivo!\n");
		exit(-1);
	}

	fprintf(fp,"Nome: %s\n", nome);
	fprintf(fp,"Idade: %d\n", idade);

	fclose(fp);


	return 0;
}