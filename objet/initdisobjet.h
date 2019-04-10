typedef struct
{

  SDL_Surface *image;
  SDL_Rect position;
}objet;
objet Initobjet(objet B,int x,int y,char nom[50]);
void  Afficherobjet(objet B,SDL_Surface *ecran);
