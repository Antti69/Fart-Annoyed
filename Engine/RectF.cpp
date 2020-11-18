#include "RectF.h"

RectF::RectF(float left_in, float top_in, float right_in, float bottom_in)		//neljällä
	:
	left(left_in),
	top(top_in),
	right(right_in),
	bottom(bottom_in)
{}

RectF::RectF(const Vec2& topleft, const Vec2& bottomright)						//kahdella
{
	RectF(topleft.x, bottomright.x, topleft.y, bottomright.y);
}

RectF::RectF(const Vec2& topleft, float width, float height)					//kolmella
{
	RectF(topleft, topleft + Vec2 (width, height));
}

bool RectF::Overlap(const RectF& other) const
{
	return left < other.right && right > other.left &&
		   top < other.bottom && bottom > other.top;
}
