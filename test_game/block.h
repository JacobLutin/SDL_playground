#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "SDL2/SDL.h"

#define BLOCK_WIDTH 40
#define BLOCK_HEIGHT 40

typedef struct Block
{
	int x;
	int y;

	SDL_Texture *texture;
} Block;

Block *Block_init(SDL_Renderer *renderer, char *texture_path, int x, int y);
void Block_draw(Block *block, SDL_Renderer *renderer);

#endif