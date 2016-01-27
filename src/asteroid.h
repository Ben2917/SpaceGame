

#ifndef ASTEROID_H_
#define ASTEROID_H_


#include <SDL.h>
#include <SDL_image.h>


#include <stdlib.h>
#include <math.h>


#include "game.h"


typedef struct {

  int speed;

  double angle;

  SDL_Texture *t;

  SDL_Rect dest;

} Asteroid;


Asteroid *CreateAsteroid(SDL_Renderer *r, double a, 
  int s, int startX, int startY);


int UpdateAsteroid(SDL_Renderer *r, Asteroid *a, double frameTime);


void DestroyAsteroid(Asteroid *a);


#endif // ASTEROID_H_


