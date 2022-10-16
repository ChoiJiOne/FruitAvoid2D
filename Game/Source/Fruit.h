#pragma once

#include "GameObject.h"
#include "BoundingBox.h"

#include <unordered_map>


/**
 * 과일 클래스 입니다.
 */
class Fruit : public GameObject, public BoundingBox
{
public:
	/**
	 * 과일의 타입입니다.
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
	 * 과일 클래스의 생성자입니다.
	 * 이때, 과일의 떨어지는 속도는 초당 픽셀 이동값으로 계산됩니다.
	 *
	 * @param InPosition - 과일의 화면상 위치입니다.
	 * @param InSpeed - 과일의 떨어지는 속도입니다.
	 * @param InWidth - 과일의 가로 크기입니다.
	 * @param InHeight - 과일의 세로 크기입니다.
	 * @param InType - 과일의 종류입니다.
	 */
	explicit Fruit(const Vec2i& InPosition, const float& InSpeed, const int32_t& InWidth, const int32_t& InHeight, const EType& InType);


	/**
	 * 과일 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Fruit(Fruit&& InInstance) noexcept;


	/**
	 * 과일 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Fruit(const Fruit& InInstance) noexcept;


	/**
	 * 과일의 가상 소멸자입니다.
	 */
	virtual ~Fruit();


	/**
	 * 과일 클래스의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Fruit& operator=(Fruit&& InInstance) noexcept;


	/**
	 * 과일 클래스의 대입 연산자 입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Fruit& operator=(const Fruit& InInstance) noexcept;


	/**
	 * 게임 플레이어 상태를 업데이트합니다.
	 * 
	 * @param InInput - 게임 엔진의 입력 시스템입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(InputSystem& InInput, float InDeltaTime) override;


	/**
	 * 게임 플레이어를 화면에 그립니다.
	 * 
	 * @param InRenderer - 게임 엔진의 렌더 시스템입니다.
	 *
	 * @throws 렌더링에 실패하면 C++ 표준 예외를 던집니다.
	 */
	virtual void Render(RenderSystem& InRenderer) override;


	/**
	 * 임의의 과일을 생성합니다.
	 * 이때, 생성된 과일의 가로 세로 크기는 일치합니다.
	 *
	 * @param InYPosition - 과일의 Y좌표 값입니다.
	 *
	 * @return 임의의로 생성한 과일 객체를 반환합니다.
	 */
	static Fruit GenerateRandomFruit(const int32_t& InYPosition);


private:
	/**
	 * 과일의 낙하 속도입니다.
	 * 이때, 속도 계산 방식은 초당 이동할 픽셀값입니다.
	 */
	float Speed_ = 0.0f;


	/**
	 * 과일의 타입 입니다.
	 */
	EType Type_;


	/**
	 * 과일 타입에 대응하는 텍스처 키 값입니다.
	 */
	static std::unordered_map<EType, std::size_t> FruitTextureKeys_;
};