#include "menu.h"
void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*manette=NULL,*souris=NULL,*clavier=NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionClic,positionmanette,positionclavier,positionsouris;
    SDL_Event event;
    int continuer = 1,y=1,x=1;

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
			case SDLK_LEFT :
			if(x==1)
			
				{
					back=IMG_Load("Back_boutton.png");
					souris=IMG_Load("souris_gr.png");
					SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;
					
 
				}
  
			
			else  if(x==2)
				{
					souris=IMG_Load("souris.png");
					clavier=IMG_Load("clavier_gr.png");
					SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
					Mix_PlayChannel(1, son, 0);						
					x=3;y=4;	

   
	
				}
			else if(x==3)
					{
					clavier=IMG_Load("clavier.png");
					manette=IMG_Load("manette_gr.png");
					SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;			
					} 
			else if(x==4)
					{
					manette=IMG_Load("manette.png");	
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);					
					x=1;y=2;			
					}
			break;
				case SDLK_RIGHT :
			if(y==1)
			
				{
					souris=IMG_Load("souris.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;
					
				}
			
			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					manette=IMG_Load("manette_gr.png");
					SDL_BlitSurface(manette, NULL, ecran, &positionmanette);
					Mix_PlayChannel(1, son, 0);
					y=3;x=4;		
				}
			else if(y==3)
					{
					manette=IMG_Load("manette.png");
					clavier=IMG_Load("clavier_gr.png");
					SDL_BlitSurface(clavier, NULL, ecran, &positionclavier);
					Mix_PlayChannel(1, son, 0);
					y=4;x=3;			
					}
			else if(y==4)
					{
					
					clavier=IMG_Load("clavier.png");
					souris=IMG_Load("souris_gr.png");
					SDL_BlitSurface(souris, NULL, ecran, &positionsouris);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;			
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{/*souris*/}
					else if(y==2)
					{setting(ecran,son,musique);}
					else if (y==3)
					{/*manette*/}
					else if (y==4)
					{/*clavier*/}
			break;
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        setting(ecran,son,musique);
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
                                {setting(ecran,son,musique);}


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
	SDL_Flip(ecran);
    }//while

    SDL_FreeSurface(background);
    SDL_FreeSurface(manette);
    SDL_FreeSurface(clavier);
    SDL_FreeSurface(souris);
    SDL_FreeSurface(back);

    SDL_Quit();


}//void
