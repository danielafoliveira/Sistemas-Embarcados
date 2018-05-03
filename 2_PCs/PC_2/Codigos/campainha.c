#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

int main(void)
{
	struct pollfd pfd;
	char buffer;
	system("echo 3 > /sys/class/gpio/export");
	system("echo falling > /sys/class/gpio/gpio3/edge");
	system("echo in      > /sys/class/gpio/gpio3/direction");
	pfd.fd = open("/sys/class/gpio/gpio3/value", O_RDONLY);
	if(pfd.fd < 0)
	{
		puts("Erro abrindo /sys/class/gpio/gpio3/value");
		puts("Execute este programa como root");
		return 1;
	}
	read(pfd.fd, &buffer, 1);
	pfd.events = POLLPRI | POLLERR;
	pfd.revents = 0;
	puts("Augardando campainha");
	poll(&pfd, 1, -1);
	if(pfd.revents) puts("Campainha pressionada: iniciar rotina de reconhecimento");
	close(pfd.fd);
	system("echo 3 > /sys/class/gpio/unexport");
	return 0;
}
