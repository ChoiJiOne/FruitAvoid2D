#include <iostream>
#include <unordered_map>
#include <ctime>

#include "CommandLine.h"
#include "CrashReport.h"
#include "Window.h"
#include "Text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

void test()
{
	std::cout << "call test function" << std::endl;
	int a = 10;
	throw std::exception("");
}

int main(int argc, char* argv[])
{
	CommandLine::Parse();
	CrashReport::Init();

	std::wcout << CommandLine::GetValue(L"-Dump") << std::endl;
	std::wcout << CommandLine::GetValue(L"-Content") << std::endl;

	test();

	return 0;
}