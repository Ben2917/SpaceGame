

#ifndef PLAYER_H_
#define PLAYER_H_


#include <stdlib.h>
#include <math.h>


#include <SDL.h>
#include <SDL_image.h>


#include "game.h"


typedef struct {

  double angle;

  SDL_Rect dest;

  SDL_Texture *t;

} Bullet;


typedef struct {

  SDL_Rect dest;

  SDL_Texture *t;

  double angle, prevBullet;

  int speed, bulletIndex;

  Bullet **b;

} Player;


Player *CreatePlayer(SDL_Renderer *r, char *tName);


void UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime); 
// pass array to check collision against


void DestroyPlayer(Player *p);


#endif // PLAYER_H_
