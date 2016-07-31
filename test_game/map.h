#ifndef __MAP_H__
#define __MAP_H__

#define LEVEL_WIDTH 15
#define LEVEL_HEIGHT 10

#include "block.h"

typedef struct Map
{
	char level[LEVEL_WIDTH][LEVEL_HEIGHT];
	Block *blocks[LEVEL_WIDTH*LEVEL_HEIGHT];

} Map;

Map *Map_init(SDL_Renderer *renderer);
void Map_draw(Map *map, SDL_Renderer *renderer);

#endif
