#pragma once
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Vec2.h"

class Ball
{
	friend class Paddle;
public:
	Ball(const Vec2& pos_in, const Vec2& dir_in);
	void Draw(Graphics& gfx) const;
	void Movement(float dt);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVel();
	Vec2 GetPos();
	void SetDirection(const Vec2& dir);
	void SetReboundY();
	void SetReboundX();
	void SetReboundXN();
private:
	float speed = 300.0f;
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	
};