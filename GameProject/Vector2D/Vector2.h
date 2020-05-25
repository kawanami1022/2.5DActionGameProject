//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------d
#pragma once
#include <array>
#include <math.h>

#define PI 3.14159265

template<class T>
class Vector2
{
public:
	Vector2();
	Vector2(T x,T y);

	T calcAngle(T x, T y);		// 角度を求める
	T calcSin(T angle);				// y軸のベクトルを求める
	T calcCos(T angle);				// x軸のベクトルを求める
	T calcTwoPtDisComp(T*, T*);		// 2つのポイントの間の距離の合成
	T calcVecX(T dis, T angle);	// 角度からx軸y軸のそれぞれの速度を計算する
	T calcVecY(T dis, T angle);	// 角度からx軸y軸のそれぞれの速度を計算する
	T x, y;								// 座標格納用変数


};



template<class T> Vector2<T>::Vector2()
{
	x = 0;
	y = 0;
}

template<class T> Vector2<T>::Vector2(T x, T y)
{
	this->x = x;
	this->y = y;
}



// デカルト座標系での角度を求める
// 目的:
//		x
 
template<class T>T Vector2<T>::calcAngle(T x, T y)
{
	// 0°～90°の時
	if (0 < x && 0 < y)
		return atan(y / x) * 180 / PI;

	// 90°～180°の時  180°～270°の時
	if (x < 0 && 0 < y || x < 0 && y < 0)
		return 180 + atan(y / x) * 180 / PI;
	// 270°～360°の時
	else { return 360 + atan(y / x) * 180 / PI; }


}

template<class T>T Vector2<T>::calcSin(T angle)
{
	return sin(angle * (PI / 180));
}

template<class T>T Vector2<T>::calcCos(T angle)
{
	return cos(angle * (PI / 180));
}

// 目的	:2点間の距離の合成した距離を求める
template<class T>T Vector2<T>::calcTwoPtDisComp(T* pointA, T* pointB)
{
	// 0:x 1:y
	int dissX = pointA[0] + pointB[0];
	int dissY = pointA[1] + pointB[1];
	return sqrtf(dissX * dissX + dissY * dissY);
}

template<class T>T Vector2<T>::calcVecX(T dis, T angle)
{
	double vec = dis * calcSin(angle);
	return vec;
}

template<class T>T Vector2<T>::calcVecY(T dis, T angle)
{
	double vec = dis * calcCos(angle);
	return vec;
}

