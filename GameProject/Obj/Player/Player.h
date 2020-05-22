//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageDiv = 4 * 4;		// ‰æ‘œ•ªŠ„”


class Player :public Obj
{
public:
	Player();
	~Player();
	void update()override;
	void draw();
	void moveX();	//	‰¡ˆÚ“®
	void moveY();	//	cˆÚ“®
	void setAngle(int);		// Šp“x‚ğŒÅ’è
	void savePos();
	Vector2 calcVelocity(short* LStickPos);	// ˆÚ“®—Ê‚ğ‹‚ß‚é
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
	Vector2* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageDiv];
};