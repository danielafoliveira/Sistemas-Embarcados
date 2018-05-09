1. Especifique algumas portas importantes pré-definidas para o protocolo TCP/IP.

Porta 80: HTTP
Porta 8080: HTTPS

2. Com relação a endereços IP, responda:

(a) Qual é a diferença entre endereços IP externos e locais?
Endereços externos são os endereços públicos, ou seja, os vistos pela internet. Os endereços locais são definidos para redes internas. A interface entre eles é o gateway

(b) Como endereços IP externos são definidos? Quem os define?
São definidos por numeros de 32 bits. Eles são controlados pela Internet Assigned Number Authority (IANA).

(c) Como endereços IP locais são definidos? Quem os define?
São definidos por numeros de 32 bitse quem os define é o próprio administrador da rede interna, podendo ser  atribuidos automaticamente via DHCP.

(d) O que é o DNS? Para que ele serve?
É uma resolução de nomes atribuidos a um endereço de IP. Serve para que um usuário possa acessar um servidor na rede sem a necessidade de decorar seu endereço IP, apenas sabendo seu nome. Ex: www.google.com.br = 172.217.29.35

3. Com relação à pilha de protocolos TCP/IP, responda:

(a) O que são suas camadas? Para que servem?
São como etapas da transmissão dos dados. Servem para dividir o processo em partes e facilitá-lo como um todo.

(b) Quais são as camadas existentes? Para que servem?
Aplicação - Os dados são empacotados
Transporte - Executa o protocolo de rede (TCP/UDP), indicando os endereços de origem e destino
Rede - Responsável pelo gerenciamento dos pacotes, filas, etc.
Enlace - Responsável pelo encaminhamento/roteamento dos pacotes
Fisica - Roteadores, cabos propriamente ditos

(c) Quais camadas são utilizadas pela biblioteca de sockets?
Aplicação e Transporte

(d) As portas usadas por servidores na função bind() se referem a qual camada?
Aplicação

(e) Os endereços usados por clientes na função connect() se referem a qual camada?
Transporte

4. Qual é a diferença entre os métodos `GET` e `POST` no protocolo HTTP?
GET: Faz requisição de uma página HTTP do endereço.
POST: Realiza o envio de uma página HTTP para o endereço.
