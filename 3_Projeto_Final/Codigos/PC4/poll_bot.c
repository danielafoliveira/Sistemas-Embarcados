#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

#include "funcoes.h"


int poll_bot()
{
	struct pollfd pfd;
	char buffer;
	system("echo 17 > /sys/class/gpio/export");
	system("echo falling > /sys/class/gpio/gpio17/edge");
	system("echo in > /sys/class/gpio/gpio17/direction");
	pfd.fd = open("/sys/class/gpio/gpio17/value", O_RDONLY);
	if(pfd.fd < 0)
	{
		puts("Erro abrindo /sys/class/gpio/gpio17/value");
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
	close(pfd.fd);
	system("echo 17 > /sys/class/gpio/unexport");
	return 0;
}
