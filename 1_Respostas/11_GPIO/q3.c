#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpio_dev_mem.h"
#include <sys/types.h>
#include <wiringPi.h>

int pin_out=7;
int pin_in = 9;

int freq = 1;
int tempo;

void muda_freq(int sig){
  freq=freq*2;
  if (freq == 128){
    freq = 1;
  }
    tempo = 1000000/(2*freq);
}

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

  tempo = 1000000/(2*freq);

  signal(SIGINT, interrompe);
  signal(SIGUSR1, muda_freq);

  int pid_filho = fork();

  if(getpid() ==0){

    while(1){
      digitalWrite(pin_out,HIGH);
      usleep(tempo);
      digitalWrite(pin_out,LOW);
      usleep(tempo);
    }

    return 0;

  }


  while (1) {

    if( digitalRead(pin_in)==0 ){
      usleep(50000);
      kill(pid_filho,SIGUSR1);
      while (digitalRead(pin_in)==0);
      usleep(50000);
    }


}
return 0;
}
