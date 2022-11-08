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
	 * @param InRotate - ������Ʈ ��ü�� ȸ�� �� �Դϴ�.
	 * @param InVelocity - ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	explicit Body(
		const Vec2f& InCenter, 
		const float& InWidth, 
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f
	);
	

	/**
	 * ������Ʈ�� ��ü�� ��Ÿ���� Ŭ������ �������Դϴ�.
	 * �̶�, �� �������� ������Ʈ ��ü ������ CIRCLE �Դϴ�.
	 *
	 * @param InCenter - ������Ʈ ��ü�� �߽� ��ǥ�Դϴ�.
	 * @param InRadius - ������Ʈ ��ü�� ������ �����Դϴ�.
     * @param InRotate - ������Ʈ ��ü�� ȸ�� �� �Դϴ�.
	 * @param InVelocity - ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	explicit Body(
		const Vec2f& InCenter, 
		const float& InRadius,
		const float& InRotate = 0.0f,
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
	Vec2f GetCenter() const { return Center_; }


	/**
	 * ������Ʈ ��ü�� �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param InCenter - ������ ������Ʈ ��ü�� �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& InCenter);


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InWidth - ������ ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& InWidth);


	/**
	 * ������Ʈ ��ü�� ���� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * ������Ʈ ��ü�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InHeight - ������ ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& InHeight);


	/**
	 * ������Ʈ ��ü�� ȸ�� ���� ����ϴ�.
	 *
	 * @return ������Ʈ ��ü�� ȸ�� ���� ��ȯ�մϴ�.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * ������Ʈ ��ü�� ȸ�� ���� �����մϴ�.
	 *
	 * @param InRotate - ������ ������Ʈ ��ü�� ȸ�� ���� �����Դϴ�.
	 */
	void SetRotate(const float& InRotate);


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
	 * ������Ʈ ��ü�� ��� �������� ����ϴ�.
	 * 
	 * @return ������Ʈ ��ü�� ��� �������� ��ȯ�մϴ�.
	 */
	const std::array<Vec2f, 4>& GetBoundingPositions() const { return BoundingPositions_; }


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
	 * @param InRotate - ��� ������ ȸ�� ���Դϴ�.
	 */
	static std::array<Vec2f, 4> CalculateBoundingPositions(const Vec2f& InCenter, const float& InWidth, const float& InHeight, const float& InRotate);


	/**
	 * ���� ��� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 *
	 * @param InPosition - �˻��� ���Դϴ�.
	 * @param InBoundingPositions - ��� ���ڵ��� �����Դϴ�.
	 *
	 * @return ���� ��� ���� ���� ���ԵǸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsIncludePositionInBounding(const Vec2f& InPosition, const std::array<Vec2f, 4>& InBoundingPositions);


	/**
	 * ���� Ÿ���� �ٵ�� ���簢�� Ÿ���� �ٵ� �浹 �˻縦 �����մϴ�.
	 * 
	 * @param InCircleBody - ���� Ÿ���� �ٵ��Դϴ�.
	 * @param InRectangleBody - ���簢�� Ÿ���� �ٵ��Դϴ�.
	 * 
	 * @return �� �ٵ� �浹�ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool IsCollisionCircleAndRectangle(const Body& InCircleBody, const Body& InRectangleBody);


	/**
	 * ���� Ÿ���� �ٵ�� ���� Ÿ���� �ٵ� �浹 �˻縦 �����մϴ�.
	 * 
	 * @param InCircleBody - ���� Ÿ���� �ٵ��Դϴ�.
	 * @param InOtherCircleBody - �� �ٸ� ���� Ÿ���� �ٵ��Դϴ�.
	 *
	 * @return �� �ٵ� �浹�ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool IsColiisionCircleAndCircle(const Body& InCircleBody, const Body& InOtherCircleBody);


	/**
	 * ���簢�� Ÿ���� �ٵ�� ���簢�� Ÿ���� �ٵ� �浹 �˻縦 �����մϴ�.
	 * 
	 * @param InRectangleBody - ���簢�� Ÿ���� �ٵ��Դϴ�.
	 * @param InOtherRectangleBody - �� �ٸ� ���簢�� Ÿ���� �ٵ��Դϴ�.
	 *
	 * @return �� �ٵ� �浹�ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool IsCollisionRectangleAndRectangle(const Body& InRectangleBody, const Body& InOtherRectangleBody);


private:
	/**
	 * ������Ʈ ��ü�� �����Դϴ�.
	 */
	Type Type_ = Type::NONE;


	/**
	 * ������Ʈ ��ü�� ����� �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	float Width_ = 0;


	/**
	 * ������Ʈ ��ü�� ���� ũ���Դϴ�.
	 */
	float Height_ = 0;


	/**
	 * ������Ʈ ��ü�� ����� ȸ�� �����Դϴ�.
	 */
	float Rotate_ = 0.0f;


	/**
	 * ������Ʈ ��ü�� �ӷ��Դϴ�.
	 */
	float Velocity_ = 0.0f;


	/**
	 * ������Ʈ�� ��� �������Դϴ�.
	 */
	std::array<Vec2f, 4> BoundingPositions_;
};