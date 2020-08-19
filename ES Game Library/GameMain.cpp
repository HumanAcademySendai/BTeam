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
	player = GraphicsDevice.CreateSpriteFromFile(_T("�v���g.png"));
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
	miss_se = SoundDevice.CreateSoundFromFile(_T("��U��.wav"));
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

	�w�i = GraphicsDevice.CreateSpriteFromFile(_T("�w�i.png")); 
	�v���C���[ = GraphicsDevice.CreateSpriteFromFile(_T("�v���C���[.png"));
	�e���r = GraphicsDevice.CreateSpriteFromFile(_T("�e���r.png"));
	�J���� = GraphicsDevice.CreateSpriteFromFile(_T("�J����.png"));
	�d�q�����W = GraphicsDevice.CreateSpriteFromFile(_T("�d�q�����W.png"));
	�����蔻�� = GraphicsDevice.CreateSpriteFromFile(_T("�����蔻��.png"));
	�t�H���g = GraphicsDevice.CreateSpriteFont(_T("MS�S�V�b�N"), 50);

	MediaManager.Attach(GraphicsDevice);

	���[�r�[ = MediaManager.CreateMediaFromFile(_T("�V���C�j���O�X�^�[�V���[�g.mp3"));

	�J�������x = 16;
	�d�q�����W���x = 15;
	�e���r���x = 10;
	�b = 0;
	��b = 0;
	�J�n_state = 0;
	���[�r�[���� = 0;
	�f�o�b�N = 0;

	for (int i = 0; i < ���̐�; i++) {
		�S�[��[i] = 100 + (150 * i);
		��_state[i] = MathHelper_Random(1, 3);
		�e���r_x[i] = 0;
		�e���r_y[i] = 400;
		������_state[i] = 0;
		�X�s�[�h_y[i] = 15;
	}

	�v���C���[_x = 100;
	�v���C���[_y = 400;
	�����蔻��_x = 200;
	�����蔻��_y = 500;
	������ = 5;

	/*std::ifstream game_file("�Q�[���f�[�^.txt");
	std::string dummy_line;

	game_file >> �^�C�~���O[0];

	game_file >> �^�C�~���O[1];

	game_file >> �^�C�~���O[2];

	game_file >> �^�C�~���O[3];

	game_file >> �^�C�~���O[4];*/

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

	���[�r�[���� = ���[�r�[->GetPosition() / 100000;

	�b += 1;

	if (�b == 60) {
		��b += 1;
		�b = 0;
	}

	if (��b == 3) {
		�J�n_state = 1;
	}

	if (�J�n_state == 1 || �J�n_state == 2) {

		���[�r�[->Play();

		for (int i = 0; i < ���̐�; i++) {

			�����蔻��_collision = Rect(�����蔻��_x, �����蔻��_y, �����蔻��_x + 150, �����蔻��_y + 90);
			��_collision[i] = Rect(�e���r_x[i], �e���r_y[i], �e���r_x[i] + 100, �e���r_y[i] + 100);

			if (��_state[i] == 1) {
				�e���r_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �e���r���x;

				if (�e���r_x[i] < 1280) {

					if (�e���r_y[i] < 300) {
						������_state[i] = 1;
					}

					if (������_state[i] == 0) {
						�e���r_y[i] -= ������;
					}
					else if (������_state[i] == 1) {
						�e���r_y[i] += ������;
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
			else if (��_state[i] == 2) {
				�e���r_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �J�������x;

				if (�e���r_x[i] < 1280) {
					�e���r_y[i] = �e���r_y[i] - (�X�s�[�h_y[i]--);
				}
			}
			else if (��_state[i] == 3) {
				�e���r_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �d�q�����W���x;
			}

			if (�J�n_state == 1) {

				if (�e���r_x[i] < -400) {
					��_state[i] = 0;
					������_state[i] = 0;
					�X�s�[�h_y[i] = 0;
				}
			}
			else if (�J�n_state == 2) {

				if (�e���r_x[i] < -500) {
					��_state[i] = 0;
					������_state[i]= 0;
					�J�n_state = 3;
				}
			}
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
	//�����蔻�蓯�m�̋����𑪂��Ĕ���
	if (count <= 0)
	{
		return GAME_SCENE(new clearScene);
	}
	//���ؗp
	if (key_buf.IsPressed(Keys_A))
	{
		return GAME_SCENE(new clearScene);

	if (��b == 85) {
		�J�n_state = 2;
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
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 0), Color(0, 0, 0), _T("����:%f"), range);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 20), Color(0, 0, 0), _T("�^�C��:%d"), count);
	SpriteBatch.DrawString(DefaultFont, Vector2(350, 40), Color(0, 0, 0), _T("�X�R�A:%d"), score);
	//SpriteBatch.Draw(*movie, Vector3(0, 200, 0), 0.5f, Vector3(0, 0, 50), Vector3(640, 360, 0), Vector2(0.25f, 0.25f));
	//	�����x�@�g��@��]���@�����c��

	SpriteBatch.DrawString(�t�H���g, Vector2(0, 0), Color(255, 255, 255), _T("%ld"), ���[�r�[->GetPosition() / 100000);
	SpriteBatch.DrawString(�t�H���g, Vector2(500, 0), Color(255, 255, 255), _T("%d"), ��b);

	if (�J�n_state == 3) {
		SpriteBatch.DrawString(�t�H���g, Vector2(1000, 0), Color(255, 255, 255), _T("�N���A"));
	}
	SpriteBatch.Draw(*�w�i, Vector3(0.0f, 0.0f, 10.0f));
	SpriteBatch.Draw(*�v���C���[, Vector3(�v���C���[_x, �v���C���[_y, 0.0f));
	SpriteBatch.Draw(*�����蔻��, Vector3(�����蔻��_x, �����蔻��_y, 0.0f));

	if (�f�o�b�N == 1) {
		SpriteBatch.DrawString(�t�H���g, Vector2(1000, 50), Color(255, 255, 255), _T("�������Ă�"));
	}

	if (�J�n_state == 1 || �J�n_state == 2) {

		for (int i = 0; i < ���̐�; i++) {

			if (��_state[i] == 1) {
				SpriteBatch.Draw(*�e���r, Vector3(�e���r_x[i], �e���r_y[i], 0.0f));
			}
			else if (��_state[i] == 2) {
				SpriteBatch.Draw(*�J����, Vector3(�e���r_x[i], �e���r_y[i], 0.0f));
			}
			else if (��_state[i] == 3) {
				SpriteBatch.Draw(*�d�q�����W, Vector3(�e���r_x[i], �e���r_y[i], 0.0f));
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
	canvas.DrawRect(�����蔻��_collision, paint);

	for (int i = 0; i < ���̐�; i++) {

		paint.SetPaintColor(Color_Red);
		canvas.DrawRect(��_collision[i], paint);
	}

	GraphicsDevice.UnlockCanvas();
}