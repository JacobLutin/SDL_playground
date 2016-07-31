#include "map.h"
#include "SDL2/SDL.h"

Map *Map_init(SDL_Renderer *renderer)
{
	int i, j;
	int x, y;
	int count;

	Map *map = malloc(sizeof(Map));

	map->level = {
	{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};

	x = 0;
	y = 0;

	for (i = 0; i < LEVEL_HEIGHT; i++)
	{
		for (j = 0; j < LEVEL_WIDTH; j++)
		{
			switch (level[i][j])
			{
				case '-':
				{
					Block *brick = Block_init(renderer, "assets/brick.bmp", x, y);
					map->blocks[count] = brick;
					count++;
				}
			}
			x += BLOCK_WIDTH;
		}
		y += BLOCK_HEIGHT;
	}

	return map;
}

void Map_draw(Map *map, SDL_Renderer *renderer)
{
	Block *block;
	int i;

	i = 0;
	block = map->blocks[i];

	while (block)
	{
		Block_draw(block, renderer);
		i++;
		block = map->blocks[i];
	}
}