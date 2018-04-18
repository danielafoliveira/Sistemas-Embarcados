#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	FILE *fp;

	fp = fopen("ola_mundo.txt","w");

	if (!fp)
	{
		printf("Erro da abertura do arquivo!\n");
		exit(-1);
	}

	fprintf(fp,"Ola mundo!\n");
	fclose(fp);


	return 0;
}

