// �쐬����Window.h���܂߂�
#include <tchar.h>
#include "Windows.h"
#include "../resource.h"

// �I���ʒm�����Ă��邩�H
bool g_isQuitMessage = false;
TCHAR szClassName[] = TEXT("sample");
// �E�C���h�E�v���V�[�W���[
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	HWND hDialog;
	switch (Msg)
	{
	case WM_CLOSE:				// ����ۂ�Window��j������
		DestroyWindow(hWnd);
		return 0;
	case WM_COMMAND:
		break;
			// 
	case WM_DESTROY:	// �v���O�����̏I����ʒm����
		PostQuitMessage(0);
		return 0L;
	}
	// ����̃E�B���h�E�v���V�[�W�����Ăяo��
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

Windows::Windows(const TCHAR* pName, HINSTANCE hInst, int nCmdShow)
{
	InitApp(hInst);
	InitInstance(hInst, nCmdShow);

}

Windows::~Windows()
{
	delete input;
}

ATOM Windows::InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);					// �\���̂̃T�C�Y
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// �N���X�̃X�^�C��
	wc.lpfnWndProc = WndProc;				// �v���V�[�W���[��
	wc.cbClsExtra = 0;					// �⏕������
	wc.cbWndExtra = 0;					// �⏕������
	wc.hInstance = hInst;					// �C���X�^���X
	wc.hIcon = (HICON)LoadImage(			// �A�C�R��
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, 
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hCursor = (HCURSOR)LoadImage(
		NULL, MAKEINTRESOURCE(IDC_ARROW),
		IMAGE_CURSOR, 0, 0, 
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground =					// �w�i�u���V
		(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;				// ���j���[��
	wc.lpszClassName = szClassName;		// �N���X��
	wc.hIconSm = (HICON)LoadImage(
		NULL, MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	return (RegisterClassEx(&wc));
}

BOOL Windows::InitInstance(HINSTANCE hInst, int nCmdShow)
{
	input = new Input();
	
	HWND hWnd;
	// �E�C���h�E�̐���
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
		MessageBox(hWnd, TEXT("�E�B���h�E�̐����Ɏ��s"), TEXT(""), MB_OK);
		return false;
	}

	// �E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return true;
}

// ���b�Z�[�W�̍X�V
bool Windows::UpdateWindowMessage(void)
{
	// ���C�����[�v
	while (!IsQuitMessage())
	{
		Message();
		Draw();		// �`��
	}
	return false;
}

// �I���ʒm�����Ă��邩�H
bool Windows::IsQuitMessage(void) { return g_isQuitMessage; }


// ���b�Z�[�W����
void Windows::Message()
{
	MSG msg;
	// ���b�Z�[�W�����݂��邩�m�F
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		// �I���ʒm�����Ă���ꍇ�͔�����
		if (msg.message == WM_QUIT)
		{
			g_isQuitMessage = true;
		}
		else
		{
			// ���b�Z�[�W���E�C���h�E�v���V�[�W���ɓ]��
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//return true;
	}
}

void Windows::Draw()
{

}



