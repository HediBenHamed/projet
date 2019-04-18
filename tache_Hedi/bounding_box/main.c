#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collision.h"


int main(int argc, char *argv[])

{
        
    SDL_Surface *ecran = NULL,*background = NULL,*ennemy = NULL;


    SDL_Rect positionbackground;
    SDL_Rect positionennemy;

    SDL_Event event;

    int continuer = 1,x=0;
    int d=0,r=0,i;
    pers p;
    


    SDL_Init(SDL_INIT_VIDEO);
    

    ecran = SDL_SetVideoMode(1366, 678, 32, SDL_HWSURFACE);

    SDL_WM_SetCaption("test collision", NULL);

// initialisé background, joueur, ennemi, objet 
    /* Chargement de Zozor */

    //zozor = IMG_Load("depart.png");
    ennemy = IMG_Load("wahch1.png");
    background = IMG_Load("map.png");
	
    initialiserperso(&p);

    /* On centre Zozor à l'écran */
    positionbackground.x=0;
    positionbackground.y=0;
    positionennemy.x=780;
    positionennemy.y=350;	

    SDL_EnableKeyRepeat(10, 10);
        

    while (continuer)

    {

        SDL_WaitEvent(&event);
        
x= collisionAB(p.depart, ennemy, p.position_joueur,positionennemy);

	
        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)

                {
			
                    case SDLK_UP: // Flèche haut
			{
                        d=8;
                            p=boujer(d,p);
			if ((x==1))
			{
			        p.position_joueur.y+=50;
			        
			}
        		}
                        break;

                    case SDLK_DOWN: // Flèche bas
			{
                        d=2;
                            p=boujer(d,p);

			if ((x==1))
			{
			        p.position_joueur.y-=50;
			        
			}
			}	
                        break;

                    case SDLK_RIGHT: // Flèche droite
			{	
                        d=6;
                            p=boujer(d,p);

			if ((x==1))
			{
			        p.position_joueur.x-=50;
			        
			}
			}	
                        break;

                    case SDLK_LEFT: // Flèche gauche
			{
                        d=4;
                            p=boujer(d,p);

			if (x==1)
			{
			        p.position_joueur.x+=50;
			        
			}
			
			}
                        break;
                        
                }

                break;
                

        }

        x=0;

        /* On place Zozor à sa nouvelle position */
	//SDL_BlitSurface(calque, NULL, ecran, &positionbackground);
	SDL_BlitSurface(background, NULL, ecran, &positionbackground);
	SDL_BlitSurface(ennemy, NULL, ecran, &positionennemy);
        //SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
	afficherperso(&p, d, ecran);
        /* On met à jour l'affichage */

        SDL_Flip(ecran);

    }


liberer_surface(&p);

    SDL_Quit();


    return EXIT_SUCCESS;

}
