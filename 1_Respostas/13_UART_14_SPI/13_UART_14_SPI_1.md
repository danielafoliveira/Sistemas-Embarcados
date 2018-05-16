1. Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).

vantagens: não é necessário enviar um sinal de clock
desvantagens: Se houver atraso entre os clocks do mestre e do escravo, a cominicação falhará.

(b) SPI.

vantagens: o clock é enviado junto, então é uma cominicação confiável
desvantagem:

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

Pode enviar a qualquer hora, pois existem dois baramentos de dados, RX e TX em cada elemento. O MSP430 pode iniciar a transmissão, ao receber o bit de start o raspberry pi irá entender que a transmissão começou.

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

Deve esperar, pois o clock usado para envio dos bits é controlado pelo raspberry pi. O MSP430 age como elemento passivo.

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?

Cada dispositivo deve ser configurado com um endereço diferente. O pinos RX dos dois MSP430s devem ser conectados ao mesmo barramento. O Raspberry pi, ao iniciar a transmissão/requisição de dados, deve primeiro enviar um byte para identificar o endereço do escravo, e só depois realizar a tarefa.

5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?

forma 1: 1 pino slave-select para cada escravo. O Raspberry pi seta o pino correspondente ao escravo a ser comunicado e realiza a transmissão.

forma 2: mesmo pino slave-select para os dois escravos (Daisy chain). Nesse caso, os escravos estão cascateados.
Enviar ao escravo 1: Transmissão de 1 byte
Enviar ao escravo 2: Transmissão de 1 byte com os dados e mais 1 byte para "empurrar os dados"
Receber do escravo 1: "Transmissão" de 2 bytes para "empurrar"
Receber do escravo 2: "Transmissão" de 1 byte para "empurrar"
