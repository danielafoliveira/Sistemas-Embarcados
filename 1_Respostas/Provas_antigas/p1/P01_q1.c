#include <stdio.h>
#include <stdlib.h>
#include <string.c>
#include <pthread.h>

int main(int argc, char const *argv[])
{
	
	FILE *p;

	char texto[10] = strcat("cal ",argv[1]," > ");


	system(argcal >)




	return 0;
}


double media_sm;
int tamanho;

void* media(void *arg){

	int *a = (int *)arg;

	int maior = 0;
	int maior_index = 0; 
	int somatorio =0;

	for (int i = 0; i < tamanho/4; ++i)
	{
		if(a[i] > maior){
			maior = a[i];
			maior_index = i;
		}

	}

	for (int i = 0; i < tamanho/4; ++i)
	{
		if(i != maior_index)
		media_sm += a[i]/tamanho;
	}
	return NULL;
}


double media_sem_maximo_paralelo(int a[], int N){

	//N é o tamanho do vetor
	tamanho = N;
	pthread_t t1,t2,t3,t4;
	pthead_create(&t1,NULL,&media_sm,&a[0]);
	pthead_create(&t2,NULL,&media_sm,&a[N/4]);
	pthead_create(&t3,NULL,&media_sm,&a[3*N/4]);
	pthead_create(&t4,NULL,&media_sm,&a[4*N/4]);


	//esperando threads
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	return media_sm;
}