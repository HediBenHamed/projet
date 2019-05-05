#include <SDL/SDL.h>
#define largeur 1200
#define hauteur 600
typedef struct joueur joueur;

struct joueur{
SDL_Surface *p[6];
SDL_Rect pp;
};

typedef struct background background;

struct background{
SDL_Surface *background;
SDL_Rect pb;
};

void initialiser_joueur1(joueur *j);
void initialiser_joueur2(joueur *j);

void initialiser_background1(background *b);
void initialiser_background2(background *b);




