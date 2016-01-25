

#ifndef PLAYER_H_
#define PLAYER_H_


#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include <SDL.h>
#include <SDL_image.h>


#include "game.h"


#define BULLET_MAX 20
#define BULLET_SPEED 640
#define BULLET_FILENAME "resources/square.png"
#define BULLET_SIZE 2
#define BULLET_DELAY 0.5

#define PLAYER_WIDTH 16
#define PLAYER_HEIGHT 16
#define PI 3.1415


typedef struct {

  double angle;

  SDL_Rect dest;

  SDL_Texture *t;

} Bullet;


typedef struct {

  SDL_Rect dest;

  SDL_Texture *t;

  double angle;

  int speed, bulletIndex;

  Bullet **b;

} Player;


Player *CreatePlayer(SDL_Renderer *r, char *tName);


void UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime); 
// pass array to check collision against


void DestroyPlayer(Player *p);


#endif // PLAYER_H_
