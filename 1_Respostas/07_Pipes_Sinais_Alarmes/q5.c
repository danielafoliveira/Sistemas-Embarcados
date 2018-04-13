#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void interrupcao(int sig){
	printf("Processo terminado!\n");
	exit(1);
}

void trata_alarme(int sig){
	system("ps -e --sort c");
	//printf("recepcaao do sinal SIGALRM\n");
}

int main (){

	signal(SIGINT,interrupcao);
	signal(SIGALRM,trata_alarme);

	while(1){
		sleep(1);
		alarm(1);
	}
	

	return 0;
}