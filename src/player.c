

#include "player.h"


#define BULLET_MAX 10
#define BULLET_SPEED 640
#define BULLET_FILENAME "resources/square.png"
#define BULLET_SIZE 2
#define BULLET_DELAY 0.25
#define PLAYER_SPEED 320


Bullet *CreateBullet(SDL_Renderer *r, int x, int y, double a)
{

  Bullet *temp = malloc(sizeof(*temp));

  temp->angle = a;

  temp->dest.x = x; 
  temp->dest.y = y; 
  temp->dest.w = BULLET_SIZE; 
  temp->dest.h = BULLET_SIZE;

  temp->t = IMG_LoadTexture(r, BULLET_FILENAME);

  return temp;

}


int UpdateBullet(SDL_Renderer *r, Bullet *b, double frameTime)
{

  b->dest.x += sin(b->angle * PI / 180) * (BULLET_SPEED * frameTime);

  b->dest.y -= cos(b->angle * PI / 180) * (BULLET_SPEED * frameTime);

  SDL_RenderCopyEx(r, b->t, NULL, &b->dest, b->angle, NULL, SDL_FLIP_NONE);

  if(b->dest.x > SCREEN_WIDTH || b->dest.x < 0 ||
    b->dest.y > SCREEN_HEIGHT || b->dest.y < 0)
    return 1;
  
  return 0;

}


void ShiftBullets(Bullet **b, int i, int size)
{

  for(int x = i; x < size; ++x)
    b[x] = b[x + 1];

}


void DestroyBullet(Bullet *b)
{

  SDL_DestroyTexture(b->t);

  free(b);

  b = 0;

}


Player *CreatePlayer(SDL_Renderer *r, char *tName)
{

  Player *temp = malloc(sizeof(*temp));

  temp->b = malloc(sizeof(Bullet *) * BULLET_MAX);

  temp->t = IMG_LoadTexture(r, tName);

  SDL_QueryTexture(temp->t, NULL, NULL, &temp->dest.w, &temp->dest.h);

  temp->dest.x = (SCREEN_WIDTH / 2) - (temp->dest.w / 2);

  temp->dest.y = (SCREEN_HEIGHT / 2) - (temp->dest.h / 2);
 
  temp->angle = 0.0;

  temp->speed = temp->bulletIndex = 0;

  return temp; 

}


void WrapAround(Player *p)
{

  if(p->dest.x + p->dest.w > SCREEN_WIDTH)
    p->dest.x = 0;
  else if(p->dest.x <= 0)
    p->dest.x = SCREEN_WIDTH - p->dest.w;
  else if (p->dest.y + p->dest.h > SCREEN_HEIGHT)
    p->dest.y = 0;
  else if (p->dest.y <= 0)
    p->dest.y = SCREEN_HEIGHT - p->dest.h;

}


void MovePlayer(SDL_Renderer *r, Player *p)
{

  const Uint8* keys = SDL_GetKeyboardState(NULL);

  if(keys[SDL_SCANCODE_UP])
    p->speed = PLAYER_SPEED;

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

  if(keys[SDL_SCANCODE_SPACE] && p->bulletIndex < BULLET_MAX
    && p->prevBullet > BULLET_DELAY) {
    
    p->b[p->bulletIndex++] = CreateBullet(r, p->dest.x + (p->dest.w / 2), 
      p->dest.y + (p->dest.h / 2), p->angle);

    p->prevBullet = 0.0;

  }

}


int UpdatePlayer(SDL_Renderer *r, Player *p, double frameTime)//, Asteroid *ast)
{

  MovePlayer(r, p);

  p->prevBullet += frameTime;

  p->dest.x += sin(p->angle * PI / 180) * (p->speed * frameTime);

  p->dest.y -= cos(p->angle * PI / 180) * (p->speed * frameTime);

  WrapAround(p);

  for(int i = 0; i < p->bulletIndex; ++i) {
  
    if(UpdateBullet(r, p->b[i], frameTime)) {

      DestroyBullet(p->b[i]);
     
      ShiftBullets(p->b, i, p->bulletIndex);

      p->bulletIndex--;
 
    }

  }

  SDL_RenderCopyEx(r, p->t, NULL, &p->dest, p->angle, NULL, SDL_FLIP_NONE);

  return 0;

}


void DestroyPlayer(Player *p)
{

  SDL_DestroyTexture(p->t);

  // printf("Freed texture.\n");

  // Destroy any bullets remaining on the screen
  for(int i = 0; i < p->bulletIndex; ++i)
    DestroyBullet(p->b[i]);

  // printf("Freed bullets.\n");

  free(p->b);

  // printf("Freed total array.\n");

  p->b = 0;

  free(p);

  p = 0;

  // printf("Freed player.\n");

}
