/**
*@file roto.c 
*/
#include "roto.h"
void f (SDL_Surface *rotation,SDL_Rect *rect,double *angle,double *zoom ,int *sens,int *tempsPrecedent , int * tempsActuel)
{

 
        (*tempsActuel) = SDL_GetTicks();

        if ((*tempsActuel) - (*tempsPrecedent) > TEMPS)

        {

           ( *angle) += 2; 

 

         ( *  tempsPrecedent) = (*tempsActuel);

        }

        else

        {

            SDL_Delay(TEMPS - ((*tempsActuel) - (*tempsPrecedent)));

        }

 

        rect->x =  rotation->w / 2;

        rect->y =  rotation->h / 2;

 
        if((*zoom) >= 2){(*sens) = 0;}

        else if((*zoom) <= 0.5){(*sens) = 1;}

 

        if((*sens) == 0){(*zoom) -= 0.02;}

        else{(*zoom) += 0.02;}
  

}
