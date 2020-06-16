#pragma once
#include <windows.h>
#include "../Input/Input.h"

extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

class Windows
{
public:
	Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow);
	~Windows();
	//------初期化
	// ウィンドクラス登録
	ATOM InitApp(HINSTANCE hInst);
	// ウィンドウ生成
	BOOL InitInstance(HINSTANCE hInst, int nCmdShow);

	bool UpdateWindowMessage(void);
	// 終了通知が来ているか？
	bool IsQuitMessage(void);
	void Message();
	// 描画処理
	void Draw();

private:

	Input* input;
	// ウィンドウハンドル
};
// ウィンドウハンドルの取得
