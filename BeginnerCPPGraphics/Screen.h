#pragma once

#include <SDL.h>
#include <vector>

using namespace std;

namespace game {

	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
		

	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
		SDL_Texture* m_texture = nullptr;
		std::vector<Uint32> m_buffer;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	};

}
