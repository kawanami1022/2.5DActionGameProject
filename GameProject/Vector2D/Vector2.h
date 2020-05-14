//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#define PI 3.14159265

class Vector2
{
public:
	Vector2();
	Vector2(int x,int y);
	Vector2(double x, double y);

	double calcAngle(double x, double y);		// �p�x�����߂�
	double calcSin(double angle);				// y���̃x�N�g�������߂�
	double calcCos(double angle);				// x���̃x�N�g�������߂�
	double calcTwoPtDisComp(int*, int*);		// 2�̃|�C���g�̊Ԃ̋����̍���
	double x, y;								// ���W�i�[�p�ϐ�
};