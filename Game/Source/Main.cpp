#include "ToyEngine.h"

#include "Player.h"
#include "Fruit.h"


/**
 * FruitAvoid2D 과일 피하기 게임입니다.
 */
class FruitAvoid2D : public GameFramework
{
public:
	/**
	 * FruitAvoid2D 게임의 상태입니다.
	 */
	enum class GameState : int32_t
	{
		Start = 0,
		Play  = 1,
		Pause = 2,
		Done  = 3
	};


public:
	/**
	 * FruitAvoid2D의 생성자입니다.
	 */
	FruitAvoid2D() = default;


	/**
	 * FruitAvoid2D의 가상 소멸자입니다.
	 */
	virtual ~FruitAvoid2D()
	{
		QuitButton_.reset();
		ResetButton_.reset();
		ContinueButton_.reset();
		StartButton_.reset();
	}


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제
	 */
	DISALLOW_COPY_AND_ASSIGN(FruitAvoid2D);


	/**
	 * ToyEngine2D 및 FruitAvoid2D 을 초기화합니다.
	 *
	 * @throws
	 * - 게임 엔진 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 * - FruitAvoid2D 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Init() override
	{
		GameFramework::Init();

		InitProperties();
		InitResources();
		InitGameProperties();
	}


	/**
	 * FruitAvoid2D 게임을 실행합니다.
	 *
	 * @throws FruitAvoid2D 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Run() override
	{
		Timer_.Reset();

		while (!bIsDone_ && !Input_->Tick())
		{
			Timer_.Tick();

			Update();
			Render();
		}
	}


	/**
	 * FruitAvoid2D 게임을 업데이트합니다.
	 *
	 * @throws FruitAvoid2D 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Update() override
	{
		if (CurrentGameState == GameState::Play)
		{

		}
		else
		{
			Button* CurrentButton = nullptr;

			switch (CurrentGameState)
			{
			case GameState::Start:
				CurrentButton = StartButton_.get();
				break;

			case GameState::Pause:
				CurrentButton = ContinueButton_.get();
				break;

			case GameState::Done:
				CurrentButton = ResetButton_.get();
				break;
			}

			CurrentButton->Update(*Input_);
			QuitButton_->Update(*Input_);
		}
	}


	/**
	 * FruitAvoid2D 게임을 화면에 렌더링합니다.
	 *
	 * @throws FruitAvoid2D 게임 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(ColorUtils::Black);

		Graphics_->DrawTexture2D(ContentUtils::GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), World_->GetWidth(), World_->GetHeight());

		if (CurrentGameState == GameState::Play)
		{

		}
		else
		{
			Button* CurrentButton = nullptr;

			switch (CurrentGameState)
			{
			case GameState::Start:
				CurrentButton = StartButton_.get();
				break;

			case GameState::Pause:
				CurrentButton = ContinueButton_.get();
				break;

			case GameState::Done:
				CurrentButton = ResetButton_.get();
				break;
			}

			Graphics_->DrawText2D(
				ContentUtils::GetFont(Text::GetHash("font64")),
				L"Fruit Avoid 2D",
				Vec2i(500, 200),
				ColorUtils::Cyan
			);

			CurrentButton->Render(*Graphics_);
			QuitButton_->Render(*Graphics_);
		}

		Graphics_->EndFrame();
	}


private:
	/**
	 * 게임에서 사용할 기본적인 요소를 초기화합니다.
	 */
	void InitProperties()
	{
		Window_ = std::make_unique<Window>(
			WindowConstructorParam{
				"FruitAvoid2D",
				100,
				100,
				1000,
				800,
				EWindowFlags::SHOWN
			}
		);

		Graphics_ = std::make_unique<Graphics>(
			*Window_,
			EGraphicsFlags::ACCELERATED | EGraphicsFlags::PRESENTVSYNC
			);

		Input_ = std::make_unique<Input>();

		World_ = std::make_unique<World>(1000, 800);
	}


	/**
	 * 게임에서 사용할 리소스를 초기화합니다.
	 */
	void InitResources()
	{
		std::vector <std::string> TextureNames = {
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
			std::size_t Key = Text::GetHash(TextureName);
			ContentUtils::LoadTexture(Key, *Graphics_, Text::Format("texture\\%s.png", TextureName.c_str()));
		}

		ContentUtils::LoadTexture(Text::GetHash("Beach"), *Graphics_, "texture\\Beach.jpg");

		std::size_t Font64Key = Text::GetHash("font64");
		ContentUtils::LoadFont(Font64Key, *Graphics_, "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 64.0f);

		std::size_t Font32Key = Text::GetHash("font32");
		ContentUtils::LoadFont(Font32Key, *Graphics_, "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);
	}


	/**
	 * 게임 내의 요소들을 초기화합니다.
	 */
	void InitGameProperties()
	{
		std::size_t Font32Key = Text::GetHash("font32");

		StartButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 400.0f),
			300.0f,
			80.0f,
			L"START",
			Font32Key,
			ColorUtils::Blue,
			ColorUtils::Black,
			[&]() { CurrentGameState = GameState::Play; },
			0.98f
		);

		ContinueButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 400.0f),
			300.0f,
			80.0f,
			L"CONTINUE",
			Font32Key,
			ColorUtils::Blue,
			ColorUtils::Black,
			[&]() { CurrentGameState = GameState::Play; },
			0.98f
		);

		ResetButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 400.0f),
			300.0f,
			80.0f,
			L"RESET",
			Font32Key,
			ColorUtils::Blue,
			ColorUtils::Black,
			[&]() { CurrentGameState = GameState::Play; },
			0.98f
		);

		QuitButton_ = std::make_unique<Button>(
			Vec2f(500.0f, 500.0f),
			300.0f,
			80.0f,
			L"QUIT",
			Font32Key,
			ColorUtils::Blue,
			ColorUtils::Black,
			[&]() { bIsDone_ = true; },
			0.98f
		);
	}


private:
	/**
	 * 현재 게임 상태입니다.
	 */
	GameState CurrentGameState = GameState::Start;

	
	/**
	 * 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * 게임을 시작하는 버튼입니다.
	 */
	std::unique_ptr<Button> StartButton_ = nullptr;


	/**
	 * 중지된 게임을 시작하는 버튼입니다.
	 */
	std::unique_ptr<Button> ContinueButton_ = nullptr;


	/**
	 * 게임을 리셋하는 버튼입니다.
	 */
	std::unique_ptr<Button> ResetButton_ = nullptr;


	/**
	 * 게임을 종료하는 버튼입니다.
	 */
	std::unique_ptr<Button> QuitButton_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<FruitAvoid2D>();
	Game->Init();
	Game->Run();

	return 0;
}