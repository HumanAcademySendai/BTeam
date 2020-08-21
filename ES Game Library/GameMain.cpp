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
	DefaultFont = GraphicsDevice.CreateDefaultFont();

	ûü´Initialize();
	iwai_Initialize();

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
int GameMain::Update()
{
	ûü´Main();
	iwai_Update();
	//½è»è¯mÌ£ðªÁÄ»è
	if (count <= 0)
	{
		return GAME_SCENE(new clearScene);
	}
	//Øp
	if (key_buf.IsPressed(Keys_A))
	{
		return GAME_SCENE(new clearScene);
	}

	return 0;

}
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();

	ûü´Draw();
	iwai_Draw();

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;


	/*paint.SetPaintColor(Color_Red);
	canvas.DrawRect(good_collision, paint);
	paint.SetPaintColor(Color_Green);
	canvas.DrawRect(perfect_collision, paint);
	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(Tv_collision, paint);
	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(½è»è_collision, paint);
	for (int i = 0; i < ¨Ì; i++) {

		if (¨_state[i] == 1) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(er_collision[i], paint);
		}
		else if (¨_state[i] == 2) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(J_collision[i], paint);
		}
		else if (¨_state[i] == 3) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(dqW_collision[i], paint);
		}
	}*/
	GraphicsDevice.UnlockCanvas();
}
void GameMain::iwai_Initialize() {
	player = GraphicsDevice.CreateSpriteFromFile(_T("vg.png"));
	player_swing = GraphicsDevice.CreateSpriteFromFile(_T("player2.png"));
	map = GraphicsDevice.CreateSpriteFromFile(_T("map.png"));
	perfect = GraphicsDevice.CreateSpriteFromFile(_T("perfect.png"));
	good = GraphicsDevice.CreateSpriteFromFile(_T("good.png"));
	miss = GraphicsDevice.CreateSpriteFromFile(_T("miss.png"));
	life = GraphicsDevice.CreateSpriteFromFile(_T("life.png"));
	Tv = GraphicsDevice.CreateSpriteFromFile(_T("Tv.png"));
//	good_point = GraphicsDevice.CreateSpriteFromFile(_T("good_point.png"));
//	perfect_point = GraphicsDevice.CreateSpriteFromFile(_T("Perfect_point.png"));
	circle = GraphicsDevice.CreateSpriteFromFile(_T("circle.png"));
	hit_point = GraphicsDevice.CreateSpriteFromFile(_T("hit_point.png"));
	good_se = SoundDevice.CreateSoundFromFile(_T("good.wav"));
	perfect_se = SoundDevice.CreateSoundFromFile(_T("perfect.wav"));
	miss_se = SoundDevice.CreateSoundFromFile(_T("óUè.wav"));
	explosion = GraphicsDevice.CreateAnimationModelFromFile(_T("bakuha.x"));
	player_x = 100;
	player_y = 350;
	swing_flg = 0;
	Tv_x = 1200;
	Tv_y = 400;
	life_y = 0;
	clip_x = 0;
	count = 1500;
	perfect_x = 280;
	perfect_y = 400;
	good_x = 300;
	good_y = 400;
	GameMain::score = 0;
	hitcount = false;
	swing_flg = false;
	Tv_alpha = 1;
	hard_speed = 1;
	explosion->SetScale(1, -1, 1);
	explosion->SetPosition(640, 360, 0);
	explosion->SetTrackEnable(0, TRUE);
	for (int i = 0; i < ¨Ì; i++)
	{

		big[i] = 1;
		circle_alpha[i] = 0;
	}
}
void GameMain::iwai_Draw() {
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();
	explosion->Draw();
	SpriteBatch.Begin();
	SpriteBatch.Draw(*map, Vector3(0, 0, 0));
	SpriteBatch.Draw(*Tv, Vector3(Tv_x, Tv_y, 0), Tv_alpha);
//	SpriteBatch.Draw(*good_point, Vector3(good_x, good_y, 0));
//	SpriteBatch.Draw(*perfect_point, Vector3(perfect_x, perfect_y, 0));
	SpriteBatch.Draw(*hit_point, Vector3(300, 400, -100));
	for (int i = 0; i < ¨Ì; i++)
	{
		SpriteBatch.Draw(*circle, Vector3(200, 300, -10), circle_alpha[i], Vector3(0, 0, 1), Vector3(200, 200, 0), Vector2(big[i], big[i]));
	}
	SpriteBatch.Draw(*player, Vector3(player_x, player_y, 0), RectWH(clip_x, 0, 300, 300));
	if (hit_test == 1)SpriteBatch.Draw(*perfect, Vector3(300, 400, 0));
	if (hit_test == 2)SpriteBatch.Draw(*good, Vector3(280, 400, 0));
	if (hit_test == 3)SpriteBatch.Draw(*miss, Vector3(280, 400, 0));
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 0), Color(0, 0, 0), _T("£:%f"), range);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 20), Color(0, 0, 0), _T("^C:%d"), count);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 40), Color(0, 0, 0), _T("XRA:%d"), score);
}
void GameMain::iwai_Update() {

	good_collision = Rect(good_x, good_y, good_x + 200.0f, good_y + 200.0f);
	perfect_collision = Rect(perfect_x + 70, perfect_y, perfect_x + 170.0f, perfect_y + 200.0f);
	Tv_collision = Rect(Tv_x + 20, Tv_y + 0, Tv_x + 100.0f, Tv_y + 100.0f);
		if (keyboard.IsKeyDown(Keys_Space) && swing_flg == false)
		{
			for (int i = 0; i < ¨Ì; i++)
			{
				swing_flg = true;
				if (perfect_collision.Intersect(er_collision[i]) && hitcount == false|| perfect_collision.Intersect(J_collision[i]) && hitcount == false|| perfect_collision.Intersect(dqW_collision[i]) && hitcount == false)
				{
					hit_test = 1;
					score += 300;
					hitcount = true;
					perfect_se->Play();
				}
				else if (good_collision.Intersect(er_collision[i]) && hitcount == false)
				{
					hit_test = 2;
					score += 100;
					hitcount = true;
					good_se->Play();
				}
				else if (range > 250 && range < 500)
				{
					hit_test = 3;
					miss_se->Play();
				}
				else
				{
					miss_se->Play();
				}
			}
		}

	if (keyboard.IsKeyUp(Keys_Space) && swing_flg == true)
	{
		clip_x = 0;
		hit_test = 0;
		swing_flg = false;
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
	for (int i = 0; i < ¨Ì; i++)
	{
		if (big[i] <= 0)
		{
			big[i] = 0;
		}
	}
}
void GameMain::ûü´Initialize() {

	wi = GraphicsDevice.CreateSpriteFromFile(_T("wi.png"));
	iwai_Initialize();

	wi = GraphicsDevice.CreateSpriteFromFile(_T("wi.png"));
	vC[ = GraphicsDevice.CreateSpriteFromFile(_T("vC[.png"));
	er = GraphicsDevice.CreateSpriteFromFile(_T("er.png"));
	J = GraphicsDevice.CreateSpriteFromFile(_T("J.png"));
	dqW = GraphicsDevice.CreateSpriteFromFile(_T("dqW.png"));
	½è»è = GraphicsDevice.CreateSpriteFromFile(_T("½è»è.png"));
	tHg = GraphicsDevice.CreateSpriteFont(_T("MSSVbN"), 50);

	MediaManager.Attach(GraphicsDevice);

	[r[ = MediaManager.CreateMediaFromFile(_T("VCjOX^[V[g.mp3"));

	J¬x = 15 ;
	dqW¬x = 6 / titleScene::hard;
	er¬x = 10 * titleScene::hard;
	b = 0;
	êb = 0;
	Jn_state = 0;
	[r[Ô = 0;
	fobN = 0;

	for (int i = 0; i < ¨Ì; i++) {
		S[[i] = 100 + (150 * i);
		er_x[i] = 0;
		er_y[i] = 400;
		J_x[i] = 0;
		J_y[i] = 400;
		dqW_x[i] = 0;
		dqW_y[i] = 400;
		//er®«_state[i] = 0;
		Xs[h_y[i] = 7;
		V[^[i] = 0;
		t[i] = 0;
	}

	¨_state[0] = 1;

	for (int i = 1; i < ¨Ì; i++) {
		¨_state[i] = MathHelper_Random(1, 3);
	}

	vC[_x = 100;
	vC[_y = 400;
	½è»è_x = 200;
	½è»è_y = 500;
	//er®« = 5;
	|Cg[0] = Vector3(1280, 400, 0);
	|Cg[1] = Vector3(800, 300, 0);
	|Cg[2] = Vector3(700, 300, 0);
	|Cg[3] = Vector3(500, 400, 0);


	/*std::ifstream game_file("Q[f[^.txt");
	std::string dummy_line;

	game_file >> ^C~O[0];

	game_file >> ^C~O[1];

	game_file >> ^C~O[2];

	game_file >> ^C~O[3];

	game_file >> ^C~O[4];*/
}

void GameMain::ûü´Main() {

	keyboard = Keyboard->GetState();
	key_buf = Keyboard->GetBuffer();
	// TODO: Add your update logic here

	[r[Ô = [r[->GetPosition() / 100000;

	b += 1;

	if (b == 60) {
		êb += 1;
		b = 0;
	}

	if (êb == 3) {
		Jn_state = 1;
	}

	if (Jn_state == 1 || Jn_state == 2) {

		[r[->Play();

		for (int i = 0; i < ¨Ì; i++) {

			½è»è_collision = Rect(½è»è_x, ½è»è_y, ½è»è_x + 150, ½è»è_y + 90);

			if (¨_state[i] == 1) {
				er_x[i] = vC[_x + (S[[i] - [r[Ô) * er¬x;
				er_collision[i] = Rect(er_x[i], er_y[i], er_x[i] + 100, er_y[i] + 250);
				if (er_x[i] < 1280)
				{
					big[i] -= 0.014;
					circle_alpha[i] = 0.5;
					hitcount = false;
				}
			}
			else if (¨_state[i] == 2) {
				J_x[i] = vC[_x + (S[[i] - [r[Ô) * J¬x;
				J_collision[i] = Rect(J_x[i], J_y[i], J_x[i] + 60, J_y[i] + 64);

				if (J_x[i] < 1280) {
					Vector3 bezier = Vector3_Bezier(|Cg[0], |Cg[1], |Cg[2], |Cg[3], t[i]);
					J_x[i] = bezier.x;
					J_y[i] = bezier.y;
					t[i] = t[i] + 0.02f * titleScene::hard;
					J_collision[i] = Rect(bezier.x, bezier.y, bezier.x + 60, bezier.y + 64);
					big[i] -= 0.013;
					circle_alpha[i] = 0.5;
					hitcount = false;
				}
			}
			else if (¨_state[i] == 3) {
				dqW_x[i] = vC[_x + (S[[i] - [r[Ô) * dqW¬x;
				dqW_collision[i] = Rect(dqW_x[i] - 3, dqW_y[i], dqW_x[i] + 100, dqW_y[i] + 150);

				if (dqW_x[i] < 1280) {
						big[i] -= 0.007;
						circle_alpha[i] = 0.5;
						hitcount = false;
					dqW_x[i] = dqW_x[i] - 2;
					////                                             ®©µ½¢hbg«@@«ÅÌ`æÊu@ 
					dqW_y[i] = MathHelper_Sin(V[^[i]) * 90 * titleScene::hard + 400;
					V[^[i] = V[^[i] + 1;
				}
			}
			if (Jn_state == 1) {

				if (er_x[i] < -400) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
				}

				if (J_x[i] < -400) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
				}

				if (J_y[i] > 1000) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
				}

				if (dqW_x[i] < -400) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
				}
			}
			else if (Jn_state == 2) {

				if (er_x[i] < -500) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Jn_state = 3;
				}

				if (J_x[i] < -500) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Jn_state = 3;
				}

				if (J_y[i] > 1100) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
				}

				if (dqW_x[i] < -500) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Jn_state = 3;
				}
			}
		}
	}
	if (êb == 85) {
		Jn_state = 2;
	}
}
void GameMain::ûü´Draw()
{
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();
	iwai_Draw();
	SpriteBatch.DrawString(tHg, Vector2(0, 0), Color(255, 255, 255), _T("%ld"), [r[->GetPosition() / 100000);
	SpriteBatch.DrawString(tHg, Vector2(500, 0), Color(255, 255, 255), _T("%d"), êb);

	if (Jn_state == 3) {
		SpriteBatch.DrawString(tHg, Vector2(1000, 0), Color(255, 255, 255), _T("NA"));
	}
	SpriteBatch.Draw(*wi, Vector3(0.0f, 0.0f, 10.0f));
	//	SpriteBatch.Draw(*vC[, Vector3(vC[_x, vC[_y, 0.0f));
	//SpriteBatch.Draw(*½è»è, Vector3(½è»è_x, ½è»è_y, 0.0f));

	if (fobN == 1) {
		SpriteBatch.DrawString(tHg, Vector2(1000, 50), Color(255, 255, 255), _T("½ÁÄé"));
	}

	if (Jn_state == 1 || Jn_state == 2) {

		for (int i = 0; i < ¨Ì; i++)
		{

			if (¨_state[i] == 1) {
				SpriteBatch.Draw(*er, Vector3(er_x[i], er_y[i], 0.0f));
			}
			else if (¨_state[i] == 2) {
				SpriteBatch.Draw(*J, Vector3(J_x[i], J_y[i], 0.0f));
			}
			else if (¨_state[i] == 3) {
				SpriteBatch.Draw(*dqW, Vector3(dqW_x[i], dqW_y[i], 0.0f));
			}
		}
	}
}