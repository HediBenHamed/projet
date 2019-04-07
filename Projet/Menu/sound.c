#include "menu.h"
void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
    SDL_Surface *background=NULL,*augmenter = NULL, *diminuer = NULL,*back=NULL,*couper=NULL;
    SDL_Rect positionaugmenter,positiondiminuer,positionbackground,positioncouper,positionback,positionClic;
    SDL_Event event;
    int continuer = 1,x=1,y=1,a=0,i=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    augmenter=IMG_Load("augmenter_volume.png");
    positionaugmenter.x = 450;
    positionaugmenter.y = 310;

    diminuer=IMG_Load("diminuer_volume.png");
    positiondiminuer.x = 750;
    positiondiminuer.y = 310;

    couper=IMG_Load("couper_son.png");
    positioncouper.x = 590;
    positioncouper.y = 310;

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
					diminuer=IMG_Load("diminuer_gr.png");
					SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
					Mix_PlayChannel(1, son, 0);
					x=2;y=1;
					
				}
  
			
			else  if(x==2)
				{
					diminuer=IMG_Load("diminuer_volume.png");
					couper=IMG_Load("couper_gr.png");
					SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
					Mix_PlayChannel(1, son, 0);	
					x=3;y=4;		
				}
			else if(x==3)
					{
					couper=IMG_Load("couper_son.png");
					augmenter=IMG_Load("augmenter_gr.png");
					SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
					Mix_PlayChannel(1, son, 0);
					x=4;y=3;			
					} 
			else if(x==4)
					{
					augmenter=IMG_Load("augmenter_gr.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);					
					x=1;y=2;			
					}
			break;
				case SDLK_RIGHT :
			if(y==1)
			
				{
					diminuer=IMG_Load("diminuer_volume.png");
					back=IMG_Load("back_gr.png");
					SDL_BlitSurface(back, NULL, ecran, &positionback);
					Mix_PlayChannel(1, son, 0);
					y=2;x=1;
					
				}
			
			else  if(y==2)
				{
					back=IMG_Load("Back_boutton.png");
					augmenter=IMG_Load("augmenter_gr.png");
					SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
					Mix_PlayChannel(1, son, 0);	
					y=3;x=4;		
				}
			else if(y==3)
					{
					augmenter=IMG_Load("augmenter_volume.png");
					couper=IMG_Load("couper_gr.png");
					SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
					Mix_PlayChannel(1, son, 0);	
					y=4;x=3;			
					}
			else if(y==4)
					{
					
					couper=IMG_Load("couper_son.png");
					diminuer=IMG_Load("diminuer_gr.png");
					SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
					Mix_PlayChannel(1, son, 0);	
					y=1;x=2;			
					}
			break;
			case SDLK_RETURN :
					if(y==1)//diminuer son
					{Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);}
					else if(y==2)//retour
					{ setting(ecran,son,musique);}
					else if (y==3)//augmenter son
					{Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);}
					else if (y==4)
					{
					if(a==0)
					{
					   Mix_PauseMusic();a=1;}
						else if(a==1)
							{Mix_ResumeMusic();a=0;}
					}

			break;

                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        setting(ecran,son,musique);
                        break;
                    case SDLK_KP1: // Demande augmenter
                        Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);
                        break;
                    case SDLK_KP2: // Demande diminuer
                        Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                        break;
		     case SDLK_KP3: // Demande  coupeer son 
                        
					if(a==0)
					{Mix_PauseMusic();a=1;}
						else if(a==1){
						Mix_ResumeMusic();
							a=0;}
                        break;	

                }
                break;
                case SDL_MOUSEBUTTONUP:

                         if (event.button.button == SDL_BUTTON_LEFT)
		         {
                             positionClic.x = event.button.x ;
                             positionClic.y = event.button.x;
 		
			 if(event.button.x >450&& event.button.x <540 && event.button.y >310&& event.button.y <390)
                            {Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*4);}

                     
			else if(event.button.x >590&& event.button.x <680 && event.button.y >310&& event.button.y <390)
                            {
					if(a==0)
					{Mix_PauseMusic();a=1;}
						else if(a==1){
						Mix_ResumeMusic();
							a=0;}
			    }

			else if(event.button.x >750&& event.button.x <840 && event.button.y >310&& event.button.y <390)
                            {Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);}

                     else if (event.button.x >70&& event.button.x <210 && event.button.y >40&& event.button.y <95)
                                {setting(ecran,son,musique);}


        		}     
		break;   	
		}//switch
		

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
	SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
        SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(background);
    SDL_FreeSurface(couper);
    SDL_FreeSurface(augmenter);
    SDL_FreeSurface(diminuer);
    SDL_FreeSurface(back);

    SDL_Quit();


}

