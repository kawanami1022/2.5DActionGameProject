#pragma once
#include <windows.h>


class Windows
{
public:
	Windows(const TCHAR* pName, int x, int y, int width, int height);
	~Windows();
	bool UpdateWindowMessage(void);
	// �I���ʒm�����Ă��邩�H
	bool IsQuitMessage(void);
	// �E�B���h�E�n���h���̎擾
	HWND GetWindowHandle(void);
};