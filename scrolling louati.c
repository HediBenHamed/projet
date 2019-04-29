#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main(void)
{
    SDL_Surface *ecran = NULL, *background = NULL;
    SDL_Rect positionbackground;
    SDL_Event event;
    int a;
    char pause;
  

int continuer=1;

    positionbackground.x = 0;
    positionbackground.y = 0;

SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=1300;

camera.h=475;

const int speed=20;

    a=SDL_Init(SDL_INIT_VIDEO);


    ecran = SDL_SetVideoMode(1300, 475, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    background = SDL_LoadBMP("BG.bmp");
    SDL_BlitSurface(background,&camera, ecran, &positionbackground);
SDL_Flip(ecran);
SDL_EnableKeyRepeat(75,30);
SDL_ShowCursor(SDL_ENABLE);
   
while (continuer == 1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        case SDL_MOUSEMOTION:
            pause=getchar();
                        break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {  
            case SDLK_ESCAPE:
            continuer=0;
            break;
            case SDLK_UP:
                        
                         camera.y-=speed;

                        break;
                  
                    case SDLK_RIGHT:
                  
                         camera.x+=speed;
           
            break;

                    case SDLK_LEFT:
           
                        camera.x-=speed;

                        break;
           
                }
}
SDL_BlitSurface(background,&camera,ecran,&positionbackground);
SDL_Flip(ecran);

              }

               
}


 
        
