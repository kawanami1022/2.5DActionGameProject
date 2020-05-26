//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <iostream>
#include <math.h>
#include <utility>
#include "collision.h"

using namespace std;

struct LINE
{
	float x_f;
	float y_f;
	float sloap;	// 傾き
};

enum COLL_ID
{
	COLL_ID_X,
	COLL_ID_Y,
	COLL_ID_MAX,
};

#ifndef _COLLISION_H_
#define _COLLISION_H_

//目的  :2つの矩形の衝突判定
template <class T>
bool collisionRect(T* Rect1UL, T* Rect1DR, T* Rect2UL, T* Rect2DR);

//目的　:2つの円の衝突判定
template <class T>
bool collisionCircle(T* C1Point, T C1Radious, T* C2Point, T C2Radious);

//目的:直線の傾きを求める
template <class T>
float getlineSloap(T* LPoint1, T* LPoint2);

//目的:2つの交点を求める
template <class T>
float *lineIntersect(T* L1Point, T L1Sloap, T* L2Point, T L2Sloap);

//目的	:点が線の中にあるか判定
template <class T>
bool checkPToLIntersect(T* LPoint1, T* LPoint2, T* CPoint);

//目的	;点が矩形の中存在してるか判定
template <class T>
bool checkPInRect(T* Point, T* RectUL, T* RectDR);

//目的:線分の当たり判定
template <class T>
bool collisionLine(T* Point1A, T* Point2A, T* Point1B, T* Point2B);



//目的  :2つの矩形の衝突判定
//入力	:Rect1UL	第1矩形の左上	
//		:Rect1DR	第1矩形の右下
//		:Rect2UL	第2矩形の左上
//		:Rect2DR	第2矩形の右下
template <class T>
bool collisionRect(T* Rect1UL, T* Rect1DR, T* Rect2UL, T* Rect2DR)
{
	if (Rect1UL[0] < Rect2DR[0] && Rect2UL[0] < Rect1DR[0]
		&& Rect1UL[1] < Rect2DR[1] && Rect2UL[1] < Rect1DR[1])
	{
		return true;
	}
	return false;
}


//目的　:2つの円の衝突判定
//入力  :C1Point	第1円の座標
//      :C1Radious  第1円の半径
//      :C2Point	第2円の座標
//      :C2Radious	第2円の半径
template <class T>
bool collisionCircle(T* C1Point, T C1Radious, T* C2Point, T C2Radious)
{
	T temp[2] = { 0,0 };
	// 2点間のx軸距離
	temp[0] = (fabsf)((C1Point[0] - C2Point[0]) * (C1Point[0] - C2Point[0]));
	// 2点間のy軸距離
	temp[1] = (fabsf)((C1Point[1] - C2Point[1]) * (C1Point[1] - C2Point[1]));

	if ((C1Radious + C2Radious) * (C1Radious + C2Radious) < (temp[0] + temp[1]))
	{
		return true;
	}
	return false;
}

//目的　:傾きを求める
//入力　:LPoint1 点1
//		:LPoint2 点2
template <class T>
float getlineSloap(T* LPoint1, T* LPoint2)
{

	return (LPoint2[1] - LPoint1[1]) / (LPoint2[0] - LPoint1[0]);
}

//目的	:2つの交点を求める
//入力	:L1Point 第1の直線上の2Dの点
//		:L1Sloap 第1の直線の傾き
//		:L2Point 第2の直線上の2Dの点
//		:L2Sloap 第2の直線の傾き
template <class T>
float* lineIntersect(T* L1Point, T L1Sloap, T* L2Point, T L2Sloap)
{
	float temp[2] = { 0,0 };

	// 交点のx軸を求める
	temp[0] = (L1Sloap * L1Point[0] - L2Sloap * L2Point[0] + L2Point[1] - L1Point[1]) / (L1Sloap - L2Sloap);
	// 交点のy軸を求める
	temp[1] = L2Sloap * (temp[0] - L2Point[0]) + L2Point[1];
	return temp;
}

//目的	:点が線の中にあるか判定
//入力	:LPoint1 直線の座標(移動元)
//		:LPoint2 直線の座標(移動先)
//		:CPoint  交点
template <class T>
bool checkPToLIntersect(T* LPoint1, T* LPoint2, float* CPoint)
{
	// 移動先のほうが大きい場合中身をを入れ替える
	if (LPoint2[COLL_ID_X] < LPoint1[COLL_ID_X]) { swap(LPoint1[COLL_ID_X], LPoint2[COLL_ID_X]); }
	if (LPoint2[COLL_ID_Y] < LPoint1[COLL_ID_Y]) { swap(LPoint1[COLL_ID_Y], LPoint2[COLL_ID_Y]); }

	if (LPoint1[COLL_ID_X] < CPoint[COLL_ID_X] && CPoint[COLL_ID_X] < LPoint2[COLL_ID_X]
		&& LPoint1[COLL_ID_Y] < CPoint[COLL_ID_Y] && CPoint[COLL_ID_Y] < LPoint2[COLL_ID_Y])
	{
		return true;
	}
	return false;
}

//目的	;点が矩形の中存在してるか判定
//入力	:Point	点の座標
//		:RectUL	矩形左上の座標
//		:RectDR 矩形右下
template <class T>
bool checkPInRect(T* Point, T* RectUL, T* RectDR)
{
	if (RectUL[COLL_ID_X] < Point[COLL_ID_X] &&
		Point[COLL_ID_X] < RectDR[COLL_ID_X] &&
		RectUL[COLL_ID_Y] < Point[COLL_ID_Y] &&
		Point[COLL_ID_Y] < RectDR[COLL_ID_Y])
	{
		return true;
	}
	return false;
}

//目的	:線分の当たり判定
//入力	:Point1A 第1の点(移動元)
//		:Point2A 第1の点(移動先)
//		:Point1B 第2の点(移動元)
//		:Point2B 第2の点(移動先)
template <class T>
bool collisionLine(T* Point1A, T* Point2A, T* Point1B, T* Point2B)
{
	LINE line[2] = { 0,0 };
	T crossPoint[2] = { 0,0 };

	// 線Aの傾き
	line[0].sloap = getlineSloap(Point1A, Point2A);
	// 線Bの傾き
	line[1].sloap = getlineSloap(Point1B, Point2B);

	*crossPoint = *lineIntersect(Point1A, line[0].sloap, Point1B, line[1].sloap);
	//crossPoint[1] = lineIntersect(Point1A, line[0].sloap, Point1B, line[1].sloap)[1];


	//----判定する
	if (checkPToLIntersect(Point1A, Point2A, crossPoint)
		&& checkPToLIntersect(Point1B, Point2B, crossPoint))
	{
		return true;
	}

	return false;
}

#endif