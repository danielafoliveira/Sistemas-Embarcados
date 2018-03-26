#include<stdio.h>
#include<stdlib.h>
#include"num_caracs.h"

int main(int argc ,char **argv){

	int num_carac;
	int i=0;
	do{
		num_carac = Num_Caracs(argv[i]);
		printf("Argumento: %s / Numero de caracteres: %d\n",argv[i], num_carac);
		i++;
	}while(i != argc);
	return 0;


}
