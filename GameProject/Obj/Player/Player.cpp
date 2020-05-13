//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <math.h>
#include "DxLib.h"
#include "../Obj.h"
#include "Player.h"

Player::Player()
{
	pos[FLAME_ID_NOW] = { 500.0,300.0 };
	pos[FLAME_ID_LAST] = { 500.0,300.0 };
	diff = { 0.0,0.0 };
	speed = 5;
	velocity = { 0.0,0.0 };
	//pad = new Pad();
}

Player::~Player()
{
	//delete pad;
}

void Player::update()
{
}

void Player::draw()
{
	DrawCircle((int)pos[FLAME_ID_NOW].x, (int)pos[FLAME_ID_NOW].y, 16, 0xffff00, true, true);
	DrawFormatString(0, 128, 0xffffff, "player:%f,%f", pos[FLAME_ID_NOW].x, pos[FLAME_ID_NOW].y);
}

//�ړI�v���[���[�ړ�
void Player::moveX()
{
	pos[FLAME_ID_NOW].x += getVelocity().x;		// �ړ��FX��
}

void Player::moveY()
{
	pos[FLAME_ID_NOW].y += getVelocity().y;		// �ړ��FX��
}

void Player::setPos()
{
	pos[FLAME_ID_LAST] = pos[FLAME_ID_NOW];
}



Vector2 Player::getPos()
{
	return pos[FLAME_ID_NOW];
}

Vector2 Player::getDiff()
{
	diff.x = pos[FLAME_ID_NOW].x - pos[FLAME_ID_LAST].x;
	diff.y = pos[FLAME_ID_NOW].y - pos[FLAME_ID_LAST].y;
	return diff;
}

Vector2 Player::calcVelocity(short* LStickPos)
{
	Vector2 vec2;
	double angle = vec2.getAngle(LStickPos[0], LStickPos[1]);	// �p�x�����߂�
	velocity.x = vec2.calcCos(angle) * speed;		// �ړ��FX��
	velocity.y = -vec2.calcSin(angle) * speed;		// �ړ��FY��
	return { velocity.x,velocity.y };
}

Vector2 Player::getVelocity()
{
	return { velocity.x,velocity.y };
}


