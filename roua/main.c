#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{SDL_Surface *ecran;
  SDL_Surface *personnage =NULL;
   SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(800, 600,32,SDL_HWSURFACE || SDL_DOUBLEBUF||SDL_FULLSCREEN );
	SDL_Rect positiondetective;

positiondetective.y=0;
positiondetective.x=0;
objet coffre,pomme;
coffre=Initobjet(coffre,200,0,"coffre.png");
pomme=Initobjet(coffre,350,0,"pomme.png");
    SDL_Event event;
    int continuer = 1,a;
    SDL_WM_SetCaption("jeux", NULL);
personnage=IMG_Load("");

  SDL_EnableKeyRepeat(150, 150);
        SDL_WaitEvent(&event);

    while (continuer)
    {


        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
		case SDL_KEYUP:
break;
            case SDL_KEYDOWN :

                 switch(event.key.keysym.sym)
                {


                    case SDLK_RIGHT:
positiondetective.x+=30;

                        break;
                    case SDLK_LEFT :

positiondetective.x-=30;

                    break;




                }
                break;


        }


 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
if(a!=1)
{Afficherobjet(pomme,ecran);
 a=coll_pomme(positiondetective,personnage ,&pomme);}
 SDL_BlitSurface(personnage,NULL,ecran, &positiondetective);
 Afficherobjet(coffre,ecran);
coffreouvet(positiondetective,personnage ,&coffre,"coffreouvet.png");
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(personnage);
    // printf("%d",positionground.w);
    SDL_Quit();

    return EXIT_SUCCESS;


}
