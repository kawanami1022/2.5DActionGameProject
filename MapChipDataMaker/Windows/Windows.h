#pragma once
#include <windows.h>
#include "../Input/Input.h"




class Windows
{
public:
	Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow);
	~Windows();
	//------������------
	// �E�B���h�N���X�o�^
	ATOM InitApp(HINSTANCE hInst);
	// �E�B���h�E����
	BOOL InitInstance(HINSTANCE hInst, int nCmdShow);

	// ���[�v
	bool Run(void);
	// �I���ʒm�����Ă��邩�H
	bool IsQuitMessage(void);
	void Message();

	HWND getWinHdl();
private:
	HWND hWnd;

	// �I���ʒm�����Ă��邩�H
	bool g_isQuitMessage = false;
	// �E�B���h�E�n���h��
};

