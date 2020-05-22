#include <Dxlib.h>
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
	if (!GameInit)
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

	image = LoadGraph("Image/mago1.jpg");
	if (image == -1)
	{
		AST();
	}

	LoadFont = LoadFontDataToHandle("Font/mago1.pfa", 0);
	if (LoadFont == -1)
	{
		AST();
	}

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

	/*DrawFormatStringToHandle(400, 300, GetColor(255, 255, 255), FontHandle, "KAMEHAMEHA");
		DrawStringToHandle(400, 200, "BAKA!", GetColor(255, 255, 255), FontHandle);*/
	DrawGraph(400, 300, image, true);
	DrawString(400, 400, "OK!", GetColor(255, 255, 255));
	
	ScreenFlip();				// 裏画面と表画面を入れ替える
}

void DrawText(int x, int y, const char* str)
{
	int dstX = x;
	int dstY = y;

	for (unsigned i = 0; str[i] != '¥0'; ++i)
	{
		unsigned checkACII = static_cast<int>(str[i]);
		if (checkACII < 32 || checkACII >126)
		{
			AST();
			return;
		}
	}

	for (unsigned i = 0; str[i] != '¥0'; ++i)
	{
		DrawRotaGraph(dstX, dstY, 0, 0, i, true);
	}

}


// ﾀｲﾄﾙｼﾝ
void TitleScene(void)
{

}



// ｹﾞｰﾑｵｰﾊﾞｰｼﾝ
void GameOverScene(void)
{

}
