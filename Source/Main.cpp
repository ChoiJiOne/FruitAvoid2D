#include "Player.h"
#include "Fruit.h"
#include "GameEngine.h"

void LoadResource()
{
	ResourceSystem& Resource = GameEngine::GetResourceSystem();

	std::string ResourcePath = GameEngine::GetRootDirectory() + "\\Resource\\";
	std::vector<std::string> PngTextureNames = {
		"Banana",
		"Coconut",
		"Orange",
		"PlayerBlockOrange",
		"Plum",
		"StarFruit",
		"GreenApple",
		"Peach",
		"PlayerBlockPurple",
		"Raspberry",
		"Strawberry",
		"BlackBerryDark",
		"GreenGrape",
		"Pear",
		"PlayerBlockRed",
		"RedApple",
		"WaterMelon",
		"BlackBerryLight",
		"Lemon",
		"PlayerBlockBlue",
		"PlayerBlockSky",
		"RedCherry",
		"BlackCherry",
		"Lime",
		"PlayerBlockGreen",
		"PlayerBlockYellow",
		"RedGrape"
	};

	for (const auto& PngTextureName : PngTextureNames)
	{
		Resource.LoadTextureFromFile(
			Text::GetHash(PngTextureName), 
			Text::Format("%stexture\\%s.png", ResourcePath.c_str(), PngTextureName.c_str())
		);
	}

	std::vector<std::string> JpgTextureNames = {
		"Beach",
	};

	for (const auto& JpgTextureName : JpgTextureNames)
	{
		Resource.LoadTextureFromFile(
			Text::GetHash(JpgTextureName),
			Text::Format("%stexture\\%s.jpg", ResourcePath.c_str(), JpgTextureName.c_str())
		);
	}

	Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);
}

Player GamePlayer(Vec2i(500, 650), 200.0f, 50, 50, Player::EColor::Blue);
Timer GameTimer;
std::list<Fruit> GameFruits;

int main(int argc, char* argv[])
{
    GameEngine::Init();

    WindowSystem& Window = GameEngine::CreateWindowSystem("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    RenderSystem& Renderer = GameEngine::CreateRenderSystem();
    InputSystem& Input = GameEngine::CreateInputSystem();
    ResourceSystem& Resource = GameEngine::CreateResourceSystem();

	LoadResource();

	std::list<Fruit> Fruits;
	for (int32_t Index = 0; Index < 20; ++Index)
	{
		Fruits.push_back(Fruit::GenerateRandomFruit(100));
	}

	GameTimer.Reset();
    while (!Input.Tick())
    {
		GameTimer.Tick();

		GamePlayer.Update(Input, GameTimer.DeltaTime());
		for (auto& fruit : Fruits)
		{
			fruit.Update(Input, GameTimer.DeltaTime());
		}

        Renderer.BeginFrame(Color::Black);

        Renderer.DrawTexture2D(Resource.GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), 1000, 800);

		GamePlayer.Render(Renderer);
		for (auto& fruit : Fruits)
		{
			fruit.Render(Renderer);
		}
        
        Renderer.EndFrame();
    }

    GameEngine::Quit();
    return 0;
}