/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
	
{

	

	//Level 1
	{	
	const Vec2 topleft = { GridStartX + (brickWidth * 3), GridStartY + (brickHeight * 3) };
	
	Color colors[BrickPysty_lvl1] = { Colors::Blue, Colors::Red, Colors::Cyan, Colors::White, Colors::Orange };

	int i = 0;
	for (int y = 0; y < BrickPysty_lvl1; y++)
	{
		Color c = colors[y];
		for (int x = 0; x < BrickViisto_lvl1; x++)
		{
			bricks[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);
			if (y == 4)
			{
				state[i] = Brick::State::indestructible;
				bricks[i].indestructible = true;
				bricks[i].SetDestr();
				
			}
			i++;
		}
	}
	}				
	//Level 2
	{	
	Color colors[BrickPysty_lvl2] = { Colors::Blue, Colors::White, Colors::Red,
								   Colors::Cyan, Colors::Blue, Colors::Gray };

	const Vec2 topleft = { GridStartX + (brickWidth * 2), GridStartY + (brickHeight * 3) };

	int i = 0;
	for (int y = 0; y < BrickPysty_lvl2; y++)
	{
		Color c = colors[y];
		for (int x = 0; x < BrickViisto_lvl2; x++)
		{
			bricks2[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);

			if (y == 5)
			{
				state2[i] = Brick::State::TwoHit;
			}
			else
			{
				state2[i] = Brick::State::Basic;
			}
			i++;
		}
	}
	}
	//Level 3
	{	
		const Vec2 topleft = { GridStartX, GridStartY };
		int i = 0;
		for (int y = 0; y < BrickPysty_lvl3; y++)
		{
			Color c = Colors::Cyan;
			for (int x = 0; x < BrickViisto_lvl3; x++)
			{
				bricks3[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				state3[i] = Brick::State::Basic;

				i++;
			}
		}
	}
	//level 3.1
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 10), GridStartY + (brickHeight * 4) };
		Color c = Colors::Orange;
		
		int i = 0;
		for (int y = 0; y < BrickPysty_lvl3_1; y++)
		{
			
			for (int x = 0; x < BrickViisto_lvl3_1; x++)
			{
				if (y == 2 && x == 1)
				{
					c = Colors::Magenta;
					state3_1[i] = Brick::State::LifeUp;
				}
				else
				{
					state3_1[i] = Brick::State::indestructible;
					bricks3_1[i].indestructible = true;
					bricks3_1[i].SetDestr();
					c = Colors::Orange;
				}
				bricks3_1[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);
				if (y == 1 && x < 2)
				{
					continue;
				}
				if (y == 2 && x == 0)
				{
					continue;
				}
				if (y == 3 && x < 2)
				{
					continue;
				}
				i++;
			}
		}
	}
	//level 4
	{
		const Vec2 topleft = { GridStartX, GridStartY + (brickHeight * 2) };
		Color c;

		int i = 0;
		for (int y = 0; y < BrickPysty_lvl4; y++)
		{
			for (int x = 0; x < BrickViisto_lvl4; x++)
			{
				if (y < 8 && x < 5)
				{
					c = Colors::Blue;
					state4[i] = Brick::State::MeterUp;
				}
				else if (y < 8 && x > 5)
				{
					c = Colors::Red;
					state4[i] = Brick::State::MeterUp;
				}
				else if (y == 8)
				{
					c = Colors::Gray;
					state4[i] = Brick::State::TwoHit;
				}
				bricks4[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				if (y < 8)
				{
					if (x < 2)
					{
						bricks4[i].SetDestr();
					}
					if (x > 3 && x < 10)
					{
						bricks4[i].SetDestr();
					}
					if (x > 11)
					{
						bricks4[i].SetDestr();
					}
				}
				i++;
			}
		}
	}
	//Level 5
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 2), GridStartY };
		int i = 0;
		int x = 0;
		int y = 0;
		Color c = Colors::Orange;
		for (y = 0; y < BrickPysty_lvl5; y++)
		{
			state5[i] = Brick::State::indestructible;
			bricks5[i].indestructible = true;
			bricks5[i].SetDestr();

			bricks5[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);

			if (y > 2 && y < 6)
			{
				bricks5[i].indestructible = false;
				bricks5[i].SetDestr();
			}
			i++;
			
		}
		const Vec2 topleft2 = { GridStartX + (brickWidth * 2), GridStartY };
		for (x = 0; x < BrickViisto_lvl5; x++)
		{
			state5[i] = Brick::State::indestructible;
			bricks5[i].indestructible = true;
			bricks5[i].SetDestr();

			bricks5[i] = Brick(RectF(topleft2 + Vec2(x * brickWidth, y * brickHeight),
				brickWidth, brickHeight), c);

			i++;
		}
		
	}
	//Level 5.1
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 7), GridStartY + (brickHeight * 3) };
		Color colors[BrickViisto_lvl5_1] = { Colors::Blue, Colors::Blue, Colors::Gray, Colors::Red, Colors::Red };
		int i = 0;
		for (int y = 0; y < BrickPysty_lvl5_1; y++)
		{
			
			for (int x = 0; x < BrickViisto_lvl5_1; x++)
			{
				Color c = colors[x];
				bricks5_1[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				if (x < 2)
				{
					state5_1[i] = Brick::State::MeterUp;
				}
				else if (x > 2)
				{
					state5_1[i] = Brick::State::MeterUp;
				}
				else
				{
					state5_1[i] = Brick::State::TwoHit;
				}
				i++;
			}
		}
	}
	//Level 6
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 2), GridStartY + (brickHeight * 5) };
		Color colors[BrickPysty_lvl6] = { Colors::Cyan, Colors::Cyan, Colors::White, Colors::Blue, Colors::Red,
			Colors::Yellow, Colors::Gray, Colors::Yellow };
		int i = 0;
		for (int y = 0; y < BrickPysty_lvl6; y++)
		{
			Color c = colors[y];
			for (int x = 0; x < BrickViisto_lvl6; x++)
			{
				bricks6[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				if (x == 4)
				{
					bricks6[i].SetDestr();
				}

				if (y == 3)
				{
					state6[i] = Brick::State::MeterUp;
				}
				else if (y == 4)
				{
					state6[i] = Brick::State::MeterUp;
				}
				else if (y == 5 || y == 7)
				{
					state6[i] = Brick::State::SpeedUp;
				}
				else if (y == 6)
				{
					state6[i] = Brick::State::TwoHit;
				}
				else
				{
					state6[i] = Brick::State::Basic;
				}


				i++;
			}
		}
	}
	//Level 7
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 2), GridStartY };
		Color c;
		int i = 0;
		for (int y = 0; y < BrickPysty_lvl7; y++)
		{

			for (int x = 0; x < BrickViisto_lvl7; ++x)
			{

				if (y == 0 && x <= 4)
				{
					c = Colors::Blue;
					state7[i] = Brick::State::MeterUp;
				}
				else if (y == 0 && x >= 5)
				{
					c = Colors::Red;
					state7[i] = Brick::State::MeterUp;
				}
				else if (y == 1)
				{
					c = Colors::Gray;
					state7[i] = Brick::State::TwoHit;
				}
				bricks7[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);
				++i;
			}
		}
	}
	//Level 7.1
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 2), GridStartY + (brickHeight * 3) };

		Color c = Colors::Orange;

		int i = 0;
		for (int y = 0; y < BrickPysty_lvl7_1; y++)
		{
			
			for (int x = 0; x < BrickViisto_lvl7_1; x++)
			{

				if (y == 0 && (x == 0 || x == 2 || x == 4 || x == 6 || x == 8 ))
				{
					state7_1[i] = Brick::State::indestructible;
					bricks7_1[i].SetDestr();
					bricks7_1[i].indestructible = true;
					c = Colors::Orange;
				}
				else if (y == 3 && (x == 1 || x == 5 || x == 9))
				{
					state7_1[i] = Brick::State::indestructible;
					bricks7_1[i].SetDestr();
					bricks7_1[i].indestructible = true;
					c = Colors::Orange;
				}
				else if (y == 3 && x == 3)
				{
					state7_1[i] = Brick::State::MultipleBalls;
					c = Colors::Green;
				}
				else if (y == 3 && x == 7)
				{
					state7_1[i] = Brick::State::LargePad;
					c = Colors::Green;
				}
				else if (y == 6 && (x == 0 || x == 2 || x == 4 || x == 6 || x == 8))
				{
					state7_1[i] = Brick::State::indestructible;
					bricks7_1[i].SetDestr();
					bricks7_1[i].indestructible = true;
					c = Colors::Orange;
				}
				else if (y == 9 && (x == 1 || x == 3 || x == 7 || x == 9))
				{
					state7_1[i] = Brick::State::indestructible;
					bricks7_1[i].SetDestr();
					bricks7_1[i].indestructible = true;
					c = Colors::Orange;
				}
				else
				{
					continue;
				}
				bricks7_1[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);
				i++;
			}
		}
	}
	//Level 8
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 4), GridStartY + (brickHeight * 5) };
		int i = 0;
		for (int y = 0; y < BrickPysty_lvlTesti; y++)
		{
			Color c = Colors::Cyan;
			for (int x = 0; x < BrickViisto_lvlTesti; x++)
			{
				bricksTesti[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				stateTesti[i] = Brick::State::MeterFull;

				i++;
			}
		}
	}
	//Testi kentt�
	{
		const Vec2 topleft = { GridStartX + (brickWidth * 4), GridStartY + (brickHeight * 5) };
		int i = 0;
		for (int y = 0; y < BrickPysty_lvlTesti; y++)
		{
			Color c = Colors::RedTest;
			for (int x = 0; x < BrickViisto_lvlTesti; x++)
			{


				bricksTesti[i] = Brick(RectF(topleft + Vec2(x * brickWidth, y * brickHeight),
					brickWidth, brickHeight), c);

				stateTesti[i] = Brick::State::MeterFull;
				if (x == 1)
				{
					bricksTesti[i].ColorChange = true;
				}

				i++;
			}
		}
	}
	
}

