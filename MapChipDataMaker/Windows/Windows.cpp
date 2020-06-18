// 作成したWindow.hを含める
#include <tchar.h>
#include "Windows.h"
#include "../resource.h"
#include "../Font/Font.h"
#include "../Procedure/procedure.h"


TCHAR szClassName[] = TEXT("sample");


Windows::Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow)
{
	InitApp(hInst);
	InitInstance(hInst, nCmdShow);

}

Windows::~Windows()
{
}

ATOM Windows::InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);					// 構造体のサイズ
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// クラスのスタイル
	wc.lpfnWndProc = WndProc;				// プロシージャー名
	wc.cbClsExtra = 0;					// 補助メモリ
	wc.cbWndExtra = 0;					// 補助メモリ
	wc.hInstance = hInst;					// インスタンス
	wc.hIcon = (HICON)LoadImage(			// アイコン
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, 
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hCursor = (HCURSOR)LoadImage(
		NULL, MAKEINTRESOURCE(IDC_ARROW),
		IMAGE_CURSOR, 0, 0, 
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground =					// 背景ブラシ
		(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;				// メニュー名
	wc.lpszClassName = szClassName;		// クラス名
	wc.hIconSm = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	return (RegisterClassEx(&wc));
}

BOOL Windows::InitInstance(HINSTANCE hInst, int nCmdShow)
{

	// ウインドウの生成
	hWnd = CreateWindow(szClassName,
		TEXT("sample"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInst,
		NULL);
	if (!hWnd)
	{
		MessageBox(hWnd, TEXT("ウィンドウの生成に失敗"), TEXT(""), MB_OK);
		return false;
	}

	// ウインドウの表示
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return true;
}

// メッセージの更新
bool Windows::Run(void)
{
	// メインループ
	while (!IsQuitMessage())
	{
		Message();
	}
	return false;
}

// 終了通知が来ているか？
bool Windows::IsQuitMessage(void) { return g_isQuitMessage; }


// メッセージ処理
void Windows::Message()
{
	MSG msg;
	// メッセージが存在するか確認
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		// 終了通知が来ている場合は抜ける
		if (msg.message == WM_QUIT)
		{
			g_isQuitMessage = true;
		}
		else
		{
			// メッセージをウインドウプロシージャに転送
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//return true;
	}
}
HWND Windows::getWinHdl()
{
	return hWnd;
}
