﻿#include "ToyEngine.h"
#include "Player.h"


/**
 * FruitAvoid2D 과일 피하기 게임입니다.
 */
class FruitAvoid2D : public GameFramework
{
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
		Player_.reset();
		Input_.reset();
		Graphics_.reset();
		Window_.reset();
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

		std::vector <std::string> TextureNames = {
			"PlayerBlockBlue",
			"PlayerBlockGreen",
			"PlayerBlockOrange",
			"PlayerBlockPurple",
			"PlayerBlockRed",
			"PlayerBlockSky",
			"PlayerBlockYellow"
		};

		for (const auto& TextureName : TextureNames)
		{
			std::size_t Key = Text::GetHash(TextureName);
			ContentUtils::AddTexture(Key, *Graphics_, Text::Format("texture\\%s.png", TextureName.c_str()));
		}

		ContentUtils::AddTexture(Text::GetHash("Beach"), *Graphics_, "texture\\Beach.jpg");

		std::size_t FontKey = Text::GetHash("font");
		ContentUtils::AddFont(FontKey, *Graphics_, "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);

		Player_ = std::make_unique<Player>(Vec2i(500, 650), 400.0f, 50, 50, Player::EColor::Blue);
	}


	/**
	 * FruitAvoid2D 게임을 실행합니다.
	 *
	 * @throws FruitAvoid2D 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Run() override
	{
		Timer_.Reset();

		while (!Input_->Tick())
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
		Player_->Update(*Input_, Timer_.GetDeltaSeconds());
	}


	/**
	 * FruitAvoid2D 게임을 화면에 렌더링합니다.
	 *
	 * @throws FruitAvoid2D 게임 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(ColorUtils::Black);

		Graphics_->DrawTexture2D(ContentUtils::GetTexture(Text::GetHash("Beach")), Vec2i(500, 400), 1000, 800);

		Player_->Render(*Graphics_);

		Graphics_->DrawText2D(ContentUtils::GetFont(Text::GetHash("font")), Text::Format(L"FPS : %d", static_cast<int32_t>(1.0f / Timer_.GetDeltaSeconds())), Vec2i(100, 50), ColorUtils::Black);

		Graphics_->EndFrame();
	}


private:
	/**
	 * FruitAvoid2D의 윈도우 창 처리를 위한 인스턴스입니다.
	 */
	std::unique_ptr<Window> Window_ = nullptr;


	/**
	 * FruitAvoid2D의 입력 처리를 위한 인스턴스입니다.
	 */
	std::unique_ptr<Input> Input_ = nullptr;


	/**
	 * FruitAvoid2D의 그래픽 관련 처리를 위한 인스턴스입니다.
	 */
	std::unique_ptr<Graphics> Graphics_ = nullptr;

	
	/**
	 * 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * 게임 플레이어 입니다.
	 */
	std::unique_ptr<Player> Player_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<FruitAvoid2D>();
	Game->Init();
	Game->Run();

	return 0;
}