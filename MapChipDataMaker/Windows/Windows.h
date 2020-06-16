#pragma once
#include <windows.h>
#include "../Input/Input.h"

extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

class Windows
{
public:
	Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow);
	~Windows();
	//------������
	// �E�B���h�N���X�o�^
	ATOM InitApp(HINSTANCE hInst);
	// �E�B���h�E����
	BOOL InitInstance(HINSTANCE hInst, int nCmdShow);

	bool UpdateWindowMessage(void);
	// �I���ʒm�����Ă��邩�H
	bool IsQuitMessage(void);
	void Message();
	// �`�揈��
	void Draw();

private:

	Input* input;
	// �E�B���h�E�n���h��
};
// �E�B���h�E�n���h���̎擾
