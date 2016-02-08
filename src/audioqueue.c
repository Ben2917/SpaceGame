

#include <stdio.h>
#include <stdlib.h>


#include <SDL_mixer.h>


// Background Music
// Mix_Music *m = NULL;

// Sound effects
// Mix_Chunk *scratch = NULL, *high = NULL, *med = NULL, *low = NULL;


// Create array of available sound effects


#define QUEUE_SIZE 80

Mix_Chunk **audioQueue;

int endIndex = 0;


int LoadSoundEffects()
{

  audioQueue = malloc(sizeof(Mix_Chunk *) * QUEUE_SIZE);

  /*
  m = Mix_LoadMUS("beat.wav");
  scratch = Mix_LoadWAV("scratch.wav");
  high = Mix_LoadWAV("high.wav");
  med = Mix_LoadWAV("medium.wav");
  low = Mix_LoadWAV("low.wav");

  if(m == NULL || scratch == NULL || high == NULL ||
    med == NULL || low == NULL)
    return -1;
  else*/

  // load all sound effects here

  return 0;

}

// change to integer code that will correspond to
// sound effect in table
void PushToQueue(Mix_Chunk *m)
{

  if(endIndex < QUEUE_SIZE) {

    audioQueue[endIndex] = malloc(sizeof(Mix_Chunk *));

    memcpy(audioQueue[endIndex], m, sizeof(Mix_Chunk));

    endIndex++;

  }
  else // return error code instead of printing error
    printf("Attempt to push clip to queue blocked.\n"
      "Too many items in queue. Consider allocating more space.\n");

}


void PlayNext()
{

  if(endIndex) { // Ensure there is a sound to play

    Mix_PlayChannel(-1, audioQueue[0], 0);

    free(audioQueue[0]);

    audioQueue[0] = 0;

    for(int i = 1; i <= endIndex; ++i) {

      audioQueue[i - 1] = audioQueue[i];

    }

    endIndex--;

  }

}


void DestroyAudio()
{

  /*
  Mix_FreeChunk(scratch);
  Mix_FreeChunk(high);
  Mix_FreeChunk(med);
  Mix_FreeChunk(low);

  Mix_FreeMusic(m);*/

  // loop to free all sound effects
  // free whatever is in the audio queue
  // free audio queue

}


