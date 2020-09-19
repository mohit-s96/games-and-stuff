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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	bool cond = wnd.kbd.KeyIsPressed(VK_UP);
	bool cond1 = wnd.kbd.KeyIsPressed(VK_DOWN);
	bool cond5 = wnd.kbd.KeyIsPressed(VK_CONTROL);
	bool cond6 = wnd.kbd.KeyIsPressed(VK_TAB);
	bool cond_start = wnd.kbd.KeyIsPressed(VK_SPACE);
	if (!game_over)
	{
		if (!game_is_live)
		{
			player1_y = player2_y = 300;
			player1_x = 20;
			player2_x = 780;
		}
		if (cond_start)
		{
			if (!game_is_live)
			{
				game_is_live = true;
			}
		}
		if (cond)
			player2_y -= 3;
		if (cond1)		 
			player2_y += 3;
		if (cond5)		 
			player1_y += 3;
		if (cond6)		 
			player1_y -= 3;
		if (player1_y < 23)
			player1_y = 23;
		if (player1_y > 577)
			player1_y = 577;
		if (player2_y < 23)
			player2_y = 23;
		if (player2_y > 577)
			player2_y = 577;
		if (game_is_live)
		{
			x = x + flag_x;
			y = y + flag_y;
			r = g = b = 255;
			if ((y + 5 >= player1_y - 15) && (x - 5 <= player1_x + 8) && (y - 5) <= player1_y + 15)
			{
				flag_x = 3;
				if (y > player1_y)
					flag_y = 2;
				if (y < player1_y)
					flag_y = -2;
			}
			if ((y + 5 >= player2_y - 15) && (x + 5 >= player2_x - 8) && (y - 5) <= player2_y + 15)
			{
				flag_x = -3;
				if (y > player2_y)
					flag_y = 2;
				if (y < player2_y)
					flag_y = -2;
			}

			if (y > 590)
			{
				flag_y = -2;
			}
			if (y < 10)
			{
				flag_y = 2;
			}

			if (x > 790)
			{
				player1_r = player1_b = 0;
				player1_g = 255;
				x = 790;
				game_over = true;
			}
			if (x < 10)
			{
				player2_r = player2_b = 0;
				player2_g = 255;
				x = 10;
				game_over = true;
			}
		}
	}
	
}

void Game::CreatePads(int x, int y, int r, int g, int b)
{
	for (int i = -3; i <= 3; i++)
	{
		for (int j = -20; j <= 20; j++)
		{
			gfx.PutPixel(x + i, y+ j, r, g, b);
		}
	}
}

void Game::ComposeFrame()
{
	for (int i = -5; i < 6; i++) {
		if (i != -1 && i != 0 && i != 1) {
			gfx.PutPixel(x + i, y, r, g, b);
			gfx.PutPixel(x, y + i, r, g, b);
		}
	}
	CreatePads(player1_x, player1_y, player1_r, player1_g, player1_b);
	CreatePads(player2_x, player2_y, player2_r, player2_g, player2_b);
}	


