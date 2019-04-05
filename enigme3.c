#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme3.h"

int enigme3(void)
{ SDL_Surface *screen=NULL, *enigme3=NULL, *boutton1=NULL, *boutton2=NULL, *boutton3=NULL, *boutton4=NULL;
SDL_Rect pos_enigme3;
SDL_Rect pos_boutton1;
SDL_Rect pos_boutton2;
SDL_Rect pos_boutton3;
SDL_Rect pos_boutton4;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1000,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
if(!screen)
{printf("unable to set 600X400 video: %s\n",SDL_GetError());
return (-1);
}
enigme3= IMG_Load("enigme3.png");
if(!enigme3)
{printf("unable to load enigme3: %s\n" ,SDL_GetError());
return(-1);
}
boutton1 = IMG_Load("1.png");
if(!boutton1)
{
printf("unable to load boutton1 : > %s",SDL_GetError());
}

boutton2 = IMG_Load("2.png");
if(!boutton2)
{
printf("unable to load boutton2 : > %s",SDL_GetError());
}
boutton3 = IMG_Load("3.png");
if(!boutton3)
{
printf("unable to load boutton3 : > %s",SDL_GetError());
}
boutton4 = IMG_Load("4.png");
if(!boutton4)
{
printf("unable to load boutton4 : > %s",SDL_GetError());
}
pos_enigme3.x =0;
pos_enigme3.y=0;
pos_boutton1.x=175;
pos_boutton1.y=428;
pos_boutton2.x=299;
pos_boutton2.y=439;
pos_boutton3.x=419;
pos_boutton3.y=435;
pos_boutton4.x=547;
pos_boutton4.y=432;

SDL_SetColorKey(boutton1,SDL_SRCCOLORKEY,SDL_MapRGB(boutton1->format,255,255,255));
SDL_SetColorKey(boutton2,SDL_SRCCOLORKEY,SDL_MapRGB(boutton2->format,255,255,255));
SDL_SetColorKey(boutton3,SDL_SRCCOLORKEY,SDL_MapRGB(boutton3->format,255,255,255));
SDL_SetColorKey(boutton4,SDL_SRCCOLORKEY,SDL_MapRGB(boutton4->format,255,255,255));
SDL_BlitSurface(enigme3,NULL,screen,&pos_enigme3);
SDL_BlitSurface(boutton1,NULL,screen,&pos_boutton1);
SDL_BlitSurface(boutton2,NULL,screen,&pos_boutton2);
SDL_BlitSurface(boutton3,NULL,screen,&pos_boutton3);
SDL_BlitSurface(boutton4,NULL,screen,&pos_boutton4);
SDL_Flip(screen);
SDL_Event event;
int continuer = 2;
while(continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{

case SDL_KEYDOWN : 
switch(event.key.keysym.sym)
{
  case SDLK_ESCAPE :
  continuer = 1;
  break;
}
case SDL_MOUSEBUTTONUP :
if(event.button.x>547&&event.button.x<632&&event.button.y>432&event.button.y<543)
{
return 1;
break;
}else
{
return 0;
break;
}
break;
}
}
SDL_FreeSurface(boutton1);
SDL_FreeSurface(boutton2);
SDL_FreeSurface(boutton3);
SDL_FreeSurface(boutton4);
SDL_FreeSurface(enigme3);
}
