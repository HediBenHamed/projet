#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage_d'ecran.h"


void initialiser_joueur1(joueur *j)
{
    j->p[0]=IMG_Load("p1.png");

    j->pp.x = 20;
    j->pp.y = 200;

}

void initialiser_joueur2(joueur *j)
{
    j->p[1]=IMG_Load("p2.png");

    j->pp.x = largeur/2 + 10;
    j->pp.y = 200;

}

void initialiser_background1(background *b)
{
    b->background=IMG_Load("background.png");
    b->pb.x=0;
    b->pb.y=0;
    b->pb.w=largeur/2;
    b->pb.h=hauteur;
}

void initialiser_background2(background *b)
{
    b->background=IMG_Load("background.png");
    b->pb.x=largeur/2;
    b->pb.y=0;
    b->pb.w=largeur/2;
    b->pb.h=hauteur;
}



