#include "Input.h"

// ウインドウプロシージャー
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uiMsg)
	{
	case WM_CLOSE:		// 閉じる際にWindowを破棄する
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:	// プログラムの終了を通知する
		PostQuitMessage(0);
		return 0L;
	}
	// 既定のウィンドウプロシージャを呼び出す
	return DefWindowProc(hWnd, uiMsg, wParam, lParam);
}
