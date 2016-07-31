#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include "SDL2/SDL.h"
#include "player.h"

#define LEFT_BORDER 0
#define RIGHT_BORDER 1000

int init_render(SDL_Renderer *renderer);
int draw_rect(SDL_Renderer *renderer, SDL_Rect rect, int RGBa[]);
int process_events(int *running, int *key_event);
int process_key_event(int key_event, Player **player);

#endif
