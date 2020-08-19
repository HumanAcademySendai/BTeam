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
	txt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 50);
	bigtxt = GraphicsDevice.CreateSpriteFont(_T("ContinueAL"), 150);
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

	//検証用
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
	SpriteBatch.DrawString(txt, Vector2(350, 40), Color(255, 255, 255), _T("スコア:%d"), GameMain::score);
	if (GameMain::score >= 0 && GameMain::score < 300)SpriteBatch.DrawString(bigtxt, _T("評価：C"), Vector2(350,300), Color(255, 0, 0));
	if (GameMain::score >= 300 && GameMain::score < 1000)SpriteBatch.DrawString(bigtxt, _T("評価：B"), Vector2(350, 300), Color(255, 0, 0));
	if (GameMain::score >= 1000 )SpriteBatch.DrawString(bigtxt, _T("評価：A"), Vector2(350, 300), Color(255, 0, 0));
	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
