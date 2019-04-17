#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include <SDL/SDL_mixer.h>
#include "f.h"
#include "collision.h"
#include "scroll.h"


int main(int argc,char** argv)    
{
    SDL_Surface* screen;
	background back;
	
    int quitter = 0;
   int jump=0,right=0,left=0;
   int a;
  


    perso S;
    Uint32 timer,elapsed;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		return 1;
	}
    screen=SDL_SetVideoMode(1024,512,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

   
    S.life=3;
	initialiser_fond(&back);
	charger_fond(&back);
	affichage_fond(&back,screen);
    SDL_WM_SetCaption("SDL_Mixer", NULL);
	SDL_Flip(screen); 
       if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
     {
      printf("%s", Mix_GetError());
     }
      Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
      Mix_Music *musique; //Création d'un pointeur de type Mix_Music
      musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
      Mix_PlayMusic(musique, -1); //Jouer infiniment la musique 
     //SDL_BlitSurface(bg,NULL,screen,NULL);
    InitSprite(&S);
    do
    {
        timer = SDL_GetTicks();


//        SDL_BlitSurface(bg,NULL,screen,NULL);
        
  
        SDL_Event event;

        while (SDL_PollEvent(&event))
        { 
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_SPACE:
                            jump = 1;
                        break;

                        case SDLK_ESCAPE:
                        quitter = 1;
                        exit(0);
                        break;


                        case SDLK_LEFT:
                            {
			left = 1;

			if(back.cadre.x>0)
			{
				
				//scrolling(&back,a);	
			}
			    }
                        break;

                        case SDLK_RIGHT:
                            {
			right = 1;
			if(back.cadre.x<975)
			{
				
				//scrolling(&back,a);
			}
			}
			break;

                        default:
                        break;
                    }

                break;

                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
			
                        case SDLK_SPACE:
                            jump = 0;
                        break;           

                        case SDLK_LEFT:
                            {left = 0;
 				
			    }
	                break;

                        case SDLK_RIGHT:
			{
                            right = 0;
				
			}
                        break;


                        default:
                        break;
                    }
                break;
            }
        }

        evolution(&S,quitter,jump,left,right,&back);
   // printf("life %d",S.life);
	affichage_fond(&back,screen);
	SDL_Flip(screen);

        affichage(&S,screen);

        


        elapsed = SDL_GetTicks() - timer;
        if (elapsed<20)
            SDL_Delay(20-elapsed);


    }
    while (quitter == 0);

const int FRAMES_PER_SECOND = 20;
int frame = 0;
 
//Ce qui va nous servir a activer/desactiver le regulateur
bool cap = true;
 
//Le regulateur
Timer fps;
//Tant que l'utilisateur n'a pas quitte
while( quit == false )
{
	//On demarre le timer fps
	fps.start();
//Tant qu'il y a un evenement
        while( SDL_PollEvent( &event ) )
        {
            //Si une touche est pressee
            if( event.type == SDL_KEYDOWN )
            {
                //Si la touche Entrée est pressee
                if( event.key.keysym.sym == SDLK_RETURN )
                {
                    //On tourne le regulateur sur on/off
                    cap = ( !cap );
 
                    if (cap == true) {
                        //Generation de la surface message
                        SDL_BlitSurface(ch,NULL,screen,NULL)
                    }
                    else {
                        //Generation de la surface message
                        SDL_BlitSurface(ch1,NULL,screen,NULL)
                    }
                }
            }
 
            //Si l'utilisateur a clique sur le X de la fenetre
            else if( event.type == SDL_QUIT )
            {
                //On quitte the programme
                quit = true;
            }
        }






  

    SDL_FreeSurface(back.masque);
    SDL_FreeSurface(back.fond);
     Mix_FreeMusic(musique); //Libération de la musique
     Mix_CloseAudio(); //Fermeture de l'API 
      SDL_Quit();
        return 0;
}
