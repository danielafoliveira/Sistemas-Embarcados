1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

Vantagens: espaços de memória protegidos, menos risco de corrupção de dados.
Desvantagens: Varios processos rodando (maior esforço computacional)

(b) threads?

Vantagens: Comunicação mais simples (apenas escrever na variável), pode rodar varias threads em uma mesma aplicação
Desvantagens: Risco de corrupção de dados devido ao compartilhamento de memória.

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

Serão criadas 2 threads além da principal. As três coexistirão até o primeiro pthread_join, neste momento a thread t1 foi terminada, e logo em seguida a thread t2 foi terminada.


(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```


Serão criadas 2 threads alé, da principal, porem a thread t2 só será criada quando a t1 for encerrada. Assim, só coexistirão 2 threads:
principal e t1 até o primeiro pthread_join
principal e t2 após isso.



3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`

se o argumento for: PTHREAD_CANCEL_ENABLE
é definido que a thread por ser cancelada (default)

se for:  PTHREAD_CANCEL_DISABLE
a thread não pode ser cancelada



(b) `pthread_setcanceltype()`

se o argumento for: PTHREAD_CANCEL_DEFERRED
é necessária uma função de cancelamento para que a thread seja cancelada (default)

se for:  PTHREAD_CANCEL_ASYNCHRONOUS
a thread pode ser cancelada a qualquer momento (não é recomendado).



(DICA: elas são relacionadas à função pthread_cancel().)
