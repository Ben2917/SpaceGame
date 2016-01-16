

#include "player.h"


Player *CreatePlayer(char *tName)
{

  Player *temp = (Player *)malloc(sizeof(*temp));

  temp->t = IMG_LoadTexture(tName);

  SDL_QueryTexture(temp-t, SDL_PIXELFORMAT_RGBA8888, 
    SDL_TEXTUREACCESS_STATIC, &temp->dest.w, &temp->dest.h);

  if(temp->dest.w != PLAYER_WIDTH || temp->dest.h != PLAYER_HEIGHT)
    printf("Warning: Unexpected texture width.\n");

  temp->dest.x = 720 - (temp->dest.w / 2);

  temp->dest.y = 720 - (temp->dest.h / 2);

  

}
