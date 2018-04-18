#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

int variavel=0;

void* funcao_exercicio(void*arg){
	int a;

	do{
		a = variavel;

		printf("%d\n", variavel);

		while(a==variavel){
			
		}
		
	}while(variavel <= 10);
}


int main(int argc, char const *argv[]){
	
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,&funcao_exercicio,NULL);

	for (variavel = 1; variavel <= 10; ++variavel){
		sleep(1);
	}

	pthread_join(thread_id,NULL);

	return 0;
}