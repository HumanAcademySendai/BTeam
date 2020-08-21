#pragma once

#include "GameScene.hpp"
#include "../ESGLib.h"

class titleScene : public CGameScene {
public:
	titleScene()
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~titleScene()
	{
		Finalize();

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
	}

	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
public:
	static int hard;
private:
	// 変数宣言
	SPRITE title;
	SPRITE memo;
	SOUND perfect_se;
	SPRITE bat;
	float bat_x, bat_y;
	float txt_x, txt_y;
	float txt_x2, txt_y2;
	float bat_roll,roll,roll2;
	int count;
	int flg;
	int scene;
	int hit;
	FONT txt;
	FONT smalltxt;

	RENDERTARGET font;
	RENDERTARGET font2;

	// 関数プロトタイプ

};
