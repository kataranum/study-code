default: main.c playlist.o
	gcc -o playlist.out main.c playlist.o -I include -Wall -Wextra

playlist.o: src/playlist.c include/playlist.h
	gcc -c playlist.o src/playlist.c -I include -Wall -Wextra

clean:
	rm -f *.o *.out
