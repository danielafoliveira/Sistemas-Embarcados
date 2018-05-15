#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <wiringPi.h>

int freq = 1;
int tempo;

void muda_freq(int sig){
  freq=freq*2;
  if (freq == 128){
    freq = 1;
  }
    tempo = 1000000/(2*freq);
}

void interrompe(){

  puts("\nPrograma Encerrado pelo usuário");
  //unsetGPIO(pin_out);
  //unsetGPIO(pin_in);
  exit(1);
}

int main(){
  wiringPiSetup() ;
  pinMode(pin_out,OUTPUT);
  pinMode(pin_in, INPUT);

  tempo = 1000000/(2*freq);

  signal(SIGINT, interrompe);
  signal(SIGUSR1, muda_freq);

  int pid_filho = fork();

  if(pid_filho ==0){

    while(1){
      digitalWrite(pin_out,HIGH);
      usleep(tempo);
      digitalWrite(pin_out,LOW);
      usleep(tempo);
    }

    return 0;

  }


  while (1) {

    struct pollfd pfd;
    char buffer;
    system("echo 4 > /sys/class/gpio/export");
    system("echo falling > /sys/class/gpio/gpio4/edge");
    system("echo in > /sys/class/gpio/gpio4/direction");
    pfd.fd = open("/sys/class/gpio/gpio4/value", O_RDONLY);

    if(pfd.fd < 0)
    {
      puts("Erro abrindo /sys/class/gpio/gpio4/value");
      puts("Execute este programa como root.");
      return 1;
    }
    // De acordo com a documentacao da interface Sysfs para GPIO
    // (https://www.kernel.org/doc/Documentation/gpio/sysfs.txt),
    // eh necessario ler o arquivo "value" antes de fazer o poll() nele
    read(pfd.fd, &buffer, 1);
    // Tambem de acordo com a documentacao da interface Sysfs para GPIO
    // (https://www.kernel.org/doc/Documentation/gpio/sysfs.txt),
    // o poll() deve ser feito considerando os sinais POLLPRI e POLLERR
    pfd.events = POLLPRI | POLLERR;
    pfd.revents = 0;
    puts("Pressione o botao...");
    poll(&pfd, 1, -1);
    puts("Borda de descida!");
    kill(pid_filho,SIGUSR1);
    usleep(50000);
    close(pfd.fd);
    system("echo 4 > /sys/class/gpio/unexport");

  }

  return 0;
}
