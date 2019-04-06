#include "player.h"

int collision(pers *p,SDL_Rect position_ennemi)
{
if (position_ennemi.x<(p->position_joueur.x+p->position_joueur.w))
    return 0;// collision_droite est vrai


else if  ((position_ennemi.x+position_ennemi.w)>p->position_joueur.x)
     return 0;// collision_gauche  vrai

 
else if  (position_ennemi.y<(position_joueur.y+p->position_joueur.h))
    return 0;// collision_bas  vrai


else if ((position_ennemi.y+position_ennemi.h)>p->position_joueur.y)
    return 0;// collision_bas  vrai

return 1;
}



	



