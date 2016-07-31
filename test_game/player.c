#include "player.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

Player *Player_init(SDL_Renderer *renderer, int x, int y)
{
	Player *player = malloc(sizeof(Player));

	SDL_Texture *texture;
	SDL_Surface *surface;

	player->x = x;
	player->y = y;
	player->velocity = 10;
	player->on_ground = 1;
	player->alive = 1;
	player->width = 40;
	player->height = 40;
	

	surface = SDL_LoadBMP("assets/test.bmp");

	if (surface == NULL)
	{
		printf("Couldn't find image.\n");
		SDL_Quit();
		exit(1);
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	player->texture = texture; 

	return player;
}
void Player_move(Player **player, Direction direction)
{
	int velocity = (*player)->velocity;
	if (direction == LEFT && (*player)->x > LEFT_BORDER)
	{
		(*player)->x -= velocity;
	}

	if (direction == RIGHT && (*player)->x < RIGHT_BORDER)
	{
		(*player)->x += velocity;
	}

}

void Player_jump(Player **player)
{
	if ((*player)->on_ground)
	{
		printf("jump pressed");
	}
}

void Player_draw(Player *player, SDL_Renderer *renderer)
{
	SDL_Rect player_rect = { player->x, player->y, player->width, player->height };
	SDL_RenderCopy(renderer, player->texture, NULL, &player_rect);
}
