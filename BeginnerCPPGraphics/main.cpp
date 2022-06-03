#include <iostream>
#include <SDL.h>
#include <vector>
using namespace std;

int main(int argc, char* args[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed." << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 2;
	}

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TextureAccess::SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!texture) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 2;
	}

	std::vector<Uint32> buffer(SCREEN_WIDTH * SCREEN_HEIGHT);

	memset(&buffer[0], 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x00FF00FF;
	}

	SDL_UpdateTexture(texture, NULL, &buffer[0], SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		//Update particles
		//Draw particles
		//Check for messages/events

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EventType::SDL_QUIT) {
				quit = true;
			}
		}
	}

	if (window == nullptr) {
		SDL_Quit();
		return 2;
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}