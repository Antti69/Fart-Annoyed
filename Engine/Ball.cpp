#include "Ball.h"
#include "Paddle.h"

Ball::Ball(const Vec2& pos_in, const Vec2& dir_in)
	:
	pos(pos_in)
{
	SetDirection(dir_in);
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Movement(float dt)
{
	pos += vel * dt;
}

bool Ball::DoWallCollision(const RectF& walls)
{
	
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		fail = true;
		
	}
	
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVel() const
{
	return vel;
}

Vec2 Ball::GetPos() const
{
	return pos;
}

void Ball::SetDirection(const Vec2& dir)
{
	vel = dir.GetNormalized() * speed;
}

void Ball::SetPos(Paddle& pad)
{
	pos.x = pad.GetRect().GetCenter().x;
	pos.y = pad.GetRect().GetCenter().y - 20.0f;
}

void Ball::SetSpeed(char merkki)
{
	if (merkki == '+')
	{
		speed += 20;
	}
	if (merkki == '-')
	{
		speed -= 20;
	}
}

bool Ball::GetFail()
{
	return fail;
}

void Ball::SetFail()
{
	fail = false;
}




