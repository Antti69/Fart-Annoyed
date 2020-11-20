#pragma once
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Vec2.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Movement(float dt);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	
};