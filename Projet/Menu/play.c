#include "menu.h"
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionClic,positionnewgame;
    SDL_Event event;
    int continuee = 1,x=1,y=1;



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
                        menu(ecran,musique);
                        break;
		   case SDLK_LEFT :
			if(x==1)
			
				{
					back=IMG_Load("Back_boutton.png");
					continuer=IMG_Load("continuer_gr.png");
					SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;
					
				}
			
			else  if(x==2)
				{
					continuer=IMG_Load("Continue_boutton.png");
					newgame=IMG_Load("Newgame_gr.png");
					SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
					Mix_PlayChannel(1, son, 0);						
					x=3;y=3;		
				}
			else if(x==3)
					{
					newgame=IMG_Load("newgame_boutton.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					x=1;y=2;			
					}
			break;
				case SDLK_RIGHT :
			if(y==1)
			
				{
					continuer=IMG_Load("Continue_boutton.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;//
					
				}//
			
			else  if(y==2)
				{	
					back=IMG_Load("Back_boutton.png");
					newgame=IMG_Load("Newgame_gr.png");
					SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
					Mix_PlayChannel(1, son, 0);	
					y=3;x=3;//	
				}
			else if(y==3)//
					{
					newgame=IMG_Load("newgame_boutton.png");
					continuer=IMG_Load("continuer_gr.png");
					SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
					Mix_PlayChannel(1, son, 0);					
					y=1;x=2;//			
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{}
					else if(y==2)
					{menu(ecran,musique);}
					else if (y==3)
					{choose(ecran,son,musique);}
			break;
                    case SDLK_KP1: // Demande resolution
                        choose(ecran,son,musique);
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
                            {choose(ecran,son,musique);}

                     else if(event.button.x >750&& event.button.x <1035 && event.button.y >310&& event.button.y <390)
                            {/*jouer(ecran);*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu(ecran,musique);}

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

