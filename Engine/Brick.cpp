#include "Brick.h"
#include <assert.h>
#include <cmath>

Brick::Brick(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{}

Brick::Brick(const RectF & rect_in, Color c_in, Game::State state_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed && !firstcol)
	{
		gfx.DrawRect(rect.Expand( -padding), c);
	}
	if (!destroyed && firstcol)
	{
		gfx.DrawRectSpacec(rect.Expand(-padding), c);
	}
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !destroyed && GetRect().IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballpos = ball.GetPos();

	if (std::signbit(ball.GetVel().x) == std::signbit((ballpos - GetCenter()).x)
		|| ballpos.x >= rect.left && ballpos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	
}

RectF Brick::GetRect() const
{
	return rect;
}

Vec2 Brick::GetCenter() const
{
	return Vec2(rect.GetCenter());
}

bool Brick::GetFirstcol()
{
	return firstcol;
}

void Brick::SetDestr()
{
	destroyed = true;
}

void Brick::Setfirstcol()
{
	firstcol = true;
}

