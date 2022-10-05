#pragma once

#include "Macro.h"

#include <string>

struct SDL_Window;


/**
 * 윈도우 클래스입니다.
 */
class WindowSystem
{
public:
	/**
	 * 윈도우 클래스의 생성자입니다.
	 *
	 * @param InTitle - 윈도우의 타이틀입니다.
	 * @param InPositionX - 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param InPositionY - 윈도우 왼쪽 상단의 Y좌표입니다.
	 * @param InWidth - 윈도우의 가로 크기입니다.
	 * @param InHeight - 윈도우의 세로 크기입니다.
	 * @param InFlags - 윈도우 옵션입니다.
	 *
	 * @throws 윈도우 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit WindowSystem(
		const std::string& InTitle,
		int32_t InPositionX,
		int32_t InPositionY,
		int32_t InWidth,
		int32_t InHeight,
		uint32_t InFlags
	);


	/**
	 * 윈도우 클래스의 가상 소멸자입니다
	 */
	virtual ~WindowSystem();


	/**
	 * 윈도우 클래스의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(WindowSystem);


	/**
	 * 게임 윈도우 위치를 변경합니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InXPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param InYPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 Y좌표입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowPosition
	 */
	void SetPosition(const int32_t& InXPosition, const int32_t& InYPosition);


	/**
	 * 게임 윈도우 위치를 얻습니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param OutXPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param OutYPosition - 스크린 상의 게임 윈도우 왼쪽 상단의 Y좌표입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowPosition
	 */
	void GetPosition(int32_t& OutXPosition, int32_t& OutYPosition);


	/**
	 * 게임 윈도우의 크기를 변경합니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InWidth - 스크린 상의 게임 윈도우의 가로 크기입니다.
	 * @param InHeight - 스크린 상의 게임 윈도우의 세로 크기입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowSize
	 */
	void SetSize(const int32_t& InWidth, const int32_t& InHeight);


	/**
	 * 게임 윈도우의 크기를 얻습니다.
	 * 이때, 단위는 픽셀단위입니다.
	 *
	 * @param InWidth - 스크린 상의 게임 윈도우의 가로 크기입니다.
	 * @param InHeight - 스크린 상의 게임 윈도우의 세로 크기입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowSize
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * 게임 윈도우의 타이틀을 설정합니다.
	 *
	 * @param InTitle - 설정할 게임 윈도우 타이틀입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowTitle
	 */
	void SetTitle(const std::string& InTitle);


	/**
	 * 게임 윈도우의 타이틀을 얻습니다.
	 *
	 * @param InTitle - 게임 윈도우 타이틀입니다.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowTitle
	 */
	void GetTitle(std::string& OutTitle);


	/**
	 * 게임 윈도우를 화면에 표시합니다.
	 */
	void Show();


	/**
	 * 게임 윈도우를 화면에서 숨깁니다.
	 */
	void Hide();


	/**
	 * 윈도우의 크기 비율을 얻습니다.
	 * 이때 비율 값은 가로 / 세로 입니다.
	 *
	 * @return 게임 윈도우의 크기 비율을 반환합니다.
	 */
	float GetAspectRatio();


	/**
	 * SDL윈도우의 포인터를 반환합니다.
	 *
	 * @return SDL 윈도우의 포인터를 반환합니다.
	 */
	SDL_Window* GetWindow() { return Window_; }


private:
	/**
	 * SDL 윈도우 포인터입니다.
	 */
	SDL_Window* Window_ = nullptr;
};