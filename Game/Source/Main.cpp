#include "Window.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		return -1;
	}

	Window window(
		WindowConstructorParam{
			"FruitAvoid2D",
			100,
			100,
			1000,
			800,
			EWindowFlags::SHOWN | EWindowFlags::RESIZABLE
		}
	);

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

	SDL_Quit();
	return 0;
}