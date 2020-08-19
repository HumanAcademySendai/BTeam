// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

int GameMain::score = 0;

#include <fstream>

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));
	player = GraphicsDevice.CreateSpriteFromFile(_T("プロト.png"));
	player_swing = GraphicsDevice.CreateSpriteFromFile(_T("player2.png"));
	map = GraphicsDevice.CreateSpriteFromFile(_T("map.png"));
	perfect = GraphicsDevice.CreateSpriteFromFile(_T("perfect.png"));
	good = GraphicsDevice.CreateSpriteFromFile(_T("good.png"));
	miss = GraphicsDevice.CreateSpriteFromFile(_T("miss.png"));
	life = GraphicsDevice.CreateSpriteFromFile(_T("life.png"));
	Tv = GraphicsDevice.CreateSpriteFromFile(_T("Tv.png"));
	good_point = GraphicsDevice.CreateSpriteFromFile(_T("good_point.png"));
	perfect_point = GraphicsDevice.CreateSpriteFromFile(_T("Perfect_point.png"));
	circle = GraphicsDevice.CreateSpriteFromFile(_T("circle.png"));
	hit_point = GraphicsDevice.CreateSpriteFromFile(_T("hit_point.png"));
	good_se = SoundDevice.CreateSoundFromFile(_T("good.wav"));
	perfect_se = SoundDevice.CreateSoundFromFile(_T("perfect.wav"));
	miss_se = SoundDevice.CreateSoundFromFile(_T("空振り.wav"));
	player_x = 100;
	player_y = 350;
	swing_flg = 0;
	Tv_x = 1200;
	Tv_y = 400;
	life_y = 0;
	clip_x = 0;
	count = 1500;
	perfect_x = 270;
	perfect_y = 450;
	good_x = 360;
	good_y = 450;
	GameMain::score = 0;
	hitcount = false;
	swing_flg = false;
	Tv_alpha = 1;
	big = 1;
	circle_alpha = 0.5;
	DefaultFont = GraphicsDevice.CreateDefaultFont();

	背景 = GraphicsDevice.CreateSpriteFromFile(_T("背景.png")); 
	プレイヤー = GraphicsDevice.CreateSpriteFromFile(_T("プレイヤー.png"));
	テレビ = GraphicsDevice.CreateSpriteFromFile(_T("テレビ.png"));
	カメラ = GraphicsDevice.CreateSpriteFromFile(_T("カメラ.png"));
	電子レンジ = GraphicsDevice.CreateSpriteFromFile(_T("電子レンジ.png"));
	当たり判定 = GraphicsDevice.CreateSpriteFromFile(_T("当たり判定.png"));
	フォント = GraphicsDevice.CreateSpriteFont(_T("MSゴシック"), 50);

	MediaManager.Attach(GraphicsDevice);

	ムービー = MediaManager.CreateMediaFromFile(_T("シャイニングスターショート.mp3"));

	カメラ速度 = 16;
	電子レンジ速度 = 15;
	テレビ速度 = 10;
	秒 = 0;
	一秒 = 0;
	開始_state = 0;
	ムービー時間 = 0;
	デバック = 0;

	for (int i = 0; i < 物の数; i++) {
		ゴール[i] = 100 + (150 * i);
		物_state[i] = MathHelper_Random(1, 3);
		テレビ_x[i] = 0;
		テレビ_y[i] = 400;
		放物線_state[i] = 0;
		スピード_y[i] = 15;
	}

	プレイヤー_x = 100;
	プレイヤー_y = 400;
	当たり判定_x = 200;
	当たり判定_y = 500;
	放物線 = 5;

	/*std::ifstream game_file("ゲームデータ.txt");
	std::string dummy_line;

	game_file >> タイミング[0];

	game_file >> タイミング[1];

	game_file >> タイミング[2];

	game_file >> タイミング[3];

	game_file >> タイミング[4];*/

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
	good_collision = Rect(good_x, good_y, good_x + 200.0f, good_y + 90.0f);
	perfect_collision = Rect(perfect_x, perfect_y, perfect_x + 90.0f, perfect_y + 90.0f);
	Tv_collision = Rect(Tv_x + 20, Tv_y + 0, Tv_x + 100.0f, Tv_y + 100.0f);
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buf = Keyboard->GetBuffer();
	// TODO: Add your update logic here

	ムービー時間 = ムービー->GetPosition() / 100000;

	秒 += 1;

	if (秒 == 60) {
		一秒 += 1;
		秒 = 0;
	}

	if (一秒 == 3) {
		開始_state = 1;
	}

	if (開始_state == 1 || 開始_state == 2) {

		ムービー->Play();

		for (int i = 0; i < 物の数; i++) {

			当たり判定_collision = Rect(当たり判定_x, 当たり判定_y, 当たり判定_x + 150, 当たり判定_y + 90);
			物_collision[i] = Rect(テレビ_x[i], テレビ_y[i], テレビ_x[i] + 100, テレビ_y[i] + 100);

			if (物_state[i] == 1) {
				テレビ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * テレビ速度;

				if (テレビ_x[i] < 1280) {

					if (テレビ_y[i] < 300) {
						放物線_state[i] = 1;
					}

					if (放物線_state[i] == 0) {
						テレビ_y[i] -= 放物線;
					}
					else if (放物線_state[i] == 1) {
						テレビ_y[i] += 放物線;
					}
				}
				else if (物_state[i] == 2) {
					テレビ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * カメラ速度;

					if (テレビ_x[i] < 1280) {
						テレビ_y[i] = テレビ_y[i] - (スピード_y[i]--);
					}
				}
				else if (物_state[i] == 3) {
					テレビ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * 電子レンジ速度;
				}

				if (開始_state == 1) {

					if (テレビ_x[i] < -400) {
						物_state[i] = 0;
						放物線_state[i] = 0;
						スピード_y[i] = 0;
					}
				}
				else if (開始_state == 2) {

					if (テレビ_x[i] < -500) {
						物_state[i] = 0;
						放物線_state[i] = 0;
						開始_state = 3;
					}
				}
			}
		}
	}

	if (key.IsKeyDown(Keys_Space)&& swing_flg == false)
	{
		swing_flg = true;
		if (perfect_collision.Intersect(Tv_collision) && hitcount == false)
			{
				hit_test = 1;
				score += 300;
				hitcount = true;
				Tv_alpha = 0;
				perfect_se->Play();
			}
			else if (good_collision.Intersect(Tv_collision) && hitcount == false)
			{
 				hit_test = 2;
				score += 100;
				hitcount = true;
				Tv_alpha = 0;
				good_se->Play();
			}
		else if (range > 250 && range< 500)
			{
				hit_test = 3;
				miss_se->Play();
			}
		else
		{
			miss_se->Play();
		}
	}
	if (key.IsKeyUp(Keys_Space) && swing_flg == true)
	{
		clip_x = 0;
		hit_test = 0;
		swing_flg = false;
	}
	Tv_x -= 15;
	if (Tv_x < -250)
	{
		hitcount = false;
		Tv_x = 1280;
		Tv_alpha = 1;
		big = 1;
	}
	range = Tv_x - player_x;
	if (swing_flg == true)
	{
		clip_x += 300;
		if (clip_x >= 2100)
		{
			clip_x = 2100;
		}
	}
		
	count--;
	big -= 0.011;
	if (big <= 0)
	{
		big = 0;
	}
	if (count <= 1000)
	{
		circle_alpha -= 0.01;
	}
	if (circle_alpha <= 0)
	{
		circle_alpha = 0;
	}
	//当たり判定同士の距離を測って判定
	if (count <= 0)
	{
		return GAME_SCENE(new clearScene);
	}
	//検証用
	if (key_buf.IsPressed(Keys_A))
	{
		return GAME_SCENE(new clearScene);
	}

	if (一秒 == 85) {
		開始_state = 2;
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
	SpriteBatch.Draw(*Tv, Vector3(Tv_x, Tv_y, 0), Tv_alpha);
	//SpriteBatch.Draw(*good_point, Vector3(good_x, good_y, 0));
	//SpriteBatch.Draw(*perfect_point, Vector3(perfect_x, perfect_y, 0));
	SpriteBatch.Draw(*hit_point, Vector3(300, 400, 0));
	SpriteBatch.Draw(*circle, Vector3(200, 300, 0), circle_alpha, Vector3(0, 0, 1), Vector3(200, 200, 0), Vector2(big, big));
	SpriteBatch.Draw(*player, Vector3(player_x, player_y, 0), RectWH(clip_x, 0, 300, 300));
	if(hit_test == 1)SpriteBatch.Draw(*perfect, Vector3(300, 400, 0));
	if(hit_test == 2)SpriteBatch.Draw(*good, Vector3(280, 400, 0));
	if(hit_test == 3)SpriteBatch.Draw(*miss, Vector3(280, 400, 0));
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 0), Color(0, 0, 0), _T("距離:%f"), range);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 20), Color(0, 0, 0), _T("タイム:%d"), count);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 40), Color(0, 0, 0), _T("スコア:%d"), score);
	//SpriteBatch.Draw(*movie, Vector3(0, 200, 0), 0.5f, Vector3(0, 0, 50), Vector3(640, 360, 0), Vector2(0.25f, 0.25f));
	//	透明度　拡大　回転軸　横幅縦幅

	SpriteBatch.DrawString(フォント, Vector2(0, 0), Color(255, 255, 255), _T("%ld"), ムービー->GetPosition() / 100000);
	SpriteBatch.DrawString(フォント, Vector2(500, 0), Color(255, 255, 255), _T("%d"), 一秒);

	if (開始_state == 3) {
		SpriteBatch.DrawString(フォント, Vector2(1000, 0), Color(255, 255, 255), _T("クリア"));
	}
	SpriteBatch.Draw(*背景, Vector3(0.0f, 0.0f, 10.0f));
	SpriteBatch.Draw(*プレイヤー, Vector3(プレイヤー_x, プレイヤー_y, 0.0f));
	SpriteBatch.Draw(*当たり判定, Vector3(当たり判定_x, 当たり判定_y, 0.0f));

	if (デバック == 1) {
		SpriteBatch.DrawString(フォント, Vector2(1000, 50), Color(255, 255, 255), _T("当たってる"));
	}

	if (開始_state == 1 || 開始_state == 2) {

		for (int i = 0; i < 物の数; i++) {

			if (物_state[i] == 1) {
				SpriteBatch.Draw(*テレビ, Vector3(テレビ_x[i], テレビ_y[i], 0.0f));
			}
			else if (物_state[i] == 2) {
				SpriteBatch.Draw(*カメラ, Vector3(テレビ_x[i], テレビ_y[i], 0.0f));
			}
			else if (物_state[i] == 3) {
				SpriteBatch.Draw(*電子レンジ, Vector3(テレビ_x[i], テレビ_y[i], 0.0f));
			}
		}
	}

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;


	//paint.SetPaintColor(Color_Red);
	//canvas.DrawRect(good_collision, paint);
	//paint.SetPaintColor(Color_Green);
	//canvas.DrawRect(perfect_collision, paint);
	//paint.SetPaintColor(Color_Blue);
	//canvas.DrawRect(Tv_collision, paint);
	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(当たり判定_collision, paint);

	for (int i = 0; i < 物の数; i++) {

		paint.SetPaintColor(Color_Red);
		canvas.DrawRect(物_collision[i], paint);
	}

	GraphicsDevice.UnlockCanvas();
}