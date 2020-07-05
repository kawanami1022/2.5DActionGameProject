#include <iostream>
#include <stdlib.h>
#include <DxLib.h>
#include "Input/keyInput.h"
#include "Geometry/Geometry.h"
#include "Vector2D/Vector2.h"
#include "Physics/Physics2D.h"

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

const unsigned int color[2] = { 0xffffff,0xff0000 };

struct Player
{
	Circle circle;
	Vector2<float> velocity;		// 移動速度
	Vector2<float> acc;			// 加速度
};


Player player;
KeyInput* keyInput;
void GameInit();
void GameInput();
void GameScene();
void GameDraw();
void GameEnd();
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	if (DxLib_Init()==-1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}
	
	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);
	GameInit();
	// ループ
	while (!ProcessMessage())
	{
		// 画面を初期化する

		GameScene();
		GameInput();
		GameDraw();

	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}

// ｹﾞｰﾑｼｰﾝの初期化
void GameInit()
{
	keyInput = new KeyInput();
	player = { { SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,16 } ,{0,3.0f},{0,0.5f} };
}

// ゲーム入力
void GameInput()
{
	keyInput->Update();
	if (keyInput->Push(KEY_INPUT_SPACE))
	{
		if (player.circle.y >= SCREEN_SIZE_Y)
		{
			player.velocity.y = -20;
		}
	}
}

// ｹﾞｰﾑｼｰﾝ
void GameScene()
{
	Gravity(&player.circle.y, SCREEN_SIZE_Y, &player.velocity.y, player.acc.y);

}

// ｹﾞｰﾑｼｰﾝの描画
void GameDraw()
{
	ClsDrawScreen();
	DrawCircle(player.circle.x, player.circle.y, 16, 0xffffff,true,true);
	DrawFormatString(0, 0, 0xffffff, "velocity:%d", (int)player.velocity.y);
	ScreenFlip();
}

void GameEnd()
{
}

