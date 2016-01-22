

#ifndef PLAYER_H_
#define PLAYER_H_


#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include <SDL.h>
#include <SDL_image.h>


#include "game.h"


#define PLAYER_WIDTH 80
#define PLAYER_HEIGHT 120
#define PI 3.1415


typedef struct {

  // hitboxes and render dest
  SDL_Rect hbOne, hbTwo, hbThree, dest;

  SDL_Texture *t;

  double angle;

  int speed;

} Player;


Player *CreatePlayer(SDL_Renderer *r, char *tName);


void UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime); 
// pass array to check collision against


void DestroyPlayer(Player *p);


#endif // PLAYER_H_
