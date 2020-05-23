#include <Dxlib.h>
#include <cstring>			// library for string
#include "font.h"
#include "main.h"

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SysInit();
	if (!SysInit())
	{
		AST();
		return -1;
	}

	GameInit();
	if (!GameInit())
	{
		AST();
		return -1;
	}

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		GameScene();
	}
	DxLib_End();
	return 0;
}


// ｼｽﾃﾑ系初期化
bool SysInit(void)
{
	bool rtnFlag = true;				// 帰り戻す用変数

	// ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);	// 65535色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);							// true:window   false:full screen
	SetWindowText("");						// ｳｲﾝﾄﾞｳｽﾞに表示されるﾀｲﾄﾙ
													   // DXﾗｲﾌﾞﾗﾘ初期化処理
	if (DxLib_Init() == -1)
	{
		// 初期化失敗
		AST();
		rtnFlag = false;
	}


	// ﾌｫﾝﾄ画像を読み込む
	LoadDivGraph(
		"Font/font.png",
		95,
		16, 6,
		16, 16,
		imageFont, 0);

	SetDrawScreen(DX_SCREEN_BACK);

	return rtnFlag;


}


// ｹﾞｰﾑ系初期化
bool GameInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

// ｹﾞｰﾑｼﾝ
void GameScene(void)
{
	GameDraw();
}

// 画面描画
void GameDraw(void)
{
	ClsDrawScreen();			// 裏になっているﾊﾞｯﾌｧをﾌﾘｱする

	// ゲーム中の背景の描画

	// ﾌｫﾝﾄ描画を確認する
	for (int i = 0; i < sizeof(imageFont); i++)
	{
		DrawGraph(0 + (i%16) * 16, 0 + (i/16)*16 , imageFont[i], true);
	}

	DrawStringFromImage(200, 200, 2,  "I'm find , Thanks !", imageFont);
	
	ScreenFlip();				// 裏画面と表画面を入れ替える
}



// ﾀｲﾄﾙｼﾝ
void TitleScene(void)
{

}



// ｹﾞｰﾑｵｰﾊﾞｰｼﾝ
void GameOverScene(void)
{

}
