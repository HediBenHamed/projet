#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme1.h"
#include "random.h"
#define largeur 900
#define hauteur 700

int enigme(void)
{ SDL_Surface *screen=NULL,*enigme[3]={NULL,NULL,NULL};
SDL_Rect pos_enigme1;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
if(!screen)
{printf("unabe to set 600x400 video: %s\n",SDL_GetError());
}
enigme[1] = IMG_Load("e2.jpg");
enigme[2] = IMG_Load("e3.jpg");
enigme[0] = IMG_Load("e1.jpg");
int i=0;
for(;i<2;i++)
{
if(!enigme[i])
{printf("unable to load enigme1: %s\n" ,SDL_GetError());
}
}
pos_enigme1.x=0;
pos_enigme1.y=0;
int x = nombre();
SDL_Event event;
int cont=1;
switch(x)
{

case 1 : 

SDL_BlitSurface(enigme[0],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

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
    if(event.button.x>553&&event.button.x<664&&event.button.y>463&&event.button.y<588)
{
 return 1;
}else
{
 return 0;
}
break;
}
break;
}
}
break;

case 2 :
SDL_BlitSurface(enigme[1],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

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
    if(event.button.x>464&&event.button.x<559&&event.button.y>506&&event.button.y<544)
{
 return 1;
}else
{
 return 0;
}
break;
}
break;
} 
}
break;

case 3 :

SDL_BlitSurface(enigme[2],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

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
    if(event.button.x>514&&event.button.x<597&&event.button.y>533&&event.button.y<558)
{
 return 1;
}else
{
 return 0;
}
break;
}
break;
}
} 
break;
}

int j=0;

for(;j<2;j++)
{
SDL_FreeSurface(enigme[j]);
}
}


