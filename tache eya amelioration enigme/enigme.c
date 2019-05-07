
#include "enigme.h"


int enigme ()

{   char nom[6];
    int r=0,A=0;
    srand(time(NULL));

    FILE* fichier=NULL;
    FILE* fichierr=NULL;
    r=rand()%4+1;


    char chaine[256]="";
    char chainer[256]="";
   /* printf("1\n" );*/


    fichier=fopen("questions.txt", "r");
    fichierr=fopen("answers.txt", "r");

/*for (int i=0; i<5; i++)
{ if (i == r) {
fgets (chaine, 265, fichier );
fgets (chainer, 265, fichierr );
}
}
fclose(fichier);
fclose(fichierr);
*/
int i =0;
while (fgets (chaine, 265, fichier ) != NULL && fgets (chainer, 1000, fichierr ) !=NULL)
{
  i++;
  if (i==r) {
break;
  }
}



/*printf("2\n" );*/


    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL, *rp =NULL, *background = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    int continuer = 1;

   /* printf("3\n" );*/

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
   /* printf("4\n" );*/


    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("GENERATION ALEATOIRE DE L ENIGME", NULL);
    /*printf("fdsdfsdf\n" );*/

background = IMG_Load("background.png");
    fond = IMG_Load("enigme.png");
    police = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 25);
    police1 = TTF_OpenFont("Perfect DOS VGA 437 Win.ttf", 15);


/*printf("5\n" );*/

    texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
    rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);

    while (continuer)

    {
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));


        position.x = 0;

        position.y = 0;
      //  SDL_BlitSurface(background, NULL, ecran, &position);

        SDL_BlitSurface(fond, NULL, ecran, &position);


        position.x = 33;

        position.y = 70;

        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x = 55;

        position.y = 260;

        SDL_BlitSurface(rp, NULL, ecran, &position);

        SDL_Flip(ecran);
        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;
                case SDL_MOUSEBUTTONDOWN :
                if( (event.button.x>65 && event.button.x<100 && event.button.y>250 && event.button.y<270) )
             {A= 1 ; continuer = 0; break;}
             else if ( (event.button.x>160 && event.button.x<210 && event.button.y>250 && event.button.y<270) )
             {A = 0 ; continuer = 0; break;}
             else if ( (event.button.x>290 && event.button.x<340 && event.button.y>250 && event.button.y<270) )
             {A = 0 ; continuer = 0 ;break;}
	     else if ( (event.button.x>370 && event.button.x<410 && event.button.y>250 && event.button.y<270) )
             {A = 0 ; continuer = 0 ;break;}
        }

    }

printf("%d\n",A );
    TTF_CloseFont(police);

    TTF_Quit();


    SDL_FreeSurface(texte);

    SDL_Quit();


    return EXIT_SUCCESS;

}
