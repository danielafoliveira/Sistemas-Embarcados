#include<stdio.h>
#include<stdlib.h>
#include"num_caracs.h"

int main(int argc ,char **argv){

	int num_carac;
	int i=0;
	do{
		num_carac += Num_Caracs(argv[i]);
		i++;
	}while(i != argc);
	printf("Total de caracteres de entrada: %d\n", num_carac);
	return 0;


}
