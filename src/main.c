

#include <time.h>
#include <stdlib.h>


#include"game.h"


int main()
{

  srand(time(NULL));

  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return -1;

  GameLoop();  

  return 0;

}
