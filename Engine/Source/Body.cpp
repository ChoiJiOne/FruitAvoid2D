#include "Body.h"
#include "MathUtils.h"
#include "Macro.h"

Body::Body(
	const Vec2f& InCenter,
	const float& InWidth,
	const float& InHeight,
	const float& InRotate,
	const float& InVelocity
)
{
	Center_ = InCenter;
	Width_ = InWidth;
	Height_ = InHeight;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
}

Body::Body(Body&& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
}

Body::Body(const Body& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
}

Body::~Body()
{
}

Body& Body::operator=(Body&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;

	return *this;
}

Body& Body::operator=(const Body& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;

	return *this;
}

void Body::SetCenter(const Vec2f& InCenter)
{
	Center_ = InCenter;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void Body::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void Body::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void Body::SetRotate(const float& InRotate)
{
	Rotate_ = InRotate;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

bool Body::IsCollision(const Body& InBody)
{
	bool bIsCollision = false;

	for (const auto& BoundingPosition : BoundingPositions_)
	{
		if (IsIncludePositionInBounding(BoundingPosition, InBody.BoundingPositions_))
		{
			bIsCollision = true;
		}
	}

	for (const auto& BoundingPosition : InBody.BoundingPositions_)
	{
		if (IsIncludePositionInBounding(BoundingPosition, BoundingPositions_))
		{
			bIsCollision = true;
		}
	}

	return bIsCollision;
}

std::array<Vec2f, 4> Body::CalculateBoundingPositions(const Vec2f& InCenter, const float& InWidth, const float& InHeight, const float& InRotate)
{
	float HalfOfWidth = InWidth / 2.0f;
	float HalfOfHeight = InHeight / 2.0f;

	std::array<Vec2f, 4> BoundingPositions = {
		Vec2f(-HalfOfWidth, -HalfOfHeight),
		Vec2f(+HalfOfWidth, -HalfOfHeight),
		Vec2f(-HalfOfWidth, +HalfOfHeight),
		Vec2f(+HalfOfWidth, +HalfOfHeight),
	};

	float CosTheta = static_cast<float>(cos(MathUtils::ToRadian(static_cast<double>(InRotate))));
	float SinTheta = static_cast<float>(sin(MathUtils::ToRadian(static_cast<double>(InRotate))));

	for (auto& BoundingPosition : BoundingPositions)
	{
		Vec2f RotatePosition;

		RotatePosition.x = BoundingPosition.x * CosTheta - BoundingPosition.y * SinTheta;
		RotatePosition.y = BoundingPosition.x * SinTheta + BoundingPosition.y * CosTheta;

		BoundingPosition = RotatePosition;
		BoundingPosition += InCenter;
	}

	return BoundingPositions;
}

bool Body::IsIncludePositionInBounding(const Vec2f& InPosition, const std::array<Vec2f, 4>& InBoundingPositions)
{
	float MinX = InBoundingPositions[0].x;
	float MaxX = InBoundingPositions[1].x;
	float MinY = InBoundingPositions[0].y;
	float MaxY = InBoundingPositions[2].y;

	if ((MinX <= InPosition.x && InPosition.x <= MaxX) &&
		(MinY <= InPosition.y && InPosition.y <= MaxY))
	{
		return true;
	}
	else
	{
		return false;
	}
}
