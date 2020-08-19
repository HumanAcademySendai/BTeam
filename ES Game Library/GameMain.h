#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
		//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// �ϐ��錾

	enum {
		���̐� = 100,
	};

	MEDIA ���[�r�[;
	SPRITE �w�i;
	SPRITE �v���C���[;
	SPRITE �e���r;
	SPRITE �J����;
	SPRITE �d�q�����W;
	SPRITE �����蔻��;

	_int64 moviepos;

	int �^�C�~���O[���̐�];
	int �b;
	int ��b;
	int �J�n_state;
	float �d�q�����W���x;
	float �e���r���x;
	float �J�������x;
	float �e���r_x[���̐�], �e���r_y[���̐�];
	float �v���C���[_x, �v���C���[_y;
	float �����蔻��_x, �����蔻��_y;
	int �S�[��[���̐�];
	char comma;
	int ���[�r�[����;
	int ��_state[���̐�];
	int ��;
	int �f�o�b�N;
	int ������;
	int ������_state[���̐�];
	float �X�s�[�h_y[���̐�];

	Rect �����蔻��_collision;
	Rect ��_collision[���̐�];

	FONT �t�H���g;

	// �֐��錾

};