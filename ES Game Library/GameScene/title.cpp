#include "../StdAfx.h"
#include "title.hpp"
int titleScene::hard = 1;
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
	memo = GraphicsDevice.CreateSpriteFromFile(_T("操作説明.png"));
	bat = GraphicsDevice.CreateSpriteFromFile(_T("bat.png"));
	perfect_se = SoundDevice.CreateSoundFromFile(_T("perfect.wav"));
	txt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 75);
	smalltxt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 35);
	count = 0;
	flg = false;
	scene = 0;
	hit = 0;
	bat_x = 350;
	bat_y = 300;
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
		if (Key_buf.IsPressed(Keys_Up))
		{
			bat_y = 300;
		}

		if (Key_buf.IsPressed(Keys_Down))
		{
			bat_y = 400;
		}
		if (bat_y == 300)
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
		else if (bat_y == 400) {

			if (Key_buf.IsPressed(Keys_Space))
			{
				titleScene::hard = 2;
				return GAME_SCENE(new GameMain);
			}
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
	SpriteBatch.Draw(*bat, Vector3(bat_x, bat_y, 0));
	SpriteBatch.DrawString(txt, Vector2(450, 300), Color(255, 255, 255), _T("ノーマルモード"));
	SpriteBatch.DrawString(txt, Vector2(450, 400), Color(255, 255, 255), _T("ハードモード"));
	SpriteBatch.DrawString(smalltxt, Vector2(400, 550), Color(255, 255, 255), _T("矢印キーで選択。スペースキーで決定。"));
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
