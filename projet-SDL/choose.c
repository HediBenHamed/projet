#include "jeu.h"
void choose(SDL_Surface* ecran)
{//void
    SDL_Surface *background=NULL,*joueur1 = NULL, *joueur2 = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionjoueur1,positionClic,positionjoueur2;
    SDL_Event event;
    int continuee = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    joueur1=IMG_Load("joueur.png");
    positionjoueur1.x = 55;
    positionjoueur1.y = 53;

    joueur2=IMG_Load("joueur.png");
    positionjoueur2.x = 955;
    positionjoueur2.y = 25;

    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuee)
    {//while
        SDL_WaitEvent(&event);
        switch(event.type)
        {//switch 1
            case SDL_QUIT:
                continuee = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {//switch 2
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        play(ecran);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //jouer1(ecran);
                        break;
                    case SDLK_KP2: // Demande contols
                        //jouer2(ecran);
                        break;


                }//switch2
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {//if case
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;

                    if(event.button.x >150&& event.button.x <340 && event.button.y >315&& event.button.y <550)
                            {/*jouer1(ecran);*/}

                     else if(event.button.x >1045&& event.button.x <1235 && event.button.y >315&& event.button.y <550)
                            {/*jouer2(ecran);*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {play(ecran);}

			}//if case
			break;
        	}//switch
		
        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
        SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
		

        SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(joueur1);
    SDL_FreeSurface(joueur2);
    SDL_FreeSurface(back);

    SDL_Quit();
}//quiiter
