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
	 * @param InWidth - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InHeight - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InVelocity - ���� �÷��̾��� �ӵ��Դϴ�.
	 * @param InColor - ���� �÷��̾��� �����Դϴ�.
	 */
	explicit Player(
		World* InWorld, 
		const Vec2f& InPosition, 
		const float& InWidth, 
		const float& InHeight, 
		const float& InVelocity,
		const EColor& InColor
	);


	/**
	 * ���� �÷��̾��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Player();


	/**
	 * ���� �÷��̾��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Player);


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
	 * ���� �÷��̾��� ���� Ÿ���Դϴ�.
	 */
	EColor Color_;


	/**
	 * ���� �÷��̾� ���� �����ϴ� �ؽ�ó Ű ���Դϴ�.
	 */
	static std::unordered_map<EColor, std::size_t> ColorTextureKeys_;
};