#include "Input.h"

// �E�C���h�E�v���V�[�W���[
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
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
