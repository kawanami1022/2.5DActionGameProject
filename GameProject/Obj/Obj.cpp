#include "Obj.h"

Obj::Obj()
{
}

Obj::~Obj()
{
}

//�ړI	;
//����	:objPos		�I�u�W�F�N�g�̍��W
//		:objPosUL	�I�u�W�F�N�g�̈ړ��͈͍���
//		:objPosDR	�I�u�W�F�N�g�̈ړ��͈͉E��
Vector2 Obj::fixPos(Vector2 *objPos, Vector2 objPosUL, Vector2 objPosDR)
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
