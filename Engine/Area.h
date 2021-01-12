#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"

class Area
{
public:
	class Life
	{
	public:
		Life() = default;
		void DrawLife(Graphics& gfx) const;
		void SetLife(char merkki);
		int GetLife() const;
	private:
		int life = 4;

	};
	class Meter
	{
	public:
		void DrawBlueMeter(Graphics& gfx) const;
		void DrawRedMeter(Graphics& gfx) const;
		void SetBlueM(char merkki);
		void SetRedM(Life& life);
		float GetBlueMeter() const;
		float GetMeterMin() const;
		bool BlueMeter = false;
		bool RedMeter = false;
	private:
		float b_meterY = 530.0f;
		float r_meterY = 530.0f;
		static constexpr float MeterMax = 260.0f;
		static constexpr float MeterMin = 550.0f;
		
	};
public:
	Area() = default;
	Area(const RectF& rect_in, Color c_in);
	void DrawWall(Graphics& gfx) const;
	RectF GetRect() const;
private:
	RectF rect;
	Color c;
	

};