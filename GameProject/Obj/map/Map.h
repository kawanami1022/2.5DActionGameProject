//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../../Vector2D/Vector2.h"
#include "../Obj.h"

#define CHIP_SIZE_X	32 
#define CHIP_SIZE_Y 32
#define CHIP_CNT_X	60
#define CHIP_CNT_Y	30
const Vector2 mapPosCorUL ={ 0,0 };		// マップ座標の左右隅
const Vector2 mapPosCorDR{ CHIP_CNT_X * CHIP_SIZE_X - SCREEN_SIZE_X,CHIP_CNT_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y };		// マップ座標の上下隅

class Map:public Obj
{
public:
	Map();
	~Map();
	void update()override;
	void draw()override;
	void drawMap();
	void moveX(Vector2 diff, int*);
	void moveY(Vector2 diff, int*);
	void setPos();
	Vector2 getDiff();
	Vector2 getPos();
private:
	Vector2 pos[FLAME_ID_MAX];
	Vector2 diff;
};