#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *bitmapTexture;
	SDL_Surface *bitmapSurface;

	int posX = 100, posY = 100;
	int width = 640, height = 480;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);

	if (window == NULL)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return 1;
	}

	bitmapSurface = SDL_LoadBMP("test.bmp");
	bitmapTexture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
	SDL_FreeSurface(bitmapSurface);

	while (1)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bitmapTexture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(bitmapTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
