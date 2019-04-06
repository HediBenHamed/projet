#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

struct personnage
{
    SDL_Surface *bas[3];
    SDL_Surface *haut[3];
    SDL_Surface *gauche[3];
    SDL_Surface *droite[3];
    SDL_Surface *depart;
    int up,down,left,right;

    SDL_Rect position_joueur;
	int score;
	int vie;
};
typedef struct personnage pers;

void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *ecran);
void mouvement(pers p,SDL_Surface *ecran);
pers boujer(int d, pers p);
int collision(pers *p,SDL_Rect position_ennemi);



#endif // PLAYER_H_
