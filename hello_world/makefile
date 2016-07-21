SDLFLAGS = `sdl2-config --cflags --libs`

main: main.c
	gcc $^ -o $@ $(SDLFLAGS)

clean:
	rm main
