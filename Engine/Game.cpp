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
	
	{	//Level 1
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
			if (y == 0)
			{
				state[i] = Brick::State::BlueMeterUp;
			}

			i++;
		}
	}
	}				

	{	//Level 2
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

	{	//Level 3
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
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (Started && !GameOver)
	{

		if (!ResetBall)
		{
			ball.Movement(dt);
		}
		else
		{
			ball.SetPos(pad);

		}
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			ResetBall = false;
		}

		if (wnd.kbd.KeyIsPressed(VK_CONTROL) && Meter.GetBlueMeter() <= Meter.GetMeterMin())
		{
			Meter.SetBlueM('-');
			ball.SetSpeed('s');
		}
		else
		{
			ball.SetSpeed('r');
		}
		if (wnd.kbd.KeyIsPressed(VK_TAB))
		{
			Meter.SetBlueM('+');
		}


		if (ball.GetFail())
		{
			Life.SetLife('-');
			ResetBall = true;
			ball.SetFail();

			if (Life.GetLife() == 0)
			{
				GameOver = true;
			}
		}

		if (ball.DoWallCollision(walls))
		{
			pad.ResetCooldown();
		}
		pad.Movement(wnd.kbd, dt);
		pad.WallCollision(walls);
		pad.BallCollision(ball);

		if (Lvl1)
		{
			BrickCollision(bricks, state, BrickTotal_lvl1);
			if (LvlUp)
			{
				Lvl1 = false;
				Lvl2 = true;
				ResetBall = true;
				LvlUp = false;
			}
		}
		else if (Lvl2)
		{
			BrickCollision(bricks2, state2, BrickTotal_lvl2);
			if (LvlUp)
			{
				Lvl2 = false;
				Lvl3 = true;
				ResetBall = true;
				LvlUp = false;
			}
		}
		else if (Lvl3)
		{
			BrickCollision(bricks3, state3, BrickTotal_lvl3);
			BrickCollision(bricks3_1, state3_1, BrickTotal_lvl3_1);
			if (LvlUp)
			{
				Lvl3 = false;
				Lvl4 = true;
				ResetBall = true;
				LvlUp = false;
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			Started = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_F2))			//Level oikotie "testiä"
		{
			Lvl1 = false;
			Lvl2 = true;
			ResetBall = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_F3))
		{
			Lvl1 = false;
			Lvl2 = false;
			Lvl3 = true;
			ResetBall = true;
		}
	}
	

}



void Game::ComposeFrame()
{
	if (!Started)
	{
		DrawTitle();
	}
	else
	{

		leftwall.DrawWall(gfx);
		rightwall.DrawWall(gfx);
		topwall.DrawWall(gfx);
		Life.DrawLife(gfx);
		ball.Draw(gfx);
		pad.Draw(gfx);
		Meter.DrawBlueMeter(gfx);
	
		if (Lvl1)
		{
			for (const Brick& b : bricks)
			{
				b.Draw(gfx);
			}
		}
		else if (Lvl2)
		{
			for (const Brick& b : bricks2)
			{
				b.Draw(gfx);
			}
		}
		else if (Lvl3)
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
		else if (Lvl4)
		{
			DrawTitle();
		}
		if (GameOver)
		{
			DrawOver();
		}
	}
}

void Game::BrickCollision(Brick* bricks, Brick::State* state, int BrickTotal_lvl1)
{

	bool Collisionhappend = false;
	float CurColDist;
	int CurColIndex;
	bool allDestroyed = true;
	for (int i = 0; i < BrickTotal_lvl1; i++)
	{
		allDestroyed = allDestroyed && bricks[i].GetDestroyed() == true;

		if (bricks[i].CheckBallCollision(ball))
		{
			const float newColDist = (ball.GetPos() - bricks[i].GetCenter()).GetLengthSq();
			if (Collisionhappend)
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
				Collisionhappend = true;
			}
		}
	}
	if (allDestroyed)
	{
		LvlUp = true;
	}
	if (Collisionhappend)
	{
		bricks[CurColIndex].ExecuteBallCollision(ball);
		pad.ResetCooldown();

		if (state[CurColIndex] == Brick::State::indestructible)
		{

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
			Life.SetLife('+');
			bricks[CurColIndex].SetDestr();
		}
		else if (state[CurColIndex] == Brick::State::BlueMeterUp)
		{
			Meter.SetBlueM('+');
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

