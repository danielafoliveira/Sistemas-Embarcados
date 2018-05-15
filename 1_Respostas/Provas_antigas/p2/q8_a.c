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
