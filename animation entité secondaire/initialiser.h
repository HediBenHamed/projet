#ifndef INITIALISER_H_INCLUDED
#define INITIALISER_H_INCLUDED
typedef struct bg bg;
struct bg{
SDL_Surface *bk;
SDL_Rect pbk;
};

typedef struct perso perso;
struct perso{
SDL_Surface *p[6];
SDL_Rect pp;
};

void initialiserbg(bg *b);
void initialiserps(perso *pr);
void afficherbg(SDL_Surface *screen,bg *b);
void afficherpers(SDL_Surface *screen,perso *pr,int *frame);
void animationd(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed);
void animationg(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed);
void accelerationg(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed);
void accelerationd(SDL_Surface *screen,bg *b,perso *pr,int *frame,int *speed);
void saut(SDL_Surface *screen,bg *b,perso *pr,int *frame);



#endif // INITIALISER_H_INCLUDED
