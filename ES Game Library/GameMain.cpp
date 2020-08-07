// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));
	player = GraphicsDevice.CreateSpriteFromFile(_T("ÉvÉçÉg.png"));
	player_swing = GraphicsDevice.CreateSpriteFromFile(_T("player2.png"));
	map = GraphicsDevice.CreateSpriteFromFile(_T("map.png"));
	perfect = GraphicsDevice.CreateSpriteFromFile(_T("perfect.png"));
	good = GraphicsDevice.CreateSpriteFromFile(_T("good.png"));
	miss = GraphicsDevice.CreateSpriteFromFile(_T("miss.png"));
	life = GraphicsDevice.CreateSpriteFromFile(_T("life.png"));
	player_x = 100;
	player_y = 350;
	swing_flg = 0;
	pc_x = 1200;
	pc_y = 500;
	life_y = 0;
	clip_x = 0;
	DefaultFont = GraphicsDevice.CreateDefaultFont();
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	player_collision = Rect(player_x + 150, player_y + 130, player_x + 250.0f, player_y + 220.0f);
	perfect_collision = Rect(player_x +150, player_y + 130, player_x + 180.0f, player_y + 220.0f);
	pc_collision = Rect(pc_x + 0, pc_y + 0, pc_x + 100.0f, pc_y + 100.0f);
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buf = Keyboard->GetBuffer();
	// TODO: Add your update logic here
	if (key.IsKeyDown(Keys_Space)&& swing_flg == 0)
	{
		swing_flg = 1;
		if (player_collision.Intersect(pc_collision)||clip_x == 2100) {
			if (range < 150)
			{
				hit_test = 1;
			}
			if (range > 150)
			{
 				hit_test = 2;
			}
		}
		else
		{
			if (range > 250 && range< 400)
			{
				hit_test = 3;
				life_y += 65;
			}
		}
	}
	if (key.IsKeyUp(Keys_Space) && swing_flg == 1)
	{
		clip_x = 0;
		hit_test = 0;
		swing_flg = 0;
	}
	pc_x -= 5;
	if (pc_x < 0)
	{
		pc_x = 1280;
	}
	range = pc_x - player_x;
	if (swing_flg == 1)
	{
		clip_x += 300;
		if (clip_x >= 2100)
		{
			clip_x = 2100;
		}
	}
	//ìñÇΩÇËîªíËìØémÇÃãóó£Çë™Ç¡ÇƒîªíË
	KeyboardBuffer Key_buf = Keyboard->GetBuffer();
	if (Key_buf.IsPressed(Keys_A))
	{
		return GAME_SCENE(new titleScene);
	}
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	SpriteBatch.Draw(*map, Vector3(0, 0, 0));
	SpriteBatch.Draw(*player, Vector3(player_x, player_y, 0), RectWH(clip_x, 0, 300, 300));
	if(hit_test == 1)SpriteBatch.Draw(*perfect, Vector3(300, 400, 0));
	if(hit_test == 2)SpriteBatch.Draw(*good, Vector3(280, 400, 0));
	if(hit_test == 3)SpriteBatch.Draw(*miss, Vector3(280, 400, 0));
	SpriteBatch.Draw(*life, Vector3(0, life_y, 0), RectWH(0, life_y, 90, 190));
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 0), Color(0, 0, 0), _T("ãóó£:%f"), range);
	SpriteBatch.End();

	GraphicsDevice.EndScene();
	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	//paint.SetPaintColor(Color_Red);
	//canvas.DrawRect(player_collision, paint);
	//paint.SetPaintColor(Color_Green);
	//canvas.DrawRect(perfect_collision, paint);
	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(pc_collision, paint);

	GraphicsDevice.UnlockCanvas();
}
