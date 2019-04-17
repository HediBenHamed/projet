#include "structs.h"
#include "collision.h"
#include "scroll.h"


void InitSprite(perso* perso);
void affichage(perso* perso,SDL_Surface* screen);
void evolution(perso* perso, int quitter,int jump,int left,int right,background *back);
