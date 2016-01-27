

#include "asteroid.h"


#define ASTEROID_FILENAME "resources/asteroid.png"


Asteroid *CreateAsteroid(SDL_Renderer *r, double a, 
  int s, int startX, int startY)
{

  Asteroid *temp = malloc(sizeof(Asteroid *));

  temp->speed = s;

  temp->angle = a;

  temp->t = IMG_LoadTexture(r, ASTEROID_FILENAME);

  SDL_QueryTexture(temp->t, NULL, NULL, &temp->dest.w, &temp->dest.h);

  temp->dest.x = startX;

  temp->dest.y = startY;

  return temp;

}


int UpdateAsteroid(SDL_Renderer *r, Asteroid *a, double frameTime)
{

  a->dest.x += sin(a->angle * PI / 180) * (a->speed * frameTime);

  a->dest.y += cos(a->angle * PI / 180) * (a->speed * frameTime);

  SDL_RenderCopyEx(r, a->t, NULL, &a->dest, 
    a->angle, NULL, SDL_FLIP_NONE);

  if(a->dest.x < 0 || a->dest.x + a->dest.w > SCREEN_WIDTH ||
    a->dest.y < 0 || a->dest.y + a->dest.h > SCREEN_HEIGHT)
    return 1;

  return 0;

}


void DestroyAsteroid(Asteroid *a)
{

  SDL_DestroyTexture(a->t);

  free(a);

  a = 0;

}
