

#ifndef PLAYER_H_
#define PLAYER_H_


#include <stdlib.h>
#include <stdio.h>


#include <SDL.h>
#include <SDL_image.h>


#define PLAYER_WIDTH 80
#define PLAYER_HEIGHT 120


typedef struct {

  // hitboxes and render dest
  SDL_Rect hbOne, hbTwo, hbThree, dest;

  SDL_Texture *t;

} Player;


Player *CreatePlayer(char *tName);


void UpdatePlayer(Player *p); // pass array to check collision against


#endif // PLAYER_H_
