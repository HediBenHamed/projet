#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
int collision_trigo(SDL_Surface *perso  ,SDL_Surface *obj,SDL_Rect posp,SDL_Rect poso )
{

int ra,rb,xb,xa,ya,yb,distance;

if(((perso->w)/2)>((perso->h)/2))
ra=(perso->w)/2;
else
ra=(perso->h)/2;
xa=(posp.x+(perso->w/2));
ya=(posp.y+(perso->h/2));
if(((obj->w)/2)>((obj->h)/2))
rb=(obj->w)/2;
else rb=(obj->h)/2;
xb=(poso.x+(obj->w/2));
yb=(poso.y+(obj->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
if(distance<=(ra+rb))
{
return 1 ;
}
else
{
return 0;
}
}
