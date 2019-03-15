#include "jeu.h"

void controls(SDL_Surface* ecran)
{//void
    SDL_Surface *background=NULL,*manette=NULL,*souris=NULL,*clavier=NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionClic,positionmanette,positionclavier,positionsouris;
    SDL_Event event;
    int continuer = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    manette=IMG_Load("manette.png");
    positionmanette.x = 100;
    positionmanette.y = 310;

    souris=IMG_Load("souris.png");
    positionsouris.x = 958;
    positionsouris.y = 310;

    clavier=IMG_Load("clavier.png");
    positionclavier.x = 530;
    positionclavier.y = 310;



    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuer)
    {//while
        SDL_WaitEvent(&event);
        switch(event.type)
        {//switch1
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {//switch2
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        setting(ecran);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //jouer_mannette();
                        break;
                    case SDLK_KP2: // Demande contols
                        //jouer_clavier();
                        break;
                    case SDLK_KP3 :
                       // jouer_souris();
                        break;
                }//switch2
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {/*jouer_mannette();*/}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {/*jouer_clavier();*/}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {/*jouer_souris();*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran);}


        		}     
		break;   	
		}//switch
		

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
        SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
        SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(manette);
    SDL_FreeSurface(clavier);
    SDL_FreeSurface(souris);
    SDL_FreeSurface(back);

    SDL_Quit();


}//void
