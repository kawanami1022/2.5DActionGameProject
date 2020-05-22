//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageDiv = 4 * 4;		// �摜������
#define PLAYER_ANIM_WIDTH	4
#define PLAYER_MAG	1.5			// �v���[���[�̔{��

class Player :public Obj
{
public:
	Player();
	~Player();
	void update()override;
	void draw();
	void moveX();	//	���ړ�
	void moveY();	//	�c�ړ�
	void setAngle(int);		// �p�x���Œ�
	void savePos();
	Vector2 calcVelocity(short* LStickPos);	// �ړ��ʂ����߂�
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
	Vector2* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageDiv];
};