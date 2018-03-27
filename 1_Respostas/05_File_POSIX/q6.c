#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bib_arqs.h"

int main(int argc, char *argv[] ){

	char conteudo[1000];

	le_arq_texto(argv[1], conteudo);

	printf("%s\n", conteudo);
}