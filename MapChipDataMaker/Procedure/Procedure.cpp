#include "procedure.h"
// ウインドウプロシージャー
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	
	Close(Msg, hWnd);
	Destroy(Msg, hWnd);
	// 既定のウィンドウプロシージャを呼び出す
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


void Close(UINT Msg, HWND hWnd)
{
	if (Msg == WM_CLOSE)
	{
		DestroyWindow(hWnd);
	}
}

void Destroy(UINT Msg, HWND hWnd)
{
	if (Msg == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
}
