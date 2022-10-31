#pragma once

#include "Macro.h"


/**
 * 게임 프레임워크 클래스입니다.
 * 이 엔진을 이용해서 게임을 개발하기 위해서는 반드시 이 클래스를 상속받아야 합니다.
 */
class GameFramework
{
public:
	/**
	 * 게임 프레임워크의 생성자입니다.
	 * 이때, 생성자는 아무런 동작을 하지 않으므로 반드시 Init 메서드를 호출해야 합니다.
	 */
	GameFramework() = default;


	/**
	 * 게임 프레임워크의 가상 소멸자입니다.
	 */
	virtual ~GameFramework();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제
	 */
	DISALLOW_COPY_AND_ASSIGN(GameFramework);


	/**
	 * 게임 프레임워크 및 엔진을 초기화합니다.
	 *
	 * @throws
	 * - 게임 엔진 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 * - 게임 프레임워크 초기화에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Init();


	/**
	 * 게임을 실행합니다.
	 *
	 * @throws 게임 실행에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Run() = 0;


	/**
	 * 게임을 업데이트합니다.
	 *
	 * @throws 게임 업데이트에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Update() = 0;


	/**
	 * 게임을 화면에 렌더링합니다.
	 *
	 * @throws 게임 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render() = 0;
};