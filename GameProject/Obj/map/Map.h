//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../../Vector2D/Vector2.h"
#include "../Obj.h"

#define CHIP_ID		5
#define CHIP_SIZE_X	32 
#define CHIP_SIZE_Y 32
#define CHIP_CNT_X	60
#define CHIP_CNT_Y	30
const Vector2<double> mapPosCorUL ={ 0,0 };		// �}�b�v���W�̍��E��
const Vector2<double> mapPosCorDR{ CHIP_CNT_X * CHIP_SIZE_X - SCREEN_SIZE_X,CHIP_CNT_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y };		// �}�b�v���W�̏㉺��

class Map:public Obj
{
public:
	Map();
	~Map();
	void update()override;
	void draw()override;
	void drawMap();
	void moveX(Vector2<double> diff, int*);
	void moveY(Vector2<double> diff, int*);
	void setPos();
	Vector2<double> getDiff();
	Vector2<double> getPos();
private:
	Vector2<double> pos[FLAME_ID_MAX];
	Vector2<double> diff;
	Vector2<int> chipCnt;
	int* chipID;
	int* mapChipImg;
};