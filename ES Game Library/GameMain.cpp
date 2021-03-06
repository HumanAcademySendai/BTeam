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

	GraphicsDevice.SetRenderState(NormalizeNormals_Enable);
	GraphicsDevice.SetRenderState(Specular_Enable);
	//GraphicsDevice.SetRenderState(CullMode_None);

	ûü´Initialize();
	iwai_Initialize();
	R_Initialize();
	//hard 58
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
	R_Update();
	//½è»è¯mÌ£ðªÁÄ»è
	if (Jn_state == 5)
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

	R_Draw();

	SpriteBatch.Begin();

	ûü´Draw();
	iwai_Draw();

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	//paint.SetPaintColor(Color_Blue);
	//canvas.DrawRect(miss_collision, paint);
	//paint.SetPaintColor(Color_Red);
	//canvas.DrawRect(good_collision, paint);
	//paint.SetPaintColor(Color_Green);
	//canvas.DrawRect(perfect_collision, paint);
	//paint.SetPaintColor(Color_Blue);
	//canvas.DrawRect(Tv_collision, paint);
	//paint.SetPaintColor(Color_Blue);
	//canvas.DrawRect(½è»è_collision, paint);
	//paint.SetPaintColor(Color_Blue);
	//canvas.DrawRect(åer_collision, paint);
	for (int i = 0; i < ¨Ì; i++) {
	//	if (¨_state[i] == 1) {
	//		paint.SetPaintColor(Color_Red);
	//		canvas.DrawRect(er_collision[i], paint);
	//	}
	//	else if (¨_state[i] == 2) {
	//		paint.SetPaintColor(Color_Red);
	//		canvas.DrawRect(J_collision[i], paint);
	//	}
	//	else if (¨_state[i] == 3) {
	//		paint.SetPaintColor(Color_Red);
	//		canvas.DrawRect(dqW_collision[i], paint);
	//	}
	}
	GraphicsDevice.UnlockCanvas();
}
void GameMain::iwai_Initialize() {
	player = GraphicsDevice.CreateSpriteFromFile(_T("vC[LQ.png"));
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
	ready = GraphicsDevice.CreateSpriteFromFile(_T("ready.png"));
	combo_sprite = GraphicsDevice.CreateSpriteFromFile(_T("combo.png"));
	go = GraphicsDevice.CreateSpriteFromFile(_T("go.png"));
	txt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 100);
	small_txt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 50);
	player_x = 150;
	player_y = 350;
	swing_flg = 0;
	Tv_x = 1200;
	Tv_y = 400;
	life_y = 0;
	clip_x = 0;
	perfect_x = 280;
	perfect_y = 400;
	good_x = 300;
	good_y = 400;
	miss_x = 300;
	miss_y = 400;
	GameMain::score = 0;
	swing_flg = false;
	Tv_alpha = 1;
	hard_speed = 1;
	big_go = 1;
	alpha_go = 1;
	combo = 0;
	font_x = 100;
	count = 1500;
	for (int i = 0; i < ¨Ì; i++)
	{
		hitcount[i] = false;
		big[i] = 1.1;
		circle_alpha[i] = 0;
		er_aplha[i] = 1;
		J_aplha[i] = 1;
		dqW_aplha[i] = 1;
		time_circle[i] = 0;
	}
}
void GameMain::iwai_Draw() {
	// TODO: Add your drawing code here
	//GraphicsDevice.Clear(Color_CornflowerBlue);

	//GraphicsDevice.BeginScene();
	
	//SpriteBatch.Begin();
	SpriteBatch.Draw(*map, Vector3(0, 0, 0));
	SpriteBatch.Draw(*Tv, Vector3(Tv_x, Tv_y, 0), Tv_alpha);
//	SpriteBatch.Draw(*good_point, Vector3(good_x, good_y, 0));
//	SpriteBatch.Draw(*perfect_point, Vector3(perfect_x, perfect_y, 0));
	SpriteBatch.Draw(*hit_point, Vector3(300, 400, -100));
	for (int i = 0; i < ¨Ì; i++)
	{
		SpriteBatch.Draw(*circle, Vector3(200, 300, -10), circle_alpha[i], Vector3(0, 0, 1), Vector3(200, 200, 0), Vector2(big[i], big[i]));
	}
	SpriteBatch.Draw(*player, Vector3(player_x, player_y, 0), RectWH(clip_x, 0, 350, 300));
	if (hit_test == 1)SpriteBatch.Draw(*perfect, Vector3(300, 350, 0));
	if (hit_test == 2)SpriteBatch.Draw(*good, Vector3(280, 350, 0));
	if (hit_test == 3)SpriteBatch.Draw(*miss, Vector3(280, 350, 0));
	//SpriteBatch.DrawString(DefaultFont, Vector2(350, 0), Color(0, 0, 0), _T("£:%f"), range);
	//SpriteBatch.DrawString(DefaultFont, Vector2(350, 20), Color(0, 0, 0), _T("^C:%d"), count);
	//SpriteBatch.DrawString(DefaultFont, Vector2(350, 40), Color(0, 0, 0), _T("XRA:%d"), score);
	//SpriteBatch.DrawString(DefaultFont, Vector2(350, 60), Color(0, 0, 0), _T("jó:%f"), explosion->GetTrackPosition(0));
	if (combo >= 2)
	{
		SpriteBatch.DrawString(txt, Vector2(font_x, 120), Color(255, 255, 255), _T("%d"), combo);
		//SpriteBatch.DrawString(small_txt, Vector2(260, 150), Color(255, 255, 255), _T("combo"));
		SpriteBatch.Draw(*combo_sprite, Vector3(260, 150, 0));
	}
	if(count >1430)SpriteBatch.Draw(*ready, Vector3(400, 160, 0));
	if(count <=1430 && count >= 1320)SpriteBatch.Draw(*go, Vector3(430,160, 0),alpha_go, Vector3(0, 0,0), Vector3(122, 112, 0), Vector2(big_go, big_go));
}
void GameMain::iwai_Update() {

 	count--;

	if (titleScene::hard == 2)
	{
		for (int i = 0; i < ¨Ì; i++)
		{
			circle_alpha[i] = 0;
		}
	}
	good_collision = Rect(good_x, good_y, good_x + 200.0f, good_y + 200.0f);
	perfect_collision = Rect(perfect_x + 70, perfect_y, perfect_x + 170.0f, perfect_y + 200.0f);
 	miss_collision = Rect(miss_x , miss_y + 0, miss_x + 300.0f, Tv_y + 200.0f);
		if (key_buf.IsPressed(Keys_Space) && swing_flg == false)
		{
			for (int i = 0; i < ¨Ì; i++)
			{
				swing_flg = true;
				if (perfect_collision.Intersect(er_collision[i]) && hitcount[i] == false|| perfect_collision.Intersect(J_collision[i]) && hitcount[i] == false|| perfect_collision.Intersect(dqW_collision[i]) && hitcount[i] == false)
				{
					combo++;
					hit_test = 1;
					score += 250 + combo*50 ;
					hitcount[i] = true;
					circle_alpha[i] = 0;
					perfect_se->Play();
					explosion->SetTrackPosition(0, 0);
					explosion->SetTrackEnable(0, true);
					er_aplha[i] = 0;
					J_aplha[i] = 0;
					dqW_aplha[i] = 0;
					explosion_big = 120;
				}
				else if (good_collision.Intersect(er_collision[i]) && hitcount[i] == false || good_collision.Intersect(J_collision[i]) && hitcount[i] == false || good_collision.Intersect(dqW_collision[i]) && hitcount[i] == false)
				{
					combo++;
					hit_test = 2;
					score += 500 + combo * 50;
					hitcount[i] = true;
					circle_alpha[i] = 0;
					good_se->Play();
					explosion->SetTrackPosition(0, 0);
					explosion->SetTrackEnable(0, true);
					er_aplha[i] = 0;
					J_aplha[i] = 0;
					dqW_aplha[i] = 0;
					explosion_big = 80;
				}
				else if (miss_collision.Intersect(er_collision[i]) && hitcount[i] == false || miss_collision.Intersect(J_collision[i]) && hitcount[i] == false || miss_collision.Intersect(dqW_collision[i]) && hitcount[i] == false)
				{
					if (titleScene::hard == 2)
					{
					}
					else
					{
						//hit_test = 3;
						//miss_se->Play();
						//combo = 0;
						//hitcount[i] = true;
						//circle_alpha[i] = 0;
						//er_aplha[i] = 0;
						//J_aplha[i] = 0;
						//dqW_aplha[i] = 0;
					}
				}
			}
		}

	//if (keyboard.IsKeyUp(Keys_Space) && swing_flg == true)
	//{
	//	clip_x = 0;
	//	hit_test = 0;
	//	swing_flg = false;
	//}
	range = Tv_x - player_x;
	if (swing_flg == true)
	{
		clip_x += 350;
	}
	if (clip_x >= 6650)
	{
		clip_x = 0;
		hit_test = 0;
		swing_flg = false;
	}
	for (int i = 0; i < ¨Ì; i++)
	{
		if (big[i] <= 0)
		{
			big[i] = 0;
		}
		if (hitcount[i] == false && er_x[i]> 0 && er_x[i] < 100)
		{
			combo = 0;
			hitcount[i] = true;
		}
		if (hitcount[i] == false && dqW_x[i] > 0 && dqW_x[i] < 100)
		{
			combo = 0;
			hitcount[i] = true;
		}
		if (hitcount[i] == false && J_x[i] > 0 && J_x[i] < 100)
		{
			combo = 0;
			hitcount[i] = true;
		}
	}
	if (count <=1430)
	{
		big_go += 0.025;
		alpha_go -= 0.01;
	}
	if (alpha_go <= 0)
	{
		alpha_go = 0;
	}
	if (combo >= 10)
	{
		font_x = 20;
	}
	if (combo < 10)
	{
		font_x = 100;
	}
	for (int i = 0; i < ¨Ì; i++)
	{
		if (hitcount[i] == true)
		{
			time_circle[i] ++;
			if (time_circle[i] >= 30)
			{
				circle_alpha[i] = 0;
			}
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
	åer = GraphicsDevice.CreateSpriteFromFile(_T("åer.png"));

	MediaManager.Attach(GraphicsDevice);

	[r[ = MediaManager.CreateMediaFromFile(_T("{bgHê.mp3"));

	J¬x = 15 ;
	dqW¬x = 6 ;
	er¬x = 20 ;
	åer¬x = 5 * titleScene::hard;
	b = 0;
	êb = 0;
	Jn_state = 0;
	[r[Ô = 0;
	fobN = 0;
	åerAÅ = 15 * titleScene::hard;
	åer_state = 0;
	tHg_state = 0;
	for (int i = 0; i < ¨Ì; i++) {
		S[[i] = 100 + (150/titleScene::hard * i);
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
	åer_x = 1000;
	åer_y = 200;
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
	else if (êb == 45) {
		Jn_state = 2;
		tHg_state = 1;
	}
	else if (êb == 53) {
		[r[->Stop();
	}
	else if (êb == 55) {
		Jn_state = 4;
	}
	else if (êb == 58) {
		Jn_state = 5;
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
					if (hitcount[i] == false)
					{
						big[i] -= 0.034;
					}
					circle_alpha[i] = 0.5;
				}
			}
			else if (¨_state[i] == 2) {
				J_x[i] = vC[_x + (S[[i] - [r[Ô) * J¬x;
				J_collision[i] = Rect(J_x[i], J_y[i], J_x[i] + 100, J_y[i] + 70);

				if (J_x[i] < 1280) {
					Vector3 bezier = Vector3_Bezier(|Cg[0], |Cg[1], |Cg[2], |Cg[3], t[i]);
					J_x[i] = bezier.x;
					J_y[i] = bezier.y;
					t[i] = t[i] + 0.02f * titleScene::hard;
					J_collision[i] = Rect(bezier.x, bezier.y, bezier.x + 60, bezier.y + 64);
					circle_alpha[i] = 0.5;
					if (hitcount[i] == false)
					{
						big[i] -= 0.015;
					}
				}
			}
			else if (¨_state[i] == 3) {
				dqW_x[i] = vC[_x + (S[[i] - [r[Ô) * dqW¬x;
				dqW_collision[i] = Rect(dqW_x[i] - 3, dqW_y[i], dqW_x[i] + 100, dqW_y[i] + 150);

				if (dqW_x[i] < 1280) {
					if (hitcount[i] == false)
					{
						big[i] -= 0.01;
					}
						circle_alpha[i] = 0.5;
					dqW_x[i] = dqW_x[i] - 2;
					////                                             ®©µ½¢hbg«@@«ÅÌ`æÊu@ 
					dqW_y[i] = MathHelper_Sin(V[^[i]) * 90 + 400;
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

				if (J_y[i] < 900) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Xs[h_y[i] = 0;
					Jn_state = 3;
				}

				if (dqW_x[i] < -500) {
					¨_state[i] = 0;
					//er®«_state[i] = 0;
					Jn_state = 3;
				}
			}
		}
	}
	else if (Jn_state == 3) {
		åer_collision = Rect(åer_x, åer_y, åer_x + 150, åer_y + 500);
		åer_x = åer_x - åer¬x;

		if (åer_state == 0) {
			circle_alpha[29] = 0;
			if (key_buf.IsPressed(Keys_Space)) {
				if (perfect_collision.Intersect(åer_collision)) {
					åerAÅ -= 1;
					åer_x += 60;
					perfect_se->Play();
					explosion_x = MathHelper_Random(åer_x, åer_x+700);
					explosion_y = MathHelper_Random(åer_y, åer_y +500);
					explosion->SetTrackPosition(0, 0);
					explosion->SetTrackEnable(0, true);
				}
			}

			if (åerAÅ <= 0) {
				åer_state = 1;
				score += 1000;
				combo++;
			}

			if (åer_x < 100) {

			}
		}
		else if (åer_state == 1) {
		}
	}
}
void GameMain::ûü´Draw()
{/*
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();*/
	//SpriteBatch.DrawString(tHg, Vector2(0, 0), Color(255, 255, 255), _T("%ld"), [r[->GetPosition() / 100000);
	//SpriteBatch.DrawString(tHg, Vector2(500, 0), Color(255, 255, 255), _T("%d"), êb);

	if (Jn_state == 3) {
		/*SpriteBatch.DrawString(tHg, Vector2(1000, 0), Color(255, 255, 255), _T("NA"));*/
	}
	SpriteBatch.Draw(*wi, Vector3(0.0f, 0.0f, 10.0f));
	//	SpriteBatch.Draw(*vC[, Vector3(vC[_x, vC[_y, 0.0f));
	//SpriteBatch.Draw(*½è»è, Vector3(½è»è_x, ½è»è_y, 0.0f));

	if (fobN == 1) {
		/*SpriteBatch.DrawString(tHg, Vector2(1000, 50), Color(255, 255, 255), _T("½ÁÄé"));*/
	}

	if (tHg_state == 1 && åer_state == 0) {
		
	}

	if (Jn_state == 1 || Jn_state == 2) {

		for (int i = 0; i < ¨Ì; i++)
		{

			if (¨_state[i] == 1) {
				SpriteBatch.Draw(*er, Vector3(er_x[i], er_y[i], 0.0f),er_aplha[i]);
			}
			else if (¨_state[i] == 2) {
				SpriteBatch.Draw(*J, Vector3(J_x[i], J_y[i], 0.0f), J_aplha[i]);
			}
			else if (¨_state[i] == 3) {
				SpriteBatch.Draw(*dqW, Vector3(dqW_x[i], dqW_y[i], 0.0f),dqW_aplha[i]);
			}
		}
	}
	else if (Jn_state == 3 && åer_state == 0) {

		SpriteBatch.DrawString(tHg, Vector2(300,300), Color(255, 255, 255), _T("8KerÌÍ:%d"),åerAÅ);
		SpriteBatch.DrawString(tHg, Vector2(700, 200), Color(0, 255, 255), _T("AÅµÄ8Kerðó¹!!"));
		SpriteBatch.Draw(*åer, Vector3(åer_x, åer_y, 10.0f));
	}
}
void GameMain::R_Initialize()
{
	explosion_x = 400;
	explosion_y = 500;
	explosion_big = 120;
	Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3(1, 1, 1);
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	light.Ambient = Color(1.0f, 1.0f, 1.0f);
	light.Specular = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);

	explosion = GraphicsDevice.CreateAnimationModelFromFile(_T("bakuha.x"), Compute_NormalTangent);
	explosion->SetScale(explosion_big, -explosion_big, 1.0f);//å«³
	explosion->SetPosition(explosion_x, explosion_y, -10000);

	Material material;
	material.Diffuse = Color(0.75f, 0.75f, 0.75f);
	material.Ambient = Color(0.5f, 0.5f, 0.5f);
	material.Specular = Color(1.0f, 1.0f, 1.0f);
	material.Power = 10.0f;
	explosion->SetMaterial(material);

	explosion->ChangeTexture("", "tex.jpg");

	explosion->SetTrackEnable(0, false);
	explosion->SetTrackLoopMode(0, AnimationLoopMode_Once);

	auto frame = explosion->GetTrackPosition(0);

	camera->SetView(Vector3(0, 0, -10), Vector3(0, 0, 0));
	camera->SetOrthographicOffCenter(0, 1280, 720, 0, -10000, 10000);
	//explosion->SetPosition(0, 0, -9.0);
	//camera->SetPerspectiveFieldOfView(45.0f, 16.0f / 9.0f, 0.1f, 10000.0f);
	GraphicsDevice.SetCamera(camera);
}
void GameMain::R_Update()
{
	explosion->AdvanceTime(GameTimer.GetElapsedSecond());
	if (explosion->GetTrackPosition(0) >= 0.5)
		{
			explosion->SetTrackEnable(0, false);
		}
	explosion->SetScale(explosion_big, -explosion_big, 1.0f);//å«³
	explosion->SetPosition(explosion_x, explosion_y, -10000);
}
void GameMain::R_Draw()
{
	for (int i = 0; i < ¨Ì; i++)
	{
		if (hitcount[i] == true)
		{
			explosion->Draw();
		}
	}
}