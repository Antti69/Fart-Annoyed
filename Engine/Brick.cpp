#include "Brick.h"
#include <assert.h>
#include <cmath>


Brick::Brick(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
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
	if (destroyed && indestructible)
	{
		gfx.DrawRect(rect.Expand(-padding), c);
	}
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	if (indestructible && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		return true;
	}
	if (!destroyed && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		return true;
	}
	return false;
}

bool Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballpos = ball.GetPos();

	if (std::signbit(ball.GetVel().x) == std::signbit((ballpos - GetCenter()).x)
		|| ballpos.x >= rect.left && ballpos.x <= rect.right)
	{
		ball.ReboundY();
		return true;
	}
	else
	{
		ball.ReboundX();
		return true;
	}
	return false;
}

void Brick::FlashEffect()
{
	c = Colors::White;
}

RectF Brick::GetRect() const
{
	return rect;
}

Vec2 Brick::GetCenter() const
{
	return Vec2(rect.GetCenter());
}

Color Brick::GetColor() const
{
	return c;
}

void Brick::SetColor(Color c)
{
	c = c;
}

bool Brick::GetFirstcol()
{
	return firstcol;
}

bool Brick::GetDestroyed()
{
	return destroyed;
}

void Brick::SetDestr()
{
	destroyed = true;
}

void Brick::Setfirstcol()
{
	firstcol = true;
}

