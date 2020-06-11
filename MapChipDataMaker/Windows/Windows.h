#pragma once
#include <windows.h>


extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);
class Windows
{
public:
	Windows(const TCHAR* pName, int x, int y, int width, int height);
	~Windows();
	bool UpdateWindowMessage(void);
	// �I���ʒm�����Ă��邩�H
	bool IsQuitMessage(void);
	void Message();
	// �`�揈��
	void Draw();

};
// �E�B���h�E�n���h���̎擾
HWND GetWindowHandle(void);