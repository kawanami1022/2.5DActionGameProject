#include "Obj.h"

Obj::Obj()
{
}

Obj::~Obj()
{
}

//目的	;
//入力	:objPos		オブジェクトの座標
//		:objPosUL	オブジェクトの移動範囲左上
//		:objPosDR	オブジェクトの移動範囲右下
Vector2 Obj::fixPos(Vector2 *objPos, Vector2 objPosUL, Vector2 objPosDR)
{
	// 移動範囲左隅に寄せる
	if ((*objPos).x <= objPosUL.x)
	{
		(*objPos).x = objPosUL.x;
	}

	// 移動範囲上隅に寄せる
	if ((*objPos).y <= objPosUL.y)
	{
		(*objPos).y = objPosUL.y;
	}

	// 移動範囲右隅に寄せる
	if (objPosDR.x <= (*objPos).x)
	{
		objPosDR.x = (*objPos).x;
	}
	
	// 移動範囲下隅に寄せる
	if (objPosDR.y <= (*objPos).y)
	{
		(*objPos).y = objPosDR.y;
	}

	return (*objPos);
}
