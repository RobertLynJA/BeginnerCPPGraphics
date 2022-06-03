#pragma once

#include <SDL.h>
#include <vector>

using namespace std;

namespace Game {

	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Texture* texture = nullptr;
		std::vector<Uint32> buffer;

	public:
		Screen();
		~Screen();
		bool init();
		bool processEvents();
		void close();
	};

}
