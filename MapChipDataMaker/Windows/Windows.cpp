// 作成したWindow.hを含める
#include <tchar.h>
#include "Windows.h"
#include "../resource.h"
#define GetHInstance( ) ((HINSTANCE)GetModuleHandle(0))
// ウィンドウハンドル
HWND hWnd = NULL;
// 終了通知が来ているか？
bool g_isQuitMessage = false;

// ウインドウプロシージャー
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	HWND hDialog;
	switch (Msg)
	{
	case WM_CLOSE:		// 閉じる際にWindowを破棄する
		DestroyWindow(hWnd);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILE_NEW:
			hDialog = CreateDialog(
				(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
				MAKEINTRESOURCE(IDD_DIALOG1),
				hWnd,
				(DLGPROC)DlgWndProc);
		}
	case WM_DESTROY:	// プログラムの終了を通知する
		PostQuitMessage(0);
		return 0L;
	}
	// 既定のウィンドウプロシージャを呼び出す
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

Windows::Windows(const TCHAR* pName, int x, int y, int width, int height)
{
	WNDCLASSEX wcex;
	// ウインドウの設定
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME+1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU2);
	wcex.lpszClassName = TEXT("DirectX9 Sample");
	wcex.hIcon = LoadIcon(GetHInstance(), MAKEINTRESOURCE(IDI_ICON1));				// アイコン
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));
	RegisterClassExW(&wcex);

	DWORD dwStyle = WS_OVERLAPPEDWINDOW;

	RECT Rect;
	Rect.left = 0;
	Rect.top = 0;
	Rect.right = width;
	Rect.bottom = height;
	// ウィンドウのスタイルに合わせた適切なサイズを取得する
	AdjustWindowRect(&Rect, dwStyle, false);

	width = Rect.right - Rect.left;
	height = Rect.bottom - Rect.top;

	input = new Input();

	// ウインドウの生成
	hWnd = CreateWindow(wcex.lpszClassName,
		pName,
		dwStyle,
		x,
		y,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);
	if (hWnd == NULL)
	{
		return;
	}



	// ウインドウの表示
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

}

Windows::~Windows()
{
	delete input;
}





// メッセージの更新
bool Windows::UpdateWindowMessage(void)
{
	// メインループ
	while (!IsQuitMessage())
	{
		Message();
		Draw();		// 描画
	}
	return false;
}

// 終了通知が来ているか？
bool Windows::IsQuitMessage(void) { return g_isQuitMessage; }

// ウィンドウハンドルの取得
HWND GetWindowHandle(void) { return hWnd; }

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

void Windows::Draw()
{

}

BOOL DlgWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

