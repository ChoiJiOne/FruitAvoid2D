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

void Graphics2D::DrawPoint(const Vec2i& InPosition, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawPoint(Renderer_, InPosition.x, InPosition.y) == 0), SDL_GetError());
}

void Graphics2D::DrawLine(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);
	CHECK((SDL_RenderDrawLine(Renderer_, InPosition0.x, InPosition0.y, InPosition1.x, InPosition1.y) == 0), SDL_GetError());
}

void Graphics2D::DrawRect(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPosition0.x, InPosition1.x),
		std::min(InPosition0.y, InPosition1.y),
		std::abs(InPosition1.x - InPosition0.x),
		std::abs(InPosition1.y - InPosition0.y)
	};

	CHECK((SDL_RenderDrawRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Graphics2D::DrawRect(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawRect(Position0, Position1, InColor);
}

void Graphics2D::DrawFillRect(const Vec2i& InPosition0, const Vec2i& InPosition1, const LinearColor& InColor)
{
	SetDrawColor(InColor);

	SDL_Rect Rect = {
		std::min(InPosition0.x, InPosition1.x),
		std::min(InPosition0.y, InPosition1.y),
		std::abs(InPosition1.x - InPosition0.x),
		std::abs(InPosition1.y - InPosition0.y)
	};

	CHECK((SDL_RenderFillRect(Renderer_, &Rect) == 0), SDL_GetError());
}

void Graphics2D::DrawFillRect(const Vec2i& InCenterPosition, int32_t InWidth, int32_t InHeight, const LinearColor& InColor)
{
	Vec2i DeltaPosition(
		static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f),
		static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f)
	);

	Vec2i Position0 = InCenterPosition - DeltaPosition;
	Vec2i Position1 = InCenterPosition + DeltaPosition;

	DrawFillRect(Position0, Position1, InColor);
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
