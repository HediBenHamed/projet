#include "collision.h"
int collisionAB(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE)
{
  int i=1;
	if ( posP.x > (posE.x +  E->w)) i = 0;
	else if ((posP.x + P->w) < posE.x ) i = 0;
	else if (((posP.y + P->h) < posE.y )||( posP.y > (posE.y + E->h))) i = 0;
return i;
}

void initialiserperso(pers *p)
{
    p->up=0;
    p->down=0;
    p->left=0;
    p->right=0;


    p->bas[1] = IMG_Load("position_choix.png");
    p->bas[2] = IMG_Load("position_choix.png");
    p->bas[3] = IMG_Load("position_choix.png");
    p->bas[4] = IMG_Load("position_choix.png");
    p->bas[5] = IMG_Load("position_choix.png");
    p->bas[6] = IMG_Load("position_choix.png");
    p->bas[7] = IMG_Load("position_choix.png");
    p->bas[8] = IMG_Load("position_choix.png");


    p->haut[1] = IMG_Load("position_choix.png");
    p->haut[2] = IMG_Load("position_choix.png");
    p->haut[3] = IMG_Load("position_choix.png");
    p->haut[4] = IMG_Load("position_choix.png");
    p->haut[5] = IMG_Load("position_choix.png");
    p->haut[6] = IMG_Load("position_choix.png");
    p->haut[7] = IMG_Load("position_choix.png");
    p->haut[8] = IMG_Load("position_choix.png");

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
    p->position_joueur.x=65;
    p->position_joueur.y=350;
}


void afficherperso(pers *p,int d,SDL_Surface *ecran)
{

if(d==6)
{	SDL_SetColorKey(p->droite[p->right],SDL_SRCCOLORKEY,SDL_MapRGB(p->droite[p->right]->format,255,255,255));
	SDL_BlitSurface(p->droite[p->right],NULL, ecran,&p->position_joueur);
	p->up=0;
        p->down=0;
        p->left=0;
}

else if (d==4)
{
	SDL_BlitSurface(p->gauche[p->left],NULL, ecran,&p->position_joueur);
	p->up=0;
        p->down=0;
        p->right=0;
}
else if (d==8)
{
	SDL_BlitSurface(p->haut[p->up],NULL, ecran,&p->position_joueur);
        SDL_Flip(ecran);
	p->right=0;
        p->down=0;
        p->left=0;
}
else if (d==2)
{	
	SDL_BlitSurface(p->bas[p->down],NULL, ecran,&p->position_joueur);
	p->up=0;
        p->right=0;
        p->left=0;
}
}
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
if(p.right==8)
    {p.right=1;}

if (p.left==8)
    {p.left=1;}

if (p.up==8)
    {p.up=1;}

if (p.down==8)
    {p.down=1;}

return p;
}

void liberer_surface(pers *p)
{
    SDL_FreeSurface(p->haut[p->up]);
    SDL_FreeSurface(p->gauche[p->left]);
    SDL_FreeSurface(p->bas[p->down]);
    SDL_FreeSurface(p->droite[p->right]);
}
