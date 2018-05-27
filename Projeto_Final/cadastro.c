#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include"funcoes.h"

int cadastro(char* usuário){
    //Você será cadastrado

    //Posicione-se em frente à camera

    //Pressione o botão
      poll_bot();
      system("raspistill -o ./imagens_cadastro/" &usuário".png"); //tira a foto
    //Ok
    return 1;

}
