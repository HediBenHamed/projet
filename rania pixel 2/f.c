#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include "collision.h"
#include "f.h"
#include "scroll.h"
void InitSprite(perso* perso)
{
    perso->x = 50;
    perso->y = 0;
    perso->status = sol;
    perso->vx = perso->vy = 0;
    perso->aux =perso->x;
    

}
//affichage
void affichage(perso* perso,SDL_Surface* screen)
{
    SDL_Rect R;
    if (perso->x <20)
  {
    perso->x=20;
    R.x = perso->x;
  }
   else if (perso->x+40 >= 8000)
  {
    perso->x = 8000 -40- 1;
    R.x = perso->x;
  }
  else if(perso->x>=512)
  {
     R.x = 512;
  }
  else
  {
    perso->x= perso->x;
    R.x = perso->x;  
  }
      
    R.y = perso->y;
    R.w = 20;
    R.h = 40;
    
   SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));
            

    SDL_Flip(screen);
}




void evolution(perso* perso, int quitter,int jump,int left,int right,background *back)
{
    int speed =7;
    int airlateralspeedfacteur = 3;
    int maxhspeed = 3;
    int impulsion = 6;
    int gravite = 1;
    int facteur = 3;
    int y;
    Uint8 r, g, bl,r1,g1,bl1,r2,g2,bl2;
    int X,Y;
    int x1,x2,y1,y2;
int a;

// controle lateral
    perso->status=jumped;

    x1= perso->aux ;
    x2=perso->aux +20;
    y1=perso->y;
    y2=perso->y+40;



  
//DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/DOWN/
  SDL_GetRGB(getpixel(back->masque, x1,y2), back->masque->format, &r, &g, &bl);
    if (((r + g + bl)==0))
    {

            
         perso->y = perso->y-perso->vy;
        perso->status = sol;
       
        if (left==1) // (*1)
            perso->vx = perso->vx - speed;

        if (right==1)
            perso->vx= perso->vx + speed;

        if ((left == 0) && (right == 0) )// (*3)
            perso->vx=0;
     

    if (jump == 1)
    {
        perso->vy = -impulsion;
    perso->status = jumped;
        y=perso->y;

    }    

    }
    else
    {   
            if (left==1) // (*1)
        perso->vx = perso->vx - speed;

    if (right==1)
        perso->vx= perso->vx + speed;

    if ((perso->status == sol) && (left == 0) && (right == 0) )// (*3)
        perso->vx=0;
// limite vitesse

// saut

    if ((jump == 1)&& (perso->status == sol))
    {
        perso->vy = -impulsion;
    perso->status = jumped;
        y=perso->y;

    }    
    
    

    if (perso->status == jumped && (jump == 1))
    gravite= gravite/facteur;
    

    
   
    //Collision sol
    

        perso->vy += gravite;
        //if (perso->vx>0)
          //  perso->vx = 0;
         
   
    }







//LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/LEFT/
     


     SDL_GetRGB(getpixel(back->masque, x1,y2-20), back->masque->format, &r, &g, &bl);
     if ((r + g + bl)==0)
    {
        perso->x = perso->x- perso->vx;
        if (left==1) // (*1)
            perso->vx =0;

        if (right==1)
            perso->vx= perso->vx + speed;

        if ((left == 0) && (right == 0)&&  (perso->status==sol) )// (*3)
            perso->vx=0;
    

        if ((jump == 1)&& (perso->status == sol))
             {
                 perso->vy = -impulsion;
                 perso->status = jumped;
                 y=perso->y;

             }   

        if (perso->status == jumped && (jump == 1))
            gravite= gravite/facteur;
    
         perso->vy += gravite;
    }






//jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/jump/
    


     SDL_GetRGB(getpixel(back->masque, x1+10,y1), back->masque->format, &r, &g, &bl);
       if ((r + g + bl)==0)
    {
        perso->y = perso->y- perso->vy;
        if (left==1) // (*1)
            perso->vx= perso->vx -speed;

        if (right==1)
            perso->vx= perso->vx + speed;

        if ((left == 0) && (right == 0) && (perso->status==sol))// (*3)
            perso->vx=0;

        

        if ((jump == 1)&& (perso->status == sol))
             {
                 perso->vy =0;
                 perso->status = jumped;
                 y=perso->y;

             }   

        if (perso->status == jumped && (jump == 1))
            gravite= gravite/facteur;
    
         perso->vy += gravite;
   
    }




      //RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/RIGHT/
     


      SDL_GetRGB(getpixel(back->masque, x2,y1+20), back->masque->format, &r, &g, &bl);
     if ((r + g + bl)==0)
    {
        perso->x = perso->x- perso->vx;
        if (left==1) // (*1)
            
            perso->vx= perso->vx - speed;
        if (right==1)
            perso->vx =0;

        if ((left == 0) && (right == 0)&&  (perso->status==sol) )// (*3)
            perso->vx=0;
        
        if ((jump == 1)&& (perso->status == sol))
             {
                 perso->vy = -impulsion;
                 perso->status = jumped;
                 y=perso->y;

             }   

        if (perso->status == jumped && (jump == 1))
            gravite= gravite/facteur;
    
         perso->vy += gravite;
    }

    if (perso->vx>=speed) // (*4)
            perso->vx =speed;


    if (perso->vx<=-speed) // (*4)
            perso->vx =-speed;

          if(perso->vy>gravite*10)
            perso->vy=gravite*10;
 

	a=perso->x;
	scrolling(back,a);


     perso->y = perso->y + perso->vy;
     perso->x = perso->x + perso->vx;
     perso->aux=perso->x+perso->vx;

     if(perso->y>=768)
     {
      
      InitSprite(perso);
      if(perso->life>0)
      perso->life--;


     }
// application du vecteur à la position.
  
}


