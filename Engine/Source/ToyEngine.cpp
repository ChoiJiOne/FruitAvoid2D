#include "ToyEngine.h"

void ToyEngine::Init()
{
	int32_t SDLFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS;
	int32_t ImageFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP | IMG_INIT_JXL | IMG_INIT_AVIF;
	int32_t SoundFlags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS;

	CHECK((SDL_Init(SDLFlags) == 0), "failed to initialize SDL");
	CHECK((IMG_Init(ImageFlags) & ImageFlags), "failed to initialize SDL_image");
	CHECK((TTF_Init() == 0), "failed to initialize SDL_ttf");
	CHECK((Mix_Init(SoundFlags) & SoundFlags), "failed to initialize SDL_mixer");
	CHECK((Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == 0), "failed to open audio");

	CommandLine::Parse();
	CrashReport::Init();
}

void ToyEngine::Quit()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
