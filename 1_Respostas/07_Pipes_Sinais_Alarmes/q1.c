#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){

	int fd[2]; //	descrição da variavel compartilhada
	//	fd[0] -> leitura    fd[1] -> escrita
	pipe(fd); //cria pipe com fd como variável compartilhada

	if(fork()==0){ //	processo filho
		int a;

		do{
			read(fd[0],&a,1);
			printf("%d\n", a);
			
		}while(a != 10);
	}

	else{

		for (int i = 1; i <= 10; ++i)
		{
			write(fd[1],&i,1);
			sleep(1);
		}

	}


	return 0;
}