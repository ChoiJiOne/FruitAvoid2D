#include "Player.h"
#include "GameEngine.h"

int main(int argc, char* argv[])
{
    GameEngine::Init();

    WindowSystem& Window = GameEngine::CreateWindowSystem("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    RenderSystem& Renderer = GameEngine::CreateRenderSystem();
    InputSystem& Input = GameEngine::CreateInputSystem();
    ResourceSystem& Resource = GameEngine::CreateResourceSystem();

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

    Texture& BGTexture = Resource.LoadTextureFromFile(Text::GetHash("Beach"), ResourcePath + "texture\\Beach.jpg");
    Font& MonoFont = Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);
	
	Player player(Vec2i(500, 650), 200.0f, 50, 50, Player::EColor::Blue);
	Timer timer;

	timer.Reset();
    while (!Input.Tick())
    {
		timer.Tick();

		player.Update(Input, timer.DeltaTime());

        Renderer.BeginFrame(Color::Black);

        Renderer.DrawTexture2D(BGTexture, Vec2i(500, 400), 1000, 800);
		player.Render(Renderer);
        
        Renderer.EndFrame();
    }

    GameEngine::Quit();
    return 0;
}