//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "../../Scene/SceneController.h"
#include "../Player/Player.h"
#include "../Obj.h"
#include "Map.h"

Map::Map()
{
	pos[FLAME_ID_NOW] = { 100,100 };
}

Map::~Map()
{
}

void Map::update()
{
}

void Map::draw()
{
	for (int y = 0; y < CHIP_CNT_Y; y++)
	{
		for (int x = 0; x < CHIP_CNT_X; x++)
		{
			DrawLine((int)(-pos[FLAME_ID_NOW].x),
				(int)(-pos[FLAME_ID_NOW].y + y * CHIP_SIZE_Y),
				(int)(-pos[FLAME_ID_NOW].x + x * CHIP_SIZE_X), 
				(int)(-pos[FLAME_ID_NOW].y + y * CHIP_SIZE_Y), 0x888888, 1);		// width
			DrawLine((int)(-pos[FLAME_ID_NOW].x + x * CHIP_SIZE_X),
				(int)(-pos[FLAME_ID_NOW].y),
				(int)(-pos[FLAME_ID_NOW].x + x * CHIP_SIZE_X), 
				(int)(-pos[FLAME_ID_NOW].y + y * CHIP_SIZE_Y), 0x888888, 1);		// width
		}
	}
	DrawFormatString(0, 0, 0x888888, "mapPos:%f,%f", pos->x, pos->y);
}

void Map::drawMap()
{
	
}

//目的	:プレーヤーの移動量分マップ移動を動かす
//入力	:プレーヤー位置
//		:プレーヤー移動速度
void Map::moveX(Vector2 velocity,int* mpCon)
{
	this->pos[FLAME_ID_NOW].x += velocity.x;
}

void Map::moveY(Vector2 velocity, int* mpCon)
{
	this->pos[FLAME_ID_NOW].y += velocity.y;
}

void Map::setPos()
{
	fixPos(&pos[FLAME_ID_NOW], mapPosCorUL, mapPosCorDR);
	pos[FLAME_ID_LAST] = pos[FLAME_ID_NOW];
}

Vector2 Map::getDiff()
{
	diff.x = pos[FLAME_ID_NOW].x - pos[FLAME_ID_LAST].x;
	diff.y = pos[FLAME_ID_NOW].y - pos[FLAME_ID_LAST].y;
	return diff;
}

Vector2 Map::getPos()
{
	return { pos[FLAME_ID_NOW].x,pos[FLAME_ID_NOW].y };
}


