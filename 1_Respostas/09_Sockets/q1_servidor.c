#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>


void tarefa_servidor(int cliente);

int main(int argc, char const *argv[]) {

  int socket_id;
  struct sockaddr socket_struct; //definida na biblioteca

  strcpy(socket_struct.sa_data,"/tmp/socket1"); //caminho/endereço do socket
  socket_struct.sa_family = AF_LOCAL; //familia do endereço

  //Definindo configurações do socket (local,orientado a conexão,protocolo TCP)
  socket_id = socket(PF_LOCAL,SOCK_STREAM,0);

  //Ligando socket ao endereço (socket,endereço(local),tamanho do endereço)
  bind(socket_id,&socket_struct,sizeof(socket_struct));

  listen(socket_id,10); //socket escutando

//  while (1) {
      struct sockaddr cliente;
      int socket_id_cliente;
      socklen_t cliente_len; // definido na biblioteca

      //recebe cliente no socket
      socket_id_cliente = accept(socket_id, &cliente, &cliente_len);

      tarefa_servidor(socket_id_cliente);

//      close(socket_id_cliente);
//    }
    close(socket_id_cliente);
    close(socket_id);


  return 0;
}


void tarefa_servidor(int cliente) {
  int numero;

  while (read(cliente,&numero,1) > 0) {
    fprintf(stderr, "%d\n", numero);
  }

}
