1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

fopen()

FILE *fopen (char *nome_do_arquivo, char
*modo)

fclose()

int fclose (FILE *ponteiro_para_arquivo);
-------------------------------------------------------------------------------
(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

fwrite()

unsigned fwrite (void *buffer,int numero_de_bytes,int
count,FILE *fp);
-------------------------------------------------------------------------------
(c) Quais são as funções (e seus protótipos) para ler arquivos?

fread()

unsigned fread (void *buffer, int numero_de_bytes, int
count, FILE *fp);
-------------------------------------------------------------------------------
(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

fseek()

int fseek ( FILE * stream, long int offset, int origin );
-------------------------------------------------------------------------------
(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

stdio.h
-------------------------------------------------------------------------------
2. O que é a norma POSIX?

É uma norma simples, de baixo-nivel, e portanto mais rápida e preferível para controle de hardware, com funções alternativas à biblioteva padrão do C. 
-------------------------------------------------------------------------------
3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

open()

int open(const char* caminho, int oflag, ...)

close()

int close(int fildes)
-------------------------------------------------------------------------------
(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

write()

ssize_t write(int fildes, const void *buf, size_t nbyte);
-------------------------------------------------------------------------------
(c) Quais são as funções (e seus protótipos) para ler arquivos?

read()

ssize_t read(int fildes, void *buf, size_t nbyte);
-------------------------------------------------------------------------------
(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

lseek()

off_t lseek(int fd, off_t offset, int whence);

-------------------------------------------------------------------------------
(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

fcntl.h
unistd.h
