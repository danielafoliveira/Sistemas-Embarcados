#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpio_dev_mem.h"
#include <sys/types.h>
#include <wiringPi.h>

int pin_out=7;
int pin_in = 0;




void interrompe(){

  puts("\nPrograma Encerrado pelo usuário");
  //unsetGPIO(pin_out);
  //unsetGPIO(pin_in);
  exit(1);
}

int main(){
  wiringPiSetup() ;
  pinMode(pin_out,OUTPUT);
  pinMode(pin_in, INPUT);

  int freq = 1;


  int tempo = 1000000/(2*freq);
int tempo_usar;
  signal(SIGINT, interrompe);


    int fd[2];
    pipe(fd);


    if(fork()==0){

  while(1){
          if (digitalRead(pin_in)==0){
                  read(fd[0],&tempo_usar,sizeof(int));
                  usleep(50000); //deboucing
                  while(digitalRead(pin_in)==0);

          }

            digitalWrite(pin_out,HIGH);
            usleep(tempo_usar);
            digitalWrite(pin_out,LOW);
            usleep(tempo_usar);
        }
  return 0;
    }
