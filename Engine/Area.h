#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"

class Area
{
public:
	Area() = default;
	Area(const RectF& rect_in, Color c_in);
	void DrawWall(Graphics& gfx) const;
	void DrawLife(Graphics& gfx) const;
	void DrawBlueMeter(Graphics& gfx) const;
	void DrawRedMeter(Graphics& gfx) const;
	void SetLife(char merkki);
	int GetLife() const;
	RectF GetRect() const;
	void SetBlueM(char merkki);
	void SetRedM();
	float GetBlueMeter() const;
	float GetMeterMin() const;
	
	bool BlueMeter = false;
	bool RedMeter = false;
private:
	RectF rect;
	Color c;
	int life = 4;
	float b_meterY = 530.0f;
	float r_meterY = 530.0f;
	static constexpr float MeterMax = 260.0f;
	static constexpr float MeterMin = 550.0f;
};