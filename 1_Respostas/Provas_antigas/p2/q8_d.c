#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void Release_UART(unsigned char TX_pin, unsigned char RX_pin){
  system("echo" TX_pin "> /sys/class/gpio" TX_pin "/unexport");
  system("echo" RX_pin "> /sys/class/gpio" RX_pin "/unexport");
}
