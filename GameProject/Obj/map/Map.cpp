//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "../../Scene/SceneController.h"
#include "../Player/Player.h"
#include "../Obj.h"
#include "Map.h"
#include "../../CPP_Lib/mapData.h"

const char* ImageFileName[] =
{
	"../../Graphic/mapChip/mapChip_03.png"
	"../../Graphic/mapChip/mapChip_05.png"
	"../../Graphic/mapChip/mapChip_06.png"
	"../../Graphic/mapChip/mapChip_07.png"
	"../../Graphic/mapChip/mapChip_09.png"
};

Map::Map()
{
	pos[FLAME_ID_NOW] = { 100,100 };
	GetMapSizeForTxt(&x, &y, "stage01.txt",',');
	
}

Map::~Map()
{
}

void Map::update()
{
}

void Map::draw()
{
	// vertucal 縦
	for (int x = 0; x < CHIP_CNT_X; x++)
	{
		//DrawLine((int)(-pos[FLAME_ID_NOW].x+CHIP_SIZE_X*),
		//	(int)(-pos[FLAME_ID_NOW].y),
		//	(int)(-pos[FLAME_ID_NOW].x), 
		//	(int)(-pos[FLAME_ID_NOW].y), 0x888888, 1);		
	}
	// side 横
	for (int x = 0; x < CHIP_CNT_X; x++)
	{
		DrawLine((int)(-pos[FLAME_ID_NOW].x),
			(int)(-pos[FLAME_ID_NOW].y),
			(int)(-pos[FLAME_ID_NOW].x),
			(int)(-pos[FLAME_ID_NOW].y), 0x888888, 1);		// width
	}
	DrawFormatString(0, 0, 0x888888, "mapPos:%f,%f", pos->x, pos->y);
}

void Map::drawMap()
{
	
}

//目的	:プレーヤーの移動量分マップ移動を動かす
//入力	:プレーヤー位置
//		:プレーヤー移動速度
void Map::moveX(Vector2<double> velocity,int* mpCon)
{
	this->pos[FLAME_ID_NOW].x += velocity.x;
}

void Map::moveY(Vector2<double> velocity, int* mpCon)
{
	this->pos[FLAME_ID_NOW].y += velocity.y;
}

void Map::setPos()
{
	fixPos(&pos[FLAME_ID_NOW], mapPosCorUL, mapPosCorDR);
	pos[FLAME_ID_LAST] = pos[FLAME_ID_NOW];
}

Vector2<double> Map::getDiff()
{
	diff.x = pos[FLAME_ID_NOW].x - pos[FLAME_ID_LAST].x;
	diff.y = pos[FLAME_ID_NOW].y - pos[FLAME_ID_LAST].y;
	return diff;
}

Vector2<double> Map::getPos()
{
	return { pos[FLAME_ID_NOW].x,pos[FLAME_ID_NOW].y };
}


