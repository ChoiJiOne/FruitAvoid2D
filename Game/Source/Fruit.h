#pragma once

#include "GameObject.h"

#include <unordered_map>


/**
 * ���� Ŭ���� �Դϴ�.
 */
class Fruit : public GameObject
{
public:
	/**
	 * ������ Ÿ���Դϴ�.
	 */
	enum class EType
	{
		None            = 0,
		Banana          = 1,
		BlackBerryDark  = 2,
		BlackBerryLight = 3,
		BlackCherry     = 4,
		Coconut         = 5,
		GreenApple      = 6,
		GreenGrape      = 7,
		Lemon           = 8,
		Lime            = 9,
		Orange          = 10,
		Peach           = 11,
		Pear            = 12,
		Plum            = 13,
		Raspberry       = 14,
		RedApple        = 15,
		RedCherry       = 16,
		RedGrape        = 17,
		StarFruit       = 18,
		Strawberry      = 19,
		WaterMelon      = 20
	};


public:
	/**
	 * ���� Ŭ������ �������Դϴ�.
	 * �̶�, ������ �������� �ӵ��� �ʴ� �ȼ� �̵������� ���˴ϴ�.
	 *
	 * @param InWorld - ������ ��ġ�� �����Դϴ�.
	 * @param InPosition - ������ ȭ��� ��ġ�Դϴ�.
	 * @param InWidth - ������ ���� ũ���Դϴ�.
	 * @param InHeight - ������ ���� ũ���Դϴ�.
	 * @param InVelocity - ������ �������� �ӵ��Դϴ�.
	 * @param InType - ������ �����Դϴ�.
	 */
	explicit Fruit(
		World* InWorld, 
		const Vec2f& InPosition, 
		const float& InWidth, 
		const float& InHeight,
		const float& InVelocity,
		const EType& InType
	);


	/**
	 * ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Fruit();


	/**
	 * ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Fruit);


	/**
	 * ������ ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ������ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InGraphics - ������ ������ ó�� �ν��Ͻ��Դϴ�.
	 */
	virtual void Render(Graphics& InGraphics) override;


private:
	/**
	 * ������ Ÿ�� �Դϴ�.
	 */
	EType Type_;


	/**
	 * ���� Ÿ�Կ� �����ϴ� �ؽ�ó Ű ���Դϴ�.
	 */
	static std::unordered_map<EType, std::size_t> FruitTextureKeys_;
};