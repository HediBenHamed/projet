#include "menu.h"
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{//void
    SDL_Surface *background=NULL,*resoluton = NULL, *control = NULL, *sound = NULL,*back=NULL;
    SDL_Rect positionresoluton,positioncontrols,positionsound,positionbackground,positionback,positionClic;
    SDL_Event event;
    int continuer = 1,x=1,y=1;

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
			case SDLK_LEFT :
			if(x==1)
			
				{
					back=IMG_Load("Back_boutton.png");
					sound=IMG_Load("sound_gr.png");
					SDL_BlitSurface(sound, NULL, ecran, &positionsound);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;
					
				}
  
			
			else  if(x==2)
				{
					sound=IMG_Load("sound_boutton.png");
					control=IMG_Load("controls_gr.png");
					SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
					Mix_PlayChannel(1, son, 0);						
					x=3;y=4;		
				}
			else if(x==3)
					{
					control=IMG_Load("Contols_boutton.png");
					resoluton=IMG_Load("Resolution_gr.png");
					SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;			
					} 
			else if(x==4)
					{
					resoluton=IMG_Load("Resolution_boutton.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);					
					x=1;y=2;			
					}
			break;
				case SDLK_RIGHT :
			if(y==1)
			
				{
					sound=IMG_Load("sound_boutton.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;
					
				}
			
			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					resoluton=IMG_Load("Resolution_gr.png");
					SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
					Mix_PlayChannel(1, son, 0);
					y=3;x=4;		
				}
			else if(y==3)
					{
					resoluton=IMG_Load("Resolution_boutton.png");
					control=IMG_Load("controls_gr.png");
					SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
					Mix_PlayChannel(1, son, 0);
					y=4;x=3;			
					}
			else if(y==4)
					{
					
					control=IMG_Load("Contols_boutton.png");
					sound=IMG_Load("sound_gr.png");
					SDL_BlitSurface(sound, NULL, ecran, &positionsound);
					Mix_PlayChannel(1, son, 0);
					y=1;x=2;			
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					{sounds(ecran,son,musique);}
					else if(y==2)
					{menu(ecran,musique);}
					else if (y==3)
					{resolution(ecran,son,musique);}
					else if (y==4)
					{controls(ecran,son,musique);}
			break;

                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        menu(ecran,musique);
                        break;
                    case SDLK_KP1: // Demande resolution
                        resolution(ecran,son,musique);
                        break;
                    case SDLK_KP2: // Demande contols
                        controls(ecran,son,musique);
                        break;
                    case SDLK_KP3 :
                       sounds(ecran,son,musique);
                        break;
                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
                    if(event.button.x >100&& event.button.x <390 && event.button.y >310&& event.button.y <390)
                            {resolution(ecran,son,musique);}

                     else if(event.button.x >525&& event.button.x <810 && event.button.y >310&& event.button.y <390)
                            {controls(ecran,son,musique);}

                     else if(event.button.x >960&& event.button.x <1240 && event.button.y >310&& event.button.y <390)
                            {sounds(ecran,son,musique);}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {menu(ecran,musique);}


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


