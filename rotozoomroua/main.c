/**
*@file main.c
*@author blur team
*date 07/05/2019
*/
#include "roto.h"

int main(int argc, char *argv[])

{

    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;

    SDL_Rect rect;

    SDL_Event event;

 double angle = 0;

    double zoom = 1;

    int sens = 1;

 
    int continuer = 1;

 int tempsPrecedent = 0, tempsActuel = 0;



    SDL_Init(SDL_INIT_VIDEO);

 
    ecran = SDL_SetVideoMode(1000, 800, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);

 
    image = IMG_Load("vrai.png");



    while(continuer)

    {

        SDL_PollEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

        }

rotation = rotozoomSurface(image, angle, zoom, 0);
 
 f(rotation,&rect,&angle,&zoom,&sens,&tempsPrecedent,&tempsActuel);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.

        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire. 

        SDL_Flip(ecran);
    }

 

    SDL_FreeSurface(ecran);

    SDL_FreeSurface(image);

    SDL_Quit();

 

    return EXIT_SUCCESS;

}
