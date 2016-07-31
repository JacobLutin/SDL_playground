#include "functions.h"
#include "player.h"
#include <stdio.h>

int draw_rect(SDL_Renderer *renderer, SDL_Rect rect, int RGBa[])
{
	SDL_SetRenderDrawColor(renderer, RGBa[0], RGBa[1], RGBa[2], RGBa[3]);
	SDL_RenderFillRect(renderer, &rect);

	return 0;
}

int init_render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	// SDL_Rect rect_new = {300, 300, 400, 200};
	// int RGBa[] = {255, 255, 0, 255};
	// draw_rect(renderer, rect_new, RGBa);

	

	return 0;
}

int process_events(int *running, int *key_event)
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				*running = 0;
				break;
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						*running = 0;
						break;
					case SDLK_a:
						printf("SDLK_a= %d\n", SDLK_a);
						*key_event = 1;
						break;
					case SDLK_d:
						printf("SDLK_d = %d\n", SDLK_d);
						*key_event = 2;
						break;
					case SDLK_SPACE:
						printf("SDLK_d = %d\n", SDLK_d);
						*key_event = 3;
						break;
				}
				break;
			}
		}

	}

	return 0;
}

int process_key_event(int key_event, Player **player)
{
	switch(key_event)
	{
		case 1:
		{
			Player_move(player, LEFT);
			printf("Player x pos = %d\n", (*player)->x);
			break;
		}
		case 2:
		{
			Player_move(player, RIGHT);
			printf("Player x pos = %d\n", (*player)->x);
			break;
		}
		case 3:
		{
			Player_jump(player);
			break;
		}
	}

	return 0;
}
