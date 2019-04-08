#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme1.h"

int enigme1(void)
{ SDL_Surface *screen=NULL,*enigme1=NULL,*boutton1=NULL,*boutton2=NULL;
SDL_Rect pos_enigme1;
SDL_Rect pos_boutton1;
SDL_Rect pos_boutton2;
SDL_Rect pos_vrai;
SDL_Rect pos_faux;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(3000,2000,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
if(!screen)
{printf("unabe to set 600x400 video: %s\n",SDL_GetError());
}
enigme1 = IMG_Load("enigm1.png");
if(!enigme1)
{printf("unable to load enigme1: %s\n" ,SDL_GetError());
}
boutton1= IMG_Load("1.png");
if(!boutton1)
{printf("unable to load boutton1: %s\n" ,SDL_GetError());
}
boutton2= IMG_Load("9.png");
if(!boutton2)
{printf("unable to load boutton2: %s\n" ,SDL_GetError());
}
pos_enigme1.x=0;
pos_enigme1.y=0;
pos_boutton1.x=339;
pos_boutton1.y=408;
pos_boutton2.x=548;
pos_boutton2.y=411;
pos_vrai.x=0;
pos_vrai.y=0;
pos_faux.x=0;
pos_faux.y=0;
SDL_BlitSurface(enigme1,NULL,screen,&pos_enigme1);
SDL_SetColorKey(boutton1,SDL_SRCCOLORKEY,SDL_MapRGB(boutton1->format,255,255,255));
SDL_BlitSurface(boutton1,NULL,screen,&pos_boutton1);
SDL_SetColorKey(boutton2,SDL_SRCCOLORKEY,SDL_MapRGB(boutton2->format,255,255,255));
SDL_BlitSurface(boutton2,NULL,screen,&pos_boutton2);
SDL_Flip(screen);
SDL_Event event;
int cont=1;
while(cont)
{
  SDL_WaitEvent(&event);
  switch(event.type)
{
  case SDL_KEYDOWN :
  switch(event.key.keysym.sym)
   {
     case SDLK_ESCAPE :
     cont=0;
     break;
     }
   break;
   case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if(event.button.x>338&&event.button.x<461&&event.button.y>404&&event.button.y<544)
{
 return 1;
}
if(event.button.x>454&&event.button.x<666&&event.button.y>404&&event.button.y<533)
{
 return 0;
}
break;
}
break;
}
}


SDL_FreeSurface(enigme1);
SDL_FreeSurface(boutton1);
SDL_FreeSurface(boutton2);
return 0;
}
