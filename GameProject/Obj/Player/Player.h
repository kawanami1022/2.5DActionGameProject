//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageCnt = 4;		// �摜�̐�
const int walkImageDiv = 4;		// �摜������


class Player :public Obj
{
public:
	Player();
	~Player();
	void update()override;
	void draw();
	void moveX();	//	���ړ�
	void moveY();	//	�c�ړ�
	void setAngle(int);
	void setPos();
	Vector2 calcVelocity(short* LStickPos);	// �ړ��ʂ����߂�
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
	Vector2* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageCnt][walkImageDiv];
};