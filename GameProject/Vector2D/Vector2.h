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

	double calcAngle(double x, double y);		// 角度を求める
	double calcSin(double angle);				// y軸のベクトルを求める
	double calcCos(double angle);				// x軸のベクトルを求める
	double calcTwoPtDisComp(int*, int*);		// 2つのポイントの間の距離の合成
	double x, y;								// 座標格納用変数
};