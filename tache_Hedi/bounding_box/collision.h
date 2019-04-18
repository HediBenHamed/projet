#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>
struct personnage
{
    SDL_Surface *bas[8];
    SDL_Surface *haut[8];
    SDL_Surface *gauche[8];
    SDL_Surface *droite[8];
    SDL_Surface *depart;
    int up,down,left,right;

    SDL_Rect position_joueur;
	int score;
	int vie;
};
typedef struct personnage pers;

int collisionAB(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE);
pers boujer(int d, pers p);
void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *ecran);
void liberer_surface(pers *p);

