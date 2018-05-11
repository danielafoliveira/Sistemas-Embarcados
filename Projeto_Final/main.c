#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include"campainha.h"

int porta_aberta = 0; //sensor fim de curso na porta
int reconhecido = 0; //sinal
int encerrar = 0; //aivado pelo CTRL+C

void encerra_threads(int sig){
  encerrar = 1;
}

void* thread_campainha(void*arg){
  while (!encerrar) {

    if(campainha()==1 && porta_aberta == 0){ //só inicia reconhecimento se a porta estiver fechada
      //reconhecido = função de reconhecimento;
      if (reconhecido == 1){ //se o usuário for cadastrado
        system("sudo ./abre.sh");
        while(porta_aberta==1); //espera porta fechar
        reconhecido == 0;
      }
      else{ //usuário nao cadastrado
        system("sudo ./negado.sh");
      }

    }
  }

}

void* thread_alarme(void*arg){
  while(!encerrar){
    if(porta_aberta == 1 && reconhecido == 0) //se a porta abrir sem que o usuário seja reconhecido
      //soar alarme
  }

}

int main(int argc, char const *argv[]) {

  signal(SIGINT,encerra_threads); //direcionando sinal de interrupção (CTRL+C)

  pthread_t id_campainha;
  pthread_create(&id_campainha,NULL,&thread_campainha,NULL); //criando thread para Campainha
  pthread_t id_alarme;
  pthread_create(&id_alarme,NULL,&thread_alarme,NULL); //criando thread para Campainha

  while (!encerrar) {
    /* code */
  }


  pthread_join(id_campainha,NULL);
  pthread_join(id_alarme,NULL);

  return 0;
}
