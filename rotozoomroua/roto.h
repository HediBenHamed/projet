#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.
 void f (SDL_Surface *rotation,SDL_Rect *rect,double *angle,double *zoom ,int *sens,int *tempsPrecedent , int * tempsActuel) ;
