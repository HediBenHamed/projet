#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "scroll.h"
#include "f.h"
#include "collision.h" 
void initialiser_fond(background *back)
{
	back->fondpos.x=10;
	back->fondpos.y=0;
	back->cadre.x=0;
	back->cadre.y=0;
	back->cadre.w=1024;
	back->cadre.h=512;
	

}

void charger_fond(background *back)
{
	if(back==NULL)
	{
		//printf("Erreur de chargement \n");
	}

  back->fond=SDL_LoadBMP("BG.bmp");
  back->masque=SDL_LoadBMP("mask.bmp");
}

void affichage_fond(background *back,SDL_Surface *fenetre)
{
	//SDL_BlitSurface(back->masque,&back->cadre,fenetre,&back->fondpos);
	SDL_BlitSurface(back->fond,&back->cadre,fenetre,&back->fondpos);
}

void scrolling(background *back,int a)
{		
	back->cadre.x = a - (1024 / 2);
	if (back->cadre.x <= 0) //awel stage tebda tescroli ken ki lperso fel west
	{
		back->cadre.x = 0;
	}

	else if (back->cadre.x + 1024 >= 8000)// hedheya fel fin mta3 stage 
	{
		back->cadre.x = 8000 - 1024;
	}
	
}
