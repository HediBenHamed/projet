
#include "menu.h"

int main (void)
{
SDL_Surface *ecran =NULL;
Mix_Music *musique;
	SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Cursed island", NULL);

if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           { 
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.mp3");
           Mix_PlayMusic(musique,-1);


menu(ecran);

Mix_FreeMusic(musique);
Mix_CloseAudio();

SDL_Quit();
    return EXIT_SUCCESS;
}




