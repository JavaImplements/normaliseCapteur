all: normalisation

dev: main.o
	gcc main.o -o normalisation

main.o: main.c
	gcc -c main.c

run: normalisation
	./normalisation

clean:
	rm -f *.o normalisation
