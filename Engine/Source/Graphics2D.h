#pragma once

#include "Macro.h"
#include "Color.h"

class Window;
struct SDL_Renderer;


/**
 * �׷��Ƚ� �ɼ� �÷����Դϴ�.
 * 
 * @see https://wiki.libsdl.org/SDL_RendererFlags
 */
enum class EGraphicsFlags : int32_t
{
	SOFTWARE = 0x00000001,
	ACCELERATED = 0x00000002,
	PRESENTVSYNC = 0x00000004,
	TARGETTEXTURE = 0x00000008
};


/**
 * �׷��Ƚ� �ɼ� �÷����� or ������ �����մϴ�.
 *
 * @param InLhs - or ������ ���� �ǿ������Դϴ�.
 * @param InRhs - or ������ ���� �ǿ������Դϴ�.
 *
 * @return or ������ ������ ����� ��ȯ�մϴ�.
 */
inline EGraphicsFlags operator|(const EGraphicsFlags& InLhs, const EGraphicsFlags& InRhs)
{
	return static_cast<EGraphicsFlags>(static_cast<uint32_t>(InLhs) | static_cast<uint32_t>(InRhs));
}


/**
 * ���� ���� �׷��Ƚ� ���� ó���� �ϴ� Ŭ�����Դϴ�.
 */
class Graphics2D
{
public:
	/**
	 * �׷��Ƚ� Ŭ������ �������Դϴ�.
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 * 
	 * @param InWindow - �׷��Ƚ� Ŭ���� �ʱ�ȭ �� ������ ������ Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InFlags - �׷��Ƚ� ���� �ɼ��Դϴ�.
	 * 
	 * @throws �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @see https://wiki.libsdl.org/SDL_CreateRenderer
	 */
	explicit Graphics2D(Window& InWindow, const EGraphicsFlags& InFlags);


	/**
	 * �׷��Ƚ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Graphics2D();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Graphics2D);


	/**
	 * ������ �������� �����մϴ�.
	 *
	 * @param InColor - �����۸� ��� �����Դϴ�.
	 *
	 * @throws ����� �ʱ�ȭ�� ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void BeginFrame(const LinearColor& InColor);


	/**
	 * ������ �������� �����ϰ�, �����۸� ȭ�鿡 ǥ���մϴ�.
	 */
	void EndFrame();


	/**
	 * SDL �������� �����͸� ����ϴ�.
	 *
	 * @return SDL �������� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Renderer* GetRenderer() { return Renderer_; }


private:
	/**
	 * SDL �������� �÷� ���¸� �����մϴ�.
	 *
	 * @param InColor - ������ SDL �������� �÷� �����Դϴ�.
	 *
	 * @throws ���� ���� ������ ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetDrawColor(const LinearColor& InColor);


	/**
	 * SDL �������� �÷� ���¸� �����մϴ�.
	 *
	 * @param InRed - ������ SDL �������� �÷� Red�� �Դϴ�.
	 * @param InGreen - ������ SDL �������� �÷� Green�� �Դϴ�.
	 * @param InBlue - ������ SDL �������� �÷� Blue�� �Դϴ�.
	 * @param InAlpha - ������ SDL �������� �÷� Alpha�� �Դϴ�.
	 *
	 * @throws ���� ���� ������ ������ ���, C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void SetDrawColor(uint8_t InRed, uint8_t InGreen, uint8_t InBlue, uint8_t InAlpha);


private:
	/**
	 * �׷��Ƚ� ������ �����ϴ� SDL �������Դϴ�.
	 */
	SDL_Renderer* Renderer_ = nullptr;
};