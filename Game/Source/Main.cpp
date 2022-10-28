#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	if (!SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		return -1;
	}

	SDL_Quit();
	return 0;
}