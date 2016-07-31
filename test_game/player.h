#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "SDL2/SDL.h"

typedef enum {
	LEFT, RIGHT
} Direction;

typedef struct Player
{
	int x;
	int y;
	int velocity;
	int on_ground;
	int alive;
	int width;
	int height;
	SDL_Texture *texture;

} Player;

Player *Player_init(SDL_Renderer *renderer, int x, int y);
void Player_move(Player **player, Direction direction);
void Player_jump(Player **player);
void Player_draw(Player *player, SDL_Renderer *renderer);

#endif
