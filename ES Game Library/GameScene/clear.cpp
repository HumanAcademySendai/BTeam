#include "../StdAfx.h"
#include "clear.hpp"
#include "../GameMain.h"
/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool clearScene::Initialize()
{
	// TODO: Add your initialization logic here
	GameMain::score;
	clear_ = GraphicsDevice.CreateSpriteFromFile(_T("clear.png"));
	a = GraphicsDevice.CreateSpriteFromFile(_T("A.png"));
	b = GraphicsDevice.CreateSpriteFromFile(_T("b.png"));
	c = GraphicsDevice.CreateSpriteFromFile(_T("c.png"));
	txt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 50);
	bigtxt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 150);
	big_se = SoundDevice.CreateSoundFromFile(_T("bigw.wav"));
	small_se = SoundDevice.CreateSoundFromFile(_T("w.wav"));
	tin_se = SoundDevice.CreateSoundFromFile(_T("tin.wav"));
	a_roll = 0;
	a_big = 4.6;
	b_big = 3;
	count = 0;
	c_roll = 0;
	if (GameMain::score >= 0 && GameMain::score < 300) tin_se->Play();
	if (GameMain::score >= 300 && GameMain::score < 1000)small_se->Play();
	if (GameMain::score >= 1000)big_se->Play();
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void clearScene::Finalize()
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
int clearScene::Update()
{
    // TODO: Add your update logic here
	count++;
	if (count < 60)
	{
		a_big -= 0.06;
		a_roll+= 6;
	}
	if (count >= 60)
	{
		a_roll = 0;
		a_big = 1; 
	}
	if (b_big > 1)
	{
		b_big -= 0.05;
	}
	if (b_big <= 1)
	{
		b_big = 1;
	}
	if (count > 40)
	{
		c_roll = -35;
	}
	KeyboardBuffer key_buf = Keyboard->GetBuffer();
	if (key_buf.IsPressed(Keys_Enter))
	{
		return GAME_SCENE(new titleScene);
	}
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void clearScene::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();
	SpriteBatch.Begin();
	SpriteBatch.Draw(*clear_, Vector3(0, 0, 0));
	SpriteBatch.DrawString(txt, Vector2(350, 40), Color(255, 255, 255), _T("ƒXƒRƒA:%d"), GameMain::score);
	if (GameMain::score >= 0 && GameMain::score < 300)SpriteBatch.Draw(*c, Vector3(700, 230, 0), 1.0f, Vector3(0, 0, c_roll), Vector3(110, 112, 0), Vector2(1, 1));
	if (GameMain::score >= 300 && GameMain::score < 1000)SpriteBatch.Draw(*b, Vector3(700, 230, 0), 1.0f, Vector3(0, 0, 0), Vector3(114, 112, 0), Vector2(b_big, b_big));
	if (GameMain::score >= 1000)SpriteBatch.Draw(*a, Vector3(700,230,0), 1.0f, Vector3(0, 0, a_roll), Vector3(110, 110, 0), Vector2(a_big, a_big));
	SpriteBatch.DrawString(bigtxt, _T("•]‰¿:"), Vector2(350, 300), Color(255, 0, 0));
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
