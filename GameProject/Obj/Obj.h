//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../Vector2D/Vector2.h"
#include <vector>
#include <map>

enum FLAME_ID
{
	FLAME_ID_NOW,
	FLAME_ID_LAST,
	FLAME_ID_MAX
};

enum class STATE
{
	//NORMAL,  // 通常
	//EX,		 // 特殊
	//DETH,	 // 爆発(死亡）
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;		// ID and frames

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void update() = 0;
	virtual void draw();
	virtual Vector2<double> fixPos(Vector2<double>*, Vector2<double>, Vector2<double>);
	 

	bool SetAnim(const STATE Key, AnimVector& data);


protected:
	Vector2<double> pos[FLAME_ID_MAX];
	Vector2<double> diff;
	int speed;	// 速度
	Vector2<double> velocity;

	// Variable use for animation

	bool _alive;		// 生きているか
	bool _dead;			// 死んでいるか

	Vector2<double> _pos;
	Vector2<double> _size;
	double _rad;		// 角度
	std::map<STATE, AnimVector> _animMap;	// Each STATE has different image ID and frame count
	STATE _state;
	//std::string _animKey;		// 現在どのｱﾆﾒｰｼｮﾝを表示するのかを表す鍵
	unsigned int _animFrame;	// ｱﾆﾒｰｼｮﾝﾌﾚｰﾑ　何ｺﾏ目か
	unsigned int _animCount;	// ｱﾆﾒｰｼｮﾝｶｳﾝﾄ　何回ﾙｰﾌﾟしたか
private:

};

