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
		enum class MeterPos
		{
			Left,
			Right,
			None
		};
		MeterPos Blue = { MeterPos::None };
		MeterPos Red = { MeterPos::None };
		MeterPos Green = { MeterPos::None };

	public:
		void DrawBlueMeter(Graphics& gfx) const;
		void DrawRedMeter(Graphics& gfx) const;
		void DrawGreenMeter(Graphics& gfx) const;
		void SetBlueM(char merkki);
		void SetRedM(Life& life);
		float GetBlueMeter() const;
		float GetMeterMin() const;
	private:
		float b_meterY = 530.0f;
		float r_meterY = 530.0f;
		float g_meterY = 530.0f;
		static constexpr float MeterMax = 260.0f;
		static constexpr float MeterMin = 550.0f;
		const RectF pohja_left = { Vec2(50.0f, MeterMax), Vec2(70.0f, MeterMin) };
		const RectF pohja_right = { Vec2(740.0f, MeterMax), Vec2(760.0f, MeterMin) };
		
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