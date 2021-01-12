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

void Paddle::Draw(Graphics& gfx) const
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

	if (!Cooldown && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		if (CatchCount())
		{
			ball.ResetBall = true;
			const Vec2 Dir = Vec2(0.2f, -1.0f);
			ball.SetDirection(Dir);
			CatchCounter -= 1;
		}
		if (std::signbit(ball.GetVel().x) == std::signbit((ballpos - rect.GetCenter()).x)
			|| ballpos.x >= rect.left && ballpos.x <= rect.right)
		{
			Vec2 dir;
			const float xDiffrence = ballpos.x - pos.x;
			dir = Vec2(xDiffrence * eXitFactor, -1.0f);
			ball.SetDirection(dir);
		}
		else
		{
			ball.ReboundX();
		}
		Cooldown = true;
		return true;
	}
	return false;
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

void Paddle::ResetCooldown()
{
	Cooldown = false;
}

void Paddle::PaddleSize()
{
	if (smallpad)
	{
		halfWidth = 33.0f;
	}
}

bool Paddle::CatchCount() const
{
	if (CatchCounter > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Paddle::SetCatch()
{
	CatchCounter = 3;
}

void Paddle::DrawCatchSign(Graphics& gfx)
{
	if (CatchCounter > 0)
	{
		gfx.DrawCircle(120, 30, 10, Colors::Green);
	}
}

