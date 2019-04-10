#include <stdio.h>
#include <stdlib.h> 
#include <SDL.h> 
#include "personnage.h"
#include "ennemi.h"  
void anim_ennemi
SDL_Surface *background ;
SDL_Surface *ennemileft ; 
SDL_Surface *ennemiright ; 
if ( personnagePosition.x == 340 )
SDL_Rect ennemiPosition;
SDL_Rect personnagePosition;
ennemiright=IMG_Load("ennemiright.png"); 
ennemileft = IMG_Load("ennemileft.png");
background=IMG_Load("background.png");
{ennemiPosition.x-=30;
SDL_BlitSurface(ennemileft,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);
ennemiPosition.x-=30;
SDL_BlitSurface(ennemileft,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);
ennemiPosition.x-=30;
SDL_BlitSurface(ennemileft,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);
ennemiPosition.x+=30;
SDL_BlitSurface(ennemiright,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);
ennemiPosition.x+=30;
SDL_BlitSurface(ennemiright,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);
ennemiPosition.x+=30;
SDL_BlitSurface(ennemiright,NULL,ecran,&ennemiPosition);
SDL_BlitSurface(b.img,&b.bckg,&ecran,NULL);
SDL_Flip(ecran);


