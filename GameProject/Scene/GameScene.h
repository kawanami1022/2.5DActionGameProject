//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------

#pragma once
//#include "../Input/InputManager.h"
//#include "../Input/PadInput.h"
#include "../Obj/Player/Player.h"
#include "../Obj/map/Map.h"

class GameScene :public BaseScene
{
public:
	GameScene();		
	~GameScene();

	void update();			// 更新処理
	void draw();			// 描画処理
	void move();			// 移動処理
	bool checkMoveObj(int*, int*, int, int, int);	// true: マップ移動 false:プレーヤー移動
private:
	Player *player;			// プレーヤー
	Map* map;				// マップ
	
};