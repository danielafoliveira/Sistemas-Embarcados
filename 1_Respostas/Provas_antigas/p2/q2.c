#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <unistd.h>

int i2c_fd;
void ctrl_c(int sig)
{
	close(i2c_fd);
	exit(-1);
}

int main(void)
{
	unsigned char slave_addr=0x20, buf[2];

  int tempo = 100, maximo, minimo, media, leitura[8];
	signal(SIGINT, ctrl_c);
	i2c_fd = open("/dev/i2c-1", O_RDWR);
	ioctl(i2c_fd, I2C_SLAVE, slave_addr);

  while(1){

    for (int i = 0; i < 8; i++) {

    	write(i2c_fd, &i, 1);
    	usleep(tempo);
    	read(i2c_fd, &buf[1], 1);
      read(i2c_fd, &buf[2], 1);

      leitura[i] = (int)( (buf[2] << 8) & buf[1] );

    }//800us até completar

    maximo = 0;
    minimo = 0x3FF; //1111111111 - 10 bits
    media = 0;
    for (int i = 0; i < 8; i++) {
      if(leitura[i] > maximo)
        maximo = leitura[i];
      else if(leitura[i] < minimo)
        minimo = leitura[i];
      media += leitura[i]/8;
    }

    fprintf(stderr, "Maximo:%d\nMinimo:%d\nMedia:%d\n", maximo, minimo, media);
    usleep(499200);
  }

}
