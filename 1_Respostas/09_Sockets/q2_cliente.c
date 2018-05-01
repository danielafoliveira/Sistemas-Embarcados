#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

void tarefa_cliente(int socket_a);

int main(int argc, char const *argv[]) {

  int socket_id;
  struct sockaddr socket_struct; //definida na biblioteca

  strcpy(socket_struct.sa_data,"/tmp/socket1"); //caminho/endereço do socket
  socket_struct.sa_family = AF_LOCAL; //familia do endereço

  //Definindo configurações do socket (local,orientado a conexão,protocolo TCP)
  socket_id = socket(PF_LOCAL,SOCK_STREAM,0);

  //Conectando ao servidor
  connect(socket_id,&socket_struct,sizeof(socket_struct));

  tarefa_cliente(socket_id);

  unlink(socket_struct.sa_data); //apaga socket do sistema
  close(socket_id);
  return 0;
}

void tarefa_cliente(int socket_a) {
  for (int i = 1; i <= 10; i++) {
      write(socket_a,&i,1);
      sleep(1);
  }
}
