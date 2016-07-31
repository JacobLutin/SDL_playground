CFLAGS = -Wall -Werror -pedantic
SDLFLAGS = `sdl2-config --cflags --libs`

main: main.c functions.c player.c block.c map.c *.h
	gcc $(CFLAGS) $^ -o $@ $(SDLFLAGS)

clean:
	rm main
