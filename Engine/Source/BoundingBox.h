#pragma once

#include "Vector.h"
#include "Macro.h"

#include <array>


/**
 * ��� ���� Ŭ�����Դϴ�.
 */
class BoundingBox
{
public:
	/**
	 * ��� ���� Ŭ������ �������Դϴ�.
	 * �̶�, ȸ�� ���� ���ʺй��� �������� �մϴ�.
	 * 
	 * @param InCenter - ��� ������ �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ȸ���� ���� �ʾ��� ���� ��� ���� ���� ũ���Դϴ�.
	 * @param InHeight - ȸ���� ���� �ʾ��� ���� ��� ���� ���� ũ���Դϴ�.
	 * @param InRotate - ��� ������ ȸ�� ���Դϴ�.
	 */
	explicit BoundingBox(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate);


	/**
	 * ��� ���� Ŭ������ ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ��ü�Դϴ�. 
	 */
	BoundingBox(BoundingBox&& InInstance) noexcept;


	/**
	 * ��� ���� Ŭ������ ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	BoundingBox(const BoundingBox& InInstance) noexcept;


	/**
	 * ��� ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~BoundingBox();


	/**
	 * ��� ���� Ŭ������ ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ��ü�Դϴ�.
	 * 
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	BoundingBox& operator=(BoundingBox&& InInstance) noexcept;


	/**
	 * ��� ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	BoundingBox& operator=(const BoundingBox& InInstance) noexcept;


	/**
	 * ��� ������ �߽� ��ġ�� ����ϴ�.
	 * 
	 * @return ��� ���� �߽� ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetCenter() const { return Center_; }


	/**
	 * ��� ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return ��� ���� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * ��� ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return ��� ���� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * ��� ������ ȸ�� ���� ����ϴ�.
	 * 
	 * @return ��� ���� ȸ�� ���� ��ȯ�մϴ�.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * ��� ������ �߽� ��ǥ�� �����մϴ�.
	 * 
	 * @param InCenter - ������ ��� ���� �߽� ��ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2i& InCenter);


	/**
	 * ��� ������ ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param InWidth - ������ ��� ���� ���� ũ���Դϴ�.
	 */
	void SetWidth(const int32_t& InWidth);


	/**
	 * ��� ������ ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param InHeight - ������ ��� ���� ���� ũ���Դϴ�.
	 */
	void SetHeight(const int32_t& InHeight);


	/**
	 * ��� ������ ȸ�� ���� �����մϴ�.
	 * 
	 * @param InRotate - ������ ��� ���� ȸ�� ���Դϴ�.
	 */
	void SetRotate(const float& InRotate);


	/**
	 * ��� ������ ���¸� ������Ʈ�մϴ�.
	 */
	void UpdateState();


	/**
	 * ��� ������ �浹 ���θ� Ȯ���մϴ�.
	 * 
	 * @param InBoundingBox - �浹 ���θ� �˻��� �ٸ� ��� �����Դϴ�.
	 * 
	 * @return ����� �Ǵ� ��� ���ڿ� �浹�ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsCollision(const BoundingBox& InBoundingBox);


private:
	/**
	 * ��� ������ �������� ����մϴ�.
	 * 
	 * @param InCenter - ��� ������ �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ȸ���� ���� �ʾ��� ���� ��� ���� ���� ũ���Դϴ�.
	 * @param InHeight - ȸ���� ���� �ʾ��� ���� ��� ���� ���� ũ���Դϴ�.
	 * @param InRotate - ��� ������ ȸ�� ���Դϴ�.
	 */
	static std::array<Vec2i, 4> CalculateBoundingPositions(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate);


	/**
	 * ���� ��� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 * 
	 * @param InPosition - �˻��� ���Դϴ�.
	 * @param InBoundingPositions - ��� ���ڵ��� �����Դϴ�.
	 * 
	 * @return ���� ��� ���� ���� ���ԵǸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool IsIncludePositionInBoundingBox(const Vec2i& InPosition, const std::array<Vec2i, 4>& InBoundingPositions);


private:
	/**
	 * ��� ������ �߽� ��ǥ�Դϴ�.
	 */
	Vec2i Center_;


	/**
	 * ȸ�� ���� �ʾ��� ���� ��� ���� ������ ũ���Դϴ�.
	 */
	int32_t Width_;


	/**
	 * ȸ������ �ʾ��� ���� ��� ���� ������ ũ���Դϴ�.
	 */
	int32_t Height_;


	/**
	 * ��� ������ ȸ�� ���Դϴ�.
	 * �̶�, ȸ�� ���� ���ʺй��� �������� �մϴ�.
	 */
	float Rotate_;


	/**
	 * ��� ������ ������ �Դϴ�.
	 * �̶�, ��� ������ �������� ȸ���� �����Դϴ�.
	 */
	std::array<Vec2i, 4> BoundingPositions_;
};