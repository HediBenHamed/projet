#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
objet Initobjet(objet B,int x, int y,char nom[50])
{
  B.image=IMG_Load(nom);
  B.position.x=x;
  B.position.y=y;
  SDL_SetColorKey(B.image, SDL_SRCCOLORKEY, SDL_MapRGB(B.image->format, 255, 255, 255));
  return B;
}
void  Afficherobjet(objet B,SDL_Surface *screen)
{
   SDL_BlitSurface(B.image,NULL,screen,&B.position);
}
