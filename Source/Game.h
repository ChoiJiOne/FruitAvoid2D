#pragma once

#include "Player.h"
#include "Fruit.h"
#include "GameEngine.h"


/**
 * FruitAvoid2D 게임을 실행하는 클래스입니다.
 */
class Game
{
public:
	/**
	 * FruitAvoid2D 게임을 실행하는 클래스의 가상 소멸자입니다.
	 */
	Game() = default;


	/**
	 * FruitAvoid2D 게임을 실행하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~Game();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제
	 */
	DISALLOW_COPY_AND_ASSIGN(Game);


	/**
	 * FruitAvoid2D 게임을 초기화합니다.
	 * 
	 * @throws FruitAvoid2D 게임 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void Init();


	/**
	 * FruitAvoid2D 게임을 실행합니다.
	 * 
	 * @throws FruitAvoid2D 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	void Run();


private:
	/**
	 * 게임 타이머입니다.
	 */
	Timer Timer_;


	/**
	 * 게임 플레이어입니다.
	 */
	std::unique_ptr<Player> Player_ = nullptr;


	/**
	 * 플레이어가 피해야 할 과일들입니다.
	 */
	std::list<Fruit> Fruits_;
};