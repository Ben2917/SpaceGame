

#include "timer.h"


#define STOPPED 0
#define STARTED 1


int state = STOPPED;


Uint32 start = 0, stop = 0;


void StartTimer()
{

  if(!state) {

    start = SDL_GetTicks();

    state = STARTED;

  }

}


void StopTimer()
{

  if(state) {

    stop = SDL_GetTicks() - start;

    state = STOPPED;

  }

}


double GetTime()
{

  return (double)(stop) / 1000;

}

