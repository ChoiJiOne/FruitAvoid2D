#include "Window.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	CHECK((SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0), "failed to initialize SDL");

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

	SDL_Renderer* Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED);

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

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		SDL_RenderClear(Renderer);
		
		SDL_RenderPresent(Renderer);
	}

	SDL_DestroyRenderer(Renderer);
	Renderer = nullptr;

	SDL_Quit();
	return 0;
}