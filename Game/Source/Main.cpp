#include "ToyEngine.h"

int main(int argc, char* argv[])
{
	ToyEngine::Init();

	Window window(
		WindowConstructorParam{
			"FruitAvoid2D",
			100,
			100,
			1000,
			800,
			EWindowFlags::SHOWN
		}
	);

	SDL_Renderer* Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* BGSurface = IMG_Load("D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\Beach.jpg");
	SDL_Texture* BGTexture = SDL_CreateTextureFromSurface(Renderer, BGSurface);

	SDL_Surface* PlayerSurface = IMG_Load("D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\PlayerBlockBlue.png");
	SDL_Texture* PlayerTexture = SDL_CreateTextureFromSurface(Renderer, PlayerSurface);

	bool bIsDone = false;
	SDL_Event Event;

	int32_t x = 500, y = 700, w = 50, h = 50;

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

		SDL_Rect WindowRect = { 0, 0, 1000, 800 };
		SDL_RenderCopy(Renderer, BGTexture, nullptr, &WindowRect);

		SDL_Rect PlayerRect = { x - w / 2, y - h / 2, w, h };
		SDL_RenderCopy(Renderer, PlayerTexture, nullptr, &PlayerRect);

		SDL_RenderPresent(Renderer);
	}

	SDL_DestroyTexture(PlayerTexture);
	PlayerTexture = nullptr;

	SDL_FreeSurface(PlayerSurface);
	PlayerSurface = nullptr;

	SDL_DestroyTexture(BGTexture);
	BGTexture = nullptr;

	SDL_FreeSurface(BGSurface);
	BGSurface = nullptr;

	SDL_DestroyRenderer(Renderer);
	Renderer = nullptr;

	ToyEngine::Quit();
	return 0;
}