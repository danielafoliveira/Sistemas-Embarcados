1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

```
ps -e
```
(b) Mostrar os processos de um usuário?

```
ps -u nome_usuario
```


(c) Ordenar todos os processos de acordo com o uso da CPU?


```
ps -e --sort c
```

(d) Mostrar a quanto tempo cada processo está rodando?

```
ps -e --sort etimes
```

2. De onde vem o nome `fork()`?

```
'fork' significa 'garfo' em ingles. A função fork() tem esse nome porque faz analogia aop formato do garfo, com bifurcações, pois em sistemas embarcados, a função fork() realiza uma divisão do caminho do programa, a partir dela é executado paralelamente um novo processo, alem do processo original. 
```

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?

```
Vantagem: é possível executar um comando (em um processo difente) de dentro de um programa.

Desvantagem: Podem ocorrer falhas de execução, pois depende muito do sistema
```

(b) `fork()` e `exec()`?

```
Vantagem: O novo processo compartilha o mesmo program counter do processo pai.

Desvantagem: 

```

4. É possível utilizar o `exec()` sem executar o `fork()` antes?

```
Sim, porém o programa principal será substituído pelo novo, indicado no argumento da função exec().
```

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?

```
a função assume que o programa citado no argumento esteja na mesma pasta do programa que está sendo executado
```

(b) `execv()`?

```
a função aceita que não sejam passados argumentos para o novo programa
```

(c) `exece()`?

```
a função aceita argumento adicional
```

(d) `execvp()`?

```
união das fuincionalidades das funções execv() e execp(): programa na mesma pasta e sem argumentos de entrada 
```

(e) `execve()`?

```
união das fuincionalidades das funções execv() e exece(): programa na mesma pasta e função recebe argumento adicional
```

(f) `execle()`?

```
união das fuincionalidades das funções exece() e execl(): aceita argumento adicional, e os argumentos podem ser mecanismos 'var args'
```
