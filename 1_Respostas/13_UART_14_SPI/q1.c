#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void Config_UART(unsigned char TX_pin, unsigned char RX_pin){
  system("echo" TX_pin "> /sys/class/gpio" TX_pin "/export");
  system("echo out > /sys/class/gpio/gpio" TX_pin "/direction");
  system("echo 1 > /sys/class/gpio/gpio"TX_pin"/value"); //INICIAR EM 1

  system("echo" RX_pin "> /sys/class/gpio" RX_pin "/export");
  system("echo both > /sys/class/gpio/gpio" RX_pin "/edge");
  system("echo in > /sys/class/gpio/gpio" RX_pin "/direction");

}

void Transmit_UART(unsigned char data_out, unsigned char TX_pin, unsigned char baud_rate){

  int tempo_bit = 1000000/(baud_rate/10); //10 = 8 bits da amostra + 2 bits de stop/start
  unsigned char data;

  system("echo 0 > /sys/class/gpio/gpio"TX_pin"/value"); //START
  usleep(tempo_bit);

  for (int i = 0; i < 8; i++){
    data = data_out & 0x80; // 0x80 = 10000000, pega o bit mais significativo;
    system("echo" data "> /sys/class/gpio/gpio"TX_pin"/value");
    data_out = data_out << 1;
    usleep(tempo_bit);
  }

  system("echo 1 > /sys/class/gpio/gpio"TX_pin"/value"); //STOR
}

unsigned char Receive_UART(unsigned char RX_pin, unsigned char baud_rate){

  struct pollfd pfd;
	int buffer;

  int tempo_bit = 1000000/(baud_rate/10); //10 = 8 bits da amostra + 2 bits de stop/start
  int data;
  int fd;

  pfd.fd = open("/sys/class/gpio/gpio4/value", O_RDONLY);
  read(pfd.fd, &buffer, 1);
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


int main(int argc, char const *argv[]) {

  return 0;
}
