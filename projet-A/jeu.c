#include "jeu.h"

void setting(SDL_Surface* ecran)
{
    SDL_Surface *background=NULL,*resoluton = NULL, *contols = NULL, *sound = NULL,*back=NULL;
    SDL_Rect positionresoluton,positioncontols,positionsound,positionbackground,positionback;
    SDL_Event event;
    int continuer = 1;

    IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    IMG_Load("Resolution_boutton.png");
    positionresoluton.x = 100;
    positionresoluton.y = 310;

    IMG_Load("Contols_boutton.png");
    positioncontols.x = 530;
    positioncontols.y = 310;

    IMG_Load("sound_boutton.png");
    positionsound.x = 960;
    positionsound.y = 310;

    IMG_Load("Back_boutton.png");
    positionsound.x = 20;
    positionsound.y = 25;



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
                        menu();
                        break;
                    case SDLK_KP1: // Demande resolution
                        resolution();
                        break;
                    case SDLK_KP2: // Demande contols
                        contols();
                        break;
                    case SDLK_KP3 :
                        sound();
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {resolution();}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {contols();}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {sound();}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu();}



        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton, NULL, ecran, &positionresolution);
        SDL_BlitSurface(controls, NULL, ecran, &positioncontols);
        SDL_BlitSurface(sound, NULL, ecran, &positionsound);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton);
    SDL_FreeSurface(controls);
    SDL_FreeSurface(sound);
    SDL_FreeSurface(back);

    SDL_Quit();


}
void play(SDL_Surface* ecran)
{
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionnewgame;
    SDL_Event event;
    int continuer = 1;

    IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    IMG_Load("newgame_boutton.png");
    positionresoluton.x = 340;
    positionresoluton.y = 310;

    IMG_Load("Continue_boutton.png");
    positioncontols.x = 750;
    positioncontols.y = 310;

    IMG_Load("Back_boutton.png");
    positionsound.x = 20;
    positionsound.y = 25;



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
                        menu();
                        break;
                    case SDLK_KP1: // Demande resolution
                        choose();
                        break;
                    case SDLK_KP2: // Demande contols
                        jouer();
                        break;


                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;

                    if(event.button.x >340&& event.button.x <625 && event.button.y >310&& event.button.y <390)
                            {choose();}

                     else if(event.button.x >750&& event.button.x <1035 && event.button.y >310&& event.button.y <390)
                            {jouer();}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu();}



        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
        SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(newgame);
    SDL_FreeSurface(continuer);
    SDL_FreeSurface(back);

    SDL_Quit();


}
void choose();
{}

void jouer();
{}

void setting(SDL_Surface* ecran);
{}
void contols();
{}
void sound();
{}
void resolution();
{}



