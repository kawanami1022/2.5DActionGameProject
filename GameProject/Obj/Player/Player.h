//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../../Input/InputManager.h"
//#include "../../Input/PadInput.h"
#include "../Obj.h"
const int walkImageDiv = 4 * 4;		// 画像分割数
#define PLAYER_ANIM_WIDTH	4
#define PLAYER_MAG	1.5			// プレーヤーの倍率

class Player :public Obj
{
public:
	Player();
	Player(Vector2<double> pos, Vector2<double> size);
	~Player();
	void update()override;
	void draw();
	void moveX();	//	横移動
	void moveY();	//	縦移動
	void setAngle(int);		// 角度を固定
	void savePos();
	Vector2<double> calcVelocity(short* LStickPos);	// 移動量を求める
	Vector2<double> getVelocity();
	Vector2<double> getPos();
	Vector2<double> getDiff();
private:
	Vector2<double>* vec2;
	int angle;
	int animCnt;
	int walkImage[walkImageDiv];

	// 初期化
	void Init(void);
};