#pragma once
#include <windows.h>


class Windows
{
public:
	Windows(const TCHAR* pName, int x, int y, int width, int height);
	~Windows();
	bool UpdateWindowMessage(void);
	// 終了通知が来ているか？
	bool IsQuitMessage(void);
	// ウィンドウハンドルの取得
	HWND GetWindowHandle(void);
};