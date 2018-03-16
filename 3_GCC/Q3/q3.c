#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char nome[100];
	printf("Digite o seu nome:\n");
	fgets(nome,100, stdin);
	printf("Ola %s\n", nome);
	return 0;
}
