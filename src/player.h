

#ifndef PLAYER_H_
#define PLAYER_H_


#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include <SDL.h>
#include <SDL_image.h>


#include "asteroid.h"
#include "constants.h"


typedef struct {

  double angle;

  SDL_Rect dest;

  SDL_Texture *t;

} Bullet;


// Player objects hold the handle to their bullets
// Extensible for multiplayer support
typedef struct {

  SDL_Rect dest;

  SDL_Texture *t;

  double angle, prevBullet;

  int speed, bulletIndex;

  Bullet **b;

} Player;


Player *CreatePlayer(SDL_Renderer *r, char *tName);


int UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime);//, Asteroid *ast); 


void DestroyPlayer(Player *p);


#endif // PLAYER_H_
