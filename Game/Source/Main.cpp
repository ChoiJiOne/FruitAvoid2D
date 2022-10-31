#include "ToyEngine.h"


/**
 * FruitAvoid2D ���� ���ϱ� �����Դϴ�.
 */
class FruitAvoid2D : public GameFramework
{
public:
	/**
	 * FruitAvoid2D�� �������Դϴ�.
	 */
	FruitAvoid2D() = default;


	/**
	 * FruitAvoid2D�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~FruitAvoid2D()
	{
		Input_.reset();
		Graphics_.reset();
		Window_.reset();
	}


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� ����
	 */
	DISALLOW_COPY_AND_ASSIGN(FruitAvoid2D);


	/**
	 * ToyEngine2D �� FruitAvoid2D �� �ʱ�ȭ�մϴ�.
	 *
	 * @throws
	 * - ���� ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - FruitAvoid2D �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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

		Graphics_ = std::make_unique<Graphics2D>(
			*Window_,
			EGraphicsFlags::ACCELERATED | EGraphicsFlags::PRESENTVSYNC
		);

		Input_ = std::make_unique<Input>();
	}


	/**
	 * FruitAvoid2D ������ �����մϴ�.
	 *
	 * @throws FruitAvoid2D ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Run() override
	{
		while (!Input_->Tick())
		{
			Update();
			Render();
		}
	}


	/**
	 * FruitAvoid2D ������ ������Ʈ�մϴ�.
	 *
	 * @throws FruitAvoid2D ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Update() override
	{

	}


	/**
	 * FruitAvoid2D ������ ȭ�鿡 �������մϴ�.
	 *
	 * @throws FruitAvoid2D ���� �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render() override
	{
		Graphics_->BeginFrame(Color::Black);
		Graphics_->EndFrame();
	}


private:
	/**
	 * FruitAvoid2D�� ������ â ó���� ���� �ν��Ͻ��Դϴ�.
	 */
	std::unique_ptr<Window> Window_ = nullptr;


	/**
	 * FruitAvoid2D�� �Է� ó���� ���� �ν��Ͻ��Դϴ�.
	 */
	std::unique_ptr<Input> Input_ = nullptr;


	/**
	 * FruitAvoid2D�� �׷��� ���� ó���� ���� �ν��Ͻ��Դϴ�.
	 */
	std::unique_ptr<Graphics2D> Graphics_ = nullptr;
};


int main(int argc, char* argv[])
{
	auto Game = std::make_unique<FruitAvoid2D>();
	Game->Init();
	Game->Run();

	return 0;
}