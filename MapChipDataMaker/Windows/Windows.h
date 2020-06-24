#pragma once
#include <windows.h>
#include "../Input/Input.h"




class Windows
{
public:
	Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow);
	~Windows();
	//------初期化------
	// ウィンドクラス登録
	ATOM InitApp(HINSTANCE hInst);
	// ウィンドウ生成
	BOOL InitInstance(HINSTANCE hInst, int nCmdShow);

	// ループ
	bool Run(void);
	// 終了通知が来ているか？
	bool IsQuitMessage(void);
	void Message();

	HWND getWinHdl();
private:
	HWND hWnd;

	// 終了通知が来ているか？
	bool g_isQuitMessage = false;
	// ウィンドウハンドル
};

