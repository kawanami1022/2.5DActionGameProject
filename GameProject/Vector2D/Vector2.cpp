//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <math.h>
#include "Vector2.h"

Vector2::Vector2()
{

}

Vector2::Vector2(int x, int y)
{
	this->x = static_cast<double>(x);
	this->y = static_cast<double>(y);
}

Vector2::Vector2(double ax, double ay) :x(ax), y(ay) {}


// デカルト座標系での角度を求める
// 目的:
//		x
double Vector2::getAngle(double x, double y)
{
	// 0°～90°の時
	if(0<x&&0<y)
		return atan(y / x) * 180 / PI;
	
	// 90°～180°の時  180°～270°の時
	if (x < 0 && 0 < y || x < 0 && y < 0)
		return 180 + atan(y / x) * 180 / PI;
	// 270°～360°の時
	else { return 360 + atan(y / x) * 180 / PI; }
	

}

double Vector2::calcSin(double angle)
{
	return sin(angle * (PI / 180));
}

double Vector2::calcCos(double angle)
{
	return cos(angle * (PI / 180));
}

// 目的	:2点間の距離の合成した距離を求める
double Vector2::calcTwoPtDisComp(int* pointA, int* pointB)
{
	// 0:x 1:y
	int dissX = pointA[0] + pointB[0];
	int dissY = pointA[1] + pointB[1];
	return sqrtf(dissX * dissX + dissY * dissY);
}

