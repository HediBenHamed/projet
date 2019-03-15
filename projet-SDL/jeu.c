#include "jeu.h"

void menu(SDL_Surface *ecran)
{   
	
    Mix_Chunk *effect=NULL;
    SDL_Surface *background = NULL,*playy=NULL,*settingg=NULL,*quit;
    SDL_Rect positionbackground,positionplay,positionsetting,positionquit,positionClic;
    SDL_Event event;
	effect = Mix_LoadWAV( "music.mp3" );

	if( effect == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    int continuer = 1;


    background = IMG_Load("backgroundmenu.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    playy=IMG_Load("boutton_play.png");
    positionplay.x=349;
    positionplay.y=315;

    settingg=IMG_Load("boutton_setting.png");
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
                    if(event.button.x >350 && event.button.x <640 && event.button.y >310&& event.button.y <390)
                            {play(ecran);}

                     else if(event.button.x >770&& event.button.x <1050 && event.button.y >310&& event.button.y <390)
                            {setting(ecran);}

                     else if (event.button.x >570&& event.button.x <850 && event.button.y >465&& event.button.y <540)
                                {Mix_PlayChannel( -1, effect,0);continuer=0; }



        }
		break;        	
		}//switch
		

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(playy, NULL, ecran, &positionplay);
        SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
        SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);
    }


    SDL_FreeSurface(background);
    SDL_FreeSurface(playy);
    SDL_FreeSurface(settingg);
    SDL_FreeSurface(quit);

    SDL_Quit();

  
}
void play(SDL_Surface* ecran)
{//void
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionClic,positionnewgame;
    SDL_Event event;
    int continuee = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    newgame=IMG_Load("newgame_boutton.png");
    positionnewgame.x = 340;
    positionnewgame.y = 310;

    continuer=IMG_Load("Continue_boutton.png");
    positioncontinuer.x = 750;
    positioncontinuer.y = 310;

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
                        menu(ecran);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //choose(ecran);
                        break;
                    case SDLK_KP2: // Demande contols
                        //jouer(ecran);
                        break;


                }//switch2
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {//if case
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;

                    if(event.button.x >340&& event.button.x <625 && event.button.y >310&& event.button.y <390)
                            {/*choose(ecran);*/}

                     else if(event.button.x >750&& event.button.x <1035 && event.button.y >310&& event.button.y <390)
                            {/*jouer(ecran);*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu(ecran);}

			}//if case
			break;
        	}//switch
		
        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
        SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(newgame);
    SDL_FreeSurface(continuer);
    SDL_FreeSurface(back);

    SDL_Quit();
}//quiiter

void setting(SDL_Surface* ecran)
{//void
    SDL_Surface *background=NULL,*resoluton = NULL, *control = NULL, *sound = NULL,*back=NULL;
    SDL_Rect positionresoluton,positioncontrols,positionsound,positionbackground,positionback,positionClic;
    SDL_Event event;
    int continuer = 1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    resoluton=IMG_Load("Resolution_boutton.png");
    positionresoluton.x = 100;
    positionresoluton.y = 310;

    sound=IMG_Load("sound_boutton.png");
    positionsound.x = 958;
    positionsound.y = 310;

    control=IMG_Load("Contols_boutton.png");
    positioncontrols.x = 530;
    positioncontrols.y = 310;



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
                        menu(ecran);
                        break;
                    case SDLK_KP1: // Demande resolution
                        //resolution();
                        break;
                    case SDLK_KP2: // Demande contols
                        controls(ecran);
                        break;
                    case SDLK_KP3 :
                       sounds(ecran);
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {/*resolution();*/}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {controls(ecran);}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {sounds(ecran);}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu(ecran);}


        		}     
		break;   	
		}//switch
		

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
        SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
        SDL_BlitSurface(sound, NULL, ecran, &positionsound);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton);
    SDL_FreeSurface(control);
    SDL_FreeSurface(sound);
    SDL_FreeSurface(back);

    SDL_Quit();


}
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
