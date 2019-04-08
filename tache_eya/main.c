#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme3.h"
#include "enigme2.h"
#include "enigme1.h"
#include "random.h"
int main(int argc, char argv[])
{ 
SDL_Surface *screen=NULL,*background=NULL,*vrai=NULL,*faux=NULL;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1000,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
SDL_Rect p_background, p_vrai, p_faux;
if(!screen)
{printf("unable to set 600X400 video: %s\n",SDL_GetError());
return (-1);
}
background=IMG_Load("background.png");
if(!background)
{
printf("unable to load image background : > %s",SDL_GetError());
}
vrai=IMG_Load("vrai.png");
if(!vrai)
{
printf("unable to load image vrai : > %s",SDL_GetError());
}
faux=IMG_Load("faux.png");
if(!faux)
{
printf("unable to load image faux : > %s",SDL_GetError());
}
p_background.x=0;
p_background.y=0;
p_vrai.x=0;
p_vrai.y=0;
p_faux.x=0;
p_faux.y=0;

SDL_BlitSurface(background,NULL,screen,&p_background);
SDL_Flip(screen);
SDL_Event event1;
int continuer = 1;
while(continuer)
{
SDL_WaitEvent(&event1);
switch(event1.type)
{
case SDL_KEYDOWN : 
switch(event1.key.keysym.sym)
{
case SDLK_ESCAPE :
continuer = 0;
break;
}
}

int a = nombre();
int x;
switch(a)
{
  case 1 :


 x=enigme1();
 if(x==1)
{
 SDL_BlitSurface(vrai,NULL,screen,&p_vrai);
 SDL_Flip(screen);
 SDL_Delay(4000);
 SDL_BlitSurface(background,NULL,screen,&p_background);
 SDL_Flip(screen);
 }else 
{
  SDL_BlitSurface(faux,NULL,screen,&p_faux);
  SDL_Flip(screen);
  SDL_Delay(4000);
  continuer = 0;
  break;
 }
 break;

 case 2 :

 x=enigme2();
 if(x==1)
{
 SDL_BlitSurface(vrai,NULL,screen,&p_vrai);
 SDL_Flip(screen);
 SDL_Delay(4000);
 SDL_BlitSurface(background,NULL,screen,&p_background);
 SDL_Flip(screen);
 }else 
{
  SDL_BlitSurface(faux,NULL,screen,&p_faux);
  SDL_Flip(screen);
  SDL_Delay(4000);
  continuer = 0;
  break;
 }
 break;

 case 3 :

 x=enigme3();
 if(x==1)
{
 SDL_BlitSurface(vrai,NULL,screen,&p_vrai);
 SDL_Flip(screen);
 SDL_Delay(4000);
 SDL_BlitSurface(background,NULL,screen,&p_background);
 SDL_Flip(screen);
 }else 
{
  SDL_BlitSurface(faux,NULL,screen,&p_faux);
  SDL_Flip(screen);
  SDL_Delay(4000);
  continuer = 0;
  break;
 }
 break;
}

}
SDL_FreeSurface(background);
SDL_FreeSurface(vrai);
SDL_FreeSurface(faux);
SDL_Quit();
}


