#include "jeu.h"
void sounds(SDL_Surface* ecran)
{
    SDL_Surface *background=NULL,*augmenter = NULL, *diminuer = NULL,*back=NULL;
    SDL_Rect positionaugmenter,positiondiminuer,positionbackground,positionback,positionClic;
    SDL_Event event;
    int continuer = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    augmenter=IMG_Load("augmenter_volume.png");
    positionaugmenter.x = 450;
    positionaugmenter.y = 310;

    diminuer=IMG_Load("diminuer_volume.png");
    positiondiminuer.x = 750;
    positiondiminuer.y = 310;


    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;



while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        setting(ecran);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //augmenter();
                        break;
                    case SDLK_KP2: // Demande contols
                        //diminuer();
                        break;

                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
 		
			 if(event.button.x >450&& event.button.x <540 && event.button.y >310&& event.button.y <390)
                            {/*augmenter();*/}

                     else if(event.button.x >750&& event.button.x <840 && event.button.y >310&& event.button.y <390)
                            {/*diminuer();*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran);}


        		}     
		break;   	
		}//switch
		

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
        SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(augmenter);
    SDL_FreeSurface(diminuer);
    SDL_FreeSurface(back);

    SDL_Quit();


}
