#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main()
{
	int f2s[2], s2f[2];
	char request='V', cur_val=1;
	srand(time(NULL)); // Inicializa gerador de valores aleatorios
	pipe(f2s);
	pipe(s2f);
	if(fork() == 0)
	{
		while(cur_val!=0)
		{
			write(s2f[1], &request, sizeof(char));
			read(f2s[0], &cur_val, sizeof(char));
			printf("Valor recebido = %d\n", cur_val);
		}
		request='F';
		write(s2f[1], &request, sizeof(char));
	}
	else
	{
		while(request=='V')
		{
			read(s2f[0], &request, sizeof(char));
			if(request=='V')
			{
				cur_val = rand()%0xF;
				write(f2s[1], &cur_val, sizeof(char));
			}
		}
	}
	return 0;
}
