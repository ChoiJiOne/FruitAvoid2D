#pragma once

#include "Macro.h"

#include <string>

struct SDL_Window;


/**
 * ������ Ŭ�����Դϴ�.
 */
class WindowSystem
{
public:
	/**
	 * ������ Ŭ������ �������Դϴ�.
	 *
	 * @param InTitle - �������� Ÿ��Ʋ�Դϴ�.
	 * @param InPositionX - ������ ���� ����� X��ǥ�Դϴ�.
	 * @param InPositionY - ������ ���� ����� Y��ǥ�Դϴ�.
	 * @param InWidth - �������� ���� ũ���Դϴ�.
	 * @param InHeight - �������� ���� ũ���Դϴ�.
	 * @param InFlags - ������ �ɼ��Դϴ�.
	 *
	 * @throws ������ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
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
	 * ������ Ŭ������ ���� �Ҹ����Դϴ�
	 */
	virtual ~WindowSystem();


	/**
	 * ������ Ŭ������ ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(WindowSystem);


	/**
	 * ���� ������ ��ġ�� �����մϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InXPosition - ��ũ�� ���� ���� ������ ���� ����� X��ǥ�Դϴ�.
	 * @param InYPosition - ��ũ�� ���� ���� ������ ���� ����� Y��ǥ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowPosition
	 */
	void SetPosition(const int32_t& InXPosition, const int32_t& InYPosition);


	/**
	 * ���� ������ ��ġ�� ����ϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param OutXPosition - ��ũ�� ���� ���� ������ ���� ����� X��ǥ�Դϴ�.
	 * @param OutYPosition - ��ũ�� ���� ���� ������ ���� ����� Y��ǥ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowPosition
	 */
	void GetPosition(int32_t& OutXPosition, int32_t& OutYPosition);


	/**
	 * ���� �������� ũ�⸦ �����մϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InWidth - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 * @param InHeight - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowSize
	 */
	void SetSize(const int32_t& InWidth, const int32_t& InHeight);


	/**
	 * ���� �������� ũ�⸦ ����ϴ�.
	 * �̶�, ������ �ȼ������Դϴ�.
	 *
	 * @param InWidth - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 * @param InHeight - ��ũ�� ���� ���� �������� ���� ũ���Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowSize
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * ���� �������� Ÿ��Ʋ�� �����մϴ�.
	 *
	 * @param InTitle - ������ ���� ������ Ÿ��Ʋ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_SetWindowTitle
	 */
	void SetTitle(const std::string& InTitle);


	/**
	 * ���� �������� Ÿ��Ʋ�� ����ϴ�.
	 *
	 * @param InTitle - ���� ������ Ÿ��Ʋ�Դϴ�.
	 *
	 * @see https://wiki.libsdl.org/SDL_GetWindowTitle
	 */
	void GetTitle(std::string& OutTitle);


	/**
	 * ���� �����츦 ȭ�鿡 ǥ���մϴ�.
	 */
	void Show();


	/**
	 * ���� �����츦 ȭ�鿡�� ����ϴ�.
	 */
	void Hide();


	/**
	 * �������� ũ�� ������ ����ϴ�.
	 * �̶� ���� ���� ���� / ���� �Դϴ�.
	 *
	 * @return ���� �������� ũ�� ������ ��ȯ�մϴ�.
	 */
	float GetAspectRatio();


	/**
	 * SDL�������� �����͸� ��ȯ�մϴ�.
	 *
	 * @return SDL �������� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Window* GetWindow() { return Window_; }


private:
	/**
	 * SDL ������ �������Դϴ�.
	 */
	SDL_Window* Window_ = nullptr;
};