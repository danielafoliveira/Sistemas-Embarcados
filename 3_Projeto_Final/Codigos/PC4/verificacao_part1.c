#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>


int main(int arg, char *argv[]){

  char  aux[1000];


  sprintf(aux,"raspistill -w 640 -h 480 -q 75 -o ./imagens/unknown.jpg");
  system(aux); //tira a foto

  
  printf("Foto Tirada \n");


return 0; 
}

