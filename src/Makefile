#Makefile for Tokenizer

CFLAGS= -g -O3
all: tokenizer

main.o: main.c tokenizer.h
	gcc -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

tokenizer: main.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ *#

run: tokenizer
	./tokenizer
