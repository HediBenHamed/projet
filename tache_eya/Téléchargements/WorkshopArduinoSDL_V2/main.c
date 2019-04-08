#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



int arduinoWriteData(int x);
int arduinoReadData(int *x);
int checkCollidsionBoundingBox(SDL_Rect a, SDL_Rect b);

int main( int argc, char *argv[ ] )
{

int directionSDL=0; //0:standby 1 : moving right 2 : moving left
int directionArduino=0; //0:standby 1 : moving right 2 : moving left

int game=1;
char received;
int collisionRightSide = 0;
int collisionLeftSide = 0;


SDL_Event event;
SDL_Surface *screen=NULL,*pomme=NULL,*barriere=NULL;
SDL_Rect positionpomme,posbarriere1,posbarriere2;

//init Link with arduino
system("stty -F /dev/ttyACM0 9600 -parenb cs8 -cstopb");

    //init SDL Video
    SDL_Init(SDL_INIT_VIDEO);

    pomme=IMG_Load("pomme.gif");
    barriere=IMG_Load("ligne.png");
    screen = SDL_SetVideoMode(600, 300, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


    positionpomme.x=20;
    positionpomme.y=150;
    positionpomme.w=pomme->w;
    positionpomme.h=pomme->h;

    posbarriere1.x=590;
    posbarriere1.y=0;
    posbarriere1.w=barriere->w;
    posbarriere1.h=barriere->h;

    posbarriere2.x=10;
    posbarriere2.y=0;
    posbarriere2.w=barriere->w;
    posbarriere2.h=barriere->h;

    if(screen == NULL)
    {
        printf("Erreur Loading Image background.bmp\n");
        return EXIT_FAILURE;
    }

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
    while (game)
    {
      //input from SDL
      while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                game = 0;
                break;
            case SDL_KEYDOWN:
            {

                if (event.key.keysym.sym == SDLK_RIGHT)
                  directionSDL = 1;

                if (event.key.keysym.sym == SDLK_LEFT)
                  directionSDL = 2;

            }
            break;
            case SDL_KEYUP:
              directionSDL=0;
            break;

            }
          }
          //input from arduino


            //update ( from SDL events and ARDUINO events)

            //check collision
            if(positionpomme.x+positionpomme.w<posbarriere1.x)
                collisionRightSide=0;
            else
                collisionRightSide=1;
            if(positionpomme.x > posbarriere2.x + posbarriere2.w)
                collisionLeftSide=0;
            else
                collisionLeftSide=1;


            if(collisionRightSide == 1){
              printf("\n COLLISION RIGHT SENDING 1 TO SERIAL");
              //........................

            } else if(collisionLeftSide == 1){
              printf("\n COLLISION LEFT SENDING 2 TO SERIAL");
            //..........................

            } else {
            printf("\n NO COLLISION SENDING 0 TO SERIAL");
            //..........................
            }

            if((directionSDL == 1 ) && !collisionRightSide){
                 positionpomme.x += 1;

            }
            if ((directionSDL == 2 ) && !collisionLeftSide){
              positionpomme.x -= 1;
            }

            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255,255, 255));
            SDL_BlitSurface(pomme ,NULL, screen, &positionpomme );
            SDL_BlitSurface(barriere ,NULL, screen, &posbarriere1 );
            SDL_BlitSurface(barriere ,NULL, screen, &posbarriere2 );
            SDL_Flip( screen );
            //printf("\nReceived from Arduino :%d ",received);
    }


    SDL_FreeSurface(pomme);
    SDL_FreeSurface(barriere);
    SDL_Quit();
    return 0;
}


int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
