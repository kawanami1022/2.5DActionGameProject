#pragma once

// ﾃﾞﾊﾞｯｸﾞﾒｯｾｰｼﾞ用定義
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d行目\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "ｱｻｰﾄ表示", MB_OK);\
	}
#else
#define AST()
#endif

// 各定義
#define SCREEN_SIZE_X 800				// 画面の横ｻｲｽﾞ
#define SCREEN_SIZE_Y 600				// 画面の縦ｻｲｽﾞ


// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
bool SysInit(void);					// ｼｽﾃﾑ系初期化
bool GameInit(void);				// ｹﾞｰﾑ系初期化
void GameScene(void);				// ｹﾞｰﾑｼﾝ
void GameDraw(void);				// 画面描画

int imageFont[95];						// ﾌｫﾝﾄ画像の読み込み


void DrawStringFromImage(int x, int y, int extend, const char* str);		// Draw Font from Font Image  ( x座標,y座標,拡大縮小,string)