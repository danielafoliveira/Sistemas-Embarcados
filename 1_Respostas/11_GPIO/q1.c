#include "gpio_sysfs.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int pin=4;

void interrompe(){
  
  unsetGPIO(pin);
  exit(1);
}

int main()
{

	setGPIO_Out(pin);
  signal(SIGINT, interrompe;

  while(1){
  	GPIO_Write(pin,1);
  	usleep(500000);
    GPIO_Write(pin,0);
  	usleep(500000);
  }

}
