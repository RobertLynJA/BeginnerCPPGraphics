#include <iostream>
#include <SDL.h>
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

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}