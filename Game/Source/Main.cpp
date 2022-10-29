#include <iostream>
#include <unordered_map>

#include "CommandLine.h"
#include "Window.h"
#include "Text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int main(int argc, char* argv[])
{
	CommandLine::Parse();
	std::wcout << CommandLine::GetValue(L"-Dump") << std::endl;
	std::wcout << CommandLine::GetValue(L"-Content") << std::endl;

	return 0;
}