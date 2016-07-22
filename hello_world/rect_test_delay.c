#include <stdio.h>
#include "SDL2/SDL.h"

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

	// Setting color of background
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderClear(renderer);

	// Setting drawing color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Creating rectangle
	SDL_Rect rect = {200, 200, 150, 100};
	SDL_RenderFillRect(renderer, &rect);

	// Rendering is done, now we want to show what we've drawn
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	// Close and destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}
