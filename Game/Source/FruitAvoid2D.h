#pragma once

#include "Player.h"
#include "Fruit.h"
#include "GameFramework.h"
#include "GameEngine.h"


/**
 * FruitAvoid2D 게임을 실행하는 클래스입니다.
 */
class FruitAvoid2D : public GameFramework
{
public:
	/**
	 * 게임을 실행하는 클래스의 생성자입니다.
	 */
	FruitAvoid2D() = default;


	/**
	 * 게임을 실행하는 클래스의 가상 소멸자입니다.
	 */
	virtual ~FruitAvoid2D();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제
	 */
	DISALLOW_COPY_AND_ASSIGN(FruitAvoid2D);


	/**
	 * 게임을 초기화합니다.
	 * 
	 * @throws 게임 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Init() override;
	

	/**
	 * 게임을 실행합니다.
	 * 
	 * @throws 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Run() override;


	/**
	 * 게임을 업데이트합니다.
	 * 
	 * @throws 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Update() override;


	/**
	 * 게임을 화면에 렌더링합니다.
	 * 
	 * @throws 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() override;


private:
	/**
	 * 게임 종료 여부를 확인합니다.
	 */
	bool bIsDone_ = false;


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
	std::queue<Fruit> WaitFruits_;


	/**
	 * 게임 내의 최대 과일의 수입니다.
	 */
	int32_t MaxFruits_ = 10;


	/**
	 * 플레이어의 목숨입니다.
	 */
	int32_t Life_ = 3;


	/**
	 * 과일의 리스폰 Y좌표입니다.
	 */
	int32_t RespawnYPosition_ = 0;


	/**
	 * 과일의 끝 지점입니다.
	 */
	int32_t EndYPosition_ = 800;
};