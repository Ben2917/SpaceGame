

#include "game.h"


// Global variables

SDL_Window *w;
SDL_Renderer *r;
Player *p;



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

  *r = SDL_CreateRenderer(*w, -1, SDL_RENDERER_ACCELERATED 
    | SDL_RENDERER_PRESENTVSYNC);

  if(!*r) {

    SDL_DestroyWindow(*w);
    return -1;

  }

  return 0;

}


void Destroy(SDL_Window *w, SDL_Renderer *r)
{

  SDL_DestroyWindow(w);

  // printf("Freed Window.\n");

  SDL_DestroyRenderer(r);

  // printf("Freed Renderer.\n");

}


void GameLoop()
{

  // SDL_Window *w; SDL_Renderer *r;

  if(Init(&w, &r) != 0) 
    return;

  //Player *p 
  p = CreatePlayer(r, "resources/player.png");

  if(p == NULL) 
    return;

  double time = 0.0;

  while(!EventLoop()) {

    StartTimer();

    SDL_Delay(17);

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);

    SDL_RenderClear(r);

    if (UpdatePlayer(r, p, time))
      break;

    SDL_RenderPresent(r);
  
    StopTimer();

    time = GetTime();

  }

  DestroyPlayer(p);

  Destroy(w, r);

}
