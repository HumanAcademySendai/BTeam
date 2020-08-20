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

	����Initialize();

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

	����Main();

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

	����Draw();

	SpriteBatch.End();

	GraphicsDevice.EndScene();

	Canvas canvas = GraphicsDevice.LockCanvas();

	Paint paint;

	paint.SetPaintColor(Color_Blue);
	canvas.DrawRect(�����蔻��_collision, paint);

	for (int i = 0; i < ���̐�; i++) {

		if (��_state[i] == 1) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(�e���r_collision[i], paint);
		}
		else if (��_state[i] == 2) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(�J����_collision[i], paint);
		}
		else if (��_state[i] == 3) {
			paint.SetPaintColor(Color_Red);
			canvas.DrawRect(�d�q�����W_collision[i], paint);
		}
	}

	GraphicsDevice.UnlockCanvas();
}

void GameMain::����Initialize() {

	�w�i = GraphicsDevice.CreateSpriteFromFile(_T("�w�i.png"));
	�v���C���[ = GraphicsDevice.CreateSpriteFromFile(_T("�v���C���[.png"));
	�e���r = GraphicsDevice.CreateSpriteFromFile(_T("�e���r.png"));
	�J���� = GraphicsDevice.CreateSpriteFromFile(_T("�J����.png"));
	�d�q�����W = GraphicsDevice.CreateSpriteFromFile(_T("�d�q�����W.png"));
	�����蔻�� = GraphicsDevice.CreateSpriteFromFile(_T("�����蔻��.png"));
	�t�H���g = GraphicsDevice.CreateSpriteFont(_T("MS�S�V�b�N"), 50);

	MediaManager.Attach(GraphicsDevice);

	���[�r�[ = MediaManager.CreateMediaFromFile(_T("�V���C�j���O�X�^�[�V���[�g.mp3"));

	�J�������x = 20;
	�d�q�����W���x = 5;
	�e���r���x = 10;
	�b = 0;
	��b = 0;
	�J�n_state = 0;
	���[�r�[���� = 0;
	�f�o�b�N = 0;

	for (int i = 0; i < ���̐�; i++) {
		�S�[��[i] = 100 + (150 * i);
		�e���r_x[i] = 0;
		�e���r_y[i] = 400;
		�J����_x[i] = 0;
		�J����_y[i] = 400;
		�d�q�����W_x[i] = 0;
		�d�q�����W_y[i] = 400;
		//�e���r����_state[i] = 0;
		�X�s�[�h_y[i] = 12;
		�V�[�^[i] = 0;
	}

	��_state[0] = 1;

	for (int i = 1; i < ���̐�; i++) {
		��_state[i] = MathHelper_Random(1, 3);
	}

	�v���C���[_x = 100;
	�v���C���[_y = 400;
	�����蔻��_x = 200;
	�����蔻��_y = 500;
	//�e���r���� = 5;

	/*std::ifstream game_file("�Q�[���f�[�^.txt");
	std::string dummy_line;

	game_file >> �^�C�~���O[0];

	game_file >> �^�C�~���O[1];

	game_file >> �^�C�~���O[2];

	game_file >> �^�C�~���O[3];

	game_file >> �^�C�~���O[4];*/
}

void GameMain::����Main() {

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

			if (��_state[i] == 1) {
				�e���r_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �e���r���x;
				�e���r_collision[i] = Rect(�e���r_x[i], �e���r_y[i], �e���r_x[i] + 100, �e���r_y[i] + 250);

				/*if (�e���r_x[i] < 1280) {

					if (�e���r_y[i] < 300) {
						������_state[i] = 1;
					}

					if (������_state[i] == 0) {
						�e���r_y[i] -= ������;
					}
					else if (������_state[i] == 1) {
						�e���r_y[i] += ������;
					}
				}*/
			}
			else if (��_state[i] == 2) {
				�J����_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �J�������x;
				�J����_collision[i] = Rect(�J����_x[i], �J����_y[i], �J����_x[i] + 60, �J����_y[i] + 64);

				if (�J����_x[i] < 1280) {
					�J����_y[i] = �J����_y[i] - (�X�s�[�h_y[i]--);
				}
			}
			else if (��_state[i] == 3) {
				�d�q�����W_x[i] = �v���C���[_x + (�S�[��[i] - ���[�r�[����) * �d�q�����W���x;
				�d�q�����W_collision[i] = Rect(�d�q�����W_x[i] - 3, �d�q�����W_y[i], �d�q�����W_x[i] + 100, �d�q�����W_y[i] + 150);

				if (�d�q�����W_x[i] < 1280) {

					�d�q�����W_x[i] = �d�q�����W_x[i] - 2;
////                                             �����������h�b�g�����@�@���ŏ��̕`��ʒu�@ 
					�d�q�����W_y[i] = MathHelper_Sin(�V�[�^[i]) * 100 + 400;
					�V�[�^[i] = �V�[�^[i] + 1;
				}
			}

			if (�J�n_state == 1) {

				if (�e���r_x[i] < -400) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�X�s�[�h_y[i] = 0;
				}

				if (�J����_x[i] < -400) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�X�s�[�h_y[i] = 0;
				}

				if (�d�q�����W_x[i] < -400) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�X�s�[�h_y[i] = 0;
				}
			}
			else if (�J�n_state == 2) {

				if (�e���r_x[i] < -500) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�J�n_state = 3;
				}

				if (�J����_x[i] < -500) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�J�n_state = 3;
				}

				if (�d�q�����W_x[i] < -500) {
					��_state[i] = 0;
					//�e���r����_state[i] = 0;
					�J�n_state = 3;
				}
			}
		}
	}

	if (��b == 85) {
		�J�n_state = 2;
	}
}

void GameMain::����Draw() {

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
				SpriteBatch.Draw(*�J����, Vector3(�J����_x[i], �J����_y[i], 0.0f));
			}
			else if (��_state[i] == 3) {
				SpriteBatch.Draw(*�d�q�����W, Vector3(�d�q�����W_x[i], �d�q�����W_y[i], 0.0f));
			}
		}
	}
}