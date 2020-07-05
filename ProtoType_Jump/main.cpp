#include <iostream>
#include <stdlib.h>
#include <DxLib.h>
#include "Input/keyInput.h"
#include "Geometry/Geometry.h"
#include "Vector2D/Vector2.h"
#include "Physics/Physics2D.h"

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

const unsigned int color[2] = { 0xffffff,0xff0000 };

struct Player
{
	Circle circle;
	Vector2<float> velocity;		// �ړ����x
	Vector2<float> acc;			// �����x
};


Player player;
KeyInput* keyInput;
void GameInit();
void GameInput();
void GameScene();
void GameDraw();
void GameEnd();
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	if (DxLib_Init()==-1)		// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}
	
	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);
	GameInit();
	// ���[�v
	while (!ProcessMessage())
	{
		// ��ʂ�����������

		GameScene();
		GameInput();
		GameDraw();

	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;
}

// �ްѼ�݂̏�����
void GameInit()
{
	keyInput = new KeyInput();
	player = { { SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,16 } ,{0,3.0f},{0,0.5f} };
}

// �Q�[������
void GameInput()
{
	keyInput->Update();
	if (keyInput->Push(KEY_INPUT_SPACE))
	{
		if (player.circle.y >= SCREEN_SIZE_Y)
		{
			player.velocity.y = -20;
		}
	}
}

// �ްѼ��
void GameScene()
{
	Gravity(&player.circle.y, SCREEN_SIZE_Y, &player.velocity.y, player.acc.y);

}

// �ްѼ�݂̕`��
void GameDraw()
{
	ClsDrawScreen();
	DrawCircle(player.circle.x, player.circle.y, 16, 0xffffff,true,true);
	DrawFormatString(0, 0, 0xffffff, "velocity:%d", (int)player.velocity.y);
	ScreenFlip();
}

void GameEnd()
{
}

