#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
void play(SDL_Surface* ecran);
void choose();
void jouer();


void setting(SDL_Surface* ecran);
void contols();
void sound();
void resolution();

int menu();


#endif // JEU_H_INCLUDED
