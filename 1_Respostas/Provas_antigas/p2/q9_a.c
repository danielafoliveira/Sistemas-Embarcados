#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

int i2c_fd_sensor, i2c_fd_display;

void Config_I2C(void){

  unsigned char addr_sensor = 0x20, addr_display = 0x51;

  i2c_fd_sensor = open("/dev/i2c-1", O_RDWR);
  ioctl(i2c_fd_sensor, I2C_SLAVE, addr_sensor);

  i2c_fd_display = open("/dev/i2c-2", O_RDWR);
  ioctl(i2c_fd_display, I2C_SLAVE, addr_display);



}
