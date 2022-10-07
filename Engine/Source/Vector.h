#pragma once

#include <cstdint>


/**
 * int32_t Ÿ���� 2���� �����Դϴ�.
 */
struct Vec2i
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec2i() noexcept
		: x(0), y(0) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 2���� ������ ù ��° �����Դϴ�.
	 * @param InY - 2���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec2i(int32_t InX, int32_t InY) noexcept
		: x(InX), y(InY) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 */
	Vec2i(const Vec2i& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 */
	Vec2i(Vec2i&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec2i& operator=(const Vec2i& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec2i& operator=(Vec2i&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;

		return *this;
	}


	/**
	 * int32_t Ÿ�� 2���� ������ ù ��° �����Դϴ�.
	 */
	int32_t x = 0;


	/**
	 * int32_t Ÿ�� 2���� ������ �� ��° �����Դϴ�.
	 */
	int32_t y = 0;
};


/**
 * float Ÿ���� 2���� �����Դϴ�.
 */
struct Vec2f
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec2f() noexcept
		: x(0.0f), y(0.0f) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 2���� ������ ù ��° �����Դϴ�.
	 * @param InY - 2���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec2f(float InX, float InY) noexcept
		: x(InX), y(InY) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 */
	Vec2f(const Vec2f& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 */
	Vec2f(Vec2f&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec2f& operator=(const Vec2f& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 2���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec2f& operator=(Vec2f&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;

		return *this;
	}


	/**
	 * float Ÿ�� 2���� ������ ù ��° �����Դϴ�.
	 */
	float x = 0.0f;


	/**
	 * float Ÿ�� 2���� ������ �� ��° �����Դϴ�.
	 */
	float y = 0.0f;
};


/**
 * int32_t Ÿ���� 3���� �����Դϴ�.
 */
struct Vec3i
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec3i() noexcept
		: x(0), y(0), z(0) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 3���� ������ ù ��° �����Դϴ�.
	 * @param InY - 3���� ������ �� ��° �����Դϴ�.
	 * @param InZ - 3���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec3i(int32_t InX, int32_t InY, int32_t InZ) noexcept
		: x(InX), y(InY), z(InZ) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 */
	Vec3i(const Vec3i& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 */
	Vec3i(Vec3i&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec3i& operator=(const Vec3i& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec3i& operator=(Vec3i&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;

		return *this;
	}


	/**
	 * int32_t Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	int32_t x = 0;


	/**
	 * int32_t Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	int32_t y = 0;


	/**
	 * int32_t Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	int32_t z = 0;
};


/**
 * float Ÿ���� 3���� �����Դϴ�.
 */
struct Vec3f
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec3f() noexcept
		: x(0.0f), y(0.0f), z(0.0f) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 3���� ������ ù ��° �����Դϴ�.
	 * @param InY - 3���� ������ �� ��° �����Դϴ�.
	 * @param InZ - 3���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec3f(float InX, float InY, float InZ) noexcept
		: x(InX), y(InY), z(InZ) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 */
	Vec3f(const Vec3f& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 */
	Vec3f(Vec3f&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec3f& operator=(const Vec3f& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 3���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec3f& operator=(Vec3f&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;

		return *this;
	}


	/**
	 * float Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	float x = 0.0f;


	/**
	 * float Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	float y = 0.0f;


	/**
	 * float Ÿ�� 3���� ������ ù ��° �����Դϴ�.
	 */
	float z = 0.0f;
};


/**
 * int32_t Ÿ���� 4���� �����Դϴ�.
 */
struct Vec4i
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec4i() noexcept
		: x(0), y(0), z(0), w(0) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 4���� ������ ù ��° �����Դϴ�.
	 * @param InY - 4���� ������ �� ��° �����Դϴ�.
	 * @param InZ - 4���� ������ �� ��° �����Դϴ�.
	 * @param InW - 4���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec4i(int32_t InX, int32_t InY, int32_t InZ, int32_t InW) noexcept
		: x(InX), y(InY), z(InZ), w(InW) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 */
	Vec4i(const Vec4i& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z), w(InInstance.w) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 */
	Vec4i(Vec4i&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z), w(InInstance.w) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator=(const Vec4i& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;
		w = InInstance.w;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4i& operator=(Vec4i&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;
		w = InInstance.w;

		return *this;
	}


	/**
	 * int32_t Ÿ�� 4���� ������ ù ��° �����Դϴ�.
	 */
	int32_t x = 0;


	/**
	 * int32_t Ÿ�� 4���� ������ �� ��° �����Դϴ�.
	 */
	int32_t y = 0;


	/**
	 * int32_t Ÿ���� 4���� ������ �� ��° �����Դϴ�.
	 */
	int32_t z = 0;


	/**
	 * int32_t Ÿ���� 4���� ������ �� ��° �����Դϴ�.
	 */
	int32_t w = 0;
};


/**
 * float Ÿ���� 4���� �����Դϴ�.
 */
struct Vec4f
{
	/**
	 * �������Դϴ�.
	 */
	explicit Vec4f() noexcept
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}


	/**
	 * �������Դϴ�.
	 *
	 * @param InX - 4���� ������ ù ��° �����Դϴ�.
	 * @param InY - 4���� ������ �� ��° �����Դϴ�.
	 * @param InZ - 4���� ������ �� ��° �����Դϴ�.
	 * @param InW - 4���� ������ �� ��° �����Դϴ�.
	 */
	explicit Vec4f(float InX, float InY, float InZ, float InW) noexcept
		: x(InX), y(InY), z(InZ), w(InW) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 */
	Vec4f(const Vec4f& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z), w(InInstance.w) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 */
	Vec4f(Vec4f&& InInstance) noexcept
		: x(InInstance.x), y(InInstance.y), z(InInstance.z), w(InInstance.w) {}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator=(const Vec4f& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;
		w = InInstance.w;

		return *this;
	}


	/**
	 * ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ 4���� �����Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vec4f& operator=(Vec4f&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		x = InInstance.x;
		y = InInstance.y;
		z = InInstance.z;
		w = InInstance.w;

		return *this;
	}


	/**
	 * float Ÿ�� 4���� ������ ù ��° �����Դϴ�.
	 */
	float x = 0.0f;


	/**
	 * float Ÿ�� 4���� ������ �� ��° �����Դϴ�.
	 */
	float y = 0.0f;


	/**
	 * float Ÿ���� 4���� ������ �� ��° �����Դϴ�.
	 */
	float z = 0.0f;


	/**
	 * float Ÿ���� 4���� ������ �� ��° �����Դϴ�.
	 */
	float w = 0.0f;
};


/**
 * Vec2i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec2i operator+(const Vec2i& InLhs, const Vec2i& InRhs);


/**
 * Vec2i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec2i operator-(const Vec2i& InLhs, const Vec2i& InRhs);


/**
 * Vec2i�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec2i operator*(const Vec2i& InLhs, const Vec2i& InRhs);


/**
 * Vec2i�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec2i operator*(const Vec2i& InLhs, const int32_t& InScale);


/**
 * Vec2i�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec2i operator*(const int32_t& InScale, const Vec2i& InRhs);


/**
 * Vec2f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec2f operator+(const Vec2f& InLhs, const Vec2f& InRhs);


/**
 * Vec2f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec2f operator-(const Vec2f& InLhs, const Vec2f& InRhs);


/**
 * Vec2f�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec2f operator*(const Vec2f& InLhs, const Vec2f& InRhs);


/**
 * Vec2f�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */

Vec2f operator*(const Vec2f& InLhs, const float& InScale);


/**
 * Vec2f�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec2f operator*(const float& InScale, const Vec2f& InRhs);


/**
 * Vec3i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec3i operator+(const Vec3i& InLhs, const Vec3i& InRhs);


/**
 * Vec3i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec3i operator-(const Vec3i& InLhs, const Vec3i& InRhs);


/**
 * Vec3i�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec3i operator*(const Vec3i& InLhs, const Vec3i& InRhs);


/**
 * Vec3i�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec3i operator*(const Vec3i& InLhs, const int32_t& InScale);


/**
 * Vec3i�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */

Vec3i operator*(const int32_t& InScale, const Vec3i& InRhs);


/**
 * Vec3f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec3f operator+(const Vec3f& InLhs, const Vec3f& InRhs);


/**
 * Vec3f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec3f operator-(const Vec3f& InLhs, const Vec3f& InRhs);


/**
 * Vec3f�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec3f operator*(const Vec3f& InLhs, const Vec3f& InRhs);


/**
 * Vec3f�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec3f operator*(const Vec3f& InLhs, const float& InScale);


/**
 * Vec3f�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec3f operator*(const float& InScale, const Vec3f& InRhs);


/**
 * Vec4i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec4i operator+(const Vec4i& InLhs, const Vec4i& InRhs);


/**
 * Vec4i�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec4i operator-(const Vec4i& InLhs, const Vec4i& InRhs);


/**
 * Vec4i�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec4i operator*(const Vec4i& InLhs, const Vec4i& InRhs);


/**
 * Vec4i�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec4i operator*(const Vec4i& InLhs, const int32_t& InScale);


/**
 * Vec4i�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec4i operator*(const int32_t& InScale, const Vec4i& InRhs);


/**
 * Vec4f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec4f operator+(const Vec4f& InLhs, const Vec4f& InRhs);


/**
 * Vec4f�� ���� �����Դϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ �� ����� ��ȯ�մϴ�.
 */
Vec4f operator-(const Vec4f& InLhs, const Vec4f& InRhs);


/**
 * Vec4f�� ���� �����Դϴ�.
 * �̶�, �� ������ ������ �� ���Ҹ� ���ϴ� �����Դϴ�.
 * ���� ������ ���, Dot �Լ��� ���� ��밡���մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ������ ������ ���� ����� ��ȯ�մϴ�.
 */
Vec4f operator*(const Vec4f& InLhs, const Vec4f& InRhs);


/**
 * Vec4f�� Scale �����Դϴ�.
 *
 * @param InLhs - Scale ������ ������ �����Դϴ�.
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec4f operator*(const Vec4f& InLhs, const float& InScale);


/**
 * Vec4f�� Scale �����Դϴ�.
 *
 * @param InScale - ������ ���ҿ� ũ�� ��ȯ�� ������ ���Դϴ�.
 * @param InRhs - Scale ������ ������ �����Դϴ�.
 *
 * @return  �� ���� ������ ���ҿ� ũ�� ��ȯ�� ������ ���͸� ��ȯ�մϴ�.
 */
Vec4f operator*(const float& InScale, const Vec4f& InRhs);


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static int32_t Dot(const Vec2i& InLhs, const Vec2i& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y);
}


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static float Dot(const Vec2f& InLhs, const Vec2f& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y);
}


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static int32_t Dot(const Vec3i& InLhs, const Vec3i& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y) + (InLhs.z * InRhs.z);
}


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static float Dot(const Vec3f& InLhs, const Vec3f& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y) + (InLhs.z * InRhs.z);
}


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static int32_t Dot(const Vec4i& InLhs, const Vec4i& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y) + (InLhs.z * InRhs.z) + (InLhs.w * InRhs.w);
}


/**
 * �� ������ ���� ������ �����մϴ�.
 *
 * @param InLhs - ���� ������ ������ �� ���� �ǿ������Դϴ�.
 * @param InRhs - ���� ������ ������ �� ������ �ǿ������Դϴ�.
 *
 * @return  �� ���� ���� ����� ��ȯ�մϴ�.
 */
inline static float Dot(const Vec4f& InLhs, const Vec4f& InRhs)
{
	return (InLhs.x * InRhs.x) + (InLhs.y * InRhs.y) + (InLhs.z * InRhs.z) + (InLhs.w * InRhs.w);
}