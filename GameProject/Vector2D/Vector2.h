#pragma once
#define PI 3.14159265

class Vector2
{
public:
	Vector2();
	Vector2(int x,int y);
	Vector2(double x, double y);

	double getAngle(double x, double y);
	double calcSin(double angle);
	double calcCos(double angle);
	double calcTwoPtDisComp(int*, int*);
	double x, y;
};