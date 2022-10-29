#include "Graphics2D.h"
#include "Window.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Graphics2D::Graphics2D(Window& InWindow, const EGraphicsFlags& InFlags)
{
	Renderer_ = SDL_CreateRenderer(InWindow.GetWindow(), -1, static_cast<uint32_t>(InFlags));
	CHECK((Renderer_ != nullptr), "failed to create renderer");
}

Graphics2D::~Graphics2D()
{
	if (Renderer_)
	{
		SDL_DestroyRenderer(Renderer_);
		Renderer_ = nullptr;
	}
}

void Graphics2D::BeginFrame(const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderClear(Renderer_) == 0), SDL_GetError());
}

void Graphics2D::EndFrame()
{
	SDL_RenderPresent(Renderer_);
}

void Graphics2D::SetDrawColor(const LinearColor& InColor)
{
	uint8_t R = 0, G = 0, B = 0, A = 0;
	Color::ToR8G8B8A8(InColor, R, G, B, A);
	SetDrawColor(R, G, B, A);
}

void Graphics2D::SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha)
{
	CHECK((SDL_SetRenderDrawColor(Renderer_, InRed, InGreen, InBlue, InAlpha) == 0), SDL_GetError());
}
