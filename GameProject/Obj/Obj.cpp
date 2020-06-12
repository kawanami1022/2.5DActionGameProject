//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "Obj.h"
#include "../Scene/SceneController.h"

Obj::Obj()
{
	_pos = { 0,0 };
	_rad = 0;
}

Obj::~Obj()
{
}

void Obj::draw()
{
	if (_animMap.find(_state) == _animMap.end()) // 見つかったらｲﾃﾚｰﾀを返す　endまで来るということは、そのﾃﾞｰﾀが存在しないということ
	{
		return;
	}
	if (_animFrame < 0 || _animFrame >= _animMap[_state].size()) // 要素数を調べるとき、取得する時はsizeを使う
	{
		return;
	}

	// _animMap[_animKey].size() コマ数

	if (_animMap[_state][_animFrame].first >= 0)
	{
		if (_animCount >= _animMap[_state][_animFrame].second)
		{
			_animFrame++;
		}

		_animCount++;

		if (_animFrame >= _animMap[_state].size())
		{
			_animFrame = 0;
			_animCount = 0;
		}

		/*lpSceneMng.AddDrawQue({ _animMap[_state][_animFrame].first,lpSceneMng.GameScreenOffset.x + _pos.x,lpSceneMng.GameScreenOffset.y +_pos.y , _rad, _zOrder, LAYER::CHAR, DX_BLENDMODE_NOBLEND, 255 });*/
		
		// Add all infomation to _drawList and draw later 
		lpSceneMng.AddDrawQue({ _animMap[_state][_animFrame].first,  _pos.x,  _pos.y , _rad });
	}
}

//目的	;
//入力	:objPos		オブジェクトの座標
//		:objPosUL	オブジェクトの移動範囲左上
//		:objPosDR	オブジェクトの移動範囲右下
Vector2<double> Obj::fixPos(Vector2<double> *objPos, Vector2<double> objPosUL, Vector2<double> objPosDR)
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
