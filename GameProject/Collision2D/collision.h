//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once

struct LINE
{
	float x_f;
	float y_f;
	float sloap;	// �X��
};

enum COLL_ID
{
	COLL_ID_X,
	COLL_ID_Y,
	COLL_ID_MAX,
};

#ifndef _COLLISION_H_
#define _COLLISION_H_

//�ړI  :2�̋�`�̏Փ˔���
template <class T>
bool collisionRect(T* Rect1UL, T* Rect1DR, T* Rect2UL, T* Rect2DR);

//�ړI�@:2�̉~�̏Փ˔���
template <class T>
bool collisionCircle(T* C1Point, T C1Radious, T* C2Point, T C2Radious);

//�ړI:�����̌X�������߂�
template <class T>
float getlineSloap(T* LPoint1, T* LPoint2);

//�ړI:2�̌�_�����߂�
template <class T>
float *lineIntersect(T* L1Point, T L1Sloap, T* L2Point, T L2Sloap);

//�ړI	:�_�����̒��ɂ��邩����
template <class T>
bool checkPToLIntersect(T* LPoint1, T* LPoint2, T* CPoint);

//�ړI	;�_����`�̒����݂��Ă邩����
template <class T>
bool checkPInRect(T* Point, T* RectUL, T* RectDR);

//�ړI:�����̓����蔻��
template <class T>
bool collisionLine(T* Point1A, T* Point2A, T* Point1B, T* Point2B);

#endif