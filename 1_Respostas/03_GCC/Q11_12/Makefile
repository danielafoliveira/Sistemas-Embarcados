q11: q11.o num_caracs.o
	gcc -o q11 q11.o num_caracs.o
q11.o: q11.c num_caracs.h
	gcc -c q11.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc -c num_caracs.c
clean:
	rm -f *.o q11
