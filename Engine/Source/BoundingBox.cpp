#include "BoundingBox.h"

BoundingBox::BoundingBox(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate)
	: Center_(InCenter)
	, Width_(InWidth)
	, Height_(InHeight)
	, Rotate_(InRotate)
{
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

BoundingBox::BoundingBox(BoundingBox&& InInstance) noexcept
	: Center_(InInstance.Center_)
	, Width_(InInstance.Width_)
	, Height_(InInstance.Height_)
	, Rotate_(InInstance.Rotate_)
	, BoundingPositions_(InInstance.BoundingPositions_)
{
}

BoundingBox::BoundingBox(const BoundingBox& InInstance) noexcept
	: Center_(InInstance.Center_)
	, Width_(InInstance.Width_)
	, Height_(InInstance.Height_)
	, Rotate_(InInstance.Rotate_)
	, BoundingPositions_(InInstance.BoundingPositions_)
{
}

BoundingBox::~BoundingBox()
{
}

BoundingBox& BoundingBox::operator=(BoundingBox&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	BoundingPositions_ = InInstance.BoundingPositions_;

	return *this;
}

BoundingBox& BoundingBox::operator=(const BoundingBox& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	BoundingPositions_ = InInstance.BoundingPositions_;

	return *this;
}

void BoundingBox::SetCenter(const Vec2i& InCenter)
{
	Center_ = InCenter;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void BoundingBox::SetWidth(const int32_t& InWidth)
{
	Width_ = InWidth;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void BoundingBox::SetHeight(const int32_t& InHeight)
{
	Height_ = InHeight;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

void BoundingBox::SetRotate(const float& InRotate)
{
	Rotate_ = InRotate;
	BoundingPositions_ = CalculateBoundingPositions(Center_, Width_, Height_, Rotate_);
}

bool BoundingBox::IsCollision(const BoundingBox& InBoundingBox)
{
	for (const auto& BoundingPosition : InBoundingBox.BoundingPositions_)
	{
		if (IsIncludePositionInBoundingBox(BoundingPosition, BoundingPositions_))
		{
			return true;
		}
	}

	for (const auto& BoundingPosition : BoundingPositions_)
	{
		if (IsIncludePositionInBoundingBox(BoundingPosition, InBoundingBox.BoundingPositions_))
		{
			return true;
		}
	}

	return false;
}

std::array<Vec2i, 4> BoundingBox::CalculateBoundingPositions(const Vec2i& InCenter, const int32_t& InWidth, const int32_t& InHeight, const float& InRotate)
{
	int32_t HalfWidth  = static_cast<int32_t>(static_cast<float>(InWidth) / 2.0f);
	int32_t HalfHeight = static_cast<int32_t>(static_cast<float>(InHeight) / 2.0f);

	std::array<Vec2i, 4> BoundingPositions = {
		InCenter + Vec2i(-HalfWidth, -HalfHeight),
		InCenter + Vec2i(+HalfWidth, -HalfHeight),
		InCenter + Vec2i(-HalfWidth, +HalfHeight),
		InCenter + Vec2i(+HalfWidth, +HalfHeight),
	};

	float CosTheta = static_cast<float>(cos(InRotate));
	float SinTheta = static_cast<float>(sin(InRotate));

	for (auto& BoundingPosition : BoundingPositions)
	{
		BoundingPosition = BoundingPosition - InCenter;

		Vec2f RotatePosition;
		RotatePosition.x = static_cast<float>(BoundingPosition.x) * CosTheta - static_cast<float>(BoundingPosition.y) * SinTheta;
		RotatePosition.y = static_cast<float>(BoundingPosition.x) * SinTheta + static_cast<float>(BoundingPosition.y) * CosTheta;

		BoundingPosition = InCenter + Vec2i(
			static_cast<int32_t>(RotatePosition.x + 0.5f), 
			static_cast<int32_t>(RotatePosition.y + 0.5f)
		);
	}

	return BoundingPositions;
}

bool BoundingBox::IsIncludePositionInBoundingBox(const Vec2i& InPosition, const std::array<Vec2i, 4>& InBoundingPositions)
{
	int32_t MinX = InBoundingPositions[0].x;
	int32_t MaxX = InBoundingPositions[1].x;
	int32_t MinY = InBoundingPositions[0].y;
	int32_t MaxY = InBoundingPositions[2].y;

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
