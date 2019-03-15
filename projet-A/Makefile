prog: play.o setting.o menu.o main.o controls.o sounds.o
	gcc play.o main.o menu.o setting.o controls.o sounds.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
play.o:play.c
	gcc -c play.c -lSDL -lSDL_image -lSDL_mixer -g
setting.o:play.c
	gcc -c setting.c -lSDL -lSDL_image -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -g
controls.o :controls.c
	gcc -c controls.c -lSDL -lSDL_image -lSDL_mixer -g
sounds.o:menu.c
	gcc -c sounds.c -lSDL -lSDL_image -lSDL_mixer -g
