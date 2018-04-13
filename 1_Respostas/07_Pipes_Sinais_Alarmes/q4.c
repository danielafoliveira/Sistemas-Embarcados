#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){

	int fd[2]; //	descrição da variavel compartilhada
	//	fd[0] -> leitura    fd[1] -> escrita
	pipe(fd); //cria pipe com fd como variável compartilhada

	if(fork()==0){ //	processo filho
		char mensagem[100] = "Digite o nome do usúario:";
		char nome[30];

		printf("%s\n",mensagem);
		scanf("%s", nome);

		write(fd[1],&nome, sizeof(nome));
		
		exit(1);	
	}

	//wait(NULL);

	char nome_recebido[30];

	read(fd[0], &nome_recebido, sizeof(nome_recebido));

	printf("\nNome recebido:\n\n %s\n\n", nome_recebido);
	

	return 0;
}