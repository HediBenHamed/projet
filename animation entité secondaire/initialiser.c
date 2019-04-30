#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initialiser.h"
#define largeur 1000
#define hauteur 700

void initialiserbg(bg *b)
{
    b->bk=IMG_Load("b.jpg");

    b->pbk.x=0;
    b->pbk.y=0;
}

void initialiserps(perso *pr)
{
    pr->p[0]=IMG_Load("pp1.png");
    pr->p[1]=IMG_Load("pp2.png");
    pr->p[2]=IMG_Load("pp3.png");
    pr->p[3]=IMG_Load("pp4.png");
    pr->p[4]=IMG_Load("pp5.png");
    pr->p[5]=IMG_Load("pp6.png");

    pr->pp.x=30;
    pr->pp.y=480;
}

void afficherbg(SDL_Surface *screen,bg *b)
{
    SDL_BlitSurface(b->bk,NULL,screen,&b->pbk);
    SDL_Flip(screen);
}

void afficherpers(SDL_Surface *screen,perso *pr,int *frame)
{
    SDL_BlitSurface(pr->p[*frame],NULL,screen,&pr->pp);
    SDL_Flip(screen);
}

void animationd(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed)
{
    afficherbg(screen,b);
    if((*frame)>=3)
    {
        *frame=0;
    }
     afficherpers(screen,pr,frame);
     pr->pp.x+=(*speed);
     SDL_Delay(50);
}

void animationg(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed)
{
    afficherbg(screen,b);
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    afficherpers(screen,pr,frame);
    pr->pp.x-=(*speed);
    SDL_Delay(50);
}

void accelerationg(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed)
{
    afficherbg(screen,b);
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    afficherpers(screen,pr,frame);
    pr->pp.x-=((*speed)*3);
    SDL_Delay(20);
}

void accelerationd(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed)
{
    afficherbg(screen,b);
    if((*frame)>=3)
    {
        *frame=0;
    }
    afficherpers(screen,pr,frame);
    pr->pp.x+=((*speed)*3);
    SDL_Delay(20);
}

void saut(SDL_Surface *screen,bg *b,perso *pr,int *frame)
{

    int s=pr->pp.y;
    if((*frame)<3)
    {
    pr->pp.x+=10;
    pr->pp.y = -0.04*((pr->pp.x)*(pr->pp.x))+100;
    afficherbg(screen,b);
    afficherpers(screen,pr,frame);
    SDL_Delay(50);
    }else
    {
    pr->pp.x-=10;
    pr->pp.y=-0.04*((pr->pp.x)*(pr->pp.x))+100;
    afficherbg(screen,b);
    afficherpers(screen,pr,frame);
    SDL_Delay(50);
    }
    if(pr->pp.y<s)
    {
        pr->pp.y=500;
    }

}

