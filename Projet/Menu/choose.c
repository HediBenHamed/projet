#include "menu.h"
void choose(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*joueur1 = NULL, *joueur2 = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positionjoueur1,positionClic,positionjoueur2;
    SDL_Event event;
    
   
    int continuee = 1,y=1,x=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    joueur1=IMG_Load("joueur1.png");
    positionjoueur1.x = 190;
    positionjoueur1.y = 220;

    joueur2=IMG_Load("joueur2.png");
    positionjoueur2.x = 875;
    positionjoueur2.y = 220;

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
			case SDLK_LEFT :
			if(x==1)
			
				{
					back=IMG_Load("Back_boutton.png");
					joueur2=IMG_Load("joueur2_gr.png");
					SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
					Mix_PlayChannel(1, son, 0);

					x=2;y=1;
					
				}
			
			else  if(x==2)
				{
					joueur2=IMG_Load("joueur2.png");
					joueur1=IMG_Load("joueur1_gr.png");
					SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
					Mix_PlayChannel(1, son, 0);				
						
					x=3;y=3;		
				}
			else if(x==3)
					{
					joueur1=IMG_Load("joueur1.png");
					back=IMG_Load("back_gr.png");
					Mix_PlayChannel(1, son, 0);					
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					x=1;y=2;			
					}
			break;
				case SDLK_RIGHT :
			if(y==1)
			
				{
					joueur2=IMG_Load("joueur2.png");
					back=IMG_Load("back_gr.png");
					
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);					
					y=2;x=1;//
					
				}//
			
			else  if(y==2)
				{	
					back=IMG_Load("Back_boutton.png");
				
					joueur1=IMG_Load("joueur1_gr.png");
					SDL_BlitSurface(joueur1, NULL, ecran, &positionjoueur1);
					Mix_PlayChannel(1, son, 0);						
					y=3;x=3;//	
				}
			else if(y==3)//
					{
					joueur1=IMG_Load("joueur1.png");
					joueur2=IMG_Load("joueur2_gr.png");
					SDL_BlitSurface(joueur2, NULL, ecran, &positionjoueur2);
					Mix_PlayChannel(1, son, 0);					
					y=1;x=2;//			
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{}
					else if(y==2)
					{play(ecran,son,musique);}
					else if (y==3)
					{choose(ecran,son,musique);}
			break;
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        play(ecran,son,musique);
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

                    if(event.button.x >270&& event.button.x <380 && event.button.y >425&& event.button.y <570)
                            {/*jouer1(ecran);*/}

                     else if(event.button.x >1045&& event.button.x <1235 && event.button.y >315&& event.button.y <550)
                            {/*jouer2(ecran);*/}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {play(ecran,son,musique);}

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

