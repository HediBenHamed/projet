#include <stdio.h> 
#include <stdlib.h> 
#include <SDL.h>
#include <SDL_image.h> 
#include "background.h"
#include "personnage.h" 
int main(int argc,char *argv[]){
SDL_Surface *enemy;
personnage=IMG_Load("enemy.png");
SDL_Rect enemyPosition;
enemyPosition.x=654;
enemyPosition.y=400;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
SDL BlitSurface (enemy,NULL,ecran,&enemyposition);
SDL_Flip(ecran) ;


