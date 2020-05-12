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
	void moveX();	//	‰¡ˆÚ“®
	void moveY();	//	cˆÚ“®
	void setPos();
	Vector2 calcVelocity(short* LStickPos);	// ˆÚ“®—Ê‚ğ‹‚ß‚é
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
};