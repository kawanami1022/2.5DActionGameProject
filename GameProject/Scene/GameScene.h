//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------

#pragma once
#include "../Input/InputManager.h"
#include "../Input/PadInput.h"
#include "../Obj/Player/Player.h"
#include "../Obj/map/Map.h"

class GameScene :public BaseScene
{
public:
	GameScene();
	~GameScene();

	void update();
	void draw();
	void move();
	bool checkMoveObj(int*, int*, int, int, int);	// true: �}�b�v�ړ� false:�v���[���[�ړ�
private:
	Pad* pad;
	Player *player;
	Map* map;
	
};