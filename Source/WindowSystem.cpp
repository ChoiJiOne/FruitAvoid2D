#include "WindowSystem.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
// @third party code - END

WindowSystem::WindowSystem(const std::string& InTitle, int32_t InPositionX, int32_t InPositionY, int32_t InWidth, int32_t InHeight, uint32_t InFlags)
{
	Window_ = SDL_CreateWindow(InTitle.c_str(), InPositionX, InPositionY, InWidth, InHeight, InFlags);
	CHECK((Window_ != nullptr), "failed to create window");
}

WindowSystem::~WindowSystem()
{
	if (Window_)
	{
		SDL_DestroyWindow(Window_);
		Window_ = nullptr;
	}
}

void WindowSystem::SetPosition(const int32_t& InXPosition, const int32_t& InYPosition)
{
	SDL_SetWindowPosition(Window_, InXPosition, InYPosition);
}

void WindowSystem::GetPosition(int32_t& OutXPosition, int32_t& OutYPosition)
{
	SDL_GetWindowPosition(Window_, &OutXPosition, &OutYPosition);
}

void WindowSystem::SetSize(const int32_t& InWidth, const int32_t& InHeight)
{
	SDL_SetWindowSize(Window_, InWidth, InHeight);
}

void WindowSystem::GetSize(int32_t& OutWidth, int32_t& OutHeight)
{
	SDL_GetWindowSize(Window_, &OutWidth, &OutHeight);
}

void WindowSystem::SetTitle(const std::string& InTitle)
{
	SDL_SetWindowTitle(Window_, InTitle.c_str());
}

void WindowSystem::GetTitle(std::string& OutTitle)
{
	OutTitle = SDL_GetWindowTitle(Window_);
}

void WindowSystem::Show()
{
	SDL_ShowWindow(Window_);
}

void WindowSystem::Hide()
{
	SDL_HideWindow(Window_);
}

float WindowSystem::GetAspectRatio()
{
	int32_t Width, Height;
	GetSize(Width, Height);

	return static_cast<float>(Width) / static_cast<float>(Height);
}