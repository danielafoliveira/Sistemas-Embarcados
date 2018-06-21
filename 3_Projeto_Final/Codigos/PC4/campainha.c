#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#include "poll_bot.h"


int poll_bot(int pin)
{
	struct pollfd pfd;
	char buffer;
	system("echo" pin " > /sys/class/gpio/export");
	system("echo falling > /sys/class/gpio/gpio "pin"/edge");
	system("echo in      > /sys/class/gpio/gpio"pin"/direction");
	pfd.fd = open("/sys/class/gpio/gpio"pin"/value", O_RDONLY);
	if(pfd.fd < 0)
	{
		puts("Erro abrindo /sys/class/gpio/gpio"pin"/value");
		puts("Execute este programa como root");
		return -1;
	}
	read(pfd.fd, &buffer, 1);
	pfd.events = POLLPRI | POLLERR;
	pfd.revents = 0;
	puts("Augardando campainha");
	poll(&pfd, 1, -1);
	if(pfd.revents) puts("Campainha pressionada: iniciar rotina de reconhecimento");
	close(pfd.fd);
	system("echo "pin" > /sys/class/gpio/unexport");
	return 1;
}
