#include <iostream>
#include <SDL.h>
#include <vector>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace game;

int main(int argc, char* args[]) {

	srand(time(nullptr));

	Screen screen;
	
	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
		return 1;
	}

	while (true) {
		//Update particles

		auto elapsed = SDL_GetTicks();
		auto red = min((1 + sin(elapsed * 0.001)) * 128, 255.0);
		auto green = min((1 + sin(elapsed * 0.002)) * 128, 255.0);
		auto blue = min((1 + sin(elapsed * 0.003)) * 128, 255.0);

		//Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, (Uint8)red, (Uint8)green, (Uint8)blue);
			}
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