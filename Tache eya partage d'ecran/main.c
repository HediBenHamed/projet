#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage_d'ecran.h"


int main(int argc, char *argv[])
{
    SDL_Surface *screen=NULL,*trait=NULL;
    joueur j1,j2;
    background b1,b2;

    SDL_Rect camera1, camera2, p_trait;

    camera1.x=0;
    camera1.y=200;
    camera1.w=largeur/2;
    camera1.h=hauteur;

    camera2.x=0;
    camera2.y=200;
    camera2.w=largeur/2;
    camera2.h=hauteur;

    p_trait.x=largeur/2;
    p_trait.y=0;

    SDL_Init(SDL_INIT_VIDEO);

    screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    initialiser_background1(&b1);
    initialiser_background2(&b2);
    initialiser_joueur1(&j1);
    initialiser_joueur2(&j2);
    /*initialiser_deuxieme_perso(&j3);*/
    trait = IMG_Load("trait.png");



    SDL_BlitSurface(b1.background,&camera1,screen,&b1.pb);
    SDL_BlitSurface(b2.background,&camera2,screen,&b2.pb);
    SDL_BlitSurface(j1.p[0],NULL,screen,&j1.pp);
    SDL_BlitSurface(j2.p[1],NULL,screen,&j2.pp);
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);

    int continuer = 1;
    SDL_Event event;

    while(continuer)
    {
    SDL_BlitSurface(b1.background,&camera1,screen,&b1.pb);
    SDL_BlitSurface(b2.background,&camera2,screen,&b2.pb);
    SDL_BlitSurface(j1.p[0],NULL,screen,&j1.pp);
    SDL_BlitSurface(j2.p[1],NULL,screen,&j2.pp);
    /*SDL_BlitSurface(j3.p[0],NULL,screen,&j3.pp);*/
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);

        SDL_WaitEvent(&event);
        switch(event.type)
        {
    case SDL_QUIT:
        continuer=0;
        break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                continuer = 0;
                break;
            }
            break;
        }

    }

}
