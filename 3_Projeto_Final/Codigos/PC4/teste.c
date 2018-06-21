#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <wiringPi.h>
#include <sys/wait.h>
#include <string.h>
#include "bib_arqs.h"
#include"funcoes.h"


 int main (){
      FILE *verifica;
      verifica = fopen("lista_verificacao.txt","r");
      char ch [20];
      char verdade [20] = "[True]";

       //testando se o arquivo foi realmente aberto
      if(verifica == NULL)
      {
      printf("Erro na abertura do arquivo!");
      }
      else
      {
	      while( (fgets(ch,20,verifica))!= NULL )
          {  		  
            printf("%s",ch);
		  }
	    fclose(verifica);
      
      }
     
      // Comparando 
      if (strcmp (verdade,ch) == 0 )
      {
        //reconhecido  = 1;
        printf("Usuario reconhecido!");
      }
      else
      { 
        //reconhecido = 0;
        printf("Usuario não reconhecido");
      }

return 0;
}
