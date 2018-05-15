#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

unsigned int AD_read_I2C(char channel){

  unsigned int data, buffer;


  write(i2c_fd_sensor,&channel,1); //requisição
  usleep(100);
  read(i2c_fd_sensor,&buffer,1); //LSBs
  read(i2c_fd_sensor,&data,1); //MSBs
  data = data << 8; //separando
  data+=buffer; //juntando

  return data;
}
