#include "procedure.h"
// �E�C���h�E�v���V�[�W���[
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	
	Close(Msg, hWnd);
	Destroy(Msg, hWnd);
	// ����̃E�B���h�E�v���V�[�W�����Ăяo��
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
