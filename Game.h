/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void CreatePads(int x, int y, int r, int g, int b);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	int x = 400, y = 300;
	int r = 0, g = 0, b = 0;
	int vx = 0, vy = 0;
	bool inhibitUp = false, inhibitDown = false, inhibitLeft = false, inhibitRight = false;
	bool game_is_live = false;
	int player1_x = 0, player2_x = 0, player1_y = 0, player2_y = 0;
	int flag_x = -3;
	int flag_y = 0;
	int player1_r = 255, player1_g = 0, player1_b = 0, player2_r = 255, player2_g = 0, player2_b = 0;
	bool game_over = false;
	/********************************/
	/*  User Variables              */
	/********************************/
};