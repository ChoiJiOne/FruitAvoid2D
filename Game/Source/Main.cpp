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

	Graphics2D graphics(
		window,
		EGraphicsFlags::ACCELERATED | EGraphicsFlags::PRESENTVSYNC
	);

	Input input;

	SDL_Surface* BGSurface = IMG_Load("D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\Beach.jpg");
	SDL_Texture* BGTexture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), BGSurface);

	SDL_Surface* PlayerSurface = IMG_Load("D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\PlayerBlockBlue.png");
	SDL_Texture* PlayerTexture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), PlayerSurface);

	int32_t x = 500, y = 700, w = 50, h = 50;

	while (!input.Tick())
	{
		graphics.BeginFrame(Color::Black);

		SDL_Rect WindowRect = { 0, 0, 1000, 800 };
		SDL_RenderCopy(graphics.GetRenderer(), BGTexture, nullptr, &WindowRect);

		SDL_Rect PlayerRect = { x - w / 2, y - h / 2, w, h };
		SDL_RenderCopy(graphics.GetRenderer(), PlayerTexture, nullptr, &PlayerRect);

		graphics.EndFrame();
	}

	SDL_DestroyTexture(PlayerTexture);
	PlayerTexture = nullptr;

	SDL_FreeSurface(PlayerSurface);
	PlayerSurface = nullptr;

	SDL_DestroyTexture(BGTexture);
	BGTexture = nullptr;

	SDL_FreeSurface(BGSurface);
	BGSurface = nullptr;

	ToyEngine::Quit();
	return 0;
}