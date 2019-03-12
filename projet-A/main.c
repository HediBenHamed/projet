#include "jeu.h"

int menu()
{
    SDL_Surface *ecran = NULL, *background = NULL,*play=NULL,*setting=NULL,*quit;
    SDL_Rect positionbackground,positionplay,positionsetting,positionquit,positionClic;
    SDL_Event event;

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("logo.jpg"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Cursed island", NULL);

    background = IMG_Load("backgroundmenu.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    play=IMG_Load("boutton_play.png");
    positionplay.x=349;
    positionplay.y=315;

    setting=IMG_Load("boutton_setting.png");
    positionsetting.x=770;
    positionsetting.y=315;

    quit=IMG_Load("boutton_exit.png");
    positionquit.x=570;
    positionquit.y=465;


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
                        continuer = 0;
                        break;
                    case SDLK_KP1: // Demande à jouer
                        play(ecran);
                        break;
                    case SDLK_KP2: // Demande l'éditeur de niveaux
                        setting(ecran);
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >350&& event.button.x <640 && event.button.y >310&& event.button.y <390)
                            {play(ecran);}

                     else if(event.button.x >770&& event.button.x <1050 && event.button.y >310&& event.button.y <390)
                            {setting(ecran);}

                     else if (event.button.x >570&& event.button.x <850 && event.button.y >465&& event.button.y <540)
                                {continuer=0; }



        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(play, NULL, ecran, &positionplay);
        SDL_BlitSurface(setting, NULL, ecran, &positionsetting);
        SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(play);
    SDL_FreeSurface(setting);
    SDL_FreeSurface(quit);

    SDL_Quit();

    return EXIT_SUCCESS;
}
