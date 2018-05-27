#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#include "funcoes.h"


int poll_bot()
{
	int estado;
	struct pollfd pfd;
	char buffer;
	system("echo 27 > /sys/class/gpio/export");
	system("echo falling > /sys/class/gpio/gpio27/edge");
	system("echo in > /sys/class/gpio/gpio27/direction");
	pfd.fd = open("/sys/class/gpio/gpio27/value", O_RDONLY);
	if(pfd.fd < 0)
	{
		puts("Erro abrindo /sys/class/gpio/gpio27/value");
		puts("Execute este programa como root");
		return -1;
	}
	read(pfd.fd, &buffer, 1);
	pfd.events = POLLPRI | POLLERR;
	pfd.revents = 0;
	puts("Augardando botao");
	poll(&pfd, 1, -1);
	if(pfd.revents) puts("mudanca do botao");
	usleep(500000);
	estado = pfd.fd;
	close(pfd.fd);
	system("echo 27 > /sys/class/gpio/unexport");
	return estado;
}
