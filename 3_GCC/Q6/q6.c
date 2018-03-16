#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char **argv){

	
	int i=1;
	printf("Ola");
	do{
		printf(" %s",argv[i]);
		i++;
	}while(i != argc);
	printf("\n");
	printf("Numero de entradas = %d\n", argc);
	return 0;


}
