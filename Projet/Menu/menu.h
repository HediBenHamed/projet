#ifndef MENU_H_
#define MENU_H_

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
void resolution(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);

void menu(SDL_Surface *ecran,Mix_Music *musique);
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
void choose(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);




#endif /* MENU_H_ */
