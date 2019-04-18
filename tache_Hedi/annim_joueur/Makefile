prog: main.o player.o 
	gcc player.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
player.o:player.c
	gcc -c player.c -lSDL -lSDL_image -lSDL_mixer -g


