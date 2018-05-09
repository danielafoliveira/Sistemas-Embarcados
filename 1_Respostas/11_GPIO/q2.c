#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int pin=4;

void interrompe(){

  puts("\nPrograma Encerrado pelo usuário");
  unsetGPIO(pin);
  exit(1);
}

int main()
{
  int freq;
  puts("Frequência:");
  scanf("%d\n", &freq);

  int tempo = 1000000/(2*freq);

	setGPIO_Out(pin);
  signal(SIGINT, interrompe);

  while(1){
  	GPIO_Write(pin,1);
  	usleep(tempo);
    GPIO_Write(pin,0);
  	usleep(tempo);
  }

}
