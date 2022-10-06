#include "Player.h"
#include "Fruit.h"
#include "GameEngine.h"

void LoadResource()
{
	ResourceSystem& Resource = GameEngine::GetResourceSystem();

	std::string ResourcePath = GameEngine::GetRootDirectory() + "\\Resource\\";
	std::vector<std::string> TextureNames = {
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

	for (const auto& TextureName : TextureNames)
	{
		Resource.LoadTextureFromFile(Text::GetHash(TextureName), Text::Format("%stexture\\%s.png", ResourcePath.c_str(), TextureName.c_str()));
	}

	Resource.LoadTextureFromFile(Text::GetHash("Beach"), ResourcePath + "texture\\Beach.jpg");
	Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);
}

int main(int argc, char* argv[])
{
    GameEngine::Init();

    WindowSystem& Window = GameEngine::CreateWindowSystem("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    RenderSystem& Renderer = GameEngine::CreateRenderSystem();
    InputSystem& Input = GameEngine::CreateInputSystem();
    ResourceSystem& Resource = GameEngine::CreateResourceSystem();

	LoadResource();

	Player player(Vec2i(500, 650), 200.0f, 50, 50, Player::EColor::Blue);
	Fruit fruit = Fruit::GenerateRandomFruit(100);
	Timer timer;

	timer.Reset();
    while (!Input.Tick())
    {
		timer.Tick();

		player.Update(Input, timer.DeltaTime());
		fruit.Update(Input, timer.DeltaTime());

        Renderer.BeginFrame(Color::Black);

        Renderer.DrawTexture2D(Resource.GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), 1000, 800);
		player.Render(Renderer);
		fruit.Render(Renderer);
        
        Renderer.EndFrame();
    }

    GameEngine::Quit();
    return 0;
}