#pragma once

#include "GameObject.h"

#include <unordered_map>


/**
 * ���� �÷��̾� Ŭ�����Դϴ�.
 */
class Player : public GameObject
{
public:
	/**
	 * ���� �÷��̾��� ���� Ÿ���Դϴ�.
	 */
	enum class EColor
	{
		None   = 0,
		Blue   = 1,
		Green  = 2,
		Orange = 3,
		Purple = 4,
		Red    = 5,
		Sky    = 6,
		Yellow = 7
	};


public:
	/**
	 * ���� �÷��̾� Ŭ������ �������Դϴ�.
	 * �̶�, ���� �÷��̾��� �ӵ��� �ʴ� �ȼ� �̵������� ���˴ϴ�.
	 *
	 * @param InWorld - ���� �÷��̾ ��ġ�� �����Դϴ�.
	 * @param InPosition - ���� �÷��̾��� ȭ��� ��ġ�Դϴ�.
	 * @param InSpeed - ���� �÷��̾��� �ӵ��Դϴ�.
	 * @param InWidth - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InHeight - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InColor - ���� �÷��̾��� �����Դϴ�.
	 */
	explicit Player(World* InWorld, const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EColor& InColor);


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
	 * ���� �÷��̾ ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ���� �÷��̾ ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InGraphics - ������ ������ ó�� �ν��Ͻ��Դϴ�.
	 */
	virtual void Render(Graphics& InGraphics) override;


private:
	/**
	 * ���� �÷��̾��� �ӵ��Դϴ�.
	 */
	float Speed_ = 0.0f;


	/**
	 * ���� �÷��̾��� ���� Ÿ���Դϴ�.
	 */
	EColor Color_;


	/**
	 * ���� �÷��̾� ���� �����ϴ� �ؽ�ó Ű ���Դϴ�.
	 */
	static std::unordered_map<EColor, std::size_t> ColorTextureKeys_;
};