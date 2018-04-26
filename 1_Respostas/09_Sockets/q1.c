#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int int main(int argc, char const *argv[]) {

  int socket_id;
  struct sockaddr socket_struct; //definida na biblioteca

  socket_struct.sa_data = "./socket1" //caminho/endereço do socket
  socket_struct.sa_family = AF_LOCAL //familia do endereço

  //Definindo configurações do socket (local,orientado a conexão,protocolo TCP)
  socket_id = socket(PF_LOCAL,SOCK_STREAM,IPPROTO_TCP);

  //Ligando socket ao endereço (socket,endereço(local),tamanho do endereço)
  bind(socket_id,&socket_struct,sizeof(socket_struct));




  return 0;
}
