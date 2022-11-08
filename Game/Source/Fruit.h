#pragma once

#include "GameObject.h"

#include <unordered_map>


/**
 * 과일 클래스 입니다.
 */
class Fruit : public GameObject
{
public:
	/**
	 * 과일의 타입입니다.
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
	 * 과일 클래스의 생성자입니다.
	 * 이때, 과일의 떨어지는 속도는 초당 픽셀 이동값으로 계산됩니다.
	 *
	 * @param InWorld - 과일이 위치할 월드입니다.
	 * @param InPosition - 과일의 화면상 위치입니다.
	 * @param InWidth - 과일의 가로 크기입니다.
	 * @param InHeight - 과일의 세로 크기입니다.
	 * @param InVelocity - 과일의 떨어지는 속도입니다.
	 * @param InType - 과일의 종류입니다.
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
	 * 과일의 가상 소멸자입니다.
	 */
	virtual ~Fruit();


	/**
	 * 과일의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Fruit);


	/**
	 * 과일을 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 과일을 화면에 그립니다.
	 * 
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) override;


private:
	/**
	 * 과일의 타입 입니다.
	 */
	EType Type_;


	/**
	 * 과일 타입에 대응하는 텍스처 키 값입니다.
	 */
	static std::unordered_map<EType, std::size_t> FruitTextureKeys_;
};