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
	if (_animMap.find(_state) == _animMap.end()) // �����������ڰ���Ԃ��@end�܂ŗ���Ƃ������Ƃ́A�����ް������݂��Ȃ��Ƃ�������
	{
		return;
	}
	if (_animFrame < 0 || _animFrame >= _animMap[_state].size()) // �v�f���𒲂ׂ�Ƃ��A�擾���鎞��size���g��
	{
		return;
	}

	// _animMap[_animKey].size() �R�}��

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

//�ړI	;
//����	:objPos		�I�u�W�F�N�g�̍��W
//		:objPosUL	�I�u�W�F�N�g�̈ړ��͈͍���
//		:objPosDR	�I�u�W�F�N�g�̈ړ��͈͉E��
Vector2<double> Obj::fixPos(Vector2<double> *objPos, Vector2<double> objPosUL, Vector2<double> objPosDR)
{
	// �ړ��͈͍����Ɋ񂹂�
	if ((*objPos).x <= objPosUL.x)
	{
		(*objPos).x = objPosUL.x;
	}

	// �ړ��͈͏���Ɋ񂹂�
	if ((*objPos).y <= objPosUL.y)
	{
		(*objPos).y = objPosUL.y;
	}

	// �ړ��͈͉E���Ɋ񂹂�
	if (objPosDR.x <= (*objPos).x)
	{
		objPosDR.x = (*objPos).x;
	}
	
	// �ړ��͈͉����Ɋ񂹂�
	if (objPosDR.y <= (*objPos).y)
	{
		(*objPos).y = objPosDR.y;
	}

	return (*objPos);
}
