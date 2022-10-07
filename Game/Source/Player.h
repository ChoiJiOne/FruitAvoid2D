#pragma once

#include "Vector.h"

#include <unordered_map>

class InputSystem;
class RenderSystem;


/**
 * ���� �÷��̾� Ŭ�����Դϴ�.
 */
class Player
{
public:
	/**
	 * ���� �÷��̾��� ���� Ÿ���Դϴ�.
	 */
	enum class EColor
	{
		None = 0,
		Blue = 1,
		Green = 2,
		Orange = 3,
		Purple = 4,
		Red = 5,
		Sky = 6,
		Yellow = 7
	};


public:
	/**
	 * ���� �÷��̾� Ŭ������ �������Դϴ�.
	 * �̶�, ���� �÷��̾��� �ӵ��� �ʴ� �ȼ� �̵������� ���˴ϴ�.
	 *
	 * @param InPosition - ���� �÷��̾��� ȭ��� ��ġ�Դϴ�.
	 * @param InSpeed - ���� �÷��̾��� �ӵ��Դϴ�.
	 * @param InWidth - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InHeight - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InColor - ���� �÷��̾��� �����Դϴ�.
	 */
	explicit Player(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EColor& InColor);


	/**
	 * ���� �÷��̾� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Player(Player&& InInstance) noexcept;


	/**
	 * ���� �÷��̾� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Player(const Player& InInstance) noexcept;


	/**
	 * ���� �÷��̾��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Player();


	/**
	 * ���� �÷��̾� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Player& operator=(Player&& InInstance) noexcept;


	/**
	 * ���� �÷��̾� Ŭ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Player& operator=(const Player& InInstance) noexcept;


	/**
	 * ���� �÷��̾� ���¸� ������Ʈ�մϴ�.
	 * 
	 * @param InInput - ���� ������ �Է� �ý����Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�
	 */
	void Update(const InputSystem& InInput, float InDeltaTime);


	/**
	 * ���� �÷��̾ ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InRenderer - ���� ������ ���� �ý����Դϴ�.
	 * 
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Render(const RenderSystem& InRenderer);


private:
	/**
	 * ���� �÷��̾��� ��ġ�Դϴ�.
	 */
	Vec2i Position_;


	/**
	 * ���� �÷��̾��� �ӵ��Դϴ�.
	 * �̶�, �ӵ� ��� ����� �ʴ� �̵��� �ȼ����Դϴ�.
	 */
	float Speed_ = 0.0f;


	/**
	 * ���� �÷��̾��� ���� ũ���Դϴ�.
	 */
	int32_t Width_ = 0;


	/**
	 * ���� �÷��̾��� ���� ũ���Դϴ�.
	 */
	int32_t Height_ = 0;


	/**
	 * ���� �÷��̾��� ���� Ÿ���Դϴ�.
	 */
	EColor Color_;


	/**
	 * ���� �÷��̾� ���� �����ϴ� �ؽ�ó Ű ���Դϴ�.
	 */
	static std::unordered_map<EColor, std::size_t> ColorTextureKeys_;
};