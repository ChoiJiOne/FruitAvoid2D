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

	Texture BGTexture(graphics, "D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\Beach.jpg");
	Texture PlayerTexture(graphics, "D:\\work\\FruitAvoid2D\\Game\\Content\\texture\\PlayerBlockBlue.png");

	int32_t x = 500, y = 700, w = 50, h = 50;

	while (!input.Tick())
	{
		graphics.BeginFrame(Color::Black);

		SDL_Rect WindowRect = { 0, 0, 1000, 800 };
		SDL_RenderCopy(graphics.GetRenderer(), BGTexture.GetTexture(), nullptr, &WindowRect);

		SDL_Rect PlayerRect = { x - w / 2, y - h / 2, w, h };
		SDL_RenderCopy(graphics.GetRenderer(), PlayerTexture.GetTexture(), nullptr, &PlayerRect);

		graphics.DrawLine(Vec2i(100, 100), Vec2i(900, 700), Color::Black);
		graphics.DrawRect(Vec2i(100, 100), Vec2i(900, 700), Color::Black);
		graphics.DrawFillRect(Vec2i(500, 400), 200, 200, Color::Cyan);

		graphics.EndFrame();
	}

	ToyEngine::Quit();
	return 0;
}