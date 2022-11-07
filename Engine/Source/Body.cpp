#include "Body.h"

Body::Body(
	const Vec2i& InCenter, 
	const int32_t& InWidth, 
	const int32_t& InHeight, 
	const Vec2f& InDirection, 
	const float& InVelocity
)
{
	Type_ = Type::RECTANGLE;
	Center_ = InCenter;
	Width_ = InWidth;
	Height_ = InHeight;
	Direction_ = InDirection;
	Velocity_ = InVelocity;
}

Body::Body(const Vec2i& InCenter, const int32_t& InRadius, const Vec2f& InDirection, const float& InVelocity)
{
	Type_ = Type::CIRCLE;
	Center_ = InCenter;
	Width_ = InRadius * 2;
	Height_ = InRadius * 2;
	Direction_ = InDirection;
	Velocity_ = InVelocity;
}

Body::Body(Body&& InInstance) noexcept
{
	Type_ = InInstance.Type_;
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Direction_ = InInstance.Direction_;
	Velocity_ = InInstance.Velocity_;
}

Body::Body(const Body& InInstance)
{
	Type_ = InInstance.Type_;
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Direction_ = InInstance.Direction_;
	Velocity_ = InInstance.Velocity_;
}

Body::~Body()
{
}

Body& Body::operator=(Body&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Type_ = InInstance.Type_;
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Direction_ = InInstance.Direction_;
	Velocity_ = InInstance.Velocity_;

	return *this;
}

Body& Body::operator=(const Body& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Type_ = InInstance.Type_;
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Direction_ = InInstance.Direction_;
	Velocity_ = InInstance.Velocity_;

	return *this;
}

bool Body::IsCollision(const Body& InBody)
{
	return false;
}
