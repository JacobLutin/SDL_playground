#include "block.h"
#include "SDL2/SDL.h"

Block *Block_init(SDL_Renderer *renderer, char *texture_path, int x, int y)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	Block *block = malloc(sizeof(Block));

	block->x = x;
	block->y = y;

	surface = SDL_LoadBMP(texture_path);
	if (surface == NULL) 
	{
		puts("Texture error.");
		SDL_Quit();
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	block->texture = texture;

	return block;
}

void Block_draw(Block *block, SDL_Renderer *renderer)
{
	SDL_Rect block_rect = { block->x, block->y, BLOCK_WIDTH, BLOCK_HEIGHT };
	SDL_RenderCopy(renderer, block->texture, NULL, &block_rect);
}
