#pragma once

// ���ޯ��ү���ޗp��`
#ifdef _DEBUG
#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %d�s��\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "���ĕ\��", MB_OK);\
	}
#else
#define AST()
#endif

// �e��`
#define SCREEN_SIZE_X 800				// ��ʂ̉�����
#define SCREEN_SIZE_Y 600				// ��ʂ̏c����


// �������ߐ錾
bool SysInit(void);					// ���ьn������
bool GameInit(void);				// �ްьn������
void GameScene(void);				// �ްѼ�
void GameDraw(void);				// ��ʕ`��

int image;
int LoadFont;						// ̫��̧�ق̱��ڽ

void DrawText(int x, int y, const char* str);