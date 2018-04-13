#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){

	int fd[2]; //	descrição da variavel compartilhada
	//	fd[0] -> leitura    fd[1] -> escrita
	pipe(fd); //cria pipe com fd como variável compartilhada

	if(fork()==0){ //	processo filho 1
		char mensagem[100] = "FILHO1: Quando o vento passa, é a bandeira que se move.";
	

		write(fd[1],&mensagem, sizeof(mensagem));
		
		sleep(1);

		char mensagem_pai[100];
		read(fd[0], &mensagem_pai , sizeof(mensagem_pai) );
		printf("%s\n", mensagem_pai);

		exit(1);	
	}

	if(fork()==0){ //	processo filho 2

		char mensagem[100] = "FILHO2: Não, é o vento que se move.";
		
		char mensagem_filho_1[100];

		read(fd[0], &mensagem_filho_1 , sizeof(mensagem_filho_1) );
		printf("%s\n", mensagem_filho_1);
		write(fd[1],&mensagem, sizeof(mensagem));
		
		exit(1);
	}

	char mensagem_pai[100] = "PAI: Os dois se enganam. É a mente dos senhores que se move";
	char mensagem_filho_2[100];

	wait(NULL);

	read(fd[0], &mensagem_filho_2 , sizeof(mensagem_filho_2) );
	printf("%s\n", mensagem_filho_2);
	write(fd[1],&mensagem_pai, sizeof(mensagem_pai));

	
	wait(NULL); //espera dois NULLs pq tem dois processos filhos
	

	return 0;
}