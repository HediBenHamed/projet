#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

struct personnage
{
    SDL_Surface *bas;
    SDL_Surface *haut;
    SDL_Surface *gauche[8];
    SDL_Surface *droite[8];
    SDL_Surface *depart;
    int left,right;

    SDL_Rect position_joueur;
	int score;
	int vie;
};
typedef struct personnage pers;


void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *ecran);
void mouvement(pers p,SDL_Surface *ecran);
pers boujer(int d, pers p);
void liberer_surface(pers *p);





#endif // PLAYER_H_
