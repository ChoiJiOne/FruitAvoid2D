#pragma once

#include "Vector.h"
#include "Macro.h"

#include <array>


/**
 * 경계 상자 클래스입니다.
 */
class BoundingBox
{
public:
	/**
	 * 경계 상자 클래스의 생성자입니다.
	 * 이때, 회전 각은 육십분법을 기준으로 합니다.
	 * 
	 * @param InCenter - 경계 상자의 중심 좌표입니다.
	 * @param InWidth - 회전을 하지 않았을 때의 경계 상자 가로 크기입니다.
	 * @param InHeight - 회전을 하지 않았을 때의 경계 상자 세로 크기입니다.
	 * @param InRotate - 경계 상자의 회전 각입니다.
	 */
	explicit BoundingBox(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate);


	/**
	 * 경계 상자 클래스의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 객체입니다. 
	 */
	BoundingBox(BoundingBox&& InInstance) noexcept;


	/**
	 * 경계 상자 클래스의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 객체입니다.
	 */
	BoundingBox(const BoundingBox& InInstance) noexcept;


	/**
	 * 경계 상자 클래스의 가상 소멸자입니다.
	 */
	virtual ~BoundingBox();


	/**
	 * 경계 상자 클래스의 대입 연산자입니다.
	 * 
	 * @param InInstance - 복사할 객체입니다.
	 * 
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	BoundingBox& operator=(BoundingBox&& InInstance) noexcept;


	/**
	 * 경계 상자 클래스의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	BoundingBox& operator=(const BoundingBox& InInstance) noexcept;


	/**
	 * 경계 상자의 중심 위치를 얻습니다.
	 * 
	 * @return 경계 상자 중심 위치를 반환합니다.
	 */
	Vec2i GetCenter() const { return Center_; }


	/**
	 * 경계 상자의 가로 크기를 얻습니다.
	 * 
	 * @return 경계 상자 가로 크기를 반환합니다.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * 경계 상자의 세로 크기를 얻습니다.
	 * 
	 * @return 경계 상자 세로 크기를 반환합니다.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * 경계 상자의 회전 각을 얻습니다.
	 * 
	 * @return 경계 상자 회전 각을 반환합니다.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * 경계 상자의 중심 좌표를 변경합니다.
	 * 
	 * @param InCenter - 변경할 경계 상자 중심 좌표입니다.
	 */
	void SetCenter(const Vec2i& InCenter);


	/**
	 * 경계 상자의 가로 크기를 변경합니다.
	 * 
	 * @param InWidth - 변경할 경계 상자 가로 크기입니다.
	 */
	void SetWidth(const int32_t& InWidth);


	/**
	 * 경계 상자의 세로 크기를 변경합니다.
	 * 
	 * @param InHeight - 변경할 경계 상자 세로 크기입니다.
	 */
	void SetHeight(const int32_t& InHeight);


	/**
	 * 경계 상자의 회전 각을 변경합니다.
	 * 
	 * @param InRotate - 변경할 경계 상자 회전 각입니다.
	 */
	void SetRotate(const float& InRotate);


	/**
	 * 경계 상자의 상태를 업데이트합니다.
	 */
	void UpdateState();


	/**
	 * 경계 상자의 충돌 여부를 확인합니다.
	 * 
	 * @param InBoundingBox - 충돌 여부를 검사할 다른 경계 상자입니다.
	 * 
	 * @return 대상이 되는 경계 상자와 충돌하면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsCollision(const BoundingBox& InBoundingBox);


private:
	/**
	 * 경계 상자의 끝점들을 계산합니다.
	 * 
	 * @param InCenter - 경계 상자의 중심 좌표입니다.
	 * @param InWidth - 회전을 하지 않았을 때의 경계 상자 가로 크기입니다.
	 * @param InHeight - 회전을 하지 않았을 때의 경계 상자 세로 크기입니다.
	 * @param InRotate - 경계 상자의 회전 각입니다.
	 */
	static std::array<Vec2i, 4> CalculateBoundingPositions(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate);


	/**
	 * 점이 경계 상자 내에 포함되는지 확인합니다.
	 * 
	 * @param InPosition - 검사할 점입니다.
	 * @param InBoundingPositions - 경계 상자들의 끝점입니다.
	 * 
	 * @return 점이 경계 상자 내에 포함되면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool IsIncludePositionInBoundingBox(const Vec2i& InPosition, const std::array<Vec2i, 4>& InBoundingPositions);


private:
	/**
	 * 경계 상자의 중심 좌표입니다.
	 */
	Vec2i Center_;


	/**
	 * 회전 하지 않았을 때의 경계 상자 가로의 크기입니다.
	 */
	int32_t Width_;


	/**
	 * 회전하지 않았을 때의 경계 상자 세로의 크기입니다.
	 */
	int32_t Height_;


	/**
	 * 경계 상자의 회전 각입니다.
	 * 이때, 회전 각은 육십분법을 기준으로 합니다.
	 */
	float Rotate_;


	/**
	 * 경계 상자의 끝점들 입니다.
	 * 이때, 경계 상자의 끝점들은 회전된 상태입니다.
	 */
	std::array<Vec2i, 4> BoundingPositions_;
};