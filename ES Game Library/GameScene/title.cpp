#include "../StdAfx.h"
#include "title.hpp"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load any non-graphic
/// related content.  Calling base.Initialize will enumerate through any components
/// and initialize them as well.
/// </summary>
bool titleScene::Initialize()
{
	// TODO: Add your initialization logic here
	title = GraphicsDevice.CreateSpriteFromFile(_T("title.png"));
	memo = GraphicsDevice.CreateSpriteFromFile(_T("ëÄçÏê‡ñæ.png"));
	perfect_se = SoundDevice.CreateSoundFromFile(_T("perfect.wav"));
	count = 0;
	flg = false;
	scene = 0;
	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void titleScene::Finalize()
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
int titleScene::Update()
{
    // TODO: Add your update logic here
	KeyboardBuffer Key_buf = Keyboard->GetBuffer();
	//if () 
	{
		if (Key_buf.IsPressed(Keys_Space))
		{
			perfect_se->Play();
			flg = true;
		}
		if (flg == true)
		{
			count++;
		}
		if (count >= 120)
		{
			return GAME_SCENE(new GameMain);
		}
	}
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void titleScene::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	SpriteBatch.Begin();
	if (scene == 0)SpriteBatch.Draw(*title, Vector3(0, 0, 0));
	if(scene == 1)SpriteBatch.Draw(*memo, Vector3(0, 0, 0));
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
