#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>


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




int coffreouvet(SDL_Rect poshero,SDL_Surface *perso,objet *coffre,char coffreouvet[50])
{int c; //1 si ouvert 2 si fermé
c=collision_trigo(perso,coffre->image,poshero,coffre->position);
if (c==1) {

  coffre->image=IMG_Load("coffreouvet.png");
}



  return c;
}

int coll_pomme(SDL_Rect poshero,SDL_Surface *perso,objet *pomme)
{int m;
m=collision_trigo(perso,pomme->image,poshero,pomme->position);
if (m==1)
{
  SDL_FreeSurface(pomme->image);

}



  return m;
}
