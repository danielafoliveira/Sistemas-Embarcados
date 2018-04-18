#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

//variaveis globais para comparação;
long int maior = 0;
int maior_index = 0;


//função para threads
void* procura_maior(void* v){

	long int *vetor = (long int *)v;

	for (int i = 0; i < (50000/4); ++i)
	{
		if(*vetor > maior){ //comparações
			maior = *vetor;
			maior_index = i;
		}
		vetor++; //deslocando ponteiro
	}

	return NULL;
}


int main(int argc, char const *argv[]){
	
	long int v[50000];

	printf("Preenchendo vetor...\n");

	for (int i = 0; i < 50000; ++i){
		v[i] = random();
	}
	printf("Vetor preenchido!\n\n");

	printf("Programa principal procurando:\n");
	system("date +%N"); //tempo inicial

	for (int i = 0; i < 50000; ++i)
	{
		if(v[i] > maior){
			maior = v[i];
			maior_index = i;
		}
	}


	system("date +%N"); //tempo final
	printf("Programa principal finalizou procura.\n");

	printf("Maior numero: %ld , posicao: %d\n", maior, maior_index);

	 //zerando variaveis para iniciar comparação usando threads
	maior = 0;
	maior_index = 0;

	printf("---------------------------------------------\n");

	//inicializando trheads
	pthread_t t1,t2,t3,t4;
	pthread_create(&t1,NULL,&procura_maior,&v[0]);
	pthread_create(&t2,NULL,&procura_maior,&v[(50000/4)]);
	pthread_create(&t3,NULL,&procura_maior,&v[((2*50000)/4)]);
	pthread_create(&t4,NULL,&procura_maior,&v[((3*50000)/4)]);

	printf("Threads procurando:\n");
	system("date +%N"); //tempo inicial

	//esperando threads
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	system("date +%N"); //tempo inicial
	printf("Threads finalizaram procura.\n");	


	printf("Maior numero: %ld , posicao: %d\n", maior, maior_index);

	return 0;
}