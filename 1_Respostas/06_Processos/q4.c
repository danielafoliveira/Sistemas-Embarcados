#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; // Variavel global para este exemplo

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}



int main(){

	for (int i = 0; i < 3; ++i)
	{
		if(fork() == 0){	// processo filho
 			Incrementa_Variavel_Global(getpid());
 			return 0;
 		}
 		sleep(1);

	}

	return 0;
}

/*

RESPOSTA:

A variável global NÃO foi compartilhada pelos processos filhos.
Cada um assumiu que ela era zero no início da execução.

*/