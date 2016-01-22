

#include "player.h"


Player *CreatePlayer(SDL_Renderer *r, char *tName)
{

  Player *temp = (Player *)malloc(sizeof(*temp));

  temp->t = IMG_LoadTexture(r, tName);

  SDL_QueryTexture(temp->t, NULL, NULL, &temp->dest.w, &temp->dest.h);

  if(temp->dest.w != PLAYER_WIDTH || temp->dest.h != PLAYER_HEIGHT)
    printf("Warning: Unexpected texture width.\n");

  // Start player in the centre of the screen
  temp->dest.x = (SCREEN_WIDTH / 2) - (temp->dest.w / 2);

  temp->dest.y = (SCREEN_HEIGHT / 2) - (temp->dest.h / 2);

  // Set up collision boxes
  
  temp->angle = 0.0;

  temp->speed = 0;

  return temp; 

}


void MovePlayer(Player *p)
{

  const Uint8* keys = SDL_GetKeyboardState(NULL);

  if(keys[SDL_SCANCODE_UP])
    p->speed = 320;

  if(!keys[SDL_SCANCODE_UP])
    p->speed = 0;

  if(keys[SDL_SCANCODE_LEFT]) {
  
    p->angle -= 3;

    if(p->angle <= 0)
      p->angle = 360; 

  }

  if(keys[SDL_SCANCODE_RIGHT]) {

    p->angle += 3;

    if(p->angle >= 360)
      p->angle = 0;

  }

}


void UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime)
{

  MovePlayer(p);

  p->dest.x += sin(p->angle * PI / 180) * (p->speed * frameTime);

  p->dest.y -= cos(p->angle * PI / 180) * (p->speed * frameTime);

  SDL_RenderCopyEx(r, p->t, NULL, &p->dest, p->angle, NULL, SDL_FLIP_NONE);

}


void DestroyPlayer(Player *p)
{

  SDL_DestroyTexture(p->t);

  free(p);

  p = 0;

}
