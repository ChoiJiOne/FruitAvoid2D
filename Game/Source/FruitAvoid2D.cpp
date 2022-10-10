#include "FruitAvoid2D.h"

FruitAvoid2D::~FruitAvoid2D()
{
}

void FruitAvoid2D::Init()
{
	GameFramework::Init();

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

	Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);

	Player_ = std::make_unique<Player>(Vec2i(500, 650), 400.0f, 50, 50, Player::EColor::Blue);

	for (int32_t Count = 1; Count <= MaxFruits_; ++Count)
	{
		WaitFruits_.push(Fruit::GenerateRandomFruit(RespawnYPosition_));
	}
}

void FruitAvoid2D::Run()
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

void FruitAvoid2D::Update()
{
	InputSystem& Input = GameEngine::GetInputSystem();

	Player_->Update(Input, Timer_.DeltaTime());

	for (int32_t Count = 1; Count <= MaxFruits_; ++Count)
	{
		auto UpdateFruit = WaitFruits_.front();
		WaitFruits_.pop();

		UpdateFruit.Update(Input, Timer_.DeltaTime());

		if (Player_->IsCollision(UpdateFruit))
		{
			CountOfCollision++;
			WaitFruits_.push(Fruit::GenerateRandomFruit(RespawnYPosition_));
			continue;
		}

		if (UpdateFruit.GetCenter().y >= EndYPosition_)
		{
			WaitFruits_.push(Fruit::GenerateRandomFruit(RespawnYPosition_));
		}
		else
		{
			WaitFruits_.push(UpdateFruit);
		}
	}
}

void FruitAvoid2D::Render()
{
	RenderSystem& Renderer = GameEngine::GetRenderSystem();
	ResourceSystem& Resource = GameEngine::GetResourceSystem();

	Renderer.BeginFrame(Color::Black);

	Renderer.DrawTexture2D(Resource.GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), 1000, 800);

	Player_->Render(Renderer);

	for (int32_t Count = 1; Count <= MaxFruits_; ++Count)
	{
		auto RenderFruit = WaitFruits_.front();
		WaitFruits_.pop();

		RenderFruit.Render(Renderer);
		WaitFruits_.push(RenderFruit);
	}

	Font& Mono = Resource.GetFont(Text::GetHash("Mono"));
	Renderer.DrawText2D(Mono, Text::Format(L"time : %3d", static_cast<int32_t>(Timer_.TotalTime())), Vec2i(200, 750), Color::Cyan);
	Renderer.DrawText2D(Mono, Text::Format(L"life : %3d", Life_), Vec2i(200, 770), Color::Cyan);

	Renderer.EndFrame();
}
