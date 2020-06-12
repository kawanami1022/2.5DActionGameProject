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
	NORMAL,  // �ʏ�
	EX,		 // ����
	DETH,	 // ����(���S�j
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void update() = 0;
	virtual void draw();
	virtual Vector2<double> fixPos(Vector2<double>*, Vector2<double>, Vector2<double>);
	 
protected:
	Vector2<double> pos[FLAME_ID_MAX];
	Vector2<double> diff;
	int speed;	// ���x
	Vector2<double> velocity;

	// Variable use for animation
	Vector2<float> _pos;
	float _rad;
	std::map<STATE, AnimVector> _animMap;
	STATE _state;
	//std::string _animKey;		// ���݂ǂ̱�Ұ��݂�\������̂���\����
	unsigned int _animFrame;	// ��Ұ����ڰс@���ϖڂ�
	unsigned int _animCount;	// ��Ұ��ݶ��ā@����ٰ�߂�����
private:

};

