q9: q9.o num_caracs.o
	gcc -o q9 q9.o num_caracs.o
q9.o: q9.c num_caracs.h
	gcc -c q9.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc -c num_caracs.c
clean:
	rm -f *.o q9

