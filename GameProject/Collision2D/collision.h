//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once

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

#endif