#include "ToyEngine.h"

void ToyEngine::Init()
{
	CommandLineUtils::Init();
	DebugUtils::Init();

	int32_t SDLFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS;

	CHECK((SDL_Init(SDLFlags) == 0), "failed to initialize SDL");

#if defined(SHIPPING)
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
}

void ToyEngine::Quit()
{
	SDL_Quit();
}
