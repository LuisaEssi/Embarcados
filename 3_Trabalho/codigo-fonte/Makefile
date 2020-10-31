projeto: main.o decod.o
	gcc $(CFLAGS) -o main main.o decod.o -lwiringPi
main.o: main.c decod.h 
	gcc $(CFLAGS) -c main.c -lwiringPi
decod.o: decod.c decod.h 
	gcc $(CFLAGS) -c decod.c -lwiringPi
clean:
	rm -f *.o main
