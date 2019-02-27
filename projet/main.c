#include "fonction.h"

int main()
{
    SDL_Surface *screen = NULL, *menu = NULL,*texte=NULL,*play=NULL,*setting=NULL,*exite=NULL,*ecran=NULL;;
    SDL_Rect positionMenu,positionplay,positionsetting,positionexit,positionecran,positionClic;

    SDL_Event event;
    int continuer = 1;
	int i=0;
	int s=0;
	int p=0;



    if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	 printf("implossible d'initialise le SDL ! %s\n",SDL_GetError());
	 return 1;
	}	
	SDL_WM_SetIcon(IMG_Load("logo.png"),NULL);
	SDL_WM_SetCaption("Guernsey", NULL);
	
	screen=SDL_SetVideoMode(1366,678,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	if(screen==NULL)
		{
		 printf("impossible de charger le mode video %s\n",SDL_GetError());
		 return 1;
		}


	menu= IMG_Load("background_p.png");
	if(menu==NULL)
	{ printf("impossible de charger l'image 1 %s\n",SDL_GetError());}
	
	positionMenu.x = 0;
    	positionMenu.y = 0;
	
	SDL_BlitSurface(menu,NULL,screen, &positionMenu);	
	SDL_Flip(screen);
	
	
	positionplay.x=351;
	positionplay.y=312;

	play=IMG_Load("boutton_play.png");
	if(play==NULL)
	{ printf("impossibl_e de charger l'image2 %s\n",SDL_GetError());}
	SDL_BlitSurface(play,NULL,screen, &positionplay);	
	SDL_Flip(screen);
	SDL_FreeSurface(play);
	

	


	positionsetting.x=769;
	positionsetting.y=313;

	setting=IMG_Load("boutton_setting.png");
	if(setting==NULL)
	{ printf("impossible de charger l'image %s\n",SDL_GetError());}
	SDL_BlitSurface(setting,NULL,screen, &positionsetting);	
	SDL_Flip(screen);
	SDL_FreeSurface(setting);
	

	positionexit.x=571;
	positionexit.y=463;

	exite=IMG_Load("boutton_exit.png");
	if(exite==NULL)
	{ printf("impossible de charger l'image %s\n",SDL_GetError());}
	SDL_BlitSurface(exite,NULL,screen, &positionexit);	
	SDL_Flip(screen);
	SDL_FreeSurface(exite);


	
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
                 }
               
	     case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{positionClic.x = event.button.x ;
		positionClic.y = event.button.x;

			
			if((event.button.x >350 && event.button.x <640 && event.button.y >310&& event.button.y <390) && (i==0))
				
							
				{	i=1;
					positionecran.x=0;
					positionecran.y=0;

					ecran=IMG_Load("play.png");
					if(exite==NULL)
					{ printf("impossible de charger l'image %s\n",SDL_GetError());}
					SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
					SDL_Flip(screen);
					SDL_FreeSurface(ecran);
					p=1;
				} 
			else  if((event.button.x >340 && event.button.x <625  && event.button.y >310 && event.button.y<390) && (p!=0)&& (i!=0))
					{	s=1;
						positionecran.x = 0;
    						positionecran.y = 0;
						ecran= IMG_Load("choose.png");
						SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
						SDL_Flip(screen);
						SDL_FreeSurface(ecran);
						i=1;
						
					
					}
	

		else if ((event.button.x >770 && event.button.x <1060  && event.button.y >310 && event.button.y<390) && (i==0))
					{i=1;
					positionecran.x=0;
					positionecran.y=0;
					ecran=IMG_Load("setting.png");

					SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
					SDL_Flip(screen);
					SDL_FreeSurface(ecran);
					s=1;
					
		
					
			
					}
					
		else if((event.button.x >100 && event.button.x <390  && event.button.y >300&& event.button.y<390) && (s!=0))
					{
					positionecran.x=0;
					positionecran.y=0;
					ecran=IMG_Load("back.png");

					SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
					SDL_Flip(screen);
					SDL_FreeSurface(ecran);
					s=2;
					}	
		else if((event.button.x >530 && event.button.x <810  && event.button.y >300&& event.button.y<390) && (s!=0))
					{s=2;
					positionecran.x=0;
					positionecran.y=0;
					ecran=IMG_Load("back.png");

					SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
					SDL_Flip(screen);
					SDL_FreeSurface(ecran);
					
					}
		else if((event.button.x >965 && event.button.x <1240  && event.button.y >300&& event.button.y<390) && (s!=0))
					{
					positionecran.x=0;
					positionecran.y=0;
					ecran=IMG_Load("back.png");

					SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
					SDL_Flip(screen);
					SDL_FreeSurface(ecran);
					s=2;
					}
	

					
					
					
			else  if((event.button.x >50 && event.button.x <210  && event.button.y >40 && event.button.y<90) && (s==2))
					{	s=1;
						positionecran.x = 0;
    						positionecran.y = 0;
						ecran= IMG_Load("setting.png");
						SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
						SDL_Flip(screen);
						SDL_FreeSurface(ecran);
						i=0;
						
					
					}	
	
					

			else  if((event.button.x >50 && event.button.x <210  && event.button.y >40 && event.button.y<90) && (s==1))
						{
	
				
						positionecran.x = 0;
    						positionecran.y = 0;
						ecran= IMG_Load("Menu.png");
						SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
						SDL_Flip(screen);
						SDL_FreeSurface(ecran);
						i=0;
	
						}
			else  if((event.button.x >50 && event.button.x <210  && event.button.y >40 && event.button.y<90) && (p==1))
						{
	
				
						positionecran.x = 0;
    						positionecran.y = 0;
						ecran= IMG_Load("Menu.png");
						SDL_BlitSurface(ecran,NULL,screen, &positionecran);	
						SDL_Flip(screen);
						SDL_FreeSurface(ecran);
						i=0;
	
						}
			
		else if ((event.button.x >580 && event.button.x <840 && event.button.y >470 && event.button.y <550) && (i==0))
				{	i++;
					continuer=0;
				}
}
		

		

		break;

	}

					
}
SDL_FreeSurface(menu);


SDL_Quit();





return 0;
}

