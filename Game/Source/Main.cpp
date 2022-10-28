#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		return -1;
	}

	SDL_Window* Window = SDL_CreateWindow("FruitAvoid2D", 100, 100, 1000, 800, SDL_WINDOW_SHOWN);

	SDL_Delay(3000);

	SDL_DestroyWindow(Window);
	Window = nullptr;

	SDL_Quit();
	return 0;
}