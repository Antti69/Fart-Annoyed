#include "Paddle.h"
#include <cmath>

Paddle::Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos(pos_in),
	halfWidth(halfWidth_in),
	halfHeight(halfHeight_in)
{
	eXitFactor = MaxExitRation / halfWidth;
}

void Paddle::Draw(Graphics& gfx)
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, WingColor);
	rect.left += WingWidth;
	rect.right -= WingWidth;
	gfx.DrawRect(rect, color);

}

bool Paddle::BallCollision(Ball& ball)
{
	const Vec2 ballpos = ball.GetPos();
	const RectF rect = GetRect();

	if (GetRect().IsOverlappingWith(ball.GetRect()))
	{
		if (std::signbit(ball.GetVel().x) == std::signbit((ballpos - rect.GetCenter()).x))
		{
			ball.ReboundY();
		}
		else if (ballpos.x >= rect.left && ballpos.x <= rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		return true;
	}
	return false;
}

void Paddle::SetReboundSpeed(Ball& ball)
{
	const Vec2 ballpos = ball.GetPos();
	
	if (ballpos.x < pos.x - 40.0f && ballpos.x > pos.x - 50.0f)
	{
		ball.vel.x = -200.0f;
	}
	if (ballpos.x < pos.x - 30.0f && ballpos.x > pos.x - 40.0f)
	{
		ball.vel.x = -150.0f;
	}
	if (ballpos.x < pos.x - 20.0f && ballpos.x > pos.x - 30.0f)
	{
		ball.vel.x = -100.0f;
	}
	if (ballpos.x < pos.x - 10.0f && ballpos.x > pos.x - 20.0f)
	{
		ball.vel.x = -50.0f;
	}

	if (ballpos.x > pos.x - 10.0f && ballpos.x < pos.x + 10.0f)			//törmäys keskelle paddlea
	{
		ball.vel.x = 0.0f;
	}

	if (ballpos.x > pos.x + 10.0f && ballpos.x < pos.x + 20.0f)
	{
		ball.vel.x = 50.0f;
	}
	if (ballpos.x > pos.x + 20.0f && ballpos.x < pos.x + 30.0f)
	{
		ball.vel.x = 100.0f;
	}
	if (ballpos.x > pos.x + 30.0f && ballpos.x < pos.x + 40.0f)
	{
		ball.vel.x = 150.0f;
	}
	if (ballpos.x > pos.x + 40.0f && ballpos.x < pos.x + 50.0f)
	{
		ball.vel.x = 200.0f;
	}
	ball.SetReboundY();
}

void Paddle::WallCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Movement(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}

