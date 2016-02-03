

#include <time.h>
#include <stdlib.h>


#include"game.h"
// I so turnt

int main()
{

  srand(time(NULL));

  if(SDL_Init(SDL_INIT_VIDEO) != 0)
    return -1;

  GameLoop();  

  atexit(SDL_Quit);

  return 0;

}
