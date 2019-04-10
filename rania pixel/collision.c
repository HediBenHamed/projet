#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include "collision.h"

Uint32 getpixel(SDL_Surface *bg, int X, int Y)
		{
		    int bpp = bg->format->BytesPerPixel;
		    /* Here p is the address to the pixel we want to retrieve */
		    Uint8 *p = (Uint8 *)bg->pixels + Y * bg->pitch + X * bpp;
		 
		    switch(bpp) 
                    {
		    case 1:
			return *p;
			break;
		 
		    case 2:
			return *(Uint16 *)p;
			break;
		 
		    case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			    return p[0] << 16 | p[1] << 8 | p[2];
			else
			    return p[0] | p[1] << 8 | p[2] << 16;
			break;
		 
		    case 4:
			return *(Uint32 *)p;
			break;
		 
		    default:
			return 0;       /* shouldn't happen, but avoids warnings */
		    }
		 }

