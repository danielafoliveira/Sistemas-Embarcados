#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

void Write_4_7seg_I2C(unsigned int value){

  unsigned int vetor[4];
  float x;
  float aux;

  // 1023 ----- 3
  // value ---- x
  //    x = (3*value)/1023;

  x = (3*value)/1023;
  vetor[0] = x;
  write(i2c_fd_display,&vetor[0],1);

  for (int i = 1; i < 4; i++) {
    aux = (x-vetor[i-1])*10;
    vetor[i] = aux;
    write(i2c_fd_display,&vetor[i],1);
  }

}
