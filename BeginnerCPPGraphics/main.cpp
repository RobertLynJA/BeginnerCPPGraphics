#include <iostream>
#include <SDL.h>
#include <vector>
#include "Screen.h"
using namespace std;
using namespace game;

int main(int argc, char* args[]) {

	Screen screen;
	
	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
		return 1;
	}

	while (true) {
		//Update particles
		//Draw particles
		//Check for messages/events

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}