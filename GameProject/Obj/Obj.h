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
	//NORMAL,  // �ʏ�
	//EX,		 // ����
	//DETH,	 // ����(���S�j
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
	int speed;	// ���x
	Vector2<double> velocity;

	// Variable use for animation

	bool _alive;		// �����Ă��邩
	bool _dead;			// ����ł��邩

	Vector2<double> _pos;
	Vector2<double> _size;
	double _rad;		// �p�x
	std::map<STATE, AnimVector> _animMap;	// Each STATE has different image ID and frame count
	STATE _state;
	//std::string _animKey;		// ���݂ǂ̱�Ұ��݂�\������̂���\����
	unsigned int _animFrame;	// ��Ұ����ڰс@���ϖڂ�
	unsigned int _animCount;	// ��Ұ��ݶ��ā@����ٰ�߂�����
private:

};

