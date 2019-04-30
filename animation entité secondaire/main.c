#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initialiser.h"
#define largeur 1000
#define hauteur 700

int main(int argc, char *argv[])
{
    int a=1,frame=0,speed=10;
    bg b;
    perso pe;
    int d=0;

    SDL_Init(SDL_INIT_VIDEO);

    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("erreur de chargement de la bibliotheque video : %s",SDL_GetError());
    }

    SDL_Surface *screen=NULL;

    screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(!screen)
    {
        printf("ereur de chargement de l'ecran : %s",SDL_GetError());
    }

    initialiserbg(&b);
    initialiserps(&pe);
    afficherbg(screen,&b);
    afficherpers(screen,&pe,&frame);
    SDL_Flip(screen);

    SDL_Event event;


    SDL_EnableKeyRepeat(10,10);
    while(a)
    {
       /* afficherbg(screen,&b);
        afficherpers(screen,&pe,&frame);
        SDL_Flip(screen);*/
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE :
                a=0;
                break;
            case SDLK_RIGHT :
                animationd(screen,&b,&pe,&frame,&speed);
                frame++;
                break;
            case SDLK_LEFT :
                animationg(screen,&b,&pe,&frame,&speed);
                frame++;
                break;
            case SDLK_n :
                accelerationg(screen,&b,&pe,&frame,&speed);
                frame++;
                break;
            case SDLK_m :
                accelerationd(screen,&b,&pe,&frame,&speed);
                frame++;
                break;
            case SDLK_v :
                if(frame<3)
                {
                    d=1;
                    if(frame>=3)
                    {
                        frame=0;
                    }
                    saut(screen,&b,&pe,&frame);
                }

                if(frame>2||frame<6)
                {
                    d=0;
                    if(frame<=2||frame>=6)
                    {
                        frame=3;
                    }
                    saut(screen,&b,&pe,&frame);
                }
                frame++;
                break;
            }
            break;
        }
    }
}
