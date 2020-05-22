#include <Dxlib.h>
#include "main.h"
#include <cstring>			// library for string

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
	if (LoadDivGraph(
		"Font/font.png",
		95,
		16,6,
		16,16,
		&imageFont[0])
		== -1)
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

	// ﾌｫﾝﾄ描画を確認する
	for (int i = 0; i < sizeof(imageFont); i++)
	{
		DrawGraph(0 + (i%16) * 16, 0 + (i/16)*16 , imageFont[i], true);
	}

	DrawString(400, 400, "OK!", GetColor(255, 255, 255));
	DrawStringFromImage(200, 200, 2,  "I'm find , Thanks !");
	
	ScreenFlip();				// 裏画面と表画面を入れ替える
}

void DrawStringFromImage(int x, int y,int extend, const char* str)
{
	int dstX = x;					// strのx座標
	int dstY = y;					// strのｙ座標
	int checkCode;					// ASCIIｺｰﾄﾞの確認
	int imageOrder;					// Order of font image
	int sizeStr = strlen(str);		// length of a string
	int fontSizeX = 16 * extend;	// ﾌｫﾝﾄ画像のサイズ
	int fontSizeY = 16 * extend;	// ﾌｫﾝﾄ画像のサイズ


	// ASCII range check
	for (int i = 0; i < sizeStr; i++)
	{
		checkCode = static_cast<int>(str[i]);
		if (checkCode < 32 || checkCode > 126)
		{
			AST();
			return;
		}
	}


	for (int i = 0; i < sizeStr; i++)
	{
		checkCode = static_cast<int>(str[i]);		// check ASCII code of each character of a string 
		imageOrder = checkCode - 32;					// then conver to Font Image order　(-32)


		DrawRotaGraph(dstX + i * fontSizeX, dstY, extend, 0, imageFont[imageOrder],true);

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
