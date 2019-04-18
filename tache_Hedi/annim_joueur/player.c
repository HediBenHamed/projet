#include "player.h"

void initialiserperso(pers *p)
{

    p->gauche[1] = IMG_Load("position_gauche1.png");
    p->gauche[2] = IMG_Load("position_gauche2.png");
    p->gauche[3] = IMG_Load("position_gauche3.png");
    p->gauche[4] = IMG_Load("position_gauche4.png");
    p->gauche[5] = IMG_Load("position_gauche5.png");
    p->gauche[6] = IMG_Load("position_gauche6.png");
    p->gauche[7] = IMG_Load("position_gauche7.png");
    p->gauche[8] = IMG_Load("position_gauche8.png");

    p->droite[1] = IMG_Load("position_droit1.png");
    p->droite[2] = IMG_Load("position_droit2.png");
    p->droite[3] = IMG_Load("position_droit3.png");
    p->droite[4] = IMG_Load("position_droit4.png");
    p->droite[5] = IMG_Load("position_droit5.png");
    p->droite[6] = IMG_Load("position_droit6.png");
    p->droite[7] = IMG_Load("position_droit7.png");
    p->droite[8] = IMG_Load("position_droit8.png");

    p->depart=IMG_Load("position_choix.png");
    p->bas= IMG_Load("position_choix.png");
    p->haut= IMG_Load("position_choix.png");

    p->left=0;
    p->right=0;


    p->position_joueur.x=65;
    p->position_joueur.y=350;
}



void mouvement(pers p,SDL_Surface *ecran)
{
    int continuer=1,d=0;
    SDL_Event event;



 SDL_BlitSurface(p.depart,NULL, ecran,&p.position_joueur);
 SDL_EnableKeyRepeat(10,30);   	

while (continuer)
    {//while
        SDL_WaitEvent(&event);

        switch(event.type)
            {//switch

                case SDL_QUIT:
                continuer = 0;
                break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {//switch
                        case SDLK_ESCAPE:
                            continuer=0 ;
                            break ;

                        case SDLK_RIGHT :
                            d=6;
                            p=boujer(d,p);
                            //afficherperso(&p, d, ecran);
				
                            break;

                        case SDLK_LEFT :
                            d=4;
                            p=boujer(d,p);
                            //afficherperso(&p, d, ecran);
					
                            break ;

                        case SDLK_UP :
                            d=8;
                            p=boujer(d,p);
                            //afficherperso(&p, d, ecran);
					
                            break ;

                        case SDLK_DOWN :
                            
			    d=2;
                            p=boujer(d,p);
                            //afficherperso(&p, d, ecran);
				
			    break ;

                    break;
                    }//swuitch 2
                    afficherperso(&p, d, ecran);
		    
		break;

            }

	
	
	SDL_Flip(ecran);
}

SDL_FreeSurface(ecran);
SDL_Quit();

}
//fonction bouger
pers boujer(int d, pers p)
{

if(d==6)
{
  p.right++;
  p.position_joueur.x+=10;

}
else if(d==4)
{
	p.left++;
	p.position_joueur.x-=10;
}
else if(d==8)
{
	
	p.position_joueur.y-=10;

}
else if(d==2)
{
	
	p.position_joueur.y+=10;

}
if(p.right==8)
    {p.right=1;}

if (p.left==8)
    {p.left=1;}



return p;
}

void afficherperso(pers *p,int d,SDL_Surface *ecran)
{

if(d==6)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->droite[p->right],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);
	p->left=0;
}

else if (d==4)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->gauche[p->left],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);
	p->right=0;
}
else if (d==8)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->haut,NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);
	p->right=0;
        p->left=0;
}
else if (d==2)
{	
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->bas,NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);
	p->right=0;
        p->left=0;
}
}

void liberer_surface(pers *p)
{
    SDL_FreeSurface(p->haut);
    SDL_FreeSurface(p->gauche[p->left]);
    SDL_FreeSurface(p->bas);
    SDL_FreeSurface(p->droite[p->right]);
}
