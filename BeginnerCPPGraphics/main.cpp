#include <iostream>
#include <SDL.h>
#include <vector>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace game;

int main(int argc, char* args[]) {

	srand(time(nullptr));

	Screen screen;
	
	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
		return 1;
	}

	Swarm swarm;

	while (true) {
		//Update particles

		auto elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update();

		auto red = min((1 + sin(elapsed * 0.001)) * 128, 255.0);
		auto green = min((1 + sin(elapsed * 0.002)) * 128, 255.0);
		auto blue = min((1 + sin(elapsed * 0.003)) * 128, 255.0);
		
		//Draw particles
		for (auto &particle : swarm.getParticles())
		{
			int x = (particle.x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = particle.y * (Screen::SCREEN_WIDTH / 2) + (Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, (Uint8)red, (Uint8)green, (Uint8)blue);
		}

		//Draw the screen
		screen.update();

		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}