CFLAGS = -Wall -Werror -pedantic
SDLFLAGS = `sdl2-config --cflags --libs`

main: main.c
	gcc $(CFLAGS) $^ -o $@ $(SDLFLAGS)

clean:
	rm main
