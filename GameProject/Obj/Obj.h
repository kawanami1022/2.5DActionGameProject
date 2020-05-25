//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../Vector2D/Vector2.h"

enum FLAME_ID
{
	FLAME_ID_NOW,
	FLAME_ID_LAST,
	FLAME_ID_MAX
};

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual Vector2<double> fixPos(Vector2<double>*, Vector2<double>, Vector2<double>);
	 
protected:
	Vector2<double> pos[FLAME_ID_MAX];
	Vector2<double> diff;
	int speed;	// ‘¬“x
	Vector2<double> velocity;
private:

};

