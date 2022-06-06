#include "Screen.h"

namespace game {

	Screen::Screen()
	{
		m_buffer.resize(SCREEN_WIDTH * SCREEN_HEIGHT);
	}

	bool Screen::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (m_window == nullptr) {
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC);

		if (!m_renderer) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TextureAccess::SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (!m_texture) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		memset(&m_buffer[0], 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, &m_buffer[0], SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		{
			return;
		}

		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF; //Alpha 255

		m_buffer[(y * SCREEN_WIDTH) + x] = color;
	}

	bool Screen::processEvents()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EventType::SDL_QUIT) {
				return false;
			}
		}

		return true;
	}

	void Screen::close()
	{
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}