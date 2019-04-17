#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <time.h>
int nombre(void)
{
    srand(time(NULL));
    int x=rand()%3 +1;
    return x;
}
 
