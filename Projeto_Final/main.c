#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <wiringPi.h>

#include"funcoes.h"

int fim_curso = 0;
int campainha = 2;
int alarme = 3;

int porta_aberta = 0; //sensor fim de curso na porta
int reconhecido = 0; //sinal
int encerrar = 0; //aivado pelo CTRL+C
int alerta = 0; //alarme de invasão

void encerra_threads(int sig);
void* thread_campainha(void*arg);
void* thread_alarme(void*arg);
void* thread_porta(void*arg);


int main(int argc, char const *argv[]) {

  wiringPiSetup();
  pinMode(fim_curso, INPUT);
  pinMode(alarme, OUTPUT);
//  pinMode(campainha, IN);

  signal(SIGINT,encerra_threads); //direcionando sinal de interrupção (CTRL+C)


  int child_pid = fork();

  if (child_pid == 0){

      pthread_t id_campainha;
      pthread_create(&id_campainha,NULL,&thread_campainha,NULL); //criando thread para Campainha
      pthread_t id_alarme;
      pthread_create(&id_alarme,NULL,&thread_alarme,NULL); //criando thread para Campainha
      pthread_t id_porta;
      pthread_create(&id_porta,NULL,&thread_porta,NULL); //criando thread para Campainha
      while (!encerrar) {
        /* code */
    }

      pthread_join(id_campainha,NULL);
      pthread_join(id_alarme,NULL);

  }
  else{

    while (!encerrar) {

    }


  }

  return 0;
}




void encerra_threads(int sig){
  puts("Programa encerrado pelo administrador!");
  encerrar = 1;
}

void* thread_campainha(void*arg){


  while (!encerrar) {

    poll_bot();
    if(porta_aberta == 0){ //só inicia reconhecimento se a porta estiver fechada
      //reconhecido = função de reconhecimento;
      if (reconhecido == 1){ //se o usuário for cadastrado
        system("sudo ./abre.sh");

        while(porta_aberta==1){
            printf("porta aberta\n\n");
            sleep(1);
        } //espera porta fechar
      //  reconhecido == 0;
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
      alerta = 1;
      while(alerta == 1){
          digitalWrite(alarme,HIGH);
          sleep(1);
          digitalWrite(alarme,LOW);
          sleep(1);
      } //espera administrador desativar alarme;
  }

}

void* thread_porta(void*arg){
  while(!encerrar){
    poll_fim_curso();
    porta_aberta = digitalRead(fim_curso);
  }

}
