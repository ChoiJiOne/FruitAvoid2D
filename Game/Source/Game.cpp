#include "Game.h"

Game::~Game()
{
	GameEngine::Quit();
}

void Game::Init()
{
	GameEngine::Init();

	WindowSystem& Window = GameEngine::CreateWindowSystem("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	RenderSystem& Renderer = GameEngine::CreateRenderSystem();
	InputSystem& Input = GameEngine::CreateInputSystem();
	ResourceSystem& Resource = GameEngine::CreateResourceSystem();

	std::string ResourcePath = GameEngine::GetRootDirectory() + "\\Game\\Content\\";
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

	Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32);

	Player_ = std::make_unique<Player>(Vec2i(500, 650), 400.0f, 50, 50, Player::EColor::Blue);

	for (int32_t Count = 1; Count <= MaxFruits; ++Count)
	{
		Fruits_.push_back(Fruit::GenerateRandomFruit(RespawnYPosition));
	}
}

void Game::Run()
{
	InputSystem& Input = GameEngine::GetInputSystem();

	Timer_.Reset();

	while (!Input.Tick())
	{
		Timer_.Tick();

		Update();
		Render();
	}
}

void Game::Update()
{
	InputSystem& Input = GameEngine::GetInputSystem();

	Player_->Update(Input, Timer_.DeltaTime());

	auto Iter = Fruits_.begin();
	while (Iter != Fruits_.end())
	{
		Iter->Update(Input, Timer_.DeltaTime());

		if (Iter->GetPosition().y >= EndYPosition)
		{
			Fruits_.erase(Iter++);
			Fruits_.push_back(Fruit::GenerateRandomFruit(RespawnYPosition));
		}
		else
		{
			Iter++;
		}
	}
}

void Game::Render()
{
	RenderSystem& Renderer = GameEngine::GetRenderSystem();
	ResourceSystem& Resource = GameEngine::GetResourceSystem();

	Renderer.BeginFrame(Color::Black);

	Renderer.DrawTexture2D(Resource.GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), 1000, 800);

	Player_->Render(Renderer);
	for (auto& fruit : Fruits_)
	{
		fruit.Render(Renderer);
	}

	Font& Mono = Resource.GetFont(Text::GetHash("Mono"));
	Renderer.DrawText2D(Mono, Text::Format(L"time : %3d", static_cast<int32_t>(Timer_.TotalTime())), Vec2i(200, 750), Color::Cyan);
	Renderer.DrawText2D(Mono, Text::Format(L"life : %3d", Life_), Vec2i(200, 770), Color::Cyan);

	Renderer.EndFrame();
}
