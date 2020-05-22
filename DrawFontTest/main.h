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

int imageFont[95];						// ̫�ĉ摜�̓ǂݍ���


void DrawStringFromImage(int x, int y, int extend, const char* str);		// Draw Font from Font Image  ( x���W,y���W,�g��k��,string)