#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>


typedef struct
{

  SDL_Surface *image;
  SDL_Rect position;
}objet;
objet Initobjet(objet B,int x,int y,char nom[50]);
void  Afficherobjet(objet B,SDL_Surface *screen);
int collision_trigo(SDL_Surface *perso,SDL_Surface *obj,SDL_Rect posp,SDL_Rect poso );
int coffreouvet(SDL_Rect poshero,SDL_Surface *perso,objet *coffre,char coffreouvet[50]);
int pomme(SDL_Rect poshero,SDL_Surface *perso,objet *pomme);
