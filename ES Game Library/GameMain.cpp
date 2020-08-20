// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

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

	髙橋Initialize();

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
	// TODO: Add your update logic here

	髙橋Main();

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

	髙橋Draw();

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(当たり判定_collision, paint);

	for (int i = 0; i < 物の数; i++) {

		if (物_state[i] == 1) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(テレビ_collision[i], paint);
		}
		else if (物_state[i] == 2) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(カメラ_collision[i], paint);
		}
		else if (物_state[i] == 3) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(電子レンジ_collision[i], paint);
		}
	}

	GraphicsDevice.UnlockCanvas();
}

void GameMain::髙橋Initialize() {

	背景 = GraphicsDevice.CreateSpriteFromFile(_T("背景.png"));
	プレイヤー = GraphicsDevice.CreateSpriteFromFile(_T("プレイヤー.png"));
	テレビ = GraphicsDevice.CreateSpriteFromFile(_T("テレビ.png"));
	カメラ = GraphicsDevice.CreateSpriteFromFile(_T("カメラ.png"));
	電子レンジ = GraphicsDevice.CreateSpriteFromFile(_T("電子レンジ.png"));
	当たり判定 = GraphicsDevice.CreateSpriteFromFile(_T("当たり判定.png"));
	フォント = GraphicsDevice.CreateSpriteFont(_T("MSゴシック"), 50);

	MediaManager.Attach(GraphicsDevice);

	ムービー = MediaManager.CreateMediaFromFile(_T("シャイニングスターショート.mp3"));

	カメラ速度 = 20;
	電子レンジ速度 = 5;
	テレビ速度 = 10;
	秒 = 0;
	一秒 = 0;
	開始_state = 0;
	ムービー時間 = 0;
	デバック = 0;

	for (int i = 0; i < 物の数; i++) {
		ゴール[i] = 100 + (150 * i);
		テレビ_x[i] = 0;
		テレビ_y[i] = 400;
		カメラ_x[i] = 0;
		カメラ_y[i] = 400;
		電子レンジ_x[i] = 0;
		電子レンジ_y[i] = 400;
		//テレビ動き_state[i] = 0;
		スピード_y[i] = 12;
		シータ[i] = 0;
	}

	物_state[0] = 1;

	for (int i = 1; i < 物の数; i++) {
		物_state[i] = MathHelper_Random(1, 3);
	}

	プレイヤー_x = 100;
	プレイヤー_y = 400;
	当たり判定_x = 200;
	当たり判定_y = 500;
	//テレビ動き = 5;

	/*std::ifstream game_file("ゲームデータ.txt");
	std::string dummy_line;

	game_file >> タイミング[0];

	game_file >> タイミング[1];

	game_file >> タイミング[2];

	game_file >> タイミング[3];

	game_file >> タイミング[4];*/
}

void GameMain::髙橋Main() {

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

			if (物_state[i] == 1) {
				テレビ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * テレビ速度;
				テレビ_collision[i] = Rect(テレビ_x[i], テレビ_y[i], テレビ_x[i] + 100, テレビ_y[i] + 250);

				/*if (テレビ_x[i] < 1280) {

					if (テレビ_y[i] < 300) {
						放物線_state[i] = 1;
					}

					if (放物線_state[i] == 0) {
						テレビ_y[i] -= 放物線;
					}
					else if (放物線_state[i] == 1) {
						テレビ_y[i] += 放物線;
					}
				}*/
			}
			else if (物_state[i] == 2) {
				カメラ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * カメラ速度;
				カメラ_collision[i] = Rect(カメラ_x[i], カメラ_y[i], カメラ_x[i] + 60, カメラ_y[i] + 64);

				if (カメラ_x[i] < 1280) {
					カメラ_y[i] = カメラ_y[i] - (スピード_y[i]--);
				}
			}
			else if (物_state[i] == 3) {
				電子レンジ_x[i] = プレイヤー_x + (ゴール[i] - ムービー時間) * 電子レンジ速度;
				電子レンジ_collision[i] = Rect(電子レンジ_x[i] - 3, 電子レンジ_y[i], 電子レンジ_x[i] + 100, 電子レンジ_y[i] + 150);

				if (電子レンジ_x[i] < 1280) {

					電子レンジ_x[i] = 電子レンジ_x[i] - 2;
////                                             動かしたいドット数↓　　↓最初の描画位置　 
					電子レンジ_y[i] = MathHelper_Sin(シータ[i]) * 100 + 400;
					シータ[i] = シータ[i] + 1;
				}
			}

			if (開始_state == 1) {

				if (テレビ_x[i] < -400) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					スピード_y[i] = 0;
				}

				if (カメラ_x[i] < -400) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					スピード_y[i] = 0;
				}

				if (電子レンジ_x[i] < -400) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					スピード_y[i] = 0;
				}
			}
			else if (開始_state == 2) {

				if (テレビ_x[i] < -500) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					開始_state = 3;
				}

				if (カメラ_x[i] < -500) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					開始_state = 3;
				}

				if (電子レンジ_x[i] < -500) {
					物_state[i] = 0;
					//テレビ動き_state[i] = 0;
					開始_state = 3;
				}
			}
		}
	}

	if (一秒 == 85) {
		開始_state = 2;
	}
}

void GameMain::髙橋Draw() {

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
				SpriteBatch.Draw(*カメラ, Vector3(カメラ_x[i], カメラ_y[i], 0.0f));
			}
			else if (物_state[i] == 3) {
				SpriteBatch.Draw(*電子レンジ, Vector3(電子レンジ_x[i], 電子レンジ_y[i], 0.0f));
			}
		}
	}
}