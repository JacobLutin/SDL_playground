#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{

	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("%s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		return 1;
	}

	SDL_Delay(3000);

	SDL_Quit();

	return 0;
}
