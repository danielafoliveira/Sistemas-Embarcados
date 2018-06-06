#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include "funcoes.h"

void cadastro(char nome[100]){

	FILE *escrita;
  // Escrevendo no arquivo
	escrita = fopen("lista.txt","a");
    char  aux[1000];

  if (escrita == NULL)
	{
		printf("Erro na abertura do arquivo");
		//return 1;
	}

  sprintf(aux,"raspistill -o ./imagens/%s.jpg",nome);
  fprintf(escrita," %s",nome);
  system(aux); //tira a foto

  fclose(escrita);
  printf("Os dados foram gravados com sucesso! \n");

 
}
