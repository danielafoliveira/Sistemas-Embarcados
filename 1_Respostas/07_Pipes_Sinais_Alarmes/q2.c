#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){

	int fd[2]; //	descrição da variavel compartilhada
	//	fd[0] -> leitura    fd[1] -> escrita
	pipe(fd); //cria pipe com fd como variável compartilhada

	if(fork()==0){ //	processo filho
		char mensagem_1[100] = "FILHO: Pai, qual é a verdadeira essência da sabedoria?";
		char mensagem_2[100] = "FILHO: Mas até uma criança de três anos sabe disso!";

		char mensagem_pai[100];

		write(fd[1],&mensagem_1, sizeof(mensagem_1));
		sleep(1); // filho hiberna para esperar pai terminar de ler o pipe

		read(fd[0], &mensagem_pai , sizeof(mensagem_pai) );
		printf("%s\n", mensagem_pai);
		write(fd[1],&mensagem_2, sizeof(mensagem_2));
		sleep(2);

		read(fd[0], &mensagem_pai , sizeof(mensagem_pai) );
		printf("%s\n", mensagem_pai);
		
		
	}

	else{

		char mensagem_1[100] = "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
		char mensagem_2[100] = "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";

		char mensagem_filho[100];

		read(fd[0], &mensagem_filho , sizeof(mensagem_filho) );
		printf("%s\n", mensagem_filho);
		write(fd[1],&mensagem_1, sizeof(mensagem_1));
		sleep(2);
		
		read(fd[0], &mensagem_filho , sizeof(mensagem_filho) );
		printf("%s\n", mensagem_filho);
		write(fd[1],&mensagem_2, sizeof(mensagem_2));
		sleep(1);
		
		

	}

	return 0;
}