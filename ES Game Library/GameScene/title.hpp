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
	// ïœêîêÈåæ
	SPRITE title;
	SPRITE memo;
	SOUND perfect_se;
	SPRITE bat;
	SPRITE nomal;
	SPRITE hard_sp;
	SPRITE title_title;
	SPRITE ëÄçÏê‡ñæ;
	SPRITE ëÄçÏê‡ñæÅQï∂éö;
	SPRITE enter_to;
	SPRITE space_to;
	SPRITE start;
	float aplha;
	float bat_x, bat_y;
	float txt_x, txt_y;
	float txt_x2, txt_y2;
	float bat_roll,roll,roll2;
	float ägëÂ_x, ägëÂ_y, ägëÂ_x2, ägëÂ_y2, ägëÂ_x3, ägëÂ_y3,ägëÂ_x4, ägëÂ_y4,ägëÂ_x5, ägëÂ_y5;;
	int count;
	int flg;
	int scene;
	int hit;
	int se_flg;
	FONT txt;
	FONT smalltxt;

	RENDERTARGET font;
	RENDERTARGET font2;

	// ä÷êîÉvÉçÉgÉ^ÉCÉv

};