void Game::Go()
{
	gfx.BeginFrame();
	elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (Started && !GameOver && !ChoiceState && !ChoiceState2)
	{
		ball.SetPos(pad);					//Pallon sijainti ja liike

		if (ball.DoWallCollision(walls) || ball2.DoWallCollision(walls) || ball3.DoWallCollision(walls))
		{
			//��net t�h�n joskus
		}
		if (Ball_1)
		{
			ball.Movement(dt);
		}
		if (Ball_2)
		{
			ball2.SetResetBall(false);
			ball2.Movement(dt);
		}
		if (Ball_3)
		{
			ball3.SetResetBall(false);
			ball3.Movement(dt);
		}
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			ball.SetResetBall(false);
		}

		if (wnd.kbd.KeyIsPressed(VK_CONTROL) && meter.GetB_meterY() <= meter.GetMeterMin() &&
			meter.Blue != Area::Meter::MeterPos::None)
		{
			meter.SetBlueM('-');			//Sinisen mittarin mekaniikka
			ball.SetSpeed('s');
			ball2.SetSpeed('s');
			ball3.SetSpeed('s');
			
		}
		else
		{
			ball.SetSpeed('r');
		}
		if (wnd.kbd.KeyIsPressed('Q'))		//T�m� testej� varten
		{
			meter.SetBlueM('+');
			
		}

		gun.WallCollision(walls);
		gun.SetPos(pad);
		gun.AmmoMovment(dt);
		

		if (wnd.kbd.KeyIsPressed(VK_TAB) && meter.Green != Area::Meter::MeterPos::None
			&& meter.GetG_meterY() <= meter.GetMeterMin() && !gun.GetGuns())			//Ase funktiot
		{
			gun.SetGuns(true);
			meter.SetGreenM('-');
		}

		if (wnd.kbd.KeyIsPressed('C'))					//Testej� varten
		{
			meter.Green = Area::Meter::MeterPos::Left;
		}
		if (wnd.kbd.KeyIsPressed('P'))
		{
			meter.Blue = Area::Meter::MeterPos::Right;
		}

		if (!Ball_1)
		{
			ball.fail = true;
		}
		if (!Ball_2)
		{
			ball2.fail = true;
		}
		if (!Ball_3)
		{
			ball3.fail = true;
		}

		bool allfail = true;
		if (ball.fail || ball2.fail || ball3.fail)				//El�m� mekaniikka
		{
			allfail = allfail && ball.fail && ball2.fail && ball3.fail;

			if (ball.fail)
			{
				Ball_1 = false;
			}
			if (ball2.fail)
			{
				Ball_2 = false;
			}
			if (ball3.fail)
			{
				Ball_3 = false;
			}

			if (allfail)
			{
				life.SetLife('-');
				ball.SetResetBall(true);
				ball.fail = false;
				Ball_1 = true;

				if (life.GetLife() == 0)
				{
					GameOver = true;
				}
			}

		}


		
		

		pad.Movement(wnd.kbd, dt);		//Paddlen funktiot
		pad.WallCollision(walls);
		pad.PaddleSize(dt);
		pad.DrawCatchSign(gfx);
		pad.ResetCooldown(dt);
		if (Ball_1)
		{
			pad.BallCollision(ball);
		}
		if (Ball_2)
		{
			pad.BallCollision(ball2);
		}
		if (Ball_3)
		{
			pad.BallCollision(ball3);
		}
		
		

		
		if (level == Level::Lvl1)			//Lvl p�ivitys
		{
			BrickCollision(bricks, state, ball, BrickTotal_lvl1, dt);
			if (LvlUp)
			{
				level = Level::Lvl2;
				ball.SetResetBall(true);
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl2)
		{
			BrickCollision(bricks2, state2, ball, BrickTotal_lvl2, dt);
			if (LvlUp)
			{
				level = Level::Lvl3;
				ball.SetResetBall(true);
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl3)
		{
			BrickCollision(bricks3, state3, ball, BrickTotal_lvl3, dt);
			BrickCollision(bricks3_1, state3_1, ball, BrickTotal_lvl3_1, dt);
			if (LvlUp)
			{
				ChoiceState = true;
				ball.SetResetBall(true);
				level = Level::Lvl4;
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl4)
		{
			BrickCollision(bricks4, state4, ball, BrickTotal_lvl4, dt);
			if (LvlUp)
			{
				level = Level::Lvl5;
				ball.SetResetBall(true);
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl5)
		{
			BrickCollision(bricks5_1, state5_1, ball, BrickTotal_lvl5_1, dt);
			BrickCollision(bricks5, state5, ball, BrickTotal_lvl5, dt);
			if (LvlUp)
			{
				
				level = Level::Lvl6;
				ball.SetResetBall(true);
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl6)
		{
			BrickCollision(bricks6, state6, ball, BrickTotal_lvl6, dt);
			if (LvlUp)
			{
				ChoiceState2 = true;
				ball.SetResetBall(true);
				level = Level::Lvl7;
				LvlUp = false;
			}
		}
		else if (level == Level::Lvl7)
		{
			BrickCollision(bricks7, state7, ball, ball2, ball3, BrickTotal_lvl7, dt);
			BrickCollision(bricks7_1, state7_1, ball, ball2, ball3, BrickTotal_lvl7_1, dt);
			if (LvlUp)
			{
				ball.SetResetBall(true);
				level = Level::Lvl8;
				LvlUp = false;
			}
		}
		else if (level == Level::Testi)
		{
			BrickCollision(bricksTesti, stateTesti, ball, BrickTotal_lvl8, dt);
			
		}

	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			Started = true;
		}

		if (ChoiceState && wnd.kbd.KeyIsPressed('B'))			//valinta mekaniikka
		{
			meter.Blue = Area::Meter::MeterPos::Left;
			ChoiceState = false;
		}
		else if (ChoiceState && wnd.kbd.KeyIsPressed('R'))
		{
			meter.Red = Area::Meter::MeterPos::Left;
			ChoiceState = false;
		}
		else if (ChoiceState && wnd.kbd.KeyIsPressed('G'))
		{
			meter.Green = Area::Meter::MeterPos::Left;
			ChoiceState = false;
		}

		if (ChoiceState2 && wnd.kbd.KeyIsPressed('B'))
		{
			ball.SetSpeed('b');
			ChoiceState2 = false;
		}
		else if (ChoiceState2 && wnd.kbd.KeyIsPressed('R'))
		{
			pad.SetPadChoiceSize(true);
			pad.padsize = Paddle::PadSize::Small;
			ChoiceState2 = false;
		}

		if (wnd.kbd.KeyIsPressed('2'))			//Level oikotie "testi� varten"
		{
			level = Level::Lvl2;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('3'))
		{
			level = Level::Lvl3;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('4'))
		{
			level = Level::Lvl4;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('5'))
		{
			level = Level::Lvl5;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('6'))
		{
			level = Level::Lvl6;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('7'))
		{
			level = Level::Lvl7;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('8'))
		{
			level = Level::Lvl8;
			ball.SetResetBall(true);
		}
		if (wnd.kbd.KeyIsPressed('T'))
		{
			level = Level::Testi;
			ball.SetResetBall(true);
		}


	}
	

}



void Game::ComposeFrame()
{
	if (!Started)
	{
		DrawTitle();
	}
	else if (ChoiceState || ChoiceState2)
	{
		DrawTitle();
	}
	else
	{

		leftwall.DrawWall(gfx);
		rightwall.DrawWall(gfx);
		topwall.DrawWall(gfx);
		life.DrawLife(gfx);
		pad.Draw(gfx);
		meter.DrawMeter(gfx, meter.Blue, meter.GetB_meterY(), Colors::Blue);
		meter.DrawMeter(gfx, meter.Red, meter.GetR_meterY(), Colors::Red);
		meter.DrawMeter(gfx, meter.Green, meter.GetG_meterY(), Colors::Green);
		gun.DrawAmmo(gfx);

		if (Ball_1)
		{
			ball.Draw(gfx);
		}
		if (Ball_2)
		{
			ball2.Draw(gfx);
		}
		if (Ball_3)
		{
			ball3.Draw(gfx);
		}

		switch (level)
		{
		case Level::Lvl1:
			DrawLevel(Level::Lvl1);
			break;

		case Level::Lvl2:
			DrawLevel(Level::Lvl2);
			break;

		case Level::Lvl3:
			DrawLevel(Level::Lvl3);
			break;

		case Level::Lvl4:
			DrawLevel(Level::Lvl4);
			break;

		case Level::Lvl5:
			DrawLevel(Level::Lvl5);
			break;

		case Level::Lvl6:
			DrawLevel(Level::Lvl6);
			break;

		case Level::Lvl7:
			DrawLevel(Level::Lvl7);
			break;

		case Level::Lvl8:
			DrawLevel(Level::Lvl8);
			break;

		case Level::Lvl9:
			DrawLevel(Level::Lvl4);
			break;

		case Level::Testi:
			DrawLevel(Level::Testi);
			break;
		}
		
		if (GameOver)
		{
			DrawOver();
		}
	}

}

void Game::BrickCollision(Brick* bricks, Brick::State* state, Ball& ball, int BrickTotal_lvl1, float dt)
{

	bool BallCollisionhappend = false;
	bool AmmoCollisionhappend = false;
	float CurColDist;
	int CurColIndex;
	bool allDestroyed = true;
	for (int i = 0; i < BrickTotal_lvl1; i++)
	{
		if (bricks[i].ColorChange)
		{
			bricks[i].SetColor('P');
		}
		if (bricks[i].ColorFlash)
		{
			bricks[i].SetColor('F');
		}

		allDestroyed = allDestroyed && bricks[i].GetDestroyed() == true;

		if (bricks[i].CheckBallCollision(ball))
		{
			const float newColDist = (ball.GetPos() - bricks[i].GetCenter()).GetLengthSq();
			if (BallCollisionhappend)
			{
				if (newColDist < CurColDist)
				{
					CurColDist = newColDist;
					CurColIndex = i;
				}
			}
			else
			{
				CurColDist = newColDist;
				CurColIndex = i;
				BallCollisionhappend = true;
			}
		}
		if (bricks[i].CheckAmmoCollision(gun))
		{
			const float newColDist = (gun.GetPos() - bricks[i].GetCenter()).GetLengthSq();
			if (AmmoCollisionhappend)
			{
				if (newColDist < CurColDist)
				{
					CurColDist = newColDist;
					CurColIndex = i;
				}
			}
			else
			{
				CurColDist = newColDist;
				CurColIndex = i;
				AmmoCollisionhappend = true;
			}
		}
	}
	if (allDestroyed)
	{
		LvlUp = true;
		ball.SetSpeed('0');
		Ball_2 = false;
		Ball_3 = false;
	}
	if (BallCollisionhappend || AmmoCollisionhappend)
	{
		if (BallCollisionhappend)
		{
			bricks[CurColIndex].ExecuteBallCollision(ball);
		}
		if (AmmoCollisionhappend)
		{
			gun.SetGuns(false);
		}
		
		if (state[CurColIndex] == Brick::State::indestructible)
		{
			bricks[CurColIndex].ColorFlash = true;
		}
		else if (state[CurColIndex] == Brick::State::Basic)
		{
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::Broken)
		{
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::TwoHit)
		{
			bricks[CurColIndex].Setfirstcol();
			state[CurColIndex] = Brick::State::Broken;
		}
		else if (state[CurColIndex] == Brick::State::SpeedUp)
		{
			ball.SetSpeed('+');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::SpeedDown)
		{
			ball.SetSpeed('-');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::LifeUp)
		{
			life.SetLife('+');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::MeterUp)
		{
			meter.SetRedM(life);
			meter.SetGreenM('+');
			meter.SetBlueM('+');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::MeterFull)
		{
			meter.SetBlueM('F');
			meter.SetGreenM('F');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::Catcher)
		{
			pad.SetCatch();
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::MultipleBalls)
		{
			Ball_2 = true;
			Ball_3 = true;
			const Vec2 pos = bricks[CurColIndex].GetCenter();
			ball2 = Ball(Vec2(pos), Vec2(0.4f, -1.0f));
			ball3 = Ball(Vec2(pos), Vec2(-0.4f, -1.0f));
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::LargePad)
		{
			pad.padsize = Paddle::PadSize::Large;
			bricks[CurColIndex].SetDestr();
		}
	}

}


void Game::DrawTitle()
{
	gfx.DrawRect(370, 280, 430, 350, Colors::Blue);
}

void Game::DrawOver()
{
	gfx.DrawRect(370, 280, 430, 350, Colors::Red);
}

void Game::DrawLevel(const Level level)
{
	if (level == Level::Lvl1)
	{
		for (const Brick& b : bricks)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl2)
	{
		for (const Brick& b : bricks2)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl3)
	{
		for (const Brick& b : bricks3)
		{
			b.Draw(gfx);
		}
		for (const Brick& b : bricks3_1)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl4)
	{
		for (const Brick& b : bricks4)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl5)
	{
		for (const Brick& b : bricks5)
		{
			b.Draw(gfx);
		}
		for (const Brick& b : bricks5_1)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl6)
	{
		for (const Brick& b : bricks6)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Lvl7)
	{
		for (const Brick& b : bricks7)
		{
			b.Draw(gfx);
		}
		for (const Brick& b : bricks7_1)
		{
			b.Draw(gfx);
		}
	}
	else if (level == Level::Testi)
	{
		for (const Brick& b : bricksTesti)
		{
			b.Draw(gfx);
		}
	}
}

void Game::Timer(float dt)
{


}



