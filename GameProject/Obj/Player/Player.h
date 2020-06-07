//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageDiv = 4 * 4;		// ‰æ‘œ•ªŠ„”
#define PLAYER_ANIM_WIDTH	4
#define PLAYER_MAG	1.5			// ƒvƒŒ[ƒ„[‚Ì”{—¦

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
	Vector2<double> calcVelocity(short* LStickPos);	// ˆÚ“®—Ê‚ğ‹‚ß‚é
	Vector2<double> getVelocity();
	Vector2<double> getPos();
	Vector2<double> getDiff();
private:
	Vector2<double>* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageDiv];
};