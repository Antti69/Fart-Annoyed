#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Movement(float dt)
{
	pos += vel * dt;

	const float left = pos.x - radius;
	const float right = pos.x + radius;
	const float top = pos.y - radius;
	const float bottom = pos.y + radius;

	if (left <= 0)
	{
		pos.x += radius;
		ReboundX();
	}
	if (right >= (float)Graphics::ScreenWidth - 1)
	{
		pos.x -= radius;
		ReboundX();
	}
	if (top <= 0)
	{
		pos.y += radius;
		ReboundY();
	}
	if (bottom >= (float)Graphics::ScreenHeight - 1)
	{
		pos.y -= radius;
		ReboundY();
	}

}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}
