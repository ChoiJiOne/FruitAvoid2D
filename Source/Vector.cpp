#include "Vector.h"

Vec2i operator+(const Vec2i& InLhs, const Vec2i& InRhs)
{
	return Vec2i(InLhs.x + InRhs.x, InLhs.y + InRhs.y);
}

Vec2i operator-(const Vec2i& InLhs, const Vec2i& InRhs)
{
	return Vec2i(InLhs.x - InRhs.x, InLhs.y - InRhs.y);
}

Vec2i operator*(const Vec2i& InLhs, const Vec2i& InRhs)
{
	return Vec2i(InLhs.x * InRhs.x, InLhs.y * InRhs.y);
}

Vec2i operator*(const Vec2i& InLhs, const int32_t& InScale)
{
	return Vec2i(InLhs.x * InScale, InLhs.y * InScale);
}

Vec2i operator*(const int32_t& InScale, const Vec2i& InRhs)
{
	return Vec2i(InScale * InRhs.x, InScale * InRhs.y);
}

Vec2f operator+(const Vec2f& InLhs, const Vec2f& InRhs)
{
	return Vec2f(InLhs.x + InRhs.x, InLhs.y + InRhs.y);
}

Vec2f operator-(const Vec2f& InLhs, const Vec2f& InRhs)
{
	return Vec2f(InLhs.x - InRhs.x, InLhs.y - InRhs.y);
}

Vec2f operator*(const Vec2f& InLhs, const Vec2f& InRhs)
{
	return Vec2f(InLhs.x * InRhs.x, InLhs.y * InRhs.y);
}

Vec2f operator*(const Vec2f& InLhs, const float& InScale)
{
	return Vec2f(InLhs.x * InScale, InLhs.y * InScale);
}

Vec2f operator*(const float& InScale, const Vec2f& InRhs)
{
	return Vec2f(InScale * InRhs.x, InScale * InRhs.y);
}

Vec3i operator+(const Vec3i& InLhs, const Vec3i& InRhs)
{
	return Vec3i(InLhs.x + InRhs.x, InLhs.y + InRhs.y, InLhs.z + InRhs.z);
}

Vec3i operator-(const Vec3i& InLhs, const Vec3i& InRhs)
{
	return Vec3i(InLhs.x - InRhs.x, InLhs.y - InRhs.y, InLhs.z - InRhs.z);
}

Vec3i operator*(const Vec3i& InLhs, const Vec3i& InRhs)
{
	return Vec3i(InLhs.x * InRhs.x, InLhs.y * InRhs.y, InLhs.z * InRhs.z);
}

Vec3i operator*(const Vec3i& InLhs, const int32_t& InScale)
{
	return Vec3i(InLhs.x * InScale, InLhs.y * InScale, InLhs.z * InScale);
}

Vec3i operator*(const int32_t& InScale, const Vec3i& InRhs)
{
	return Vec3i(InScale * InRhs.x, InScale * InRhs.y, InScale * InRhs.z);
}

Vec3f operator+(const Vec3f& InLhs, const Vec3f& InRhs)
{
	return Vec3f(InLhs.x + InRhs.x, InLhs.y + InRhs.y, InLhs.z + InRhs.z);
}

Vec3f operator-(const Vec3f& InLhs, const Vec3f& InRhs)
{
	return Vec3f(InLhs.x - InRhs.x, InLhs.y - InRhs.y, InLhs.z - InRhs.z);
}

Vec3f operator*(const Vec3f& InLhs, const Vec3f& InRhs)
{
	return Vec3f(InLhs.x * InRhs.x, InLhs.y * InRhs.y, InLhs.z * InRhs.z);
}

Vec3f operator*(const Vec3f& InLhs, const float& InScale)
{
	return Vec3f(InLhs.x * InScale, InLhs.y * InScale, InLhs.z * InScale);
}

Vec3f operator*(const float& InScale, const Vec3f& InRhs)
{
	return Vec3f(InScale * InRhs.x, InScale * InRhs.y, InScale * InRhs.z);
}

Vec4i operator+(const Vec4i& InLhs, const Vec4i& InRhs)
{
	return Vec4i(InLhs.x + InRhs.x, InLhs.y + InRhs.y, InLhs.z + InRhs.z, InLhs.w + InRhs.w);
}

Vec4i operator-(const Vec4i& InLhs, const Vec4i& InRhs)
{
	return Vec4i(InLhs.x - InRhs.x, InLhs.y - InRhs.y, InLhs.z - InRhs.z, InLhs.w - InRhs.w);
}

Vec4i operator*(const Vec4i& InLhs, const Vec4i& InRhs)
{
	return Vec4i(InLhs.x * InRhs.x, InLhs.y * InRhs.y, InLhs.z * InRhs.z, InLhs.w * InRhs.w);
}

Vec4i operator*(const Vec4i& InLhs, const int32_t& InScale)
{
	return Vec4i(InLhs.x * InScale, InLhs.y * InScale, InLhs.z * InScale, InLhs.w * InScale);
}

Vec4i operator*(const int32_t& InScale, const Vec4i& InRhs)
{
	return Vec4i(InScale * InRhs.x, InScale * InRhs.y, InScale * InRhs.z, InScale * InRhs.w);
}

Vec4f operator+(const Vec4f& InLhs, const Vec4f& InRhs)
{
	return Vec4f(InLhs.x + InRhs.x, InLhs.y + InRhs.y, InLhs.z + InRhs.z, InLhs.w + InRhs.w);
}

Vec4f operator-(const Vec4f& InLhs, const Vec4f& InRhs)
{
	return Vec4f(InLhs.x - InRhs.x, InLhs.y - InRhs.y, InLhs.z - InRhs.z, InLhs.w - InRhs.w);
}

Vec4f operator*(const Vec4f& InLhs, const Vec4f& InRhs)
{
	return Vec4f(InLhs.x * InRhs.x, InLhs.y * InRhs.y, InLhs.z * InRhs.z, InLhs.w * InRhs.w);
}

Vec4f operator*(const Vec4f& InLhs, const float& InScale)
{
	return Vec4f(InLhs.x * InScale, InLhs.y * InScale, InLhs.z * InScale, InLhs.w * InScale);
}

Vec4f operator*(const float& InScale, const Vec4f& InRhs)
{
	return Vec4f(InScale * InRhs.x, InScale * InRhs.y, InScale * InRhs.z, InScale * InRhs.w);
}