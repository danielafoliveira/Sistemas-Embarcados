#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/poll.h>

unsigned char Receive_UART(unsigned char RX_pin, unsigned char baud_rate){

  struct pollfd pfd;
	int buffer;

  int tempo_bit = 1000000/(baud_rate/10); //10 = 8 bits da amostra + 2 bits de stop/start
  int data;
  int fd;

  pfd.fd = open("/sys/class/gpio/gpio4/value", O_RDONLY);
  lseek(pfd.fd, 0, SEEK_SET);
  poll(&pfd, 1, -1); //START
  usleep(tempo_bit/2);

  for (int i = 0; i < 8; i++){
    read(pfd.fd, &buffer, 1);
    if(buffer == 1){
      data = 0x01;
    }
    else{
      data = 0x00;
    }
    data = data << 1;
    usleep(tempo_bit/2);
  }

  close(pfd.fd);
  return data;
}
