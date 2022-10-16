#pragma once

#include "GameObject.h"
#include "BoundingBox.h"

#include <unordered_map>


/**
 * ���� Ŭ���� �Դϴ�.
 */
class Fruit : public GameObject, public BoundingBox
{
public:
	/**
	 * ������ Ÿ���Դϴ�.
	 */
	enum class EType
	{
		None = 0,
		Banana = 1,
		BlackBerryDark = 2,
		BlackBerryLight = 3,
		BlackCherry = 4,
		Coconut = 5,
		GreenApple = 6,
		GreenGrape = 7,
		Lemon = 8,
		Lime = 9,
		Orange = 10,
		Peach = 11,
		Pear = 12,
		Plum = 13,
		Raspberry = 14,
		RedApple = 15,
		RedCherry = 16,
		RedGrape = 17,
		StarFruit = 18,
		Strawberry = 19,
		WaterMelon = 20
	};


public:
	/**
	 * ���� Ŭ������ �������Դϴ�.
	 * �̶�, ������ �������� �ӵ��� �ʴ� �ȼ� �̵������� ���˴ϴ�.
	 *
	 * @param InPosition - ������ ȭ��� ��ġ�Դϴ�.
	 * @param InSpeed - ������ �������� �ӵ��Դϴ�.
	 * @param InWidth - ������ ���� ũ���Դϴ�.
	 * @param InHeight - ������ ���� ũ���Դϴ�.
	 * @param InType - ������ �����Դϴ�.
	 */
	explicit Fruit(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EType& InType);


	/**
	 * ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Fruit(Fruit&& InInstance) noexcept;


	/**
	 * ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Fruit(const Fruit& InInstance) noexcept;


	/**
	 * ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Fruit();


	/**
	 * ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Fruit& operator=(Fruit&& InInstance) noexcept;


	/**
	 * ���� Ŭ������ ���� ������ �Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Fruit& operator=(const Fruit& InInstance) noexcept;


	/**
	 * ���� �÷��̾� ���¸� ������Ʈ�մϴ�.
	 * 
	 * @param InInput - ���� ������ �Է� �ý����Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(InputSystem& InInput, float InDeltaTime) override;


	/**
	 * ���� �÷��̾ ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InRenderer - ���� ������ ���� �ý����Դϴ�.
	 *
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render(RenderSystem& InRenderer) override;


	/**
	 * ������ ������ �����մϴ�.
	 * �̶�, ������ ������ ���� ���� ũ��� ��ġ�մϴ�.
	 *
	 * @param InYPosition - ������ Y��ǥ ���Դϴ�.
	 *
	 * @return �����Ƿ� ������ ���� ��ü�� ��ȯ�մϴ�.
	 */
	static Fruit GenerateRandomFruit(const int32_t& InYPosition);


private:
	/**
	 * ������ ���� �ӵ��Դϴ�.
	 * �̶�, �ӵ� ��� ����� �ʴ� �̵��� �ȼ����Դϴ�.
	 */
	float Speed_ = 0.0f;


	/**
	 * ������ Ÿ�� �Դϴ�.
	 */
	EType Type_;


	/**
	 * ���� Ÿ�Կ� �����ϴ� �ؽ�ó Ű ���Դϴ�.
	 */
	static std::unordered_map<EType, std::size_t> FruitTextureKeys_;
};