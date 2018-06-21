#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>


int main(int arg, char *argv[]){

  char  aux[1000];


  sprintf(aux,"raspistill -o ./imagens/unknown.jpg");
  system(aux); //tira a foto

  fclose(escrita);
  printf("Os dados foram gravados com sucesso! \n");


return 0; 
}

