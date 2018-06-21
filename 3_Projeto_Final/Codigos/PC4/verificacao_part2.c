#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <string.h>


int main(int arg, char *argv[]){
  FILE *arq;
  char leitura[100];
  char *result;

  // abrindo arquivo 
  arq = fopen("lista_verificacao.txt","rt");
    if (arq == NULL)
	{
		printf("Erro na abertura do arquivo");
		return 1;
	}
    
  // leitura do arquivo 
  fscanf(arq,"%c",&result);
  
  if (strcmp(result,"[True]"))
  {
    printf("porta pode ser aberta \n ");
  }
  if (strcmp(result,"[False]"))
  {
    printf("porta fechada, pessoa nao identificada \n");
  }

  return 0; 
}

