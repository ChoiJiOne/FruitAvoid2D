#pragma once

#include <array>

#include "Vector.h"


/**
 * 오브젝트의 몸체를 나타내는 클래스입니다.
 */
class Body
{
public:
	/**
	 * 오브젝트의 몸체 형식입니다. 
	 */
	enum class Type
	{
		NONE      = 0,
		CIRCLE    = 1,
		RECTANGLE = 2
	};


public:
	/**
	 * 오브젝트의 몸체를 나타내는 클래스의 기본 생성자입니다.
	 * 이때, 생성자에서 초기화를 수행하지 않으므로, 사용하기 전에 적절한 초기화를 수행해야 합니다.
	 */
	Body() = default;


	/**
	 * 오브젝트의 몸체를 나타내는 클래스의 생성자입니다.
	 * 이때, 이 생성자의 오브젝트 몸체 형식은 RECTANGLE 입니다.
	 * 
	 * @param InCenter - 오브젝트 몸체의 중심 좌표입니다.
	 * @param InWidth - 오브젝트 몸체의 가로 크기입니다.
	 * @param InHeight - 오브젝트 몸체의 세로 크기입니다.
	 * @param InDirection - 오브젝트 몸체의 진행 방향입니다.
	 * @param InVelocity - 오브젝트 몸체의 속력입니다.
	 */
	explicit Body(
		const Vec2i& InCenter, 
		const int32_t& InWidth, 
		const int32_t& InHeight,
		const Vec2f& InDirection = Vec2f(0.0f, 0.0f),
		const float& InVelocity = 0.0f
	);
	

	/**
	 * 오브젝트의 몸체를 나타내는 클래스의 생성자입니다.
	 * 이때, 이 생성자의 오브젝트 몸체 형식은 CIRCLE 입니다.
	 *
	 * @param InCenter - 오브젝트 몸체의 중심 좌표입니다.
	 * @param InRadius - 오브젝트 몸체의 반지름 길이입니다.
     * @param InDirection - 오브젝트 몸체의 진행 방향입니다.
	 * @param InVelocity - 오브젝트 몸체의 속력입니다.
	 */
	explicit Body(
		const Vec2i& InCenter, 
		const int32_t& InRadius,
		const Vec2f& InDirection = Vec2f(0.0f, 0.0f),
		const float& InVelocity = 0.0f
	);

	
	/**
	 * 오브젝트 몸체 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Body(Body&& InInstance) noexcept;


	/**
	 * 오브젝트 몸체 클래스의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	Body(const Body& InInstance) noexcept;


	/**
	 * 오브젝트 몸체 클래스의 가상 소멸자입니다.
	 */
	virtual ~Body();


	/**
	 * 오브젝트 몸체 클래스의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Body& operator=(Body&& InInstance) noexcept;


	/**
	 * 오브젝트 몸체 클래스의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	Body& operator=(const Body& InInstance) noexcept;


	/**
	 * 오브젝트 몸체의 타입을 얻습니다.
	 * 
	 * @return 오브젝트 몸체의 타입을 반환합니다.
	 */
	Type GetType() const { return Type_; }


	/**
	 * 오브젝트 몸체의 타입을 설정합니다.
	 * 
	 * @param InType - 설정할 오브젝트 몸체의 타입입니다.
	 */
	void SetType(const Type& InType) { Type_ = InType; }


	/**
	 * 오브젝트 몸체의 중심 좌표를 얻습니다.
	 *
	 * @return 오브젝트 몸체의 중심 좌표를 반환합니다.
	 */
	Vec2i GetCenter() const { return Center_; }


	/**
	 * 오브젝트 몸체의 중심 좌표를 설정합니다.
	 *
	 * @param InCenter - 설정할 오브젝트 몸체의 중심좌표입니다.
	 */
	void SetCenter(const Vec2i& InCenter) { Center_ = InCenter; }


	/**
	 * 오브젝트 몸체의 가로 크기를 얻습니다.
	 *
	 * @return 오브젝트 몸체의 가로 크기를 반환합니다.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * 오브젝트 몸체의 가로 크기를 설정합니다.
	 *
	 * @param InWidth - 설정할 오브젝트 몸체의 가로 크기입니다.
	 */
	void SetWidth(const int32_t& InWidth) { Width_ = InWidth; }


	/**
	 * 오브젝트 몸체의 가로 세로 크기를 얻습니다.
	 *
	 * @return 오브젝트 몸체의 세로 크기를 반환합니다.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * 오브젝트 몸체의 세로 크기를 설정합니다.
	 *
	 * @param InHeight - 설정할 오브젝트 몸체의 세로 크기입니다.
	 */
	void SetHeight(const int32_t& InHeight) { Height_ = InHeight; }


	/**
	 * 오브젝트 몸체의 방향을 얻습니다.
	 *
	 * @return 오브젝트 몸체의 방향을 반환합니다.
	 */
	Vec2f GetDirection() const { return Direction_; }


	/**
	 * 오브젝트 몸체의 방향을 설정합니다.
	 *
	 * @param InDirection - 설정할 오브젝트 몸체의 방향입니다.
	 */
	void SetDirection(const Vec2f& InDirection) { Direction_ = InDirection; }


	/**
	 * 오브젝트 몸체의 속도를 얻습니다.
	 * 이때, 방향은 내부의 프로퍼티를 기준입니다.
	 * 
	 * @return 오브젝트의 속도를 반환합니다.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * 오브젝트 몸체의 속도를 설정합니다.
	 * 이때, 방향은 내부의 프로퍼티를 기준입니다.
	 * 
	 * @param InVelocity - 설정할 오브젝트 몸체의 속도입니다.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * 다른 오브젝트 몸체와 충돌하는지 검사합니다.
	 * 
	 * @param InBody - 검사를 수행할 다른 오브젝트의 몸체입니다.
	 * 
	 * @return 다른 오브젝트와 충돌한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsCollision(const Body& InBody);


private:
	/**
	 * 경계 영역 점들을 계산합니다.
	 * 
	 * @param InCenter - 경계 영역의 중심 좌표입니다.
	 * @param InWidth - 경계 영역의 가로 크기입니다.
	 * @param InHeight - 경계 영역의 세로 크기입니다.
	 * @param InDirection - 경계 영역의 방향입니다.
	 */
	static std::array<Vec2i, 4> CalculateBoundingPositions(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const Vec2f& InDirection);


	/**
	 * 점이 경계 영역 내에 포함되는지 확인합니다.
	 *
	 * @param InPosition - 검사할 점입니다.
	 * @param InBoundingPositions - 경계 상자들의 끝점입니다.
	 *
	 * @return 점이 경계 상자 내에 포함되면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsIncludePositionInBounding(const Vec2i& InPosition, const std::array<Vec2i, 4>& InBoundingPositions);


private:
	/**
	 * 오브젝트 몸체의 형식입니다.
	 */
	Type Type_ = Type::NONE;


	/**
	 * 오브젝트 몸체의 월드상 중심 좌표입니다.
	 */
	Vec2i Center_;


	/**
	 * 오브젝트 몸체의 가로 크기입니다.
	 */
	int32_t Width_ = 0;


	/**
	 * 오브젝트 몸체의 세로 크기입니다.
	 */
	int32_t Height_ = 0;


	/**
	 * 오브젝트 몸체의 월드상 이동 방향입니다.
	 */
	Vec2f Direction_;


	/**
	 * 오브젝트 몸체의 속력입니다.
	 */
	float Velocity_ = 0.0f;


	/**
	 * 오브젝트의 경계 영역점입니다.
	 */
	std::array<Vec2i, 4> BoundingPositions;
};