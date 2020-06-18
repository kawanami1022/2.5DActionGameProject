#include "procedure.h"
// ウインドウプロシージャー
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (Msg)
	{
	case WM_CLOSE:				// 閉じる際にWindowを破棄する
		DestroyWindow(hWnd);
		return 0;
	case WM_COMMAND:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:	// プログラムの終了を通知する
		PostQuitMessage(0);
		return 0L;
	}
	// 既定のウィンドウプロシージャを呼び出す
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}