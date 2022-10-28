#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		return -1;
	}

	SDL_Window* Window = SDL_CreateWindow("FruitAvoid2D", 100, 100, 1000, 800, SDL_WINDOW_SHOWN);

	bool bIsDone = false;
	SDL_Event Event;

	while (!bIsDone)
	{
		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_QUIT)
			{
				bIsDone = true;
			}
		}
	}

	SDL_DestroyWindow(Window);
	Window = nullptr;

	SDL_Quit();
	return 0;
}