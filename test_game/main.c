#include <stdio.h>
#include "SDL2/SDL.h"
#include "functions.h"
#include "player.h"
#include "map.h"
#include "blocks.h"

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Test rect",
				 SDL_WINDOWPOS_UNDEFINED,
				 SDL_WINDOWPOS_UNDEFINED,
				 640, 480, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Player *player = Player_init(renderer, 100, 100);

	Map *map = Map_init(renderer)

	int running = 1;
	int key_event = 0;

	// game loop
	while (running == 1)
	{
		key_event = 0;

		// processing events
		process_events(&running, &key_event);

		process_key_event(key_event, &player);

		// render display
		init_render(renderer);

		Map_draw(map, renderer);

		Player_draw(player, renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}

	// Close and destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}
