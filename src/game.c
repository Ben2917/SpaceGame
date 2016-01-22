

#include "game.h"


int EventLoop()
{

  SDL_Event e;

  while(SDL_PollEvent(&e)) {

    if(e.type == SDL_KEYDOWN) {
     
      if(e.key.keysym.sym == SDLK_ESCAPE)
        return 1;

    }
    else if(e.type == SDL_QUIT)
      return 1;

  }

  return 0;

}


int Init(SDL_Window **w, SDL_Renderer **r)
{

  *w = SDL_CreateWindow("Asteroids",
    0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if(!*w) { 
    
    *r = NULL; 
    return -1;

  }

  *r = SDL_CreateRenderer(*w, -1, 
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if(!*r)
    return -1;

  return 0;

}


void Destroy(SDL_Window **w, SDL_Renderer **r)
{

  SDL_DestroyWindow(*w);

  SDL_DestroyRenderer(*r);

}


void GameLoop()
{

  SDL_Window *w; SDL_Renderer *r;

  if(Init(&w, &r) != 0)
    return;

  Player *p = CreatePlayer(r, "resources/player.png");

  double time = 0.0;

  while(!EventLoop()) {

    StartTimer();

    SDL_Delay(17);

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
 
    SDL_RenderClear(r);

    UpdatePlayer(r, p, time);

    SDL_RenderPresent(r);
  
    StopTimer();

    time = GetTime();

    // printf("%lf\n", time);

  }

  Destroy(&w, &r);

  DestroyPlayer(p);

}
