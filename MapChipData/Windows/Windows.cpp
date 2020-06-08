// �쐬����Window.h���܂߂�
#include "Windows.h"

// �E�B���h�E�n���h��
HWND hWnd = NULL;
// �I���ʒm�����Ă��邩�H
bool g_isQuitMessage = false;

// �E�C���h�E�v���V�[�W���[
static LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uiMsg)
	{
	case WM_CLOSE:		// ����ۂ�Window��j������
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:	// �v���O�����̏I����ʒm����
		PostQuitMessage(0);
		return 0L;
	}
	// ����̃E�B���h�E�v���V�[�W�����Ăяo��
	return DefWindowProc(hWnd, uiMsg, wParam, lParam);
}

Windows::Windows(const TCHAR* pName, int x, int y, int width, int height)
{
	WNDCLASSEX wcex;
	// �E�C���h�E�̐ݒ�
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = TEXT("DirectX9 Sample");
	wcex.hIcon = LoadIcon(NULL, IDC_ARROW);				// �A�C�R��
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassExW(&wcex);

	DWORD dwStyle = WS_OVERLAPPEDWINDOW;

	RECT Rect;
	Rect.left = 0;
	Rect.top = 0;
	Rect.right = width;
	Rect.bottom = height;
	// �E�B���h�E�̃X�^�C���ɍ��킹���K�؂ȃT�C�Y���擾����
	AdjustWindowRect(&Rect, dwStyle, false);

	width = Rect.right - Rect.left;
	height = Rect.bottom - Rect.top;

	// �E�C���h�E�̐���
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

	// �E�C���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

}

Windows::~Windows()
{
}





// ���b�Z�[�W�̍X�V
bool Windows::UpdateWindowMessage(void)
{
	// ���C�����[�v
	while (!IsQuitMessage())
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
	return false;
}

// �I���ʒm�����Ă��邩�H
bool Windows::IsQuitMessage(void) { return g_isQuitMessage; }

// �E�B���h�E�n���h���̎擾
HWND Windows::GetWindowHandle(void) { return hWnd; }

