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
	 * FruitAvoid2D의 생성자입니다.
	 */
	FruitAvoid2D() = default;


	/**
	 * FruitAvoid2D의 가상 소멸자입니다.
	 */
	virtual ~FruitAvoid2D()
	{
		RemoveFruits();

		Player_.reset();
		Input_.reset();
		World_.reset();
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

		World_ = std::make_unique<World>(1000, 800);

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

		std::size_t FontKey = Text::GetHash("font");
		ContentUtils::LoadFont(FontKey, *Graphics_, "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);

		Player_ = std::make_unique<Player>(World_.get(), PlayerStartPosition, 50.0f, 50.0f, 500.0f, Player::EColor::Blue);

		CreateFruits();
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
		for (auto& fruit : Fruits_)
		{
			fruit->Update(*Input_, Timer_.GetDeltaSeconds());
		}

		Player_->Update(*Input_, Timer_.GetDeltaSeconds());

		int32_t CountOfNewFruit = 0;
		for (auto Iter = Fruits_.begin(); Iter != Fruits_.end(); )
		{
			bool bIsRemove = false;
			Fruit* CurrentFruit = Iter->get();

			if (CurrentFruit->GetBody().IsCollision(Player_->GetBody()) || 
				CurrentFruit->GetBody().GetCenter().y >= static_cast<float>(World_->GetHeight()))
			{
				bIsRemove = true;
			}

			if (bIsRemove)
			{
				Iter = Fruits_.erase(Iter);
				CountOfNewFruit++;
			}
			else
			{
				Iter++;
			}
		}

		for (int32_t Count = 1; Count <= CountOfNewFruit; ++Count)
		{
			AddNewFruit();
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

		Player_->Render(*Graphics_);

		for (auto& fruit : Fruits_)
		{
			fruit->Render(*Graphics_);
		}

		Graphics_->DrawText2D(ContentUtils::GetFont(Text::GetHash("font")), Text::Format(L"FPS : %d", static_cast<int32_t>(1.0f / Timer_.GetDeltaSeconds())), Vec2i(100, 50), ColorUtils::Black);

		Graphics_->EndFrame();
	}


private:
	/**
	 * 게임 내의 과일 오브젝트들을 생성합니다.
	 */
	void CreateFruits()
	{
		if (Fruits_.size() > 0)
		{
			RemoveFruits();
		}

		for (int32_t Count = 1; Count <= MaxFruits_; ++Count)
		{
			AddNewFruit();
		}
	}


	/**
	 * 게임 내의 과일 오브젝트들을 삭제합니다.
	 */
	void RemoveFruits()
	{
		for (auto& fruit : Fruits_)
		{
			fruit.reset();
		}
	}


	/**
	 * 임의의 과일을 추가합니다.
	 */
	void AddNewFruit()
	{
		static float FruitSpeeds[] = {
			100.0f,
//			250.0f,
//			300.0f,
//			350.0f,
//			400.0f,
//			450.0f,
//			500.0f
		};

		static float FruitSizes[] = {
			50.0f,
			60.0f,
			70.0f,
			80.0f,
			90.0f
		};

		static Fruit::EType FruitTypes[] = {
			Fruit::EType::Banana,
			Fruit::EType::BlackBerryDark,
			Fruit::EType::BlackBerryLight,
			Fruit::EType::BlackCherry,
			Fruit::EType::Coconut,
			Fruit::EType::GreenApple,
			Fruit::EType::GreenGrape,
			Fruit::EType::Lemon,
			Fruit::EType::Lime,
			Fruit::EType::Orange,
			Fruit::EType::Peach,
			Fruit::EType::Pear,
			Fruit::EType::Plum,
			Fruit::EType::Raspberry,
			Fruit::EType::RedApple,
			Fruit::EType::RedCherry,
			Fruit::EType::RedGrape,
			Fruit::EType::StarFruit,
			Fruit::EType::Strawberry,
			Fruit::EType::WaterMelon
		};

		float FruitSize = FruitSizes[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitSizes) - 1)];

		Fruits_.push_back(std::make_unique<Fruit>(
			World_.get(),
			Vec2f(MathUtils::GenerateRandomFloat<float>(0.0f, static_cast<float>(World_->GetWidth())), 0.0f),
			FruitSize,
			FruitSize,
			FruitSpeeds[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitSpeeds) - 1)],
			FruitTypes[MathUtils::GenerateRandomInt<int32_t>(0, std::size(FruitTypes) - 1)]
		));
	}


private:
	/**
	 * 2D 게임 월드입니다.
	 */
	std::unique_ptr<World> World_ = nullptr;


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


	/**
	 * 게임 플레이어 시작 위치입니다.
	 */
	Vec2f PlayerStartPosition = Vec2f(500.0f, 650.0f);


	/**
	 * 게임 플레이어의 라이프입니다.
	 */
	int32_t Life = 3;


	/**
	 * 플레이어가 피해야 할 과일들입니다.
	 */
	std::list<std::unique_ptr<Fruit>> Fruits_;


	/**
	 * 과일의 최대 개수입니다.
	 */
	const int32_t MaxFruits_ = 15;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<FruitAvoid2D>();
	Game->Init();
	Game->Run();

	return 0;
}