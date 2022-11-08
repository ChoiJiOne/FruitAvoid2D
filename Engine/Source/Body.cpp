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
	Type_ = Type::RECTANGLE;
	Center_ = InCenter;
	Width_ = InWidth;
	Height_ = InHeight;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
}

Body::Body(
	const Vec2f& InCenter,
	const float& InRadius,
	const float& InRotate,
	const float& InVelocity
)
{
	Type_ = Type::CIRCLE;
	Center_ = InCenter;
	Width_ = InRadius * 2.0f;
	Height_ = InRadius * 2.0f;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
}

Body::Body(Body&& InInstance) noexcept
{
	Type_ = InInstance.Type_;
	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
}

Body::Body(const Body& InInstance)
{
	Type_ = InInstance.Type_;
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

	Type_ = InInstance.Type_;
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

	Type_ = InInstance.Type_;
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
	if (Type_ == Type::NONE || InBody.Type_ == Type::NONE) return false;

	CHECK((Type_ == Type::CIRCLE || Type_ == Type::RECTANGLE), "undefined game object body type");
	CHECK((InBody.Type_ == Type::CIRCLE || InBody.Type_ == Type::RECTANGLE), "undefined game object body type");

	bool bIsCollision = false;

	if (Type_ == Type::CIRCLE)
	{
		if (InBody.Type_ == Type::CIRCLE)
		{
			bIsCollision = IsColiisionCircleAndCircle(*this, InBody);
		}
		else // InBody.Type_ == Type::RECTANGLE
		{
			bIsCollision = IsCollisionCircleAndRectangle(*this, InBody);
		}
	}
	else // Type_ == Type::RECTANGLE
	{
		if (InBody.Type_ == Type::CIRCLE)
		{
			bIsCollision = IsCollisionCircleAndRectangle(InBody, *this);
		}
		else // Type_ == Type::RECTANGLE
		{
			bIsCollision = IsCollisionRectangleAndRectangle(*this, InBody);
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

bool Body::IsCollisionCircleAndRectangle(const Body& InCircleBody, const Body& InRectangleBody)
{
	CHECK((InCircleBody.GetType() == Type::CIRCLE), "invalid function parameter");
	CHECK((InRectangleBody.GetType() == Type::RECTANGLE), "invalid function parameter");

	bool bIsCollision = false;
	const std::array<Vec2f, 4>& CircleBodyPositions = InCircleBody.GetBoundingPositions();
	const std::array<Vec2f, 4>& RectangleBodyPositions = InRectangleBody.GetBoundingPositions();

	return bIsCollision;
}

bool Body::IsColiisionCircleAndCircle(const Body& InCircleBody, const Body& InOtherCircleBody)
{
	CHECK((InCircleBody.GetType() == Type::CIRCLE), "invalid function parameter");
	CHECK((InOtherCircleBody.GetType() == Type::CIRCLE), "invalid function parameter");

	bool bIsCollision = false;
	const std::array<Vec2f, 4>& CircleBodyPositions = InCircleBody.GetBoundingPositions();
	const std::array<Vec2f, 4>& OtherCircleBodyPositions = InOtherCircleBody.GetBoundingPositions();

	return bIsCollision;
}

bool Body::IsCollisionRectangleAndRectangle(const Body& InRectangleBody, const Body& InOtherRectangleBody)
{
	CHECK((InRectangleBody.GetType() == Type::RECTANGLE), "invalid function parameter");
	CHECK((InOtherRectangleBody.GetType() == Type::RECTANGLE), "invalid function parameter");

	bool bIsCollision = false;
	const std::array<Vec2f, 4>& RectangleBodyPositions = InRectangleBody.GetBoundingPositions();
	const std::array<Vec2f, 4>& OtherRectangleBodyPositions = InOtherRectangleBody.GetBoundingPositions();

	return bIsCollision;
}
