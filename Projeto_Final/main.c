#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>


#include"campainha.h"

int porta_aberta = 0;
int reconhecido = 0;
int encerrar = 0;

void encerra_threads(int sig){
  encerrar = 1;
}

void* thread_campainha(void*arg){
  while (!encerrar) {

    if(campainha()==1 && porta_aberta == 0){
      //reconhecido = função de reconhecimento;
      if (reconhecido == 1){
        system("sudo ./abre.sh");
      }
      else{
        system("sudo ./negado.sh");
      }

    }
  }

}

void* thread_alarme(void*arg){
  while(!encerrar){
    if(porta_aberta == 1 && reconhecido == 0)
      //soar alarme
  }

}

int main(int argc, char const *argv[]) {

  signal(SIGINT,encerra_threads);

  pthread_t id_campainha;
  pthread_create(&id_campainha,NULL,&thread_campainha,NULL); //criando thread para Campainha
  pthread_t id_alarme;
  pthread_create(&id_alarme,NULL,&thread_alarme,NULL); //criando thread para Campainha




  pthread_join(id_campainha,NULL);
  pthread_join(id_alarme,NULL);

  return 0;
}
