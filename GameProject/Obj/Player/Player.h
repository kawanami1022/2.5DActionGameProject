#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"

class Player :public Obj
{
public:
	Player();
	~Player();
	void update()override;
	void draw()override;
	void moveX();	//	���ړ�
	void moveY();	//	�c�ړ�
	void setPos();
	Vector2 calcVelocity(short* LStickPos);	// �ړ��ʂ����߂�
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
};