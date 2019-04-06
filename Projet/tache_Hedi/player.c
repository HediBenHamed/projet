#include "player.h"
void initialiserperso(pers *p)
{
    p->up=0;
    p->down=0;
    p->left=0;
    p->right=0;



    p->bas[1] = IMG_Load("haut_1.png");
    p->bas[2] = IMG_Load("haut_2.png");
    p->bas[3] = IMG_Load("haut_3.png");

    p->haut[1] = IMG_Load("bas_1.png");
    p->haut[2] = IMG_Load("bas_2.png");
    p->haut[3] = IMG_Load("bas_3.png");

    p->gauche[1] = IMG_Load("gauche_1.png");
    p->gauche[2] = IMG_Load("gauche_2.png");
    p->gauche[3] = IMG_Load("gauche_3.png");

    p->droite[1] = IMG_Load("droite_1.png");
    p->droite[2] = IMG_Load("droite_2.png");
    p->droite[3] = IMG_Load("droite_3.png");

    p->depart=IMG_Load("depart.png");
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
                            afficherperso(&p, d, ecran);
                            break;

                        case SDLK_LEFT :
                            d=4;
                            p=boujer(d,p);
                            afficherperso(&p, d, ecran);
                            break ;

                        case SDLK_UP :
                            d=8;
                            p=boujer(d,p);
                            afficherperso(&p, d, ecran);
                            break ;

                        case SDLK_DOWN :
                            
			    d=2;
                            p=boujer(d,p);
                            afficherperso(&p, d, ecran);
			    break ;

                    break;
                    }//swuitch 2
                    
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
	p.up++;
	p.position_joueur.y-=10;

}
else if(d==2)
{
	p.down++;
	p.position_joueur.y+=10;

}
if(p.right==3)
    {p.right=1;}

if (p.left==3)
    {p.left=1;}

if (p.up==3)
    {p.up=1;}

if (p.down==3)
    {p.down=1;}

return p;
}

void afficherperso(pers *p,int d,SDL_Surface *ecran)
{

if(d==6)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->droite[p->right],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);


        p->up=0;
        p->down=0;
        p->left=0;
}

else if (d==4)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->gauche[p->left],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);

        p->up=0;
        p->down=0;
        p->right=0;
}
else if (d==8)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->haut[p->up],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);

        p->up=0;
        p->down=0;
        p->left=0;
}
else if (d==2)
{	
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(p->bas[p->down],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);

        p->up=0;
        p->down=0;
        p->left=0;
}
}
int collision(pers *p,SDL_Rect position_ennemi)
{

	
if (position_ennemi.x==(p->position_joueur.x+p->position_joueur.w))
    return 1;// collision_droite est vrai

else if  ((position_ennemi.x+position_ennemi.w)==p->position_joueur.x)
     return 1;// collision_gauche  vrai

else if  (position_ennemi.y==(position_ennemi.y+p->position_joueur.h))
    return 1;// collision_bas  vrai

else if ((position_ennemi.y+position_ennemi.h)==p->position_joueur.y)
    return 1;// collision_bas  vrai

return 0;
}
