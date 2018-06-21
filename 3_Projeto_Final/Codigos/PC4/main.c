#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <wiringPi.h>
#include <sys/wait.h>
#include <string.h>

#include "bib_arqs.h"
#include"funcoes.h"

int fim_curso = 2;
//int campainha = 0;
int alarme = 3;
int cadastrar = 0;

int porta_aberta = 0; //sensor fim de curso na porta
int reconhecido = 0; //sinal
int alerta = 0; //alarme de invasão
int child_pid;

int encerrar=0;


pthread_t id_campainha;
pthread_t id_alarme;
pthread_t id_porta;

void encerra_prog(int sig);
void encerra_threads(int sig);
void* thread_campainha(void*arg);
void* thread_alarme(void*arg);
void* thread_porta(void*arg);


int main(int argc, char const *argv[]) {

//  reconhecido = (char) *argv[1];
//  printf("%c\n",reconhecido );
  wiringPiSetup();
  pinMode(fim_curso, INPUT);
  pinMode(alarme, OUTPUT);
//  pinMode(campainha, IN);



  if (fork() == 0){
      child_pid = getpid();
      signal(SIGINT,encerra_threads); //direcionando sinal de interrupção (CTRL+C)

      pthread_create(&id_campainha,NULL,&thread_campainha,NULL); //criando thread para Campainha
      pthread_create(&id_alarme,NULL,&thread_alarme,NULL); //criando thread para Campainha
      pthread_create(&id_porta,NULL,&thread_porta,NULL); //criando thread para Campainha
	int a;

      char comando;
      while (!encerrar) {
        a = open("msgs_admin.txt", O_RDONLY);
	read(a,&comando,1);
	close(a);
//	le_arq_texto("msgs_admin.txt", comando);
//        printf("%c\n", comando);
        sleep(1);
        if (comando=='d'){
      //    printf("admin quer desativar\n");
          alerta = 0;
          char aux = 'a';
          a = open("msgs_admin.txt", O_RDWR);
	        write(a,&aux,1);
	        close(a);
        }

        if (comando=='l'){
          reconhecido = 1;
          system("sudo ./abre.sh");

          while(porta_aberta==1 && !encerrar){
              printf("porta aberta\n\n");
              sleep(1);
          } //espera porta fechar
          reconhecido = 0;

//        printf("Acesso liberado, aguardando campainha. status reconhecido = %c\n",reconhecido);
  //      sleep(1);
          char aux = 'a';
          a = open("msgs_admin.txt", O_RDWR);
	        write(a,&aux,1);
	        close(a);
        }
        if (comando=='b'){
          reconhecido = 0;
        }



      }

  }

  if (fork()==0){//filho 2
      system("./servidor 8080"); // Executa o servidor
  }
 if (fork()==0){//filho 3
      system("sudo python bot.py"); // Executa o bot
  }

  signal(SIGINT,encerra_prog); //direcionando sinal de interrupção (CTRL+C)



  while (!encerrar) {



  }

  wait(NULL);
  wait(NULL);

  return 0;
}
void encerra_prog(int sig){
  encerrar = 1;

}
void encerra_threads(int sig){
  alerta = 0;

  puts("Encerrando...");
  encerrar = 1;
  if (pthread_cancel(id_campainha) ==-1){
    puts("tread da campainha nao foi cancelada");
  }
  if (pthread_cancel(id_alarme) ==-1){
    puts("tread do alarme nao foi cancelada");
  }

  if (pthread_cancel(id_porta) ==-1){
    puts("tread da port nao foi cancelada");
  }
printf("threads canceladas\n" );
  pthread_join(id_campainha,NULL);
//  pthread_join(id_alarme,NULL);
  pthread_join(id_porta,NULL);

  system("gpio unexportall");
 puts("Programa encerrado pelo administrador!");

  exit(1);

}

void* thread_campainha(void*arg){
pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

  while (!encerrar) {

    poll_bot();
    if(porta_aberta == 0 && alerta== 0) { //só inicia reconhecimento se a porta estiver fechada
      //reconhecido = função de reconhecimento;
       // tirando foto para reconhecimento
      char aux [100] = "raspistill -w 640 -h 480 -q 75 -o ./imagens/unknown.jpg";
      system(aux); //tira a foto

      printf("Foto foi tirada");

      system("sudo ./face.sh");
      FILE *verifica;
      verifica = fopen("lista_verificacao.txt","r");
      char ch [20];
      char verdade [20] = "[True]";

       //testando se o arquivo foi realmente aberto
      if(verifica == NULL)
      {
      printf("Erro na abertura do arquivo!");
      }
      else
      {
	      while( (fgets(ch,20,verifica))!= NULL )
          {
            //printf("%s",ch);
		      }
	    fclose(verifica);

      }

      // Comparando string  com arquivo
      if (strcmp (verdade,ch) == 0 )
      {
        reconhecido  = 1;
        printf("Usuario reconhecido! \n\n");
      }
      else
      {
        reconhecido = 0;
        printf("Usuario não reconhecido\n\n");
      }

      if (reconhecido == 1){ //se o usuário for cadastrado
        printf("Acesso permitido\n\n");
        system("sudo ./abre.sh");


        while(porta_aberta==1 && !encerrar){
            printf("porta aberta\n\n");
            sleep(1);
        } //espera porta fechar
        reconhecido = 0;
      }
      else{ //usuário nao cadastrado
        puts("Acesso negado\n\n");
        system("sudo ./negado.sh");
         if (cadastrar){
          cadastro("nome");
        }

      }

    }
  }
  pthread_exit(0);

}

void* thread_alarme(void*arg){
  while(!encerrar){
      if(alerta == 1 && !encerrar){
        /*  digitalWrite(alarme,HIGH);
          sleep(1);
          digitalWrite(alarme,LOW);
          sleep(1); */
          printf("Alerta de invasao\n\n");
          system("sudo ./alarme.sh");
/*          puts("-----------------");
          puts("CTRL+C para sair");

          sleep(3);
          puts(" ");
          puts("ESPERE");
          puts("-----------------"); */
          if (encerrar ==1){
            pthread_exit(0);
          }

      } //espera administrador desativar alarme;
    }
  pthread_exit(0);
}

void* thread_porta(void*arg){
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  while(!encerrar){
//printf("alerta = %d",alerta);
    porta_aberta = digitalRead(fim_curso);
 //   printf("porta aberta = %d",porta_aberta);
    sleep(1);
    if(porta_aberta == 1 && reconhecido == 0){
      alerta = 1;
      while (alerta == 1 && !encerrar);
    }
  }
  pthread_exit(0);

}
