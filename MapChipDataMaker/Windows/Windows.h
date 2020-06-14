#pragma once
#include <windows.h>
#include "../Input/Input.h"

extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

class Windows
{
public:
	Windows(const TCHAR* pName, int x, int y, int width, int height);
	~Windows();
	bool UpdateWindowMessage(void);
	// 終了通知が来ているか？
	bool IsQuitMessage(void);
	void Message();
	// 描画処理
	void Draw();
	// ダイアログ用ウィンドウプロシージャー
private:
	Input* input;
};
// ウィンドウハンドルの取得
<<<<<<< HEAD
HWND GetWindowHandle(void);
=======
HWND GetWindowHandle(void);
>>>>>>> 15bf2dd6549b6f8ace83cf854b0f8e95da6d90b4
