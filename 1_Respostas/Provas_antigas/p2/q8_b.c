#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/poll.h>

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
