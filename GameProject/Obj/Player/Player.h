//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageCnt = 4;		// ‰æ‘œ‚Ì”
const int walkImageDiv = 4;		// ‰æ‘œ•ªŠ„”


class Player :public Obj
{
public:
	Player();
	~Player();
	void update()override;
<<<<<<< HEAD
	void draw(int);
=======
	void draw();
>>>>>>> aef9ed36edb90bb82598103c3c45a9ce22a905e1
	void moveX();	//	‰¡ˆÚ“®
	void moveY();	//	cˆÚ“®
	void setAngle(int);
	void setPos();
	Vector2 calcVelocity(short* LStickPos);	// ˆÚ“®—Ê‚ğ‹‚ß‚é
	Vector2 getVelocity();
	Vector2 getPos();
	Vector2 getDiff();
private:
	Vector2* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageCnt][walkImageDiv];
};