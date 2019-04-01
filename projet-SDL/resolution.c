
#include "jeu.h"

void resolution(SDL_Surface* ecran)
{//void
    SDL_Surface *background=NULL,*resoluton_1 = NULL, *resoluton_2 = NULL, *resoluton_3 = NULL,*back=NULL;
    SDL_Rect positionresoluton_1,positionresoluton_2,positionresoluton_3,positionbackground,positionback,positionClic;
    SDL_Event event;
    int continuer = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    resoluton_1=IMG_Load("800x600.png");
    positionresoluton_1.x = 100;
    positionresoluton_1.y = 310;

    resoluton_2=IMG_Load("1280x720.png");
    positionresoluton_2.x = 958;
    positionresoluton_2.y = 310;

    resoluton_3=IMG_Load("1366x768.png");
    positionresoluton_3.x = 530;
    positionresoluton_3.y = 310;



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
                        //800x600();
                        break;
                    case SDLK_KP2: // Demande contols
                        //1280x720();
                        break;
                    case SDLK_KP3 :
                       //1366x768();
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {/*800x600();*/}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {/*1280x720();*/}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {/*1366x768();*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran);}


        		}     
		break;   	

		}//switch

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton_1, NULL, ecran, &positionresoluton_1);
        SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
        SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton_1);
    SDL_FreeSurface(resoluton_2);
    SDL_FreeSurface(resoluton_3);
    SDL_FreeSurface(back);

    SDL_Quit();


}

