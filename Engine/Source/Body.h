#pragma once

#include <array>

#include "Vector.h"


/**
 * ������Ʈ�� ��ü�� ��Ÿ���� Ŭ�����Դϴ�.
 */
class Body
{
public:
	/**
	 * ������Ʈ�� ��ü �����Դϴ�. 
	 */
	enum class Type
	{
		NONE      = 0,
		CIRCLE    = 1,
		RECTANGLE = 2
	};


public:
	/**
	 * ������Ʈ�� ��ü�� ��Ÿ���� Ŭ������ �⺻ �������Դϴ�.
	 * �̶�, �����ڿ��� �ʱ�ȭ�� �������� �����Ƿ�, ����ϱ� ���� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Body() = default;


	/**
	 * ������Ʈ�� ��ü�� ��Ÿ���� Ŭ������ �������Դϴ�.
	 * �̶�, �� �������� ������Ʈ ��ü ������ RECTANGLE �Դϴ�.
	 * 
	 * @param InCenter - ������Ʈ ��ü�� �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 * @param InHeight - ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 * @param InDirection - ������Ʈ ��ü�� ���� �����Դϴ�.
	 * @param InVelocity - ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	explicit Body(
		const Vec2i& InCenter, 
		const int32_t& InWidth, 
		const int32_t& InHeight,
		const Vec2f& InDirection = Vec2f(0.0f, 0.0f),
		const float& InVelocity = 0.0f
	);
	

	/**
	 * ������Ʈ�� ��ü�� ��Ÿ���� Ŭ������ �������Դϴ�.
	 * �̶�, �� �������� ������Ʈ ��ü ������ CIRCLE �Դϴ�.
	 *
	 * @param InCenter - ������Ʈ ��ü�� �߽� ��ǥ�Դϴ�.
	 * @param InRadius - ������Ʈ ��ü�� ������ �����Դϴ�.
     * @param InDirection - ������Ʈ ��ü�� ���� �����Դϴ�.
	 * @param InVelocity - ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	explicit Body(
		const Vec2i& InCenter, 
		const int32_t& InRadius,
		const Vec2f& InDirection = Vec2f(0.0f, 0.0f),
		const float& InVelocity = 0.0f
	);

	
	/**
	 * ������Ʈ ��ü Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Body(Body&& InInstance) noexcept;


	/**
	 * ������Ʈ ��ü Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Body(const Body& InInstance) noexcept;


	/**
	 * ������Ʈ ��ü Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Body();


	/**
	 * ������Ʈ ��ü Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Body& operator=(Body&& InInstance) noexcept;


	/**
	 * ������Ʈ ��ü Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Body& operator=(const Body& InInstance) noexcept;


	/**
	 * ������Ʈ ��ü�� Ÿ���� ����ϴ�.
	 * 
	 * @return ������Ʈ ��ü�� Ÿ���� ��ȯ�մϴ�.
	 */
	Type GetType() const { return Type_; }


	/**
	 * ������Ʈ ��ü�� Ÿ���� �����մϴ�.
	 * 
	 * @param InType - ������ ������Ʈ ��ü�� Ÿ���Դϴ�.
	 */
	void SetType(const Type& InType) { Type_ = InType; }


	/**
	 * ������Ʈ ��ü�� �߽� ��ǥ�� ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2i GetCenter() const { return Center_; }


	/**
	 * ������Ʈ ��ü�� �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param InCenter - ������ ������Ʈ ��ü�� �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2i& InCenter) { Center_ = InCenter; }


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InWidth - ������ ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	void SetWidth(const int32_t& InWidth) { Width_ = InWidth; }


	/**
	 * ������Ʈ ��ü�� ���� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InHeight - ������ ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	void SetHeight(const int32_t& InHeight) { Height_ = InHeight; }


	/**
	 * ������Ʈ ��ü�� ������ ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ������ ��ȯ�մϴ�.
	 */
	Vec2f GetDirection() const { return Direction_; }


	/**
	 * ������Ʈ ��ü�� ������ �����մϴ�.
	 *
	 * @param InDirection - ������ ������Ʈ ��ü�� �����Դϴ�.
	 */
	void SetDirection(const Vec2f& InDirection) { Direction_ = InDirection; }


	/**
	 * ������Ʈ ��ü�� �ӵ��� ����ϴ�.
	 * �̶�, ������ ������ ������Ƽ�� �����Դϴ�.
	 * 
	 * @return ������Ʈ�� �ӵ��� ��ȯ�մϴ�.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * ������Ʈ ��ü�� �ӵ��� �����մϴ�.
	 * �̶�, ������ ������ ������Ƽ�� �����Դϴ�.
	 * 
	 * @param InVelocity - ������ ������Ʈ ��ü�� �ӵ��Դϴ�.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * �ٸ� ������Ʈ ��ü�� �浹�ϴ��� �˻��մϴ�.
	 * 
	 * @param InBody - �˻縦 ������ �ٸ� ������Ʈ�� ��ü�Դϴ�.
	 * 
	 * @return �ٸ� ������Ʈ�� �浹�Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsCollision(const Body& InBody);


private:
	/**
	 * ��� ���� ������ ����մϴ�.
	 * 
	 * @param InCenter - ��� ������ �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ��� ������ ���� ũ���Դϴ�.
	 * @param InHeight - ��� ������ ���� ũ���Դϴ�.
	 * @param InDirection - ��� ������ �����Դϴ�.
	 */
	static std::array<Vec2i, 4> CalculateBoundingPositions(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const Vec2f& InDirection);


	/**
	 * ���� ��� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 *
	 * @param InPosition - �˻��� ���Դϴ�.
	 * @param InBoundingPositions - ��� ���ڵ��� �����Դϴ�.
	 *
	 * @return ���� ��� ���� ���� ���ԵǸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsIncludePositionInBounding(const Vec2i& InPosition, const std::array<Vec2i, 4>& InBoundingPositions);


private:
	/**
	 * ������Ʈ ��ü�� �����Դϴ�.
	 */
	Type Type_ = Type::NONE;


	/**
	 * ������Ʈ ��ü�� ����� �߽� ��ǥ�Դϴ�.
	 */
	Vec2i Center_;


	/**
	 * ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	int32_t Width_ = 0;


	/**
	 * ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	int32_t Height_ = 0;


	/**
	 * ������Ʈ ��ü�� ����� �̵� �����Դϴ�.
	 */
	Vec2f Direction_;


	/**
	 * ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	float Velocity_ = 0.0f;


	/**
	 * ������Ʈ�� ��� �������Դϴ�.
	 */
	std::array<Vec2i, 4> BoundingPositions;
};