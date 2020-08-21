#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"

class GameMain : public CGameScene {
public:
	GameMain()
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

public:
	static int score;
private:
	// 変数宣言
	enum {
		物の数 = 100,
	};
	SPRITE player;
	SPRITE player_swing;
	SPRITE player_Empty_swing;
	SPRITE map;
	SPRITE perfect;
	SPRITE good;
	SPRITE miss;
	SPRITE life;
	SPRITE good_point;
	SPRITE perfect_point;
	SPRITE Tv;
	SPRITE circle;
	SPRITE hit_point;
	SOUND good_se;
	SOUND perfect_se;
	SOUND miss_se;
	float player_x, player_y;
	float Tv_x, Tv_y;
	int hit_test;
	float range;
	int swing_flg;
	float life_y;
	float clip_x;
	int count;
	float good_x,good_y;
	float perfect_x, perfect_y;
	int hitcount = 0;
	float Tv_alpha;
	float big[物の数];
	float circle_alpha[物の数];
	float hard_speed;
	Rect  player_collision;
	Rect  perfect_collision;
	Rect  Tv_collision;
	Rect  good_collision;
	Rect  good2_collision;
	ANIMATIONMODEL explosion;

	MEDIA ムービー;
	SPRITE 背景;
	SPRITE プレイヤー;
	SPRITE テレビ;
	SPRITE カメラ;
	SPRITE 電子レンジ;
	SPRITE 当たり判定;

	_int64 moviepos;

	int タイミング[物の数];
	int 秒;
	int 一秒;
	int 開始_state;
	float 電子レンジ速度;
	float テレビ速度;
	float カメラ速度;
	float テレビ_x[物の数], テレビ_y[物の数];
	float カメラ_x[物の数], カメラ_y[物の数];
	float 電子レンジ_x[物の数], 電子レンジ_y[物の数];
	float プレイヤー_x, プレイヤー_y;
	float 当たり判定_x, 当たり判定_y;
	int ゴール[物の数];
	char comma;
	int ムービー時間;
	int 物_state[物の数];
	int 数;
	int デバック;
	//int テレビ動き;
	//int テレビ動き_state[物の数];
	float スピード_y[物の数];
	float シータ[物の数];
	Vector3 ポイント[4];
	float t[物の数];

	Rect 当たり判定_collision;
	Rect テレビ_collision[物の数];
	Rect カメラ_collision[物の数];
	Rect 電子レンジ_collision[物の数];

	FONT フォント;

	KeyboardState keyboard;
	KeyboardBuffer key_buf;
	// 関数宣言

	void 髙橋Initialize();
	void 髙橋Main();
	void 髙橋Draw();
	void iwai_Initialize();
	void iwai_Update();
	void iwai_Draw();
};