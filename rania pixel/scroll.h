#ifndef SCROLL_H_INCLUDED
#define SCROLL_H_INCLUDED




typedef struct background background;
struct background{
SDL_Surface *fond;
SDL_Surface *masque; 
SDL_Rect fondpos;
SDL_Rect cadre;
};

void initialiserfond(background *back);
void chargerfond(background *back);
void blit_map(background *back,SDL_Surface *fenetre);
void scrolling(background *back,int a);
#endif
