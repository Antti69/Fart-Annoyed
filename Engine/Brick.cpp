#include "Brick.h"

Brick::Brick(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.Expand( -padding), c);
	}
}

bool Brick::BallCollision(Ball& ball)
{
	if (!destroyed && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}

RectF Brick::GetRect()
{
	return rect;
}
